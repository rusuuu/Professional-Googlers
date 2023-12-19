#pragma once

#include "crow.h";
#include "Database.h"
#include "UserHelper.h"

import UserValidator;

class UserHandler
{
public:
	UserHandler(Database::Storage& db);

	crow::response CreateUser(const crow::request& req);

	crow::response GetUsers();
	crow::response GetUserByName(const crow::request& req);

	crow::response UpdateUser(const crow::request& req, std::string name);

	crow::response DeleteUser();
private:
	Database::Storage& m_db;
};