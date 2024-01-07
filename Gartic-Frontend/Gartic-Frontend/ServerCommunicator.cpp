//#include "ServerCommunicator.h"
//
//ServerCommunicator::ServerCommunicator(QObject* parent) : QObject(parent) {
//    QThread* thread = new QThread(this);
//    this->moveToThread(thread);
//    thread->start();
//
//    manager = new QNetworkAccessManager(this);
//    serverUrl = "http://localhost:18080";  
//}
//
//ServerCommunicator::~ServerCommunicator() {
//    manager->deleteLater();
//}
//
//void ServerCommunicator::sendLoginRequest(const QString& username, const QString& password) {
//    QUrl url(serverUrl + "/login");  /
//    QNetworkRequest request(url);
//
//    
//    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
//
//    QByteArray postData;
//    postData.append("username=" + QUrl::toPercentEncoding(username));
//    postData.append("&password=" + QUrl::toPercentEncoding(password));
//
//    connect(manager, &QNetworkAccessManager::finished, this, &ServerCommunicator::onLoginFinished);
//    manager->post(request, postData);  
//}
//
//void ServerCommunicator::onLoginFinished(QNetworkReply* reply) {
//    bool success = false;
//    QString message = "Failed to connect to server";
//
//    if (reply->error() == QNetworkReply::NoError) {
//        const QByteArray response = reply->readAll();
//        
//
//        success = true;  
//        message = "Login successful";  
//    }
//    else {
//        message = reply->errorString();
//    }
//
//    emit loginResponseReceived(success, message);
//}
//
