# QGIS-OAuth2-Plugin
Open Geospatial Consortium Testbed 13 - OAuth2 Plugin for QGIS 2.18.4

This version of the OAuth2 plugin for QGIS 2.18.x was created for OGC Testbed 13 and is based on the code from Boundless Geo (https://github.com/boundlessgeo/qgis-oauth-cxxplugin). During the Testbed 13 project, we have made changes to the sources and extended the functionalities to mainly support OAuth2 Dynamic Client Registration via Software Statements but also to support manual finish of the Authorization Code Grant.

The details are documented in the public Testbed 13 Engineering Report with the title "OGC Testbed-13: Security ER" that associated with this project. The report can be downloaded from the OGC website once published (approx. mid. January 2018): http://www.opengeospatial.org/docs/er

The following is the list of changes and improvements:

| Change / Improvement | Description  |
| ---------------------| :------------|
| state parameter      | The Boundless Geo version of the plugin requests the state parameter to be provided by the user. We have changed that as we think that the user must not be responsible for providing that, as a duplication of a state parameter could lead to unintentional errors. The Testbed 13 version generates the state parameter automatically for each authorization request to the Authorization Server and checks the value from the redirect to ensure no CSRF attacks. 
| optional parameters  | The Testbed 13 version populates all the extra parameters as provided by the user vi the GUI. This was important to support the setup from 52North using the Auth0 Authorization Server, because the optional parameter audience was required.
| Dynamic Client Registration | The Testbed 13 version provides an additional configuration tab "software statement" which allows a user to automatically register the plugin with a required configuration with the Authorization Server. Of course this can only be leveraged, if the Authorization Server involved supports the registration via digitally signed software statements (JWTs) as described in this ER.
| Authorization Code manual | Support for the Authorization Code flow to copy and paste the authorization code when redirect_uri is not locahost or 127.0.0.1
