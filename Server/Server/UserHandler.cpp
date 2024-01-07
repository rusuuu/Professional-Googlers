#include "UserHandler.h"

UserHandler::UserHandler(Database::Storage& db) : m_db(db)
{

}

crow::response UserHandler::LoginUser(const crow::request& req)
{
	try
	{
		auto credentialJson = crow::json::load(req.body);

		std::string userEmail = credentialJson["email"].s();
		std::string userPassword = credentialJson["password"].s();


		if (userEmail.empty())
		{
			return crow::response(400, "Email cannot be empty");
		}
		if (userPassword.empty())
		{
			return crow::response(400, "Password cannot be empty");
		}

		auto users = m_db.get_all<User>();
		for (const auto& user : users)
		{
			if (user.GetEmail() == userEmail)
			{
				if (user.GetPassword() == userPassword)
				{
					return crow::response(200, "Login successful");
				}
				else
				{
					return crow::response(401, "Invalid email or passoword");
				}
			}
		}

		return crow::response(401, "Invalid email or passoword");
	}
	catch (const std::exception& e)
	{
		return crow::response(500, e.what());
	}
}

crow::response UserHandler::RegisterUser(const crow::request& req)
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
		return crow::response(201, "User created successfully");
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

crow::response UserHandler::GetUserByName(const crow::request& req)
{
	try
	{
		std::string userName = req.url_params.get("name");
		if (userName.empty())
		{
			return crow::response(400, "Name parameter is missing");
		}

		auto users = m_db.get_all<User>();
		for (const auto& user : users)
		{
			if (user.GetName() == userName)
			{
				crow::json::wvalue jsonUser;
				jsonUser["id"] = user.GetId();
				jsonUser["name"] = user.GetName();
				jsonUser["password"] = user.GetPassword();
				jsonUser["email"] = user.GetEmail();
				jsonUser["image_path"] = user.GetImagePath();
				jsonUser["role"] = user.GetRole();

				return crow::response(200, jsonUser);
			}
		}

		return crow::response(404, "User not found");
	}
	catch (const std::exception& e)
	{
		return crow::response(500, e.what());
	}
}

crow::response UserHandler::UpdateUser(const crow::request& req)
{
	try
	{
		std::string userName = req.url_params.get("name");
		if (userName.empty())
		{
			return crow::response(400, "Name parameter is missing");
		}

		auto userJson = crow::json::load(req.body);
		if (!userJson)
		{
			return crow::response(400);
		}

		auto name = userJson["name"].s();
		auto password = userJson["password"].s();
		auto email = userJson["email"].s();
		auto imagePath = userJson["image_path"].s();
		auto role = userJson["role"].b();

		auto users = m_db.get_all<User>();
		for (auto& user : users)
		{
			if (user.GetName() == userName)
			{
				if (user.GetName() != name)
				{
					CheckNames(name, ExtractNames(users));

					user.SetName(name);
				}
				if (user.GetPassword() != password)
				{
					user.SetPassword(password);
				}
				if (user.GetEmail() != email)
				{
					CheckEmails(email, ExtractEmails(users));

					user.SetEmail(email);
				}
				if (user.GetImagePath() != imagePath)
				{
					user.SetImagePath(imagePath);
				}
				if (user.GetRole() != role)
				{
					user.SetRole(role);
				}

				m_db.update(user);
				return crow::response(200, "User updated successfully");
			}
		}

		return crow::response(404, "User not found");
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

crow::response UserHandler::DeleteUser(const crow::request& req)
{
	try
	{
		std::string userName = req.url_params.get("name");
		if (userName.empty())
		{
			return crow::response(400, "Name parameter is missing");
		}

		auto users = m_db.get_all<User>();
		for (auto& user : users)
		{
			if (user.GetName() == userName)
			{
				m_db.remove<User>(user.GetId());
				return crow::response(200, "User deleted successfully");
			}
		}

		return crow::response(404, "User not found");
	}
	catch (const std::exception& e)
	{
		return crow::response(500, e.what());
	}
}