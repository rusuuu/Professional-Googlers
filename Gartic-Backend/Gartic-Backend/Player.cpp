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


