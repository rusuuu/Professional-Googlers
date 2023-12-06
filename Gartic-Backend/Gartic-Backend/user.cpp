#include "user.cppm"

#include <utility>

namespace gartic 
{
    // Constructors
    User::User() : m_role(Role::NoRole) {}

    User::User(std::string userName, std::string userEmail, std::string userPassword, std::string userPicture, Role userRole)
        : m_name(std::move(userName)), m_email(std::move(userEmail)), m_password(std::move(userPassword)),
        m_picture(std::move(userPicture)), m_role(userRole) {}

    // Rule of Five
    User::User(const User& other)
        : m_name(other.m_name), m_email(other.m_email), m_password(other.m_password),
        m_picture(other.m_picture), m_role(other.m_role), m_statistics(other.m_statistics) {}

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
        swap(first.m_statistics, second.m_statistics);
    }

    std::ostream& operator<< (std::ostream& os, const User& user)
    {
        os << "User: " << user.m_name << ", Role: " << static_cast<int>(user.m_role);
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
    User::Role User::GetRole() const 
    {
        return m_role; 
    }
    User::Statistics User::GetStatistics() const 
    {
        return m_statistics; 
    }

    void User::SetRole(Role newRole)
    { 
        m_role = newRole;
    }
    void User::UpdateStatistics(const Statistics& stats) 
    { 
        m_statistics = stats; 
    }
}
