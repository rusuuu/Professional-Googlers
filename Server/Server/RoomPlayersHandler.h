#pragma once

#include <vector>
#include <string>

#include "crow.h"
#include "Database.h"
#include "RoomPlayer.h"
#include "RoomHelper.h"

class RoomPlayersHandler
{
public:
    RoomPlayersHandler(Database::Storage& db);

    crow::response AddPlayerToRoom(const crow::request& req);

    crow::response RemovePlayerFromRoom(const crow::request& req);

    crow::response GetPlayersInRoom(const crow::request& req);

private:
	Database::Storage& m_db;
};

