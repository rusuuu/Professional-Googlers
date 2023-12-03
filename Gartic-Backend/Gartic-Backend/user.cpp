#include "user.cppm"

namespace gartic
{
    User::User() : m_role(Role::NoRole) {}

    User::User(const std::string& userName, Role userRole) : m_name(userName), m_role(userRole) {}

    User::User(const User& other) = default;

    User::User(User&& other) noexcept = default;

    User& User::operator=(User other)
    {
        swap(*this, other);
        return *this;
    }

    User::~User() = default;

    void swap(User& first, User& second) noexcept
    {
        using std::swap;
        swap(first.m_name, second.m_name);
        swap(first.m_role, second.m_role);
    }

    const std::string& User::GetName() const
    {
        return m_name;
    }

    User::Role User::GetRole() const
    {
        return m_role;
    }

    std::ostream& operator<<(std::ostream& os, const User& user)
    {
        os << "User: " << user.m_name << ", Role: " << static_cast<int>(user.m_role);
        return os;
    }
}
