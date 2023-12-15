export module guess;

#include <string>
#include <iostream>
#include <utility>

export namespace gartic
{
    class Guess
    {
    public:

        // Constructors
        Guess();
        Guess(int id, int gameId, std::string guessText, bool isCorrect);

        // Rule of Five
        Guess(const Guess& other);
        Guess(Guess&& other) noexcept;
        Guess& operator=(Guess other);

        ~Guess();

        // Member functions
        friend void swap(Guess& first, Guess& second) noexcept;
        friend std::ostream& operator<< (std::ostream& os, const Guess& guess);

        const int GetId() const;
        const int GetGameId() const;
        const std::string& GetGuessText() const;
        const bool GetIsCorrect() const;


        void SetId(int id);
        void SetGameId(int gameId);
        void SetGuessText(std::string& guessText);
        void SetIsCorrect(bool isCorrect);

    private:
        int m_id;
        int m_gameId;
        std::string m_guessText;
        bool m_isCorrect;
    };
}
