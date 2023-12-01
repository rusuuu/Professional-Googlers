module player;
import std;

using gartic::Player;

gartic::Player::Player() : m_name(""), m_role(Role::NoRole)
{
	
}

gartic::Player::Player(const std::string& playerName, Role playerRole) : 
	m_name(playerName), 
	m_role(playerRole)
{
	
}

gartic::Player::Player(const Player& other) : Player{ other.m_name, other.m_role }
{
	
}

Player& gartic::Player::operator=(const Player& rhs)
{
	// Copy-and-swap idiom:
	// Make a temporary copy
	Player temp{ rhs };
	swap(temp);
	return *this;
}

gartic::Player::~Player()
{
}

void gartic::Player::swap(Player& other) noexcept
{
	std::swap(m_name, other.m_name);

	//manual swap
	Role tempRole{ m_role };
	m_role = other.m_role;
	other.m_role = tempRole;
}

const std::string& gartic::Player::GetName() const
{
	return m_name;
}

Player::Role gartic::Player::GetRole() const
{
	return m_role;
}

std::ostream& operator<< (std::ostream& os, const Player& player)
{
	os << "Player: " << player.GetName() << ", Role: ";
	switch (player.GetRole())
	{
	case Player::Role::Drawer:
		os << "Drawer";
		break;
	case Player::Role::Guesser:
		os << "Guesser";
		break;
	default:
		os << "No Role";
		break;
	}
	return os;
}

void swap(Player& first, Player& second) noexcept
{
	first.swap(second);
}
