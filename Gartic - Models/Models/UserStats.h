#pragma once

#include <string>

#include "define.h"
class MODELS_API UserStats
{
public:
	UserStats();
	UserStats(const int id, const std::string name, const int totalGames, const int gamesWon, const int gamesLost, const int totalPoints);

	void SetId(int id);
	void SetName(const std::string& name);
	void SetTotalGames(const int& totalGames);
	void SetGamesWon(const int& gamesWon);
	void SetGamesLost(const int& gamesLost);
	void SetTotalPoints(const int& totalPoints);

	int GetId() const;
	std::string GetName() const;
	int GetTotalGames() const;
	int GetGamesWon() const;
	int GetGamesLost() const;
	int GetTotalPoints() const;

private:
	int m_id;
	std::string m_name;
	int m_totalGames;
	int m_gamesWon;
	int m_gamesLost;
	int m_totalPoints;

};

