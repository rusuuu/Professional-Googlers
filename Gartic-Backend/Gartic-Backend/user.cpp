#include "user.cppm"

#include <utility>

namespace gartic 
{
    // Constructors
    User::User() {}

    User::User(int ID, std::string userName, std::string userEmail, std::string userPassword, std::string userPicture, std::string userRole, int gamesPlayed, int gamesWon, int correctGuesses)
        : m_id(ID), m_name(std::move(userName)), m_email(std::move(userEmail)), m_password(std::move(userPassword)),
        m_picture(std::move(userPicture)), m_role(userRole), m_gamesPlayed(gamesPlayed), m_gamesWon(gamesWon), m_correctGuesses(correctGuesses){}

    // Rule of Five
    User::User(const User& other)
        : m_name(other.m_name), m_email(other.m_email), m_password(other.m_password),
        m_picture(other.m_picture), m_role(other.m_role), m_gamesPlayed(other.m_gamesPlayed), m_gamesWon(other.m_gamesPlayed), m_correctGuesses(other.m_correctGuesses){}

    User::User(User&& other) noexcept
        : User()
    {
        swap(*this, other);
    }

    User& User::operator=(User other)
    {
        swap(*this, other);
        return *this;
    }

    User::~User() {}

    // Member functions
    void swap(User& first, User& second) noexcept
    {
        using std::swap;
        swap(first.m_name, second.m_name);
        swap(first.m_email, second.m_email);
        swap(first.m_password, second.m_password);
        swap(first.m_picture, second.m_picture);
        swap(first.m_role, second.m_role);
        swap(first.m_gamesPlayed, second.m_gamesPlayed);
        swap(first.m_gamesWon, second.m_gamesWon);
        swap(first.m_correctGuesses, second.m_correctGuesses);
    }

    std::ostream& operator<< (std::ostream& os, const User& user)
    {
        os << "User: " << user.m_name << ", Role: " << user.m_role;
        return os;
    }

    const std::string& User::GetName() const 
    {
        return m_name; 
    }
    const std::string& User::GetEmail() const
    {
        return m_email; 
    }
    const std::string& User::GetPassword() const 
    {
        return m_password; 
    }
    const std::string& User::GetPicture() const 
    {
        return m_picture; 
    }
    const std::string User::GetRole() const
    {
        return m_role; 
    }
    const int User::GetGamesPlayed() const
    {
        return m_gamesPlayed;
    }

    const int User::GetGamesWon() const
    {
        return m_gamesWon;
    }

    const int User::GetCorrectGuesses() const
    {
        return m_correctGuesses;
    }
    

    void User::SetRole(std::string newRole)
    { 
        m_role = newRole;
    }

    void User::SetGamesPlayed(int gamesPlayed)
    {
        m_gamesPlayed = gamesPlayed;
    }

    void User::SetGamesWon(int gamesWon)
    {
        m_gamesWon = gamesWon;
    }

    void User::SetCorrectGuesses(int correctGuesses)
    {
        m_correctGuesses = correctGuesses;
    }
    

}
