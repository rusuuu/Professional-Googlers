#include "UserStatsHandler.h"

UserStatsHandler::UserStatsHandler(Database::Storage& db) : m_db(db)
{
}

crow::response UserStatsHandler::CreateUserStats(const crow::request& req)
{
	try 
	{
        auto statsJson = crow::json::load(req.body);
        if (!statsJson) 
        {
            return crow::response(400, "Invalid JSON");
        }

        UserStats newStats;

        newStats.SetId(statsJson["id"].i());
        newStats.SetName(statsJson["name"].s());
        newStats.SetTotalGames(statsJson["totalGames"].i());
        newStats.SetGamesWon(statsJson["gamesWon"].i());
        newStats.SetGamesLost(statsJson["gamesLost"].i());
        newStats.SetTotalPoints(statsJson["totalPoints"].i());

        if (newStats.GetName().empty())
        {
            return crow::response(400, "Name cannot be empty");
        }

        auto usersStats = m_db.get_all<UserStats>();
                
        m_db.insert(newStats);
        return crow::response(201, "User stats created successfully");
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

crow::response UserStatsHandler::GetUserStats()
{
    try {
        auto stats = m_db.get_all<UserStats>(); 
        crow::json::wvalue jsonResponse;
        std::vector<crow::json::wvalue> jsonStats;

        for (const auto& stat : stats) 
        {
            crow::json::wvalue jsonStat;

            jsonStat["id"] = stat.GetId();
            jsonStat["name"] = stat.GetName();
            jsonStat["totalGames"] = stat.GetTotalGames();
            jsonStat["gamesWon"] = stat.GetGamesWon();
            jsonStat["gamesLost"] = stat.GetGamesLost();
            jsonStat["totalPoints"] = stat.GetTotalPoints();

            jsonStats.emplace_back(jsonStat);
        }

        jsonResponse = std::move(jsonStats);
        return crow::response(200, jsonResponse);
    }
    catch (const std::exception& e)
    {
        return crow::response(500, e.what());
    }
}

crow::response UserStatsHandler::GetUserStatsByName(const crow::request& req)
{
    try 
    {        
        std::string userName = req.url_params.get("name");
        if (userName.empty())
        {
            return crow::response(400, "Name parameter is missing");
        }

        auto stats = m_db.get_all<UserStats>();
        for (const auto& stat : stats)
        {
            if (stat.GetName() == userName)
            {
                crow::json::wvalue jsonStat;

                jsonStat["id"] = stat.GetId();
                jsonStat["name"] = stat.GetName();
                jsonStat["totalGames"] = stat.GetTotalGames();
                jsonStat["gamesWon"] = stat.GetGamesWon();
                jsonStat["gamesLost"] = stat.GetGamesLost();
                jsonStat["totalPoints"] = stat.GetTotalPoints();

                return crow::response(200, jsonStat);
            }
        }

        return crow::response(404, "User stats not found");
    }
    catch (const std::exception& e)
    {
        return crow::response(500, e.what());
    }
}

crow::response UserStatsHandler::UpdateUserStats(const crow::request& req)
{
    try
    {
        std::string userName = req.url_params.get("name");
        if (userName.empty()) 
        {
            return crow::response(400, "Name parameter is missing");
        }

        auto statsJson = crow::json::load(req.body);
        if (!statsJson)
        {
            return crow::response(400);
        }

        auto totalGames = statsJson["totalGames"].i();
        auto gamesWon = statsJson["gamesWon"].i();
        auto gamesLost = statsJson["gamesLost"].i();
        auto totalPoints = statsJson["totalPoints"].i();

        auto stats = m_db.get_all<UserStats>();
        for (auto& stat : stats)
        {
            if (stat.GetName() == userName)
            {                
                if (stat.GetTotalGames() != totalGames)
                {
                    stat.SetTotalGames(totalGames);
                }
                if (stat.GetGamesWon() != gamesWon) 
                {
                    stat.SetGamesWon(gamesWon);
                }
                if (stat.GetGamesLost() != gamesLost)
                {
                    stat.SetGamesLost(gamesLost);
                }
                if (stat.GetTotalPoints() != totalPoints) 
                {
                    stat.SetTotalPoints(totalPoints);
                }
                                
                m_db.update(stat);
                return crow::response(200, "User stats updated successfully");
            }
        }

        return crow::response(404, "User stats not found");
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

crow::response UserStatsHandler::DeleteUserStats(const crow::request& req)
{
    try 
    {
        std::string userName = req.url_params.get("name");
        if (userName.empty()) 
        {
            return crow::response(400, "Name parameter is missing");
        }

        auto stats = m_db.get_all<UserStats>();
        for (auto& stat : stats) 
        {
            if (stat.GetName() == userName) 
            {
                
                m_db.remove<UserStats>(stat.GetId());
                return crow::response(200, "User stats deleted successfully");
            }
        }

        return crow::response(404, "User stats not found");
    }
    catch (const std::exception& e)
    {
        return crow::response(500, e.what());
    }
}
