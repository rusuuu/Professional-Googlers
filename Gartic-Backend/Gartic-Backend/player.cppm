import <iostream>;

export module piece;

namespace garticBackend
{
	export class Player
	{
	private:

		int m_playerID;
		std::string m_playerName, m_playerEmail, m_playerPassword;

	public:

		Player();

		void SetPlayerID(int playerID);
		int GetPlayerID();

		void SetPlayerName(std::string playerName);
		std::string GetPlayerName();

		void SetPlayerEmail(std::string playerEmail);
		std::string GetPlayerEmail();

		void SetPlayerPassword(std::string playerPassword);
		std::string GetPlayerPassword();
	};
}