#include "Game.h"


Game::Game()
{
    m_gameId = 0;
    m_hostUserId = 0;
    m_maxPlayers = 0;
    m_drawTime = 0;
    m_wordCount = 0;
    m_numRounds = 0;
}

Game::Game(int gameId, int hostUserId, int maxPlayers, int drawTime, int wordCount, int numRounds, const std::string& gameName)
{
    m_gameId = gameId;
    m_hostUserId = hostUserId;
    m_maxPlayers = maxPlayers;
    m_drawTime = drawTime;
    m_wordCount = wordCount;
    m_numRounds = numRounds; 
    m_gameName = gameName;
}

int Game::GetGameId() const
{
    return m_gameId;
}

int Game::GetHostUserId() const
{
    return m_hostUserId;
}

int Game::GetMaxPlayers() const
{
    return m_maxPlayers;
}

int Game::GetDrawTime() const
{
    return m_drawTime;
}

int Game::GetWordCount() const
{
    return m_wordCount;
}

int Game::GetNumRounds() const
{
    return m_numRounds;
}

void Game::SetGameId(int gameId)
{
    m_gameId = gameId;
}

void Game::SetHostUserId(int hostUserId)
{
    m_hostUserId = hostUserId;
}

void Game::SetMaxPlayers(int maxPlayers)
{
    m_maxPlayers = maxPlayers;
}

void Game::SetDrawTime(int drawTime)
{
    m_drawTime = drawTime;
}

void Game::SetWordCount(int wordCount)
{
    m_wordCount = wordCount;
}

void Game::SetNumRounds(int numRounds)
{
    m_numRounds = numRounds;
}

