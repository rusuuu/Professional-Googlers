#pragma once

#include "crow.h";
#include "Database.h"

class UserStatsHandler
{
public:
	UserStatsHandler(Database::Storage& db);

	crow::response CreateUserStats(const crow::request& req);

	crow::response GetUserStats();
	crow::response GetUserStatsByName(const crow::request& req);

	crow::response UpdateUserStats(const crow::request& req);

	crow::response DeleteUserStats(const crow::request& req);

private:
	Database::Storage& m_db;
};

