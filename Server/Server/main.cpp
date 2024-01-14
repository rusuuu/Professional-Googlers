#include <iostream>

#include "crow.h"
#include "Database.h"
#include "RoomHandler.h"
#include "UserHandler.h"
#include "UserStatsHandler.h"

int main() 
{
    crow::SimpleApp app;

    const std::string databaseFile = "database.sqlite";
    
    Database::Storage database = Database::CreateStorage(databaseFile);
    database.sync_schema();

    UserHandler userHandler(database);
    CROW_ROUTE(app, "/login").methods(crow::HTTPMethod::Post)([&userHandler](const crow::request& req) { return userHandler.LoginUser(req); });
    CROW_ROUTE(app, "/register").methods(crow::HTTPMethod::Post)([&userHandler](const crow::request& req) { return userHandler.RegisterUser(req); });

    CROW_ROUTE(app, "/users").methods(crow::HTTPMethod::Get)([&userHandler]() { return userHandler.GetUsers(); });
    CROW_ROUTE(app, "/user/name").methods(crow::HTTPMethod::Get)([&userHandler](const crow::request& req) { return userHandler.GetUserByName(req); });
    CROW_ROUTE(app, "/user/update").methods(crow::HTTPMethod::Put)([&userHandler](const crow::request& req) { return userHandler.UpdateUser(req); });
    CROW_ROUTE(app, "/user/delete").methods(crow::HTTPMethod::Delete)([&userHandler](const crow::request& req) { return userHandler.DeleteUser(req); });

    UserStatsHandler statsHandler(database);
    CROW_ROUTE(app, "/stats").methods(crow::HTTPMethod::Post)([&statsHandler](const crow::request& req) { return statsHandler.CreateUserStats(req); });

    CROW_ROUTE(app, "/stats").methods(crow::HTTPMethod::Get)([&statsHandler]() { return statsHandler.GetUserStats(); });
    CROW_ROUTE(app, "/stats/name").methods(crow::HTTPMethod::Get)([&statsHandler](const crow::request& req) { return statsHandler.GetUserStatsByName(req); });
    CROW_ROUTE(app, "/stats/update").methods(crow::HTTPMethod::Put)([&statsHandler](const crow::request& req) { return statsHandler.UpdateUserStats(req); });
    CROW_ROUTE(app, "/stats/delete").methods(crow::HTTPMethod::Delete)([&statsHandler](const crow::request& req) { return statsHandler.DeleteUserStats(req); });

    RoomHandler roomHandler;
    CROW_ROUTE(app, "/createRoom/<int>/<int>").methods(crow::HTTPMethod::Post)([&roomHandler](int roomId, int hostId)
        {
        roomHandler.CreateRoom(roomId, hostId);
        return crow::response(200, "Room created");
        });
    CROW_ROUTE(app, "/joinRoom/<int>/<int>").methods(crow::HTTPMethod::Put)([&roomHandler](int roomId, int userId) 
        {
        Room* room = roomHandler.GetRoom(roomId);
        if (room) 
        {
            room->AddUser(userId);
            return crow::response(200, "User added to room");
        }
        return crow::response(404, "Room not found");
        });

    CROW_ROUTE(app, "/startGame/<int>/<int>").methods(crow::HTTPMethod::Post)([&roomHandler](int roomId, int userId)
        {
        Room* room = roomHandler.GetRoom(roomId);
        if (room && room->IsHost(userId))
        {
            room->StartGame(userId);
            return crow::response(200, "Game started");
        }
        return crow::response(404, "Room not found or user is not host");
        });
    CROW_ROUTE(app, "/rooms").methods(crow::HTTPMethod::Get)([&roomHandler]()
        {
        return crow::response(200, roomHandler.GetAllRooms());
        });
    CROW_ROUTE(app, "/room/<int>").methods(crow::HTTPMethod::Get)([&roomHandler](int roomId)
        {
            return crow::response(200, roomHandler.GetRoomById(roomId));
        });

    app.port(18080).multithreaded().run();
    return 0;
}
