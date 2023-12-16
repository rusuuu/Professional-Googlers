#include "database.h"

bool gartic::DataBaseStorage::Initialize()
{
    m_db.sync_schema();

    auto initUserCount = m_db.count<User>();

    if (initUserCount == 0)
        PopulateStorageWithUsers();
}

std::vector<gartic::User> gartic::DataBaseStorage::GetUsers()
{
	return m_db.get_all<User>();
}

std::optional<gartic::User> gartic::DataBaseStorage::FindUserById(int userId)
{
    return m_db.get_optional<User>(userId);
}

void gartic::DataBaseStorage::AddUser(const User& user)
{
	User newUser;
    newUser.SetName(user.GetName());
    newUser.SetEmail(user.GetEmail());
    newUser.SetPassword(user.GetPassword());
    newUser.SetPicture(user.GetPicture());
    newUser.SetRole(user.GetRole());
    newUser.SetGamesPlayed(user.GetGamesPlayed());
    newUser.SetGamesWon(user.GetGamesWon());
    newUser.SetCorrectGuesses(user.GetCorrectGuesses());

    m_db.insert(newUser);
}

void gartic::DataBaseStorage::UpdateUser(User& user)
{
    User newUser;
    newUser.SetName(user.GetName());
    newUser.SetEmail(user.GetEmail());
    newUser.SetPassword(user.GetPassword());
    newUser.SetPicture(user.GetPicture());
    newUser.SetRole(user.GetRole());
    newUser.SetGamesPlayed(user.GetGamesPlayed());
    newUser.SetGamesWon(user.GetGamesWon());
    newUser.SetCorrectGuesses(user.GetCorrectGuesses());

    user = newUser;
}

void gartic::DataBaseStorage::DeleteUser(int userId)
{
	m_db.remove<User>(userId);
}

std::vector<gartic::Room> gartic::DataBaseStorage::GetRooms()
{
    return m_db.get_all<Room>();
}

std::optional<gartic::Room> gartic::DataBaseStorage::FindRoomById(int roomId)
{
    return m_db.get_optional<Room>(roomId);
}

void gartic::DataBaseStorage::AddRoom(const Room& room)
{
    Room newRoom;
    newRoom.SetCode(room.GetCode());
}

std::vector<gartic::Game> gartic::DataBaseStorage::GetGames()
{
    return m_db.get_all<Game>();
}

void gartic::DataBaseStorage::AddGame(const Game& game)
{
    Game newGame;
    newGame.SetRoomID(game.GetRoomID());
    newGame.SetMaxPlayers(game.GetMaxPlayers());
    newGame.SetDrawTime(game.GetDrawTime());
    newGame.SetRounds(game.GetRounds());
    newGame.SetWordCount(game.GetWordCount());
    newGame.SetRoomCode(game.GetRoomCode());
}

std::vector<gartic::Drawing> gartic::DataBaseStorage::GetDrawings()
{
    return m_db.get_all<Drawing>();
}

void gartic::DataBaseStorage::AddDrawing(const Drawing& drawing)
{
    Drawing newDrawing;
    newDrawing.SetGameId(drawing.GetGameId());
    newDrawing.SetData(drawing.GetData());
}

std::vector<gartic::Guess> gartic::DataBaseStorage::GetGuesses()
{
    return m_db.get_all<Guess>();
}

void gartic::DataBaseStorage::AddGuess(const Guess& guess)
{
    Guess newGuess;
    newGuess.SetGameId(guess.GetGameId());
    newGuess.SetGuessText(guess.GetGuessText());
    newGuess.SetIsCorrect(guess.GetIsCorrect());
}

void gartic::DataBaseStorage::PopulateStorageWithUsers()
{
    std::vector<User> users{
        User{-1, "Claudiu", "claudiu.rusu@student.unitbv.ro", "@RuSu_2003"},
        User{-1, "Iulia", "iulia.tipleiu@student.unitbv.ro", "@IuLiA_2003"},
        User{-1, "Alex", "alexandru.decean@student.unitbv.ro", "@AlEx_2003"}
    };
    m_db.insert_range(users.begin(), users.end());
}
