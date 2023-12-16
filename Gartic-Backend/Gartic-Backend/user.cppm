#pragma once

export module user;

#include <string>
#include <iostream>

namespace gartic
{
    export class User
    {
    public:
       
        // Constructors
        User();
        User(int ID, std::string userName, std::string userEmail, std::string userPassword, std::string userPicture, std::string userRole = "", int gamesPlayed = 0, int gamesWon = 0, int correctGuesses = 0);

        // Rule of Five
        User(const User& other);
        User(User&& other) noexcept;
        User& operator=(User other);

        ~User();

        // Member functions
        friend void swap(User& first, User& second) noexcept;
        friend std::ostream& operator<< (std::ostream& os, const User& user);

        const int GetId() const;
        const std::string& GetName() const;
        const std::string& GetEmail() const;
        const std::string& GetPassword() const; 
        const std::string& GetPicture() const;
        const std::string GetRole() const;
        const int GetGamesPlayed() const;
        const int GetGamesWon() const;
        const int GetCorrectGuesses() const;
        
        bool CanDraw() const;
        bool CanGuess() const;

    	void SetId(int id);
    	void SetName(std::string& name);
    	void SetEmail(std::string& email);
    	void SetPassword(std::string& password);
    	void SetPicture(std::string& picture);
        void SetRole(std::string newRole);
        void SetGamesPlayed(int gamesPlayed);
        void SetGamesWon(int gamesWon);
        void SetCorrectGuesses(int correctGuesses);
       
    private:
        int m_id;
        std::string m_name;
        std::string m_email;
        std::string m_password; 
        std::string m_picture;
        std::string m_role;
        int m_gamesPlayed;
        int m_gamesWon;
        int m_correctGuesses;
        
    };
}
