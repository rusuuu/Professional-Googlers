#include "UserStats.h"

UserStats::UserStats()
{
	m_id = -1;
	m_name = std::string();
	m_totalGames = -1;
	m_gamesWon = -1;
	m_gamesLost = -1;
	m_totalPoints = -1;
}

UserStats::UserStats(const int id, const std::string name, const int totalGames, const int gamesWon, const int gamesLost, const int totalPoints)
{
	m_id = id;
	m_name = name;
	m_totalGames = totalGames;
	m_gamesWon = gamesWon;
	m_gamesLost = gamesLost;
	m_totalPoints = totalPoints;
}

void UserStats::SetId(int id)
{
	m_id = id;
}

void UserStats::SetName(const std::string& name)
{
	m_name = name;
}

void UserStats::SetTotalGames(const int& totalGames)
{
	m_totalGames = totalGames;
}

void UserStats::SetGamesWon(const int& gamesWon)
{
	m_gamesWon = gamesWon;
}

void UserStats::SetGamesLost(const int& gamesLost)
{
	m_gamesLost = gamesLost;
}

void UserStats::SetTotalPoints(const int& totalPoints)
{
	m_totalPoints = totalPoints;
}

int UserStats::GetId() const
{
	return m_id;
}

std::string UserStats::GetName() const
{
	return m_name;
}

int UserStats::GetTotalGames() const
{
	return m_totalGames;
}

int UserStats::GetGamesWon() const
{
	return m_gamesWon;
}

int UserStats::GetGamesLost() const
{
	return m_gamesLost;
}

int UserStats::GetTotalPoints() const
{
	return m_totalPoints;
}
