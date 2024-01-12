#include <iostream>

#include "crow.h"
#include "Database.h"
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


    app.port(18080).multithreaded().run();
    return 0;
}
