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
		crow::response AddUsersToDataBaseRoute(DataBaseStorage& storage, const crow::request& req, int userId) const;

	private:
		crow::SimpleApp m_app;
	};
}

