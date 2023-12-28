#pragma once

#include "crow.h"
#include "Database.h"

class RoomHandler
{
public:
	RoomHandler(Database::Storage& db);

	crow::response CreateRoom(const crow::request& req);
	crow::response GetRooms();
	crow::response GetRoomByCode(const crow::request& req);
	crow::response UpdateRoom(const crow::request& req);
	crow::response DeleteRoom(const crow::request& req);
	
private:
	Database::Storage& m_db;
};

