#include "GameHandler.h"

GameHandler::GameHandler(Database::Storage& db) : m_db(db)
{

}

//crow::response GameHandler::HostGame(const crow::request& req)
//{
//    try
//    {
//        auto gameJson = crow::json::load(req.body);
//        if (!gameJson)
//        {
//            return crow::response(400);
//        }
//
//        Game newGame;
//
//        newGame.SetHostUserId(gameJson["host_user_id"].i());
//        newGame.SetMaxPlayers(gameJson["max_players"].i());
//        newGame.SetDrawTime(gameJson["draw_time"].i());  
//        newGame.SetWordCount(gameJson["word_count"].i());  
//        newGame.SetNumRounds(gameJson["num_rounds"].i());  
//
//        m_db.insert(newGame);
//        return crow::response(201, "Game hosted successfully");
//    }
//    catch (const std::exception& e)
//    {
//        return crow::response(500, e.what());
//    }
//}

//crow::response GameHandler::GetGames()
//{
//    try
//    {
//        auto games = m_db.get_all<Game>();
//        crow::json::wvalue jsonResponse;
//        std::vector<crow::json::wvalue> jsonGames;
//
//        for (const auto& game : games)
//        {
//            crow::json::wvalue jsonGame;
//
//            jsonGame["game_id"] = game.GetGameId();
//            jsonGame["host_user_id"] = game.GetHostUserId();
//            jsonGame["max_players"] = game.GetMaxPlayers();
//            jsonGame["draw_time"] = game.GetDrawTime();  
//            jsonGame["word_count"] = game.GetWordCount();  
//            jsonGame["num_rounds"] = game.GetNumRounds();  
//
//            jsonGames.emplace_back(jsonGame);
//        }
//
//        jsonResponse = std::move(jsonGames);
//        return crow::response(200, jsonResponse);
//    }
//    catch (const std::exception& e)
//    {
//        return crow::response(500, e.what());
//    }
//}

//crow::response GameHandler::GetGameById(const crow::request& req)
//{
//    try
//    {
//        int gameId = std::stoi(req.url_params.get("game_id"));
//        if (gameId <= 0)
//        {
//            return crow::response(400, "Invalid game ID");
//        }
//
//        auto games = m_db.get_all<Game>();
//        for (const auto& game : games)
//        {
//            if (game.GetGameId() == gameId)
//            {
//                crow::json::wvalue jsonGame;
//                jsonGame["game_id"] = game.GetGameId();
//                jsonGame["host_user_id"] = game.GetHostUserId();
//                jsonGame["max_players"] = game.GetMaxPlayers();
//                jsonGame["draw_time"] = game.GetDrawTime();  
//                jsonGame["word_count"] = game.GetWordCount();  
//                jsonGame["num_rounds"] = game.GetNumRounds();  
//
//                return crow::response(200, jsonGame);
//            }
//        }
//
//        return crow::response(404, "Game not found");
//    }
//    catch (const std::exception& e)
//    {
//        return crow::response(500, e.what());
//    }
//}
