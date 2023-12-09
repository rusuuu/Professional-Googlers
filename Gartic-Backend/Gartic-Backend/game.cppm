export module game;

#include <string>
#include <iostream>
#include <utility>

export namespace gartic
{
	class Game
	{
	public:
		//Constructors
		Game();
		Game(int ID, int roomID, int maxPlayers, int drawTime, int rounds, int wordCount, std::string roomCode);

		//Rule of Five
		Game(const Game& other);
		Game(Game&& other) noexcept;
		Game& operator=(Game other);
		~Game();

		//Member functions
		friend void swap(Game& first, Game& second) noexcept;
		friend std::ostream& operator<<(std::ostream os, const Game& game);

		const int GetMaxPlayers() const;
		const int GetDrawTime() const;
		const int GetRounds() const;
		const int GetWordCount() const;
		const std::string& GetRoomCode() const;

		void SetMaxPlayers(int maxPlayers);
		void SetDrawTime(int drawTime);
		void SetRounds(int rounds);
		void SetWordCount(int wordCount);
		void SetRoomCode(std::string roomCode);

	private:
		int m_id;
		int m_roomID;
		int m_maxPlayers;
		int m_drawTime;
		int m_rounds;
		int m_wordCount;
		std::string m_roomCode;
	};
	
}