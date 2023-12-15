export module round;

import user;

#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include "game.cppm"

namespace gartic
{
    class Round
    {
    public:
        // Constructors
        Round();
        Round(const Game& game, int gameId, const std::vector<User>& players, const std::string& currentWord);

        // Rule of Five
        Round(const Round& other);
        Round(Round&& other) noexcept;
        Round& operator=(Round other);
        ~Round();

        // Member functions
        friend void swap(Round& first, Round& second) noexcept;
        friend std::ostream& operator<<(std::ostream& os, const Round& round);

        // Getters
        const Game& GetGame() const;
        const int GetGameId() const;
        const std::vector<User>& GetPlayers() const;
        const std::string& GetCurrentWord() const;

        // Setters
        void SetCurrentWord(const std::string& currentWord);
        void SetGame(const Game& game, int gameId);
        void SetPlayers(const std::vector<User>& players);

    private:
        const Game* m_game;
        int m_gameId;
        std::vector<User> m_players;
        std::string m_currentWord;
    };
}
