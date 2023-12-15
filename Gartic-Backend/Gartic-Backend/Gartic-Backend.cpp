#include "crow.h"
#include <functional>
#include <string>
#include "database.h"

namespace sql = sqlite_orm;

std::string hash_password(const std::string& password)
{
    std::hash<std::string> hasher;
    size_t hashed = hasher(password);
    return std::to_string(hashed);
}

int main()
{
    crow::SimpleApp app;

    DataBaseStorage storage;


    // User Registration
    CROW_ROUTE(app, "/register")
        .methods("POST"_method)
        ([&db](const crow::request& req) {
            auto x = crow::json::load(req.body);
            if (!x) {
                return crow::response(400);
            }

            std::string name = x["name"].s();
            std::string email = x["email"].s();
            std::string password = x["password"].s();

            std::string hashed_password = hash_password(password);

            Database::User user{0, name, email, hashed_password, "", "", 0, 0, 0};
            Database::AddUser(db, user);

            return crow::response(200);  // User registered
            });

    // User Login
    CROW_ROUTE(app, "/login")
        .methods("POST"_method)
        ([&db](const crow::request& req) {
            auto x = crow::json::load(req.body);
            if (!x) {
                return crow::response(400);
            }

            std::string email = x["email"].s();
            std::string password = x["password"].s();

            std::string hashed_password = hash_password(password);

            Database::User user = Database::User::GetUserByEmail(db, email);
            if (user.GetId == 0) {
                return crow::response(404);  // User not found
            }

            if (user.password != hashed_password) {
                return crow::response(401);  // Unauthorized
            }

            return crow::response(200);  // User verified
            });

    app.port(18080).multithreaded().run();
}