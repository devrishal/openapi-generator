/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * The version of the OpenAPI document: 1.0.0
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#include "PFXUserApi.h"
#include "PFXHelpers.h"
#include "PFXServerConfiguration.h"
#include <QJsonArray>
#include <QJsonDocument>

namespace test_namespace {

PFXUserApi::PFXUserApi(const QString &scheme, const QString &host, int port, const QString &basePath, const int timeOut)
    : _scheme(scheme),
      _host(host),
      _port(port),
      _basePath(basePath),
      _timeOut(timeOut),
      _manager(nullptr),
      isResponseCompressionEnabled(false),
      isRequestCompressionEnabled(false) {
      initializeServerConfigs();
      }

PFXUserApi::~PFXUserApi() {
}

void PFXUserApi::initializeServerConfigs(){

//Default server
QList<PFXServerConfiguration> defaultConf = QList<PFXServerConfiguration>();
//varying endpoint server 
QList<PFXServerConfiguration> serverConf = QList<PFXServerConfiguration>();
defaultConf.append(PFXServerConfiguration(
    "http://petstore.swagger.io/v2",
    "No description provided",
    QMap<QString, PFXServerVariable>()));
_serverConfigs.insert("createUser",defaultConf);
_serverIndices.insert("createUser",0);

_serverConfigs.insert("createUsersWithArrayInput",defaultConf);
_serverIndices.insert("createUsersWithArrayInput",0);

_serverConfigs.insert("createUsersWithListInput",defaultConf);
_serverIndices.insert("createUsersWithListInput",0);

_serverConfigs.insert("deleteUser",defaultConf);
_serverIndices.insert("deleteUser",0);

_serverConfigs.insert("getUserByName",defaultConf);
_serverIndices.insert("getUserByName",0);

_serverConfigs.insert("loginUser",defaultConf);
_serverIndices.insert("loginUser",0);

_serverConfigs.insert("logoutUser",defaultConf);
_serverIndices.insert("logoutUser",0);

_serverConfigs.insert("updateUser",defaultConf);
_serverIndices.insert("updateUser",0);


}

/**
* returns 0 on success and -1, -2 or -3 on failure.
* -1 when the variable does not exist and -2 if the value is not defined in the enum and -3 if the operation or server index is not found 
*/
int PFXUserApi::setDefaultServerValue(int serverIndex, const QString &operation, const QString &variable, const QString &value){
    auto it = _serverConfigs.find(operation);
    if(it != _serverConfigs.end() && serverIndex < it.value().size() ){
      return _serverConfigs[operation][serverIndex].setDefaultValue(variable,value);
    }
    return -3;
}
void PFXUserApi::setServerIndex(const QString &operation, int serverIndex){
    if(_serverIndices.contains(operation) && serverIndex < _serverConfigs.find(operation).value().size() )
        _serverIndices[operation] = serverIndex;
}

void PFXUserApi::setScheme(const QString &scheme) {
    _scheme = scheme;
}

void PFXUserApi::setHost(const QString &host) {
    _host = host;
}

void PFXUserApi::setPort(int port) {
    _port = port;
}

void PFXUserApi::setApiKey(const QString &apiKeyName, const QString &apiKey){
    _apiKeys.insert(apiKeyName,apiKey);
}

void PFXUserApi::setBearerToken(const QString &token){
    _bearerToken = token;
}

void PFXUserApi::setUsername(const QString &username) {
    _username = username;
}

void PFXUserApi::setPassword(const QString &password) {
    _password = password;
}

void PFXUserApi::setBasePath(const QString &basePath) {
    _basePath = basePath;
}

void PFXUserApi::setTimeOut(const int timeOut) {
    _timeOut = timeOut;
}

void PFXUserApi::setWorkingDirectory(const QString &path) {
    _workingDirectory = path;
}

void PFXUserApi::setNetworkAccessManager(QNetworkAccessManager* manager) {
    _manager = manager;  
}

void PFXUserApi::addHeaders(const QString &key, const QString &value) {
    defaultHeaders.insert(key, value);
}

void PFXUserApi::enableRequestCompression() {
    isRequestCompressionEnabled = true;
}

void PFXUserApi::enableResponseCompression() {
    isResponseCompressionEnabled = true;
}

void PFXUserApi::abortRequests(){
    emit abortRequestsSignal();
}

void PFXUserApi::createUser(const PFXUser &body) {
    QString fullPath = QString(_serverConfigs["createUser"][_serverIndices.value("createUser")].URL()+"/user");


    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "POST");

    QByteArray output = body.asJson().toUtf8();
    input.request_body.append(output);

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXUserApi::createUserCallback);
    connect(this, &PFXUserApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXUserApi::createUserCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit createUserSignal();
        emit createUserSignalFull(worker);
    } else {
        emit createUserSignalE(error_type, error_str);
        emit createUserSignalEFull(worker, error_type, error_str);
    }
}

void PFXUserApi::createUsersWithArrayInput(const QList<PFXUser> &body) {
    QString fullPath = QString(_serverConfigs["createUsersWithArrayInput"][_serverIndices.value("createUsersWithArrayInput")].URL()+"/user/createWithArray");


    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "POST");

    QJsonDocument doc(::test_namespace::toJsonValue(body).toArray());
    QByteArray bytes = doc.toJson();
    input.request_body.append(bytes);

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXUserApi::createUsersWithArrayInputCallback);
    connect(this, &PFXUserApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXUserApi::createUsersWithArrayInputCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit createUsersWithArrayInputSignal();
        emit createUsersWithArrayInputSignalFull(worker);
    } else {
        emit createUsersWithArrayInputSignalE(error_type, error_str);
        emit createUsersWithArrayInputSignalEFull(worker, error_type, error_str);
    }
}

void PFXUserApi::createUsersWithListInput(const QList<PFXUser> &body) {
    QString fullPath = QString(_serverConfigs["createUsersWithListInput"][_serverIndices.value("createUsersWithListInput")].URL()+"/user/createWithList");


    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "POST");

    QJsonDocument doc(::test_namespace::toJsonValue(body).toArray());
    QByteArray bytes = doc.toJson();
    input.request_body.append(bytes);

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXUserApi::createUsersWithListInputCallback);
    connect(this, &PFXUserApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXUserApi::createUsersWithListInputCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit createUsersWithListInputSignal();
        emit createUsersWithListInputSignalFull(worker);
    } else {
        emit createUsersWithListInputSignalE(error_type, error_str);
        emit createUsersWithListInputSignalEFull(worker, error_type, error_str);
    }
}

void PFXUserApi::deleteUser(const QString &username) {
    QString fullPath = QString(_serverConfigs["deleteUser"][_serverIndices.value("deleteUser")].URL()+"/user/{username}");
    QString usernamePathParam("{");
    usernamePathParam.append("username").append("}");
    fullPath.replace(usernamePathParam, QUrl::toPercentEncoding(::test_namespace::toStringValue(username)));
    

    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "DELETE");

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXUserApi::deleteUserCallback);
    connect(this, &PFXUserApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXUserApi::deleteUserCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit deleteUserSignal();
        emit deleteUserSignalFull(worker);
    } else {
        emit deleteUserSignalE(error_type, error_str);
        emit deleteUserSignalEFull(worker, error_type, error_str);
    }
}

void PFXUserApi::getUserByName(const QString &username) {
    QString fullPath = QString(_serverConfigs["getUserByName"][_serverIndices.value("getUserByName")].URL()+"/user/{username}");
    QString usernamePathParam("{");
    usernamePathParam.append("username").append("}");
    fullPath.replace(usernamePathParam, QUrl::toPercentEncoding(::test_namespace::toStringValue(username)));
    

    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "GET");

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXUserApi::getUserByNameCallback);
    connect(this, &PFXUserApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXUserApi::getUserByNameCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    PFXUser output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit getUserByNameSignal(output);
        emit getUserByNameSignalFull(worker, output);
    } else {
        emit getUserByNameSignalE(output, error_type, error_str);
        emit getUserByNameSignalEFull(worker, error_type, error_str);
    }
}

void PFXUserApi::loginUser(const QString &username, const QString &password) {
    QString fullPath = QString(_serverConfigs["loginUser"][_serverIndices.value("loginUser")].URL()+"/user/login");


    if (fullPath.indexOf("?") > 0)
        fullPath.append("&");
    else
        fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("username")).append("=").append(QUrl::toPercentEncoding(::test_namespace::toStringValue(username)));

    if (fullPath.indexOf("?") > 0)
        fullPath.append("&");
    else
        fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("password")).append("=").append(QUrl::toPercentEncoding(::test_namespace::toStringValue(password)));

    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "GET");

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXUserApi::loginUserCallback);
    connect(this, &PFXUserApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXUserApi::loginUserCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    QString output;
    ::test_namespace::fromStringValue(QString(worker->response), output);
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit loginUserSignal(output);
        emit loginUserSignalFull(worker, output);
    } else {
        emit loginUserSignalE(output, error_type, error_str);
        emit loginUserSignalEFull(worker, error_type, error_str);
    }
}

void PFXUserApi::logoutUser() {
    QString fullPath = QString(_serverConfigs["logoutUser"][_serverIndices.value("logoutUser")].URL()+"/user/logout");


    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "GET");

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXUserApi::logoutUserCallback);
    connect(this, &PFXUserApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXUserApi::logoutUserCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit logoutUserSignal();
        emit logoutUserSignalFull(worker);
    } else {
        emit logoutUserSignalE(error_type, error_str);
        emit logoutUserSignalEFull(worker, error_type, error_str);
    }
}

void PFXUserApi::updateUser(const QString &username, const PFXUser &body) {
    QString fullPath = QString(_serverConfigs["updateUser"][_serverIndices.value("updateUser")].URL()+"/user/{username}");
    QString usernamePathParam("{");
    usernamePathParam.append("username").append("}");
    fullPath.replace(usernamePathParam, QUrl::toPercentEncoding(::test_namespace::toStringValue(username)));
    

    PFXHttpRequestWorker *worker = new PFXHttpRequestWorker(this, _manager);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    PFXHttpRequestInput input(fullPath, "PUT");

    QByteArray output = body.asJson().toUtf8();
    input.request_body.append(output);

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &PFXHttpRequestWorker::on_execution_finished, this, &PFXUserApi::updateUserCallback);
    connect(this, &PFXUserApi::abortRequestsSignal, worker, &QObject::deleteLater); 
    worker->execute(&input);
}

void PFXUserApi::updateUserCallback(PFXHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit updateUserSignal();
        emit updateUserSignalFull(worker);
    } else {
        emit updateUserSignalE(error_type, error_str);
        emit updateUserSignalEFull(worker, error_type, error_str);
    }
}

} // namespace test_namespace
