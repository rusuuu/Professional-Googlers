#include "AuthenticationService.h"

AuthenticationService::AuthenticationService(QObject* parent)
{

}

void AuthenticationService::loginUser(const std::string& email, const std::string& password)
{
    std::string url = "http://localhost:18080/login";

    nlohmann::json jsonPayload;
    jsonPayload["email"] = email;
    jsonPayload["password"] = password;

    sendPostRequest(url, jsonPayload.dump());
}

void AuthenticationService::registerUser(const std::string& name, const std::string& email, const std::string& password)
{
    std::string url = "http://localhost:18080/register";

    nlohmann::json jsonPayload;
    jsonPayload["name"] = name;
    jsonPayload["email"] = email;
    jsonPayload["password"] = password;
    jsonPayload["image_path"] = "";

    sendPostRequest(url, jsonPayload.dump());
}

void AuthenticationService::sendPostRequest(const std::string& url, const std::string& jsonPayload)
{
    cpr::Body body(jsonPayload);
    cpr::Header headers = { {"Content-Type", "application/json"} };
    cpr::Response response = cpr::Post(cpr::Url{ url }, body, headers);

    if (200 <= response.status_code < 300) 
    {
        if (url.find("/login") != std::string::npos) 
        {
            emit loginResponseReceived(true, QString::fromUtf8(response.text));
        }
        else if (url.find("/register") != std::string::npos) 
        {
            emit registerResponseReceived(false, QString::fromUtf8("User registered successfully"));
        }
    }
    else
    {
        if (url.find("/login") != std::string::npos) 
        {
            emit loginResponseReceived(false, QString::fromUtf8(response.text));
        }
        else if (url.find("/register") != std::string::npos) 
        {
            emit registerResponseReceived(false, QString::fromUtf8(response.text));
        }
    }
}