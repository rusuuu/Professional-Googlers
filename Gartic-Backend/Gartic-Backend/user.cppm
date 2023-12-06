export module user;

#include <string>
#include <iostream>
#include <utility>

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

        struct Statistics
        {
            int gamesPlayed = 0;
            int gamesWon = 0;
            int correctGuesses = 0;
        };

        // Constructors
        User();
        User(std::string userName, std::string userEmail, std::string userPassword, std::string userPicture, Role userRole = Role::NoRole);

        // Rule of Five
        User(const User& other);
        User(User&& other) noexcept;
        User& operator=(User other);

        ~User();

        // Member functions
        friend void swap(User& first, User& second) noexcept;
        friend std::ostream& operator<< (std::ostream& os, const User& user);

        const std::string& GetName() const;
        const std::string& GetEmail() const;
        const std::string& GetPassword() const; // Consider hashing passwords for security
        const std::string& GetPicture() const;
        Role GetRole() const;
        Statistics GetStatistics() const;

        void SetRole(Role newRole);
        void UpdateStatistics(const Statistics& stats);

    private:
        std::string m_name;
        std::string m_email;
        std::string m_password; // Store hashed password
        std::string m_picture;
        Role m_role;
        Statistics m_statistics;
    };
}
