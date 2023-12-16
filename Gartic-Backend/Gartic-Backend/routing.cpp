#include "routing.h"

using namespace gartic;

void Routing::Run(UserHandler& storage)
{
	CROW_ROUTE(m_app, "/")([]() {
		return "This is an example app of crow and sql-orm";
		});

    CROW_ROUTE(m_app, "/users")([&storage, this](const crow::request& req) {

        std::vector<crow::json::wvalue> users_json;

        auto users = storage.GetUsers();
        for (const auto& user : users)
        {
            users_json.push_back(crow::json::wvalue{
                {"id", user.GetId()},
                {"name", user.GetName()},
                {"email", user.GetEmail()}
                });
        }
        return crow::json::wvalue{ users_json };
    });

    CROW_ROUTE(m_app, "/login")([& storage, this](const crow::request& req){

        return VerifyUserToDataBaseRoute(storage, req);
    });

    CROW_ROUTE(m_app, "/register/<std::string>/<std::string>")([&storage, this](const crow::request& req, const std::string& name, const std::string& password) {

        return AddUserToDataBaseRoute(storage, req, name, password);
        });

	m_app.port(18080).multithreaded().run();
}

crow::response Routing::VerifyUserToDataBaseRoute(UserHandler& storage, const crow::request& req) const
{
    //validate user's login credentials 

    char* email_chr = req.url_params.get("email");
    char* password_chr = req.url_params.get("password");

    try {
        auto credentials = storage.FindUserForLogin(email_chr, password_chr);

        // If credentials are empty, throw an exception
        if (!credentials.has_value()) 
            throw std::runtime_error("User's credentials are incorrect!");
       
    	return crow::response(200);

    }
    catch (const std::exception& e) 
    {
        // Handle the exception
        return crow::response(500);
    }
}

crow::response Routing::AddUserToDataBaseRoute(UserHandler& storage, const crow::request& req, const std::string& email, const std::string& password) const
{
    char* email_chr = req.url_params.get("email");
    char* password_chr = req.url_params.get("password");

    try {
        auto credentials = storage.FindUserForLogin(email_chr, password_chr);

        // If credentials are not empty, throw an exception
        if (credentials.has_value())
            throw std::runtime_error("User's credentials already exist! Please login");

        storage.AddUserForRegister(email, password);

        return crow::response(200);

    }
    catch (const std::exception& e)
    {
        // Handle the exception
        return crow::response(500);
    }
}
