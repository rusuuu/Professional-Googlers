export module database;


#include <sqlite_orm/sqlite_orm.h>
#include "user.cppm"
#include "game.cppm"
//#include "Drawing.h"
//#include "Guess.h"
//#include "Room.h"

namespace sql = sqlite_orm;

export namespace Database 
{

    using Storage = decltype(sql::make_storage(""));
        
    struct User 
    {
        int id;
        std::string name;
        std::string email;
        std::string password;
        std::string picture;
        std::string role;
        int gamesPlayed;
        int gamesWon;
        int correctGuesses;
        
    };

    struct Room 
    {
        int id;
        std::string code;
        // Add more fields as necessary
    };

    struct Game 
    {
        int id;
        int roomId;
        // Add more fields as necessary
    };

    struct Drawing 
    {
        int id;
        int gameId;
        std::string data;  // This could be a path to the image or binary data
    };

    struct Guess 
    {
        int id;
        int gameId;
        std::string guessText;
        bool isCorrect;
    };

    // Create the SQLite storage object
    inline auto CreateStorage(const std::string& fileName) 
    {
        return sql::make_storage(
            fileName,

            sql::make_table("Users",
                sql::make_column("Id", &User::id, sql::autoincrement(), sql::primary_key()),
                sql::make_column("Name", &User::name),
                sql::make_column("Email", &User::email),
                sql::make_column("Password", &User::password),
                sql::make_column("Picture", &User::picture),
                sql::make_column("Role", &User::role),
                sql::make_column("Games played", &User::gamesPlayed),
                sql::make_column("Games won", &User::gamesWon),
                sql::make_column("Correct guesses", &User::correctGuesses)),

            sql::make_table("Rooms",
                sql::make_column("Id", &Room::id, sql::autoincrement(), sql::primary_key()),
                sql::make_column("Code", &Room::code)),
            
            sql::make_table("Games",
                sql::make_column("Id", &Game::id, sql::autoincrement(), sql::primary_key()),
                sql::make_column("RoomId", &Game::roomId)),
            
            sql::make_table("Drawings",
                sql::make_column("Id", &Drawing::id, sql::autoincrement(), sql::primary_key()),
                sql::make_column("GameId", &Drawing::gameId),
                sql::make_column("Data", &Drawing::data)),
            
            sql::make_table("Guesses",
                sql::make_column("Id", &Guess::id, sql::autoincrement(), sql::primary_key()),
                sql::make_column("GameId", &Guess::gameId),
                sql::make_column("GuessText", &Guess::guessText),
                sql::make_column("IsCorrect", &Guess::isCorrect))
        );
    }

   
    void AddUser(Storage& storage, const User& user) 
    {
        storage.insert(user);
    }

    void AddRoom(Storage& storage, const Room& room)
    {
        storage.insert(room);
    }
    void AddGame(Storage& storage, const Game& game)
    {
        storage.insert(game);
    }
    void AddDrawing(Storage& storage, const Drawing& drawing)
    {
        storage.insert(drawing);
    }
    void AddGuess(Storage& storage, const Guess& guess)
    {
        storage.insert(guess);
    }
    void UpdateUser(Storage& storage, const User& user)
    {
        storage.update(user);
    }
    std::optional<User> FindUserById(Storage& storage, int userId)
    {
        return storage.get_optional<User>(userId);
    }
    std::optional<Room> FindRoomById(Storage& storage, int roomId)
    {
        return storage.get_optional<Room>(roomId);
    }
    std::vector<User> GetAllUsers(Storage& storage)
    {
        return storage.get_all<User>();
    }
    void DeleteUser(Storage& storage, int userId)
    {
        storage.remove<User>(userId);
    }

}
