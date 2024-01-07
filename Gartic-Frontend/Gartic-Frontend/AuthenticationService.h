#pragma once
#include <string>
#include <QObject>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

class AuthenticationService : public QObject 
{
	Q_OBJECT

public:
	explicit AuthenticationService(QObject* parent = nullptr);

	void loginUser(const std::string& email, const std::string& password);
	void registerUser(const std::string& name, const std::string& email, const std::string& password);

signals:
	void loginResponseReceived(bool success, const QString& result);
	void registerResponseReceived(bool success, const QString& message);

private:
	void sendPostRequest(const std::string& url, const std::string& jsonPayload);
};
