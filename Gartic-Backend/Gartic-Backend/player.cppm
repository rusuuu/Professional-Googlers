export module player;
import std;
using std::uint8_t;

namespace gartic
{
	export class Player
	{
	public:
		enum class Role : uint8_t
		{
			Drawer,
			Guesser,
			NoRole
		};
	public:
		Player();
		Player(const std::string& playerName, Role playerRole);

		// Rule of 5  
		Player(const Player& other);
		Player& operator= (const Player& rhs);

		~Player();

		// For copy-and-swap idiom:
		void swap(Player& other) noexcept;

		const std::string& GetName() const;
		Role GetRole() const;

	private:
		std::string m_name;
		Role m_role : 2;
	};

	export std::ostream& operator<< (std::ostream& os, const Player& player);

	// For copy-and-swap idiom:
	export void swap(Player& first, Player& second) noexcept;
	
}

