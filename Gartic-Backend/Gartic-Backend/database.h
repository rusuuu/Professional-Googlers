#pragma once

#include <string>
#include <vector>

#include <crow.h> 
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

import user;
import room;
import game;
import drawing;
import guess;

namespace gartic
{
    inline auto CreateStorage(const std::string& fileName)
    {
        return sql::make_storage(
            fileName,

            sql::make_table("Users",
                sql::make_column("Id", &User::SetId, &User::GetId, sql::primary_key().autoincrement()),
                sql::make_column("Name", &User::SetName, &User::GetName),
                sql::make_column("Email", &User::SetEmail, &User::GetEmail),
                sql::make_column("Password", &User::SetPassword, &User::GetPassword),
                sql::make_column("Picture", &User::SetPicture, &User::GetPicture),
                sql::make_column("Role", &User::SetRole, &User::GetRole),
                sql::make_column("Games played", &User::SetGamesPlayed, &User::GetGamesPlayed),
                sql::make_column("Games won", &User::SetGamesWon, &User::GetGamesWon),
                sql::make_column("Correct guesses", &User::SetCorrectGuesses, &User::GetCorrectGuesses)),

            sql::make_table("Rooms",
                sql::make_column("Id", &Room::SetId, &Room::GetId, sql::primary_key().autoincrement()),
                sql::make_column("Code", &Room::SetCode, &Room::GetCode)),

            sql::make_table("Games",
                sql::make_column("Id", &Game::SetId, &Game::GetId, sql::primary_key().autoincrement()),
                sql::make_column("RoomId", &Game::SetRoomID, &Game::GetRoomID)),

            sql::make_table("Drawings",
                sql::make_column("Id", &Drawing::SetId, &Drawing::GetId, sql::primary_key().autoincrement()),
                sql::make_column("GameId", &Drawing::SetGameId, &Drawing::GetGameId),
                sql::make_column("Data", &Drawing::SetData, &Drawing::GetData)),

            sql::make_table("Guesses",
                sql::make_column("Id", &Guess::SetId, &Guess::GetId, sql::primary_key().autoincrement()),
                sql::make_column("GameId", &Guess::SetGameId, &Guess::GetGameId),
                sql::make_column("GuessText", &Guess::SetGuessText, &Guess::GetGuessText),
                sql::make_column("IsCorrect", &Guess::SetIsCorrect, &Guess::GetIsCorrect))
        );

    }

    using Storage = decltype(sql::make_storage(""));

    class DataBaseStorage
    {
    public:
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

    private:
        const std::string kDbFile{ "gartic.sqlite" };

    private:
        Storage m_db = CreateStorage(kDbFile);
    };

    class AddToDataBaseHandler
    {

    private:
        DataBaseStorage& m_db;
    };
};

