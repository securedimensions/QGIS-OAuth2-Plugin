/***************************************************************************
     testqgsauthoauth2config.cpp
     ----------------------
    Date                 : August 2016
    Copyright            : (C) 2016 by Boundless Spatial, Inc. USA
    Author               : Larry Shaffer
    Email                : lshaffer at boundlessgeo dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "qgstest.h"

#include <QtTest/QtTest>
#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QTemporaryFile>

#include "testutils.h"
#include "qgsapplication.h"
#include "qgsauthmanager.h"
#include "qgsauthoauth2config.h"

#include <stdio.h>
#include <stdlib.h>


inline QTextStream &qStdout()
{
  static QTextStream r( stdout );
  return r;
}

void suppressDebugHandler( QtMsgType type, const char *msg )
{
  switch ( type )
  {
#if QT_VERSION >= QT_VERSION_CHECK( 5, 5, 0 )
    case QtInfoMsg:
      break;
#endif
    case QtDebugMsg:
      break;
    case QtWarningMsg:
      fprintf( stderr, "Warning: %s\n", msg );
      break;
    case QtCriticalMsg:
      fprintf( stderr, "Critical: %s\n", msg );
      break;
    case QtFatalMsg:
      fprintf( stderr, "Fatal: %s\n", msg );
      abort();
  }
}

/** \ingroup UnitTests
 * Unit tests for QgsAuthOAuth2Config
 */
class TestQgsAuthOAuth2Config: public QObject
{
    Q_OBJECT

  private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void testOAuth2Config();
    void testOAuth2ConfigIO();
    void testOAuth2ConfigUtils();

  private:
    QgsAuthOAuth2Config *baseConfig( bool loaded = false );
    QByteArray baseConfigTxt( bool pretty = false );

    QVariantMap baseVariantMap();
    QByteArray baseVariantTxt();

    static QString smHashes;
    //static QObject *smParentObj;
    QtMsgHandler mOrigMsgHandler;
};

QString TestQgsAuthOAuth2Config::smHashes = "#####################";
//QObject *TestQgsAuthOAuth2Config::smParentObj = new QObject();

void TestQgsAuthOAuth2Config::initTestCase()
{
  setPrefixEnviron();
  mOrigMsgHandler = qInstallMsgHandler( suppressDebugHandler );

  QgsApplication::init();
  QgsApplication::initQgis();
  if ( QgsAuthManager::instance()->isDisabled() )
    QSKIP( "Auth system is disabled, skipping test case", SkipAll );

  qInstallMsgHandler( mOrigMsgHandler );

  //qDebug() << QgsApplication::showSettings().toUtf8().constData();
}

void TestQgsAuthOAuth2Config::cleanupTestCase()
{
  qDebug() << "\n";
  qInstallMsgHandler( suppressDebugHandler );
  QgsApplication::exitQgis();
}

void TestQgsAuthOAuth2Config::init()
{
  qStdout() << "\n" << smHashes << " Start "
            << QTest::currentTestFunction() << " " << smHashes << "\n";
  qStdout().flush();
}

void TestQgsAuthOAuth2Config::cleanup()
{
  qStdout() << smHashes << " End "
            << QTest::currentTestFunction() << " " << smHashes << "\n";
  qStdout().flush();
}

QgsAuthOAuth2Config *TestQgsAuthOAuth2Config::baseConfig( bool loaded )
{
  QgsAuthOAuth2Config *config = new QgsAuthOAuth2Config( qApp );
  if ( loaded )
  {
    config->setId( "abc1234" );
    config->setVersion( 1 );
    config->setConfigType( QgsAuthOAuth2Config::Custom );
    config->setGrantFlow( QgsAuthOAuth2Config::AuthCode );
    config->setName( "MyConfig" );
    config->setDescription( "A test config" );
    config->setRequestUrl( "https://request.oauth2.test" );
    config->setTokenUrl( "https://token.oauth2.test" );
    config->setRefreshTokenUrl( "https://refreshtoken.oauth2.test" );
    config->setRedirectUrl( "subdir" );
    config->setRedirectPort( 7777 );
    config->setClientId( "myclientid" );
    config->setClientSecret( "myclientsecret" );
    config->setUsername( "myusername" );
    config->setPassword( "mypassword" );
    config->setScope( "scope_1 scope_2 scope_3" );
    //config->setState( "somestate" );
    config->setApiKey( "someapikey" );
    config->setPersistToken( false );
    config->setAccessMethod( QgsAuthOAuth2Config::Header );
    config->setRequestTimeout( 30 ); // in seconds
    QVariantMap queryPairs;
    queryPairs.insert( "pf.username", "myusername" );
    queryPairs.insert( "pf.password", "mypassword" );
    config->setQueryPairs( queryPairs );
  }

  return config;
}

QByteArray TestQgsAuthOAuth2Config::baseConfigTxt( bool pretty )
{
  QByteArray out;
  if ( pretty )
  {
#if QT_VERSION < QT_VERSION_CHECK( 5, 0, 0 )
    out += "{\n"
           " \"accessMethod\" : 0,\n"
           " \"apiKey\" : \"someapikey\",\n"
           " \"clientId\" : \"myclientid\",\n"
           " \"clientSecret\" : \"myclientsecret\",\n"
           " \"configType\" : 1,\n"
           " \"description\" : \"A test config\",\n"
           " \"grantFlow\" : 0,\n"
           " \"id\" : \"abc1234\",\n"
           " \"name\" : \"MyConfig\",\n"
           " \"password\" : \"mypassword\",\n"
           " \"persistToken\" : false,\n"
           " \"queryPairs\" :  {\n"
           "  \"pf.password\" : \"mypassword\",\n"
           "  \"pf.username\" : \"myusername\"\n"
           " },\n"
           " \"redirectPort\" : 7777,\n"
           " \"redirectUrl\" : \"subdir\",\n"
           " \"refreshTokenUrl\" : \"https://refreshtoken.oauth2.test\",\n"
           " \"requestTimeout\" : 30,\n"
           " \"requestUrl\" : \"https://request.oauth2.test\",\n"
           " \"scope\" : \"scope_1 scope_2 scope_3\",\n"
           " \"state\" : \"somestate\",\n"
           " \"tokenUrl\" : \"https://token.oauth2.test\",\n"
           " \"username\" : \"myusername\",\n"
           " \"version\" : 1\n"
           "}";
#else
    out += "{\n"
           "    \"accessMethod\": 0,\n"
           "    \"apiKey\": \"someapikey\",\n"
           "    \"clientId\": \"myclientid\",\n"
           "    \"clientSecret\": \"myclientsecret\",\n"
           "    \"configType\": 1,\n"
           "    \"description\": \"A test config\",\n"
           "    \"grantFlow\": 0,\n"
           "    \"id\": \"abc1234\",\n"
           "    \"name\": \"MyConfig\",\n"
           "    \"objectName\": \"\",\n"
           "    \"password\": \"mypassword\",\n"
           "    \"persistToken\": false,\n"
           "    \"queryPairs\": {\n"
           "        \"pf.password\": \"mypassword\",\n"
           "        \"pf.username\": \"myusername\"\n"
           "    },\n"
           "    \"redirectPort\": 7777,\n"
           "    \"redirectUrl\": \"subdir\",\n"
           "    \"refreshTokenUrl\": \"https://refreshtoken.oauth2.test\",\n"
           "    \"requestTimeout\": 30,\n"
           "    \"requestUrl\": \"https://request.oauth2.test\",\n"
           "    \"scope\": \"scope_1 scope_2 scope_3\",\n"
           "    \"state\": \"somestate\",\n"
           "    \"tokenUrl\": \"https://token.oauth2.test\",\n"
           "    \"username\": \"myusername\",\n"
           "    \"version\": 1\n"
           "}\n";
#endif
  }
  else
  {
    out += "{\"accessMethod\":0,"
           "\"apiKey\":\"someapikey\","
           "\"clientId\":\"myclientid\","
           "\"clientSecret\":\"myclientsecret\","
           "\"configType\":1,"
           "\"description\":\"A test config\","
           "\"grantFlow\":0,"
           "\"id\":\"abc1234\","
           "\"name\":\"MyConfig\","
#if QT_VERSION >= QT_VERSION_CHECK( 5, 0, 0 )
           "\"objectName\":\"\","
#endif
           "\"password\":\"mypassword\","
           "\"persistToken\":false,"
           "\"queryPairs\":{\"pf.password\":\"mypassword\",\"pf.username\":\"myusername\"},"
           "\"redirectPort\":7777,"
           "\"redirectUrl\":\"subdir\","
           "\"refreshTokenUrl\":\"https://refreshtoken.oauth2.test\","
           "\"requestTimeout\":30,"
           "\"requestUrl\":\"https://request.oauth2.test\","
           "\"scope\":\"scope_1 scope_2 scope_3\","
           "\"state\":\"somestate\","
           "\"tokenUrl\":\"https://token.oauth2.test\","
           "\"username\":\"myusername\","
           "\"version\":1}";
  }
  return out;
}

QVariantMap TestQgsAuthOAuth2Config::baseVariantMap()
{
  QVariantMap vmap;
  vmap.insert( "apiKey", "someapikey" );
  vmap.insert( "accessMethod", 0 );
  vmap.insert( "clientId", "myclientid" );
  vmap.insert( "clientSecret", "myclientsecret" );
  vmap.insert( "configType", 1 );
  vmap.insert( "description", "A test config" );
  vmap.insert( "grantFlow", 0 );
  vmap.insert( "id", "abc1234" );
  vmap.insert( "name", "MyConfig" );
#if QT_VERSION >= QT_VERSION_CHECK( 5, 0, 0 )
  vmap.insert( "objectName", "" );
#endif
  vmap.insert( "password", "mypassword" );
  vmap.insert( "persistToken", false );
  QVariantMap qpairs;
  qpairs.insert( "pf.password", "mypassword" );
  qpairs.insert( "pf.username", "myusername" );
  vmap.insert( "queryPairs", qpairs );
  vmap.insert( "redirectPort", 7777 );
  vmap.insert( "redirectUrl", "subdir" );
  vmap.insert( "refreshTokenUrl", "https://refreshtoken.oauth2.test" );
  vmap.insert( "requestTimeout", 30 );
  vmap.insert( "requestUrl", "https://request.oauth2.test" );
  vmap.insert( "scope", "scope_1 scope_2 scope_3" );
  vmap.insert( "state", "somestate" );
  vmap.insert( "tokenUrl", "https://token.oauth2.test" );
  vmap.insert( "username", "myusername" );
  vmap.insert( "version", 1 );

  return vmap;
}

QByteArray TestQgsAuthOAuth2Config::baseVariantTxt()
{
  QByteArray out;
  return out;
}


void TestQgsAuthOAuth2Config::testOAuth2Config()
{
  qDebug() << "Verify base object config";
  QgsAuthOAuth2Config *config1 = new QgsAuthOAuth2Config( qApp );
  QVERIFY( !config1->isValid() );

  qDebug() << "Verify property interface";
  QObject *configo = config1;
  QCOMPARE( configo->property( "configType" ).toString(), QString( "1" ) ); // Custom
  config1->setConfigType( QgsAuthOAuth2Config::Predefined );
  QCOMPARE( configo->property( "configType" ).toString(), QString( "0" ) );
  QCOMPARE( QString( "%1" ).arg( config1->configType() ), QString( "0" ) );
  configo->setProperty( "configType", "Custom" );
  QCOMPARE( configo->property( "configType" ).toString(), QString( "1" ) );

  config1->deleteLater();

  qDebug() << "Verify base object validity";
  QgsAuthOAuth2Config *config2 = baseConfig();
  QVERIFY( !config2->isValid() );
  config2->deleteLater();

  QgsAuthOAuth2Config *config3 = baseConfig( true );
  QVERIFY( config3->isValid() );

  qDebug() << "Verify base object internal signals";
  QSignalSpy spy_config( config3, SIGNAL( configChanged() ) );
  QSignalSpy spy_valid( config3, SIGNAL( validityChanged( bool ) ) );

  config3->setRedirectPort( 0 );
  // validity should now be false

  QCOMPARE( spy_config.count(), 1 );
  QCOMPARE( spy_valid.count(), 1 );
  QList<QVariant> valid_args = spy_valid.takeAt( 0 );
  QVERIFY( valid_args.at( 0 ).toBool() == false );
  QVERIFY( !config3->isValid() );

  config3->setRedirectPort( 7777 );
  // validity should now be true

  QCOMPARE( spy_config.count(), 2 );
  QCOMPARE( spy_valid.count(), 1 );
  QList<QVariant> valid_args2 = spy_valid.takeAt( 0 );
  QVERIFY( valid_args2.at( 0 ).toBool() == true );
  QVERIFY( config3->isValid() );

  QCOMPARE( spy_valid.count(), 0 );
  config3->setRedirectPort( 4444 );
  // validity should still be true, so no validityChanged fired

  QCOMPARE( spy_config.count(), 3 );
  QCOMPARE( spy_valid.count(), 0 );
  QVERIFY( config3->isValid() );

  config3->deleteLater();

  qDebug() << "Validate equality";
  QgsAuthOAuth2Config *config4 = baseConfig( true );
  QgsAuthOAuth2Config *config5 = baseConfig( true );
  QgsAuthOAuth2Config *config6 = baseConfig();
  QVERIFY( *config4 == *config5 );
  QVERIFY( *config4 != *config6 );

  //config5->setName( "Blah blah" );
  config5->setRedirectPort( 2222 );
  QVERIFY( *config4 != *config5 );
  config4->deleteLater();
  config5->deleteLater();
  config6->deleteLater();
}

void TestQgsAuthOAuth2Config::testOAuth2ConfigIO()
{
  qDebug() << "Verify saving config to text";
  QgsAuthOAuth2Config *config1 = baseConfig( true );
  bool ok = false;
  QByteArray cfgtxt = config1->saveConfigTxt( QgsAuthOAuth2Config::JSON, true, &ok );
  QVERIFY( ok );
  //qDebug() << "cfgtxt: \n" << cfgtxt;
  //qDebug() << "baseConfigTxt: \n" << baseConfigTxt( true );
  QCOMPARE( baseConfigTxt( true ), cfgtxt );
  cfgtxt.clear();

  ok = false;
  cfgtxt = config1->saveConfigTxt( QgsAuthOAuth2Config::JSON, false, &ok );
  QVERIFY( ok );
  //qDebug() << "cfgtxt: \n" << cfgtxt;
  //qDebug() << "baseConfigTxt: \n" << baseConfigTxt( false );
  QCOMPARE( baseConfigTxt( false ), cfgtxt );

  qDebug() << "Verify loading config from text";
  // from base
  QgsAuthOAuth2Config *config2 = new QgsAuthOAuth2Config( qApp );
  QVERIFY( config2->loadConfigTxt( baseConfigTxt( true ), QgsAuthOAuth2Config::JSON ) );
  QVERIFY( *config1 == *config2 );

  // roundtrip already saved text
  QgsAuthOAuth2Config *config3 = new QgsAuthOAuth2Config( qApp );
  QVERIFY( config3->loadConfigTxt( cfgtxt, QgsAuthOAuth2Config::JSON ) );
  QVERIFY( *config1 == *config3 );

  // roundtrip already loaded obj
  ok = false;
  cfgtxt.clear();
  cfgtxt = config2->saveConfigTxt( QgsAuthOAuth2Config::JSON, true, &ok );
  QVERIFY( ok );
  //qDebug() << "cfgtxt: \n" << cfgtxt;
  //qDebug() << "baseConfigTxt: \n" << baseConfigTxt( true );
  QCOMPARE( baseConfigTxt( true ), cfgtxt );

  qDebug() << "Verify writing config to file";
  QString rndsuffix = QgsAuthManager::instance()->uniqueConfigId();
  QString dirname = QString( "oauth2_configs_%1" ).arg( rndsuffix );
  QDir tmpdir = QDir::temp();
  tmpdir.mkdir( dirname );

  QgsAuthOAuth2Config *config4 = baseConfig( true );
  QgsAuthOAuth2Config *config5 = baseConfig( true );
  config5->setName( "Blah blah" );
  config5->setRedirectPort( 2222 );

  qDebug() << QDir::tempPath() + "/" + dirname;

  QString config4path( QDir::tempPath() + "/" + dirname + "/config4.json" );
  QString config5path( QDir::tempPath() + "/" + dirname + "/config5.json" );

  QVERIFY( QgsAuthOAuth2Config::writeOAuth2Config( config4path, config4,
           QgsAuthOAuth2Config::JSON, true ) );
  QVERIFY( QgsAuthOAuth2Config::writeOAuth2Config( config5path, config5,
           QgsAuthOAuth2Config::JSON, true ) );

  qDebug() << "Verify reading config files from directory";
  ok = false;
  QList<QgsAuthOAuth2Config *> configs =
    QgsAuthOAuth2Config::loadOAuth2Configs( QDir::tempPath() + "/" + dirname,
        qApp, QgsAuthOAuth2Config::JSON, &ok );
  QVERIFY( ok );
  QCOMPARE( configs.size(), 2 );
  QgsAuthOAuth2Config *config6 = configs.takeFirst();
  QgsAuthOAuth2Config *config7 = configs.takeFirst();
  QVERIFY( config6->isValid() );
  QVERIFY( config7->isValid() );
  if ( config6->redirectPort() == 2222 )
  {
    QVERIFY( *config6 == *config5 );
    QVERIFY( *config7 == *config4 );
  }
  else
  {
    QVERIFY( *config7 == *config5 );
    QVERIFY( *config6 == *config4 );
  }

  // TODO: add tests for mapOAuth2Configs and mappedOAuth2ConfigsCache
}

void TestQgsAuthOAuth2Config::testOAuth2ConfigUtils()
{
  QVariantMap basevmap = baseVariantMap();
  bool ok = false;

  qDebug() << "Verify serializeFromVariant";
  QByteArray vtxt = QgsAuthOAuth2Config::serializeFromVariant(
                      basevmap, QgsAuthOAuth2Config::JSON, true, &ok );
  QVERIFY( ok );
  //qDebug() << vtxt;
  //qDebug() << baseConfigTxt( true );
  QCOMPARE( vtxt, baseConfigTxt( true ) );

  qDebug() << "Verify variantFromSerialized";
  QVariantMap vmap = QgsAuthOAuth2Config::variantFromSerialized(
                       baseConfigTxt( true ), QgsAuthOAuth2Config::JSON, &ok );
  QVERIFY( ok );
  QCOMPARE( vmap.value( "name" ).toString(), QString( "MyConfig" ) );
  QCOMPARE( vmap, basevmap );

}

QGSTEST_MAIN( TestQgsAuthOAuth2Config )
#include "testqgsauthoauth2config.moc"
