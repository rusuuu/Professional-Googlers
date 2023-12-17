#include "UserHandler.h"

UserHandler::UserHandler(Database::Storage& db) : m_db(db)
{

}

crow::response UserHandler::CreateUser(const crow::request& req)
{
	try
	{
		auto userJson = crow::json::load(req.body);
		if (!userJson)
		{
			return crow::response(400);
		}

		User newUser;

		newUser.SetName(userJson["name"].s());
		newUser.SetPassword(userJson["password"].s());
		newUser.SetEmail(userJson["email"].s());
		newUser.SetImagePath(userJson["image_path"].s());
		newUser.SetRole(userJson["role"].b());

		auto users = m_db.get_all<User>();
		CheckNames(newUser.GetName(), ExtractNames(users));
		CheckEmails(newUser.GetEmail(), ExtractEmails(users));

		m_db.insert(newUser);
		return crow::response(201);
	}
	catch (const std::invalid_argument& e)
	{
		return crow::response(400, e.what());
	}
	catch (const std::exception& e)
	{
		return crow::response(500, e.what());
	}
}

crow::response UserHandler::GetUsers()
{
	try 
	{
		auto users = m_db.get_all<User>();
		crow::json::wvalue jsonResponse;
		std::vector<crow::json::wvalue> jsonUsers;

		for (const auto& user : users) {
			crow::json::wvalue jsonUser;

			jsonUser["id"] = user.GetId();
			jsonUser["name"] = user.GetName();
			jsonUser["password"] = user.GetPassword();
			jsonUser["email"] = user.GetEmail();
			jsonUser["image_path"] = user.GetImagePath();
			jsonUser["role"] = user.GetRole();

			jsonUsers.emplace_back(jsonUser);
		}

		jsonResponse = std::move(jsonUsers);
		return crow::response(200, jsonResponse);
	}
	catch (const std::exception& e) 
	{
		return crow::response(500, e.what());
	}
}
