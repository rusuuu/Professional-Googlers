module game;

#include "game.cppm"

#include <utility>

namespace gartic
{
	//Constructors
	Game::Game() {}

	Game::Game(int ID, int roomID, int maxPlayers, int drawTime, int rounds, int wordCount, std::string roomCode)
		:m_id(ID), m_roomID(roomID), m_maxPlayers(maxPlayers), m_drawTime(drawTime), m_rounds(rounds), m_wordCount(wordCount),
		m_roomCode(std::move(roomCode)) {}

	//Rule of five
	Game::Game(const Game& other)
		:m_id(other.m_id), m_roomID(other.m_roomID), m_maxPlayers(other.m_maxPlayers),
		m_drawTime(other.m_drawTime), m_rounds(other.m_rounds), m_wordCount(other.m_wordCount),
		m_roomCode(other.m_roomCode) {}

	Game::Game(Game&& other) noexcept
		:Game()
	{
		swap(*this, other);
	}

	Game& Game::operator=(Game other)
	{
		swap(*this, other);
		return *this;
	}

	Game::~Game() {}

	//Member functions

	void swap(Game& first, Game& second) noexcept
	{
		using std::swap;
		swap(first.m_id, second.m_id);
		swap(first.m_roomID, second.m_roomID);
		swap(first.m_maxPlayers, second.m_maxPlayers);
		swap(first.m_drawTime, second.m_drawTime);
		swap(first.m_rounds, second.m_rounds);
		swap(first.m_wordCount, second.m_wordCount);
		swap(first.m_roomCode, second.m_roomCode);
	}

	std::ostream& operator<<(std::ostream os, const Game& game)
	{
		os << "Game ID: " << game.m_id << ", Room ID: " << game.m_roomID
			<< ", Max Players: " << game.m_maxPlayers << ", Draw Time: " << game.m_drawTime
			<< ", Rounds: " << game.m_rounds << ", Word Count: " << game.m_wordCount
			<< ", Room Code: " << game.m_roomCode;

		return os;
	}

	//Getters

	const int Game::GetMaxPlayers() const
	{
		return m_maxPlayers;
	}

	const int Game::GetDrawTime() const
	{
		return m_drawTime;
	}

	const int Game::GetRounds() const
	{
		return m_rounds;
	}

	const int Game::GetWordCount() const
	{
		return m_wordCount;
	}

	const std::string& Game::GetRoomCode() const
	{
		return m_roomCode;
	}

	//Setters

	void Game::SetMaxPlayers(int maxPlayers)
	{
		m_maxPlayers = maxPlayers;
	}

	void Game::SetDrawTime(int drawTime)
	{
		m_drawTime = drawTime;
	}

	void Game::SetRounds(int rounds)
	{
		m_rounds = rounds;
	}

	void Game::SetWordCount(int wordCount)
	{
		m_wordCount = wordCount;
	}

	void Game::SetRoomCode(std::string roomCode)
	{
		m_roomCode = std::move(roomCode);
	}

	
}