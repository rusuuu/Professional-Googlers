#include "RoomPlayersHandler.h"

RoomPlayersHandler::RoomPlayersHandler(Database::Storage& db) : m_db(db)
{

}

crow::response RoomPlayersHandler::AddPlayerToRoom(const crow::request& req)
{
	try 
	{
		auto roomJson = crow::json::load(req.body);

		int roomId = roomJson["room_id"].i();
		std::string username = roomJson["username"].s();

		RoomPlayer roomPlayer;
		roomPlayer.SetRoomId(roomId);
		roomPlayer.SetUser(username);

		m_db.insert(roomPlayer);
		return crow::response(200, "Player added to room successfully");
	}
	catch (std::exception& e)
	{
		return crow::response(500, e.what());
	}
}

crow::response RoomPlayersHandler::RemovePlayerFromRoom(const crow::request& req)
{
	try
	{
		auto roomJson = crow::json::load(req.body);

		int roomId = roomJson["room_id"].i();
		std::string username = roomJson["username"].s();

		m_db.remove<RoomPlayer>(sql::where(sql::and_(sql::is_equal(sql::c(&RoomPlayer::GetRoomId), roomId), sql::is_equal(sql::c(&RoomPlayer::GetUser), username))));
		return crow::response(200, "Player removed from room successfully");
	}
	catch (std::exception& e)
	{
		return crow::response(500, e.what());
	}
}

crow::response RoomPlayersHandler::GetPlayersInRoom(const crow::request& req)
{
	try
	{
		int roomId = std::stoi(req.url_params.get("id"));

		auto roomPlayers = m_db.get_all<RoomPlayer>(sql::where(sql::c(&RoomPlayer::GetRoomId) = roomId));
		auto players = ExtractPlayerNamesFromRoom(roomPlayers);

		crow::json::wvalue response;
		std::vector<crow::json::wvalue> playersJson;

		for (const auto& player : players)
		{
			crow::json::wvalue playerJson;
			playerJson["username"] = player;
			playersJson.push_back(playerJson);
		}

		response = std::move(playersJson);
		return crow::response(200, response);
	}
	catch (std::exception& e)
	{
		return crow::response(500, e.what());
	}
}

