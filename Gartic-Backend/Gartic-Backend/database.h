#pragma once

#include <string>
#include <vector>

#include <crow.h> 
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

#include "user.cppm"
#include "room.cppm"
#include "game.cppm"
#include "drawing.cppm"
#include "guess.cppm"

namespace gartic
{
    inline auto CreateStorage(const std::string& fileName)
    {
        return sql::make_storage(
            fileName,

            sql::make_table(
                "Users",
                sql::make_column("Id", &User::SetId, &User::GetId, sql::primary_key().autoincrement()),
                sql::make_column("Name", &User::SetName, &User::GetName),
                sql::make_column("Email", &User::SetEmail, &User::GetEmail),
                sql::make_column("Password", &User::SetPassword, &User::GetPassword),
                sql::make_column("Picture", &User::SetPicture, &User::GetPicture),
                sql::make_column("Role", &User::SetRole, &User::GetRole),
                sql::make_column("Games played", &User::SetGamesPlayed, &User::GetGamesPlayed),
                sql::make_column("Games won", &User::SetGamesWon, &User::GetGamesWon),
                sql::make_column("Correct guesses", &User::SetCorrectGuesses, &User::GetCorrectGuesses)
            ),

            sql::make_table(
                "Rooms",
                sql::make_column("Id", &Room::SetId, &Room::GetId, sql::primary_key().autoincrement()),
                sql::make_column("Code", &Room::SetCode, &Room::GetCode)
            ),

            sql::make_table(
                "Games",
                sql::make_column("Id", &Game::SetId, &Game::GetId, sql::primary_key().autoincrement()),
                sql::make_column("RoomId", &Game::SetRoomID, &Game::GetRoomID)
            ),

            sql::make_table(
                "Drawings",
                sql::make_column("Id", &Drawing::SetId, &Drawing::GetId, sql::primary_key().autoincrement()),
                sql::make_column("GameId", &Drawing::SetGameId, &Drawing::GetGameId),
                sql::make_column("Data", &Drawing::SetData, &Drawing::GetData)
            ),

            sql::make_table(
                "Guesses",
                sql::make_column("Id", &Guess::SetId, &Guess::GetId, sql::primary_key().autoincrement()),
                sql::make_column("GameId", &Guess::SetGameId, &Guess::GetGameId),
                sql::make_column("GuessText", &Guess::SetGuessText, &Guess::GetGuessText),
                sql::make_column("IsCorrect", &Guess::SetIsCorrect, &Guess::GetIsCorrect)
            )
        );

    }

    using Storage = decltype(CreateStorage(""));

    class DataBaseStorage
    {
    public:

        bool Initialize();

        std::vector<User> GetUsers();
        std::optional<User> FindUserById(int userId);
        std::optional<User> FindUserForLogin(const std::string& name, const std::string& password);
        void AddUser(const User& user);
        void UpdateUser(User& user);
        void DeleteUser(int userId);

        std::vector<Room> GetRooms();
        std::optional<Room> FindRoomById(int roomId);
        void AddRoom(const Room& room);

        std::vector<Game> GetGames();
        void AddGame(const Game& game);

        std::vector<Drawing> GetDrawings();
        void AddDrawing(const Drawing& drawing);

        std::vector<Guess> GetGuesses();
        void AddGuess(const Guess& guess);

    private:
        void PopulateStorageWithUsers();

    private:
        const std::string kDbFile{ "products.sqlite" };

    private:
        Storage m_db = CreateStorage(kDbFile);

    };

    class AddToDataBaseHandler
    {
    public:
        AddToDataBaseHandler(DataBaseStorage& storage);

        crow::response operator() (const crow::request& req) const;

    private:
        DataBaseStorage& m_db;
    };
};

