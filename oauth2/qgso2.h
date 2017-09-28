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

#ifndef QGSO2_H
#define QGSO2_H

#include "o2.h"

class QgsAuthOAuth2Config;

/**
 * QGIS-specific subclass of O2 lib's base OAuth 2.0 authenticator.
 * Adds support for QGIS authentication system.
 */
class QgsO2: public O2
{

    Q_OBJECT

  public:
    explicit QgsO2( const QString &authcfg, QgsAuthOAuth2Config *oauth2config = nullptr,
                    QObject *parent = nullptr, QNetworkAccessManager *manager = nullptr );

    ~QgsO2();

    QString authcfg() const { return mAuthcfg; }
    QgsAuthOAuth2Config *oauth2config() { return mOAuth2Config; }

    Q_PROPERTY(QString state READ state WRITE setState NOTIFY stateChanged)
    QString state();
    void setState(const QString &value);

  public slots:
    void clearProperties();
    void onSetAuthCode(const QString &code);

  public Q_SLOTS:
	/// Authenticate.
    void link() override;

  protected:
  	QString state_;
  
  protected Q_SLOTS:
    /// Handle verification response.
    void onVerificationReceived(QMap<QString, QString>) override;

  Q_SIGNALS:
	void stateChanged();
  void getAuthCode();

  private:
    void initOAuthConfig();

    bool isLocalHost(QUrl redirectUrl);

    void setSettingsStore( bool persist = false );

    void setVerificationResponseContent();

    QString mTokenCacheFile;
    QString mAuthcfg;
    bool mIsLocalHost;
    QgsAuthOAuth2Config *mOAuth2Config;

};

#endif // QGSO2_H
