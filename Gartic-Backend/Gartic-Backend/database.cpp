#include "database.h"

bool gartic::UserHandler::Initialize()
{
    m_db.sync_schema();

    auto initUserCount = m_db.count<User>();

    if (initUserCount == 0)
        PopulateStorageWithUsers();
}

std::vector<gartic::User> gartic::UserHandler::GetUsers()
{
	return m_db.get_all<User>();
}

std::optional<gartic::User> gartic::UserHandler::GetUserById(int userId)
{
    return m_db.get_optional<User>(userId);
}

std::optional<gartic::User> gartic::UserHandler::FindUserForLogin(const std::string& email, const std::string& password)
{
    return m_db.get_optional<User>(email, password);
}

void gartic::UserHandler::AddUser(const User& user)
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

void gartic::UserHandler::AddUserForRegister(const std::string& email, const std::string& password)
{
    User newUser;
    newUser.SetEmail(email);
    newUser.SetEmail(password);

    m_db.insert(newUser);
}

void gartic::UserHandler::UpdateUser(User& user)
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

void gartic::UserHandler::DeleteUser(int userId)
{
	m_db.remove<User>(userId);
}

std::vector<gartic::Room> gartic::UserHandler::GetRooms()
{
    return m_db.get_all<Room>();
}

std::optional<gartic::Room> gartic::UserHandler::FindRoomById(int roomId)
{
    return m_db.get_optional<Room>(roomId);
}

void gartic::UserHandler::AddRoom(const Room& room)
{
    Room newRoom;
    newRoom.SetCode(room.GetCode());
}

std::vector<gartic::Game> gartic::UserHandler::GetGames()
{
    return m_db.get_all<Game>();
}

void gartic::UserHandler::AddGame(const Game& game)
{
    Game newGame;
    newGame.SetRoomID(game.GetRoomID());
    newGame.SetMaxPlayers(game.GetMaxPlayers());
    newGame.SetDrawTime(game.GetDrawTime());
    newGame.SetRounds(game.GetRounds());
    newGame.SetWordCount(game.GetWordCount());
    newGame.SetRoomCode(game.GetRoomCode());
}

std::vector<gartic::Drawing> gartic::UserHandler::GetDrawings()
{
    return m_db.get_all<Drawing>();
}

void gartic::UserHandler::AddDrawing(const Drawing& drawing)
{
    Drawing newDrawing;
    newDrawing.SetGameId(drawing.GetGameId());
    newDrawing.SetData(drawing.GetData());
}

std::vector<gartic::Guess> gartic::UserHandler::GetGuesses()
{
    return m_db.get_all<Guess>();
}

void gartic::UserHandler::AddGuess(const Guess& guess)
{
    Guess newGuess;
    newGuess.SetGameId(guess.GetGameId());
    newGuess.SetGuessText(guess.GetGuessText());
    newGuess.SetIsCorrect(guess.GetIsCorrect());
}

void gartic::UserHandler::PopulateStorageWithUsers()
{
    std::vector<User> users{
        User{-1, "Claudiu", "claudiu.rusu@student.unitbv.ro", "@RuSu_2003"},
        User{-1, "Iulia", "iulia.tipeiu@student.unitbv.ro", "@IuLiA_2003"},
        User{-1, "Alex", "alexandru.decean@student.unitbv.ro", "@AlEx_2003"}
    };
    m_db.insert_range(users.begin(), users.end());
}
