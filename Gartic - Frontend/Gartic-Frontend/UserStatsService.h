#pragma once
#include <string>
#include <QObject>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

class UserStatsService: public QObject
{
	Q_OBJECT

public:
	explicit UserStatsService(QObject* parent = nullptr);

	void CreateUserStats(const std::string& name, const int& totalGames, const int& gamesWon, const int& gamesLost, const int& totalPoints);
	void GetUserStats(const std::string& name);
	void UpdateUserStats(const std::string& name, const int& totalGames, const int& gamesWon, const int& gamesLost, const int& totalPoints);
	void DeleteUserStats(const std::string& name);

signals:
	void CreateUserStatsResponse(bool success, const QString& result);
	void GetUserStatsResponse(bool success, const QString& result);
	void UpdateUserStatsResponse(bool success, const QString& result);
	void DeleteUserStatsResponse(bool success, const QString& result);

private:
	void sendPostRequest(const std::string& url, const std::string& jsonPayload);
	void sendPutRequest(const std::string& url, const std::string& jsonPayload);
	void sendGetRequest(const std::string& url, const std::string& jsonPayload);
	void sendDeleteRequest(const std::string& url, const std::string& jsonPayload);

};

