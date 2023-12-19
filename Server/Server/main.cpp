#include <iostream>

#include "crow.h"
#include "Database.h"
#include "UserHandler.h"

int main() 
{
    crow::SimpleApp app;

    const std::string databaseFile = "database.sqlite";
    
    Database::Storage database = Database::CreateStorage(databaseFile);
    database.sync_schema();

    UserHandler userHandler(database);
    CROW_ROUTE(app, "/users").methods(crow::HTTPMethod::POST)([&userHandler](const crow::request& req) { return userHandler.CreateUser(req); });
    CROW_ROUTE(app, "/users").methods(crow::HTTPMethod::GET)([&userHandler]() { return userHandler.GetUsers(); });

    CROW_ROUTE(app, "/users/<string>").methods(crow::HTTPMethod::PUT)([&userHandler](const crow::request& req, std::string name) { return userHandler.UpdateUser(req, name); });
    CROW_ROUTE(app, "/user/<string>").methods(crow::HTTPMethod::Delete)([&userHandler](const crow::request & req, std::string name) { return userHandler.DeleteUser(req, name); });

    app.port(18080).multithreaded().run();
    return 0;
}
