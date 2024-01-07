#include "RoomHandler.h"

RoomHandler::RoomHandler(Database::Storage& db) : m_db(db)
{

}

crow::response RoomHandler::CreateRoom(const crow::request& req)
{
    try
    {
        auto roomJson = crow::json::load(req.body);
        if (!roomJson)
        {
            return crow::response(400);
        }

        Room newRoom;

        newRoom.SetHostId(roomJson["host_id"].i());
        newRoom.SetMaxPlayers(roomJson["max_players"].i());
        newRoom.SetDrawTime(roomJson["draw_time"].i());
        //newRoom.SetRoomCode(generateRoomCode()); 

        m_db.insert(newRoom);
        return crow::response(201, "Room created successfully");
    }
    catch (const std::exception& e)
    {
        return crow::response(500, e.what());
    }
}

crow::response RoomHandler::GetRooms()
{
    try
    {
        auto rooms = m_db.get_all<Room>();
        crow::json::wvalue jsonResponse;
        std::vector<crow::json::wvalue> jsonRooms;

        for (const auto& room : rooms)
        {
            crow::json::wvalue jsonRoom;

            jsonRoom["id"] = room.GetId();
            jsonRoom["host_id"] = room.GetHostId();
            jsonRoom["max_players"] = room.GetMaxPlayers();
            jsonRoom["draw_time"] = room.GetDrawTime();
            jsonRoom["room_code"] = room.GetRoomCode();

            jsonRooms.emplace_back(jsonRoom);
        }

        jsonResponse = std::move(jsonRooms);
        return crow::response(200, jsonResponse);
    }
    catch (const std::exception& e)
    {
        return crow::response(500, e.what());
    }
}

crow::response RoomHandler::GetRoomByCode(const crow::request& req)
{
    try
    {
        std::string roomCode = req.url_params.get("room_code");

        auto rooms = m_db.get_all<Room>(sql::where(sql::c(&Room::GetRoomCode) == roomCode));

        if (rooms.empty())
        {
            return crow::response(404, "Room not found");
        }

        const auto& room = rooms.front();

        crow::json::wvalue jsonRoom;

        jsonRoom["id"] = room.GetId();
        jsonRoom["host_id"] = room.GetHostId();
        jsonRoom["max_players"] = room.GetMaxPlayers();
        jsonRoom["draw_time"] = room.GetDrawTime();
        jsonRoom["room_code"] = room.GetRoomCode();

        return crow::response(200, jsonRoom);
    }
    catch (const std::exception& e)
    {
        return crow::response(500, e.what());
    }
}


crow::response RoomHandler::UpdateRoom(const crow::request& req)
{
    try
    {
        auto roomJson = crow::json::load(req.body);
        if (!roomJson)
        {
            return crow::response(400);
        }

        int roomId = std::stoi(req.url_params.get("id"));

        auto rooms = m_db.get_all<Room>(sql::where(sql::c(&Room::GetId) == roomId));

        if (rooms.empty())
        {
            return crow::response(404, "Room not found");
        }

        auto& room = rooms[0]; 

        room.SetHostId(roomJson["host_id"].i());
        room.SetMaxPlayers(roomJson["max_players"].i());
        room.SetDrawTime(roomJson["draw_time"].i());

        m_db.update(room);
        return crow::response(200, "Room updated successfully");
    }
    catch (const std::exception& e)
    {
        return crow::response(500, e.what());
    }
}

crow::response RoomHandler::DeleteRoom(const crow::request& req)
{
    try
    {
        int roomId = std::stoi(req.url_params.get("id"));

        auto rooms = m_db.get_all<Room>(sql::where(sql::c(&Room::GetId) == roomId));

        if (rooms.empty())
        {
            return crow::response(404, "Room not found");
        }

        auto& room = rooms[0]; // Accesează prima cameră (dacă există)

        m_db.remove<Room>(room.GetId());
        return crow::response(200, "Room deleted successfully");
    }
    catch (const std::exception& e)
    {
        return crow::response(500, e.what());
    }
}


