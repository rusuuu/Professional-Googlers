#pragma once

#include <string>

#include "Define.h"  

class MODELS_API Game
{
public:
    Game();
    Game(int gameId, int hostUserId, int maxPlayers, int drawTime, int wordCount, int numRounds, const std::string& gameName);

    void SetGameId(int gameId);
    void SetHostUserId(int hostUserId);
    void SetMaxPlayers(int maxPlayers);
    void SetDrawTime(int drawTime);
    void SetWordCount(int wordCount);
    void SetNumRounds(int numRounds);

    int GetGameId() const;
    int GetHostUserId() const;
    int GetMaxPlayers() const;
    int GetDrawTime() const;
    int GetWordCount() const;
    int GetNumRounds() const;

private:
    int m_gameId;
    int m_hostUserId;
    int m_maxPlayers;
    int m_drawTime;
    int m_wordCount;
    int m_numRounds;
    std::string m_gameName;
};
