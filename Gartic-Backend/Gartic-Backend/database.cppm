export module database;

#include <sqlite_orm/sqlite_orm.h>

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

        static const User GetUserByEmail(Database::Storage& storage, const std::string& email)
        {
            auto users = storage.get_all<Database::User>(sql::where(sql::c(&Database::User::email) == email));

            if (!users.empty()) {
                return users.front();
            }

            return User{ 0, "", "", "", "", "", 0, 0, 0 };
        }
    };

    struct Room 
    {
        int id;
        std::string code;
        
    };

    struct Game 
    {
        int id;
        int roomId; 
        int maxPlayers; 
        int drawTime;
        int rounds;
        int wordCount; 
        std::string roomCode;
    };

    struct Drawing 
    {
        int id;
        int gameId;
        std::string data; 
    };

    struct Guess 
    {
        int id;
        int gameId;
        std::string guessText;
        bool isCorrect;
    };

    inline auto CreateStorage(const std::string& fileName) 
    {
        return sql::make_storage(
            fileName,

            sql::make_table("Users",
                sql::make_column("Id", &User::id, sql::primary_key().autoincrement(), sql::primary_key()),
                sql::make_column("Name", &User::name),
                sql::make_column("Email", &User::email),
                sql::make_column("Password", &User::password),
                sql::make_column("Picture", &User::picture),
                sql::make_column("Role", &User::role),
                sql::make_column("Games played", &User::gamesPlayed),
                sql::make_column("Games won", &User::gamesWon),
                sql::make_column("Correct guesses", &User::correctGuesses)),

            sql::make_table("Rooms",
                sql::make_column("Id", &Room::id, sql::primary_key().autoincrement(), sql::primary_key()),
                sql::make_column("Code", &Room::code)),
            
            sql::make_table("Games",
                sql::make_column("Id", &Game::id, sql::primary_key().autoincrement(), sql::primary_key()),
                sql::make_column("RoomId", &Game::roomId)),
            
            sql::make_table("Drawings",
                sql::make_column("Id", &Drawing::id, sql::primary_key().autoincrement(), sql::primary_key()),
                sql::make_column("GameId", &Drawing::gameId),
                sql::make_column("Data", &Drawing::data)),
            
            sql::make_table("Guesses",
                sql::make_column("Id", &Guess::id, sql::primary_key().autoincrement(), sql::primary_key()),
                sql::make_column("GameId", &Guess::gameId),
                sql::make_column("GuessText", &Guess::guessText),
                sql::make_column("IsCorrect", &Guess::isCorrect))
        );

    }

   
    void AddUser(Database::Storage& storage, const Database::User& user) 
    {
        storage.insert(user);
    }

    void AddRoom(Database::Storage& storage, const Database::Room& room)
    {
        storage.insert(room);
    }
    void AddGame(Database::Storage& storage, const Database::Game& game)
    {
        storage.insert(game);
    }
    void AddDrawing(Database::Storage& storage, const Database::Drawing& drawing)
    {
        storage.insert(drawing);
    }
    void AddGuess(Database::Storage& storage, const Database::Guess& guess)
    {
        storage.insert(guess);
    }
    void UpdateUser(Database::Storage& storage, const Database::User& user)
    {
        storage.update(user);
    }
    std::optional<User> FindUserById(Database::Storage& storage, int userId)
    {
        return storage.get_optional<User>(userId);
    }
    std::optional<Room> FindRoomById(Database::Storage& storage, int roomId)
    {
        return storage.get_optional<Room>(roomId);
    }
    std::vector<User> GetAllUsers(Database::Storage& storage)
    {
        return storage.get_all<User>();
    }
    void DeleteUser(Database::Storage& storage, int userId)
    {
        storage.remove<User>(userId);
    }

}
