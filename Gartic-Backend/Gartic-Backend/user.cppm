export module user;

#include <string>
#include <iostream>

export namespace gartic
{
    class User
    {
    public:
        enum class Role
        {
            Drawer,
            Guesser,
            NoRole
        };

        User();
        User(const std::string& userName, Role userRole);

        // Rule of Five
        User(const User& other);
        User(User&& other) noexcept;
        User& operator=(User other);

        ~User();

        // For copy-and-swap idiom:
        friend void swap(User& first, User& second) noexcept;

        const std::string& GetName() const;
        Role GetRole() const;

        friend std::ostream& operator<< (std::ostream& os, const User& user);

    private:
        std::string m_name;
        Role m_role;
    };
}