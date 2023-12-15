#include "guess.cppm"

#include <utility>

namespace gartic
{
    // Constructors
    Guess::Guess() {}

    Guess::Guess(int id, int gameId, std::string guessText, bool isCorrect)
	    : m_id(id), m_gameId(gameId), m_guessText(std::move(guessText)), m_isCorrect(isCorrect){}

    // Rule of Five
    Guess::Guess(const Guess& other)
        : m_id(other.m_id), m_gameId(other.m_gameId), m_guessText(other.m_guessText), m_isCorrect(other.m_isCorrect){}

    Guess::Guess(Guess&& other) noexcept
        : Guess()
    {
        swap(*this, other);
    }

    Guess& Guess::operator=(Guess other)
    {
        swap(*this, other);
        return *this;
    }

    Guess::~Guess() {}

    // Member functions
    void swap(Guess& first, Guess& second) noexcept
    {
        using std::swap;
        swap(first.m_id, second.m_id);
        swap(first.m_gameId, second.m_gameId);
        swap(first.m_guessText, second.m_guessText);
        swap(first.m_isCorrect, second.m_isCorrect);
    }

    std::ostream& operator<< (std::ostream& os, const Guess& guess)
    {
        os << "Guess: " << guess.m_id << ", Game: " << guess.m_gameId << ", Guess text: " << guess.m_guessText;
        return os;
    }


    //Getters

    const int Guess::GetId() const
    {
        return m_id;
    }

    const int Guess::GetGameId() const
    {
        return m_gameId;
    }

    const std::string& Guess::GetGuessText() const
    {
        return m_guessText;
    }

    const bool Guess::GetIsCorrect() const
    {
        return m_isCorrect;
    }

    //Setters

    void Guess::SetId(int id)
    {
        m_id = id;
    }

    void Guess::SetGameId(int gameId)
    {
        m_gameId = gameId;
    }

    void Guess::SetGuessText(std::string& guessText)
    {
        m_guessText = guessText;
    }

    void Guess::SetIsCorrect(bool isCorrect)
    {
        m_isCorrect = isCorrect;
    }
}
