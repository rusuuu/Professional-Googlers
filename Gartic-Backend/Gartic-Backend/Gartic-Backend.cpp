#include "crow.h"

import database;

int main()
{
    crow::SimpleApp app;

    auto db = Database::CreateStorage("");

    /*CROW_ROUTE(app, "/")([]() {
        return "Hello world";
        });*/

    // User Registration
    CROW_ROUTE(app, "/register")
        .methods("POST"_method)
        (&db{
            auto x = crow::json::load(req.body);
            if (!x) {
                return crow::response(400);
            }

            std::string name = x["name"].s();
            std::string email = x["email"].s();
            std::string password = x["password"].s();

            // TODO: Add code to hash the password

            Database::User user{0, name, email, password, "", "", 0, 0, 0};
            Database::AddUser(db, user);

            return crow::response(200);
            });

    // User Login
    

    app.port(18080).multithreaded().run();
}