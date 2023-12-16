#pragma once

#include <crow.h>
#include "database.h"

namespace gartic
{
	class Routing
	{
	public:
		void Run(UserHandler& storage);

	private:
		crow::response VerifyUserToDataBaseRoute(UserHandler& storage, const crow::request& req) const;
		crow::response AddUserToDataBaseRoute(UserHandler& storage, const crow::request& req, const std::string& email, const std::string& password) const;

	private:
		crow::SimpleApp m_app;
	};
}

