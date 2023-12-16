#include "routing.h"

using namespace gartic;

void Routing::Run(DataBaseStorage& storage)
{
	CROW_ROUTE(m_app, "/")([]() {
		return "This is an example app of crow and sql-orm";
		});

    CROW_ROUTE(m_app, "/login")([& storage, this](const crow::request& req){

        return VerifyUsersToDataBaseRoute(storage, req);
    });

	m_app.port(18080).multithreaded().run();
}

crow::response Routing::VerifyUsersToDataBaseRoute(DataBaseStorage& storage, const crow::request& req) const
{
    //validate user's login credentials 

    char* name_chr = req.url_params.get("name");
    char* password_chr = req.url_params.get("password");

    try {
        auto credentials = storage.FindUserForLogin(name_chr, password_chr);

        // If credentials is empty, throw an exception
        if (!credentials.has_value()) 
            throw std::runtime_error("User's credentials are incorrect");
       
    	return crow::response(200);

    }
    catch (const std::exception& e) 
    {
        // Handle the exception
        return crow::response(500);
    }
}

//// User Registration
    //CROW_ROUTE(app, "/register")
    //    .methods("POST"_method)
    //    ([&db](const crow::request& req) {
    //        auto x = crow::json::load(req.body);
    //        if (!x) {
    //            return crow::response(400);
    //        }

    //        std::string name = x["name"].s();
    //        std::string email = x["email"].s();
    //        std::string password = x["password"].s();

    //        std::string hashed_password = hash_password(password);

    //        Database::User user{0, name, email, hashed_password, "", "", 0, 0, 0};
    //        Database::AddUser(db, user);

    //        return crow::response(200);  // User registered
    //        });
