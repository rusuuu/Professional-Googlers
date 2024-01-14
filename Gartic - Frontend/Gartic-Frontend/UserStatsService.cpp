#include "UserStatsService.h"

UserStatsService::UserStatsService(QObject* parent)
{
}

void UserStatsService::CreateUserStats(const std::string& name, const int& totalGames, const int& gamesWon, const int& gamesLost, const int& totalPoints)
{
    std::string url = "http://localhost:18080/stats";  

    nlohmann::json jsonPayload;
    jsonPayload["name"] = name;
    jsonPayload["totalGames"] = totalGames;
    jsonPayload["gamesWon"] = gamesWon;
    jsonPayload["gamesLost"] = gamesLost;
    jsonPayload["totalPoints"] = totalPoints;

    sendPostRequest(url, jsonPayload.dump());
}

void UserStatsService::GetUserStats(const std::string& name)
{
    std::string url = "http://localhost:18080/stats/name?name=" + name;

    sendGetRequest(url, "");
}

void UserStatsService::UpdateUserStats(const std::string& name, const int& totalGames, const int& gamesWon, const int& gamesLost, const int& totalPoints)
{
    std::string url = "http://localhost:18080/stats/update";  

    nlohmann::json jsonPayload;
    jsonPayload["name"] = name;
    jsonPayload["totalGames"] = totalGames;
    jsonPayload["gamesWon"] = gamesWon;
    jsonPayload["gamesLost"] = gamesLost;
    jsonPayload["totalPoints"] = totalPoints;

    sendPutRequest(url, jsonPayload.dump());
}

void UserStatsService::DeleteUserStats(const std::string& name)
{
    std::string url = "http://localhost:18080/stats/delete?name=" + name;

    sendDeleteRequest(url, "");
}

void UserStatsService::sendPostRequest(const std::string& url, const std::string& jsonPayload)
{
    cpr::Body body(jsonPayload);
    cpr::Header headers = { {"Content-Type", "application/json"} };
    cpr::Response response = cpr::Post(cpr::Url{ url }, body, headers);

    if (200 <= response.status_code && response.status_code < 300)
    {
        emit CreateUserStatsResponse(true, QString::fromUtf8(response.text.c_str()));
    }
    else 
    {  
        emit CreateUserStatsResponse(false, QString::fromUtf8(response.text.c_str()));
    }
}

void UserStatsService::sendPutRequest(const std::string& url, const std::string& jsonPayload)
{
    cpr::Body body(jsonPayload);
    cpr::Header headers = { {"Content-Type", "application/json"} };
    cpr::Response response = cpr::Put(cpr::Url{ url }, body, headers);

    if (200 <= response.status_code && response.status_code < 300)
    {
        emit UpdateUserStatsResponse(true, QString::fromUtf8(response.text.c_str()));
    }
    else 
    {
        emit UpdateUserStatsResponse(false, QString::fromUtf8(response.text.c_str()));
    }
}

void UserStatsService::sendGetRequest(const std::string& url, const std::string& jsonPayload)
{
    cpr::Header headers = { {"Content-Type", "application/json"} };
    cpr::Response response = cpr::Get(cpr::Url{ url }, headers);

    if (200 <= response.status_code && response.status_code < 300) 
    {
        emit GetUserStatsResponse(true, QString::fromUtf8(response.text.c_str()));
    }
    else
    {
        emit GetUserStatsResponse(false, QString::fromUtf8(response.text.c_str()));
    }
}

void UserStatsService::sendDeleteRequest(const std::string& url, const std::string& jsonPayload)
{
    cpr::Header headers = { {"Content-Type", "application/json"} };
    cpr::Response response = cpr::Delete(cpr::Url{ url }, headers);

    if (200 <= response.status_code && response.status_code < 300) 
    {     
        emit DeleteUserStatsResponse(true, QString::fromUtf8(response.text.c_str()));
    }
    else
    {
        emit DeleteUserStatsResponse(false, QString::fromUtf8(response.text.c_str()));
    }
}
