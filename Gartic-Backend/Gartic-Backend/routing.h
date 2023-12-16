#pragma once

#include <crow.h>
#include "database.h"

namespace gartic
{
	class Routing
	{
	public:
		void Run(DataBaseStorage& storage);

	private:
		crow::response VerifyUserToDataBaseRoute(DataBaseStorage& storage, const crow::request& req) const;
		crow::response AddUserToDataBaseRoute(DataBaseStorage& storage, const crow::request& req, const std::string& email, const std::string& password) const;

	private:
		crow::SimpleApp m_app;
	};
}

