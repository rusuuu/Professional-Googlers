#pragma once

#include "crow.h"
#include "Database.h"
#include "User.h"
#include "Game.h"

class GameHandler
{
public:
    GameHandler(Database::Storage& db);

    crow::response HostGame(const crow::request& req);
    crow::response GetGames();
    crow::response GetGameById(const crow::request& req);

private:
    Database::Storage& m_db;
};

