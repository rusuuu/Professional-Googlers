//#pragma once
//
//#include <QObject>
//#include <QNetworkAccessManager>
//#include <QNetworkReply>
//#include <QThread>
//
//class ServerCommunicator : public QObject {
//    Q_OBJECT
//
//public:
//    explicit ServerCommunicator(QObject* parent = nullptr);
//    ~ServerCommunicator();
//
//    void sendLoginRequest(const QString& username, const QString& password);
//    void sendRegistrationRequest(const QString& username, const QString& password, const QString& email);
//   
//
//signals:
//    void loginResponseReceived(bool success, const QString& message);
//    void registrationResponseReceived(bool success, const QString& message);
//    
//
//private:
//    QNetworkAccessManager* manager;
//    QString serverUrl;
//
//private slots:
//    void onLoginFinished(QNetworkReply* reply);
//    void onRegistrationFinished(QNetworkReply* reply);
//    
//};
