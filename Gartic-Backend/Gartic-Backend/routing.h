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
		crow::response VerifyUsersToDataBaseRoute(DataBaseStorage& storage, const crow::request& req) const;

	private:
		crow::SimpleApp m_app;
	};
}

