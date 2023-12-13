#include "round.cppm"

#include <utility>

namespace gartic
{
    // Constructors
    Round::Round() {}

    Round::Round(const Game& game, int gameId, const std::vector<User>& players, const std::string& currentWord)
        : m_game(&game), m_gameId(gameId), m_players(players), m_currentWord(currentWord) {}

    // Rule of Five
    Round::Round(const Round& other)
        : m_game(other.m_game), m_gameId(other.m_gameId), m_players(other.m_players), m_currentWord(other.m_currentWord) {}

    Round::Round(Round&& other) noexcept
        : Round()
    {
        swap(*this, other);
    }

    Round& Round::operator=(Round other)
    {
        swap(*this, other);
        return *this;
    }

    Round::~Round() {}

    // Member functions
    void swap(Round& first, Round& second) noexcept
    {
        using std::swap;
        swap(first.m_game, second.m_game);
        swap(first.m_gameId, second.m_gameId);
        swap(first.m_players, second.m_players);
        swap(first.m_currentWord, second.m_currentWord);
    }

    std::ostream& operator<<(std::ostream& os, const Round& round)
    {
        os << "Round for Game ID: " << round.m_gameId << ", Current Word: " << round.m_currentWord;
        return os;
    }

    // Getters
    const Game& Round::GetGame() const
    {
        return *m_game;
    }

    const int Round::GetGameId() const
    {
        return m_gameId;
    }

    const std::vector<User>& Round::GetPlayers() const
    {
        return m_players;
    }

    const std::string& Round::GetCurrentWord() const
    {
        return m_currentWord;
    }

    // Setters
    void Round::SetCurrentWord(const std::string& currentWord)
    {
        m_currentWord = currentWord;
    }

    void Round::SetGame(const Game& game, int gameId)
    {
        m_game = &game;
        m_gameId = gameId;
    }

    void Round::SetPlayers(const std::vector<User>& players)
    {
        m_players = players;
    }
}
