/***************************************************************************
begin                : August 1, 2016
copyright            : (C) 2016 by Monsanto Company, USA
author               : Larry Shaffer, Boundless Spatial
email                : lshaffer at boundlessgeo dot com
***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
***************************************************************************/

#include "qgso2.h"

#include "o0globals.h"
#include "o0settingsstore.h"
#include "o2replyserver.h"
#include "qgsapplication.h"
#include "qgsauthoauth2config.h"
#include "qgslogger.h"

#include <QDir>
#include <QSettings>
#include <QUrl>


namespace
{
  const char O2_OAUTH2_STATE[] = "state";
  /// Add query parameters to a query
  static void addQueryParametersToUrl(QUrl &url,  QList<QPair<QString, QString> > parameters) {
#if QT_VERSION < 0x050000
    url.setQueryItems(parameters);
#else
    QUrlQuery query(url);
    query.setQueryItems(parameters);
    url.setQuery(query);
#endif
  }
}

QgsO2::QgsO2( const QString &authcfg, QgsAuthOAuth2Config *oauth2config,
  QObject *parent, QNetworkAccessManager *manager )
  : O2( parent, manager )
  , mTokenCacheFile( QString::null )
  , mAuthcfg( authcfg )
  , mOAuth2Config( oauth2config )
{
  initOAuthConfig();
}

QgsO2::~QgsO2()
{
  // FIXME: This crashes app on QgsApplication destruction
  //        Verify that objects are actually being deleted via QgsAuthManager's destruction
  //mOAuth2Config->deleteLater();

  if ( mTokenCacheFile.startsWith( QgsAuthOAuth2Config::tokenCacheDirectory( true ) )
    && QFile::exists( mTokenCacheFile ) )
  {
    if ( !QFile::remove( mTokenCacheFile ) )
    {
      QgsDebugMsg( QStringLiteral( "Could not remove temp token cache file: %1" ).arg( mTokenCacheFile ) );
    }
  }
}

void QgsO2::onSetAuthCode(const QString &code)
{
  setCode( code );
  onVerificationReceived( QMap<QString, QString>() );
}

bool QgsO2::isLocalHost(QUrl redirectUrl)
{
  QString hostName = redirectUrl.host();
  if( hostName == "localhost" || hostName == "127.0.0.1" || hostName == "[::1]" )
  {
    return true;
  }
  return false;
}

void QgsO2::initOAuthConfig()
{
  if ( !mOAuth2Config )
  {
    return;
  }

  // common properties to all grant flows
  QUrl redirectUrl( mOAuth2Config->redirectUrl() );
  mIsLocalHost = isLocalHost( redirectUrl );
  if( mIsLocalHost )
  {
    QString localpolicy = QStringLiteral( "http://%1:% 1%2" ).arg( redirectUrl.host() ).arg( redirectUrl.path() ).replace( QStringLiteral( "% 1" ), QStringLiteral( "%1" ) );
    QgsDebugMsg( QStringLiteral( "localpolicy(w/port): %1" ).arg( localpolicy.arg( mOAuth2Config->redirectPort() ) ) );
    setLocalhostPolicy( localpolicy );
  }
  setLocalPort( mOAuth2Config->redirectPort() );
  redirectUri_ = mOAuth2Config->redirectUrl();
  setTokenUrl( mOAuth2Config->tokenUrl() );
  setRefreshTokenUrl( mOAuth2Config->refreshTokenUrl() );

  setScope( mOAuth2Config->scope() );
  setState("ignore me");

  // common optional properties
  setApiKey( mOAuth2Config->apiKey() );
  setExtraRequestParams( mOAuth2Config->queryPairs() );

  O2::GrantFlow o2flow;
  switch ( mOAuth2Config->grantFlow() )
  {
  case QgsAuthOAuth2Config::AuthCode:
    o2flow = O2::GrantFlowAuthorizationCode;
    setRequestUrl( mOAuth2Config->requestUrl() );
    setClientId( mOAuth2Config->clientId() );
    setClientSecret( mOAuth2Config->clientSecret() );

    break;
  case QgsAuthOAuth2Config::Implicit:
    o2flow = O2::GrantFlowImplicit;
    setRequestUrl( mOAuth2Config->requestUrl() );
    setClientId( mOAuth2Config->clientId() );

    break;
  case QgsAuthOAuth2Config::ResourceOwner:
    o2flow = O2::GrantFlowResourceOwnerPasswordCredentials;
    setClientId( mOAuth2Config->clientId() );
    setClientSecret( mOAuth2Config->clientSecret() );
    setUsername( mOAuth2Config->username() );
    setPassword( mOAuth2Config->password() );

    break;
  }
  setGrantFlow( o2flow );

  setSettingsStore( mOAuth2Config->persistToken() );

  setVerificationResponseContent();
}

void QgsO2::setSettingsStore( bool persist )
{
  mTokenCacheFile = QgsAuthOAuth2Config::tokenCachePath( mAuthcfg, !persist );

  QSettings *settings = new QSettings( mTokenCacheFile, QSettings::IniFormat );
  O0SettingsStore *store = new O0SettingsStore( settings, O2_ENCRYPTION_KEY );
  store->setGroupKey( QStringLiteral( "authcfg_%1" ).arg( mAuthcfg ) );
  setStore( store );
}

void QgsO2::setVerificationResponseContent()
{
  QFile verhtml( QStringLiteral( ":/oauth2method/oauth2_verification_finished.html" ) );
  if ( verhtml.open( QIODevice::ReadOnly | QIODevice::Text ) )
  {
    setReplyContent( verhtml.readAll() );
  }
}

// slot
void QgsO2::clearProperties()
{
  // TODO: clear object properties
}

QString QgsO2::state()
{
  return state_;
}

//Sets state to random number each time it's called
void QgsO2::setState(const QString &/*value*/)
{
  qsrand(QTime::currentTime().msec());
  state_ = QString::number(qrand());
  Q_EMIT stateChanged();
}


void QgsO2::link()
{
  qDebug() << "QgsO2::link";

  if (linked())
  {
    qDebug() << "QgsO2::link: Linked already";
    Q_EMIT linkingSucceeded();
    return;
  }

  setLinked(false);
  setToken("");
  setTokenSecret("");
  setExtraTokens(QVariantMap());
  setRefreshToken(QString());
  setExpires(0);

  if (grantFlow_ == GrantFlowAuthorizationCode)
  {
    if( mIsLocalHost )
    {
      // Start listening to authentication replies
      replyServer_->listen(QHostAddress::Any, localPort_);

      // Save redirect URI, as we have to reuse it when requesting the access token
      redirectUri_ = localhostPolicy_.arg(replyServer_->serverPort());
    }
    // Assemble intial authentication URL
    QList<QPair<QString, QString> > parameters;
    parameters.append(qMakePair(QString(O2_OAUTH2_RESPONSE_TYPE), (grantFlow_ == GrantFlowAuthorizationCode)? QString(O2_OAUTH2_GRANT_TYPE_CODE): QString(O2_OAUTH2_GRANT_TYPE_TOKEN)));
    parameters.append(qMakePair(QString(O2_OAUTH2_CLIENT_ID), clientId_));
    parameters.append(qMakePair(QString(O2_OAUTH2_REDIRECT_URI), redirectUri_));
    parameters.append(qMakePair(QString(O2_OAUTH2_SCOPE), scope_));
    parameters.append(qMakePair(QString(O2_OAUTH2_STATE), state_));
    parameters.append(qMakePair(QString(O2_OAUTH2_API_KEY), apiKey_));

    for(QVariantMap::const_iterator iter = extraReqParams_.begin(); iter != extraReqParams_.end(); ++iter)
    {
      parameters.append(qMakePair(iter.key(), iter.value().toString()));
    }

    // Show authentication URL with a web browser
    QUrl url(requestUrl_);
    addQueryParametersToUrl(url, parameters);
    qDebug() << "QgsO2::link: Emit openBrowser" << url.toString();
    Q_EMIT openBrowser(url);
    if ( !mIsLocalHost )
    {
      Q_EMIT getAuthCode();
    }
  }
  else if (grantFlow_ == GrantFlowResourceOwnerPasswordCredentials)
  {
    QList<O0RequestParameter> parameters;
    parameters.append(O0RequestParameter(O2_OAUTH2_CLIENT_ID, clientId_.toUtf8()));
    parameters.append(O0RequestParameter(O2_OAUTH2_CLIENT_SECRET, clientSecret_.toUtf8()));
    parameters.append(O0RequestParameter(O2_OAUTH2_USERNAME, username_.toUtf8()));
    parameters.append(O0RequestParameter(O2_OAUTH2_PASSWORD, password_.toUtf8()));
    parameters.append(O0RequestParameter(O2_OAUTH2_GRANT_TYPE, O2_OAUTH2_GRANT_TYPE_PASSWORD));
    parameters.append(O0RequestParameter(O2_OAUTH2_SCOPE, scope_.toUtf8()));
    parameters.append(O0RequestParameter(O2_OAUTH2_API_KEY, apiKey_.toUtf8()));


    for(QVariantMap::const_iterator iter = extraReqParams_.begin(); iter != extraReqParams_.end(); ++iter)
    {
      parameters.append(O0RequestParameter(iter.key().toUtf8(), iter.value().toString().toUtf8()));
    }


    QByteArray payload = O0BaseAuth::createQueryParameters(parameters);

    QUrl url(tokenUrl_);
    QNetworkRequest tokenRequest(url);
    tokenRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QNetworkReply *tokenReply = manager_->post(tokenRequest, payload);

    connect(tokenReply, SIGNAL(finished()), this, SLOT(onTokenReplyFinished()), Qt::QueuedConnection);
    connect(tokenReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onTokenReplyError(QNetworkReply::NetworkError)), Qt::QueuedConnection);
  }
}

void QgsO2::onVerificationReceived(const QMap<QString, QString> response)
{
  qDebug() << "QgsO2::onVerificationReceived:" << response;
  qDebug() << "QgsO2::onVerificationReceived: Emitting closeBrowser()";
  Q_EMIT closeBrowser();

  if ( mIsLocalHost )
  {
    if (response.contains("error"))
    {
      qWarning() << "QgsO2::onVerificationReceived: Verification failed: " << response;
      Q_EMIT linkingFailed();
      return;
    }

    if (response.contains("state"))
    {
      if(response.value("state","ignore")!=state_)
      {
        qWarning() << "QgsO2::onVerificationReceived: Verification failed: (Response returned wrong state) " << response;
        Q_EMIT linkingFailed();
        return;
      }
    }
    else
    {
      qWarning() << "QgsO2::onVerificationReceived: Verification failed: (Response does not contain state) " << response;
      Q_EMIT linkingFailed();
      return;
    }
    // Save access code
    setCode(response.value(QString(O2_OAUTH2_GRANT_TYPE_CODE)));
  }

  if (grantFlow_ == GrantFlowAuthorizationCode)
  {

    // Exchange access code for access/refresh tokens
    QString query;
    if(!apiKey_.isEmpty())
      query = QString("?" + QString(O2_OAUTH2_API_KEY) + "=" + apiKey_);
    QNetworkRequest tokenRequest(QUrl(tokenUrl_.toString() + query));
    tokenRequest.setHeader(QNetworkRequest::ContentTypeHeader, O2_MIME_TYPE_XFORM);
    QMap<QString, QString> parameters;
    parameters.insert(O2_OAUTH2_GRANT_TYPE_CODE, code());
    parameters.insert(O2_OAUTH2_CLIENT_ID, clientId_);
    parameters.insert(O2_OAUTH2_CLIENT_SECRET, clientSecret_);
    parameters.insert(O2_OAUTH2_REDIRECT_URI, redirectUri_);
    parameters.insert(O2_OAUTH2_GRANT_TYPE, O2_AUTHORIZATION_CODE);
    QByteArray data = buildRequestBody(parameters);
    QNetworkReply *tokenReply = manager_->post(tokenRequest, data);
    timedReplies_.add(tokenReply);
    connect(tokenReply, SIGNAL(finished()), this, SLOT(onTokenReplyFinished()), Qt::QueuedConnection);
    connect(tokenReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onTokenReplyError(QNetworkReply::NetworkError)), Qt::QueuedConnection);
  }
  else
  {
    setToken(response.value(O2_OAUTH2_ACCESS_TOKEN));
    setRefreshToken(response.value(O2_OAUTH2_REFRESH_TOKEN));
  }
}
