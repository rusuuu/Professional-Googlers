#include "pch.h"
#include "Room.h"

Room::Room()
{
	m_hostId = -1;
	m_maxPlayers = -1;
	m_drawTime = -1;
	m_roomCode = std::string();
	m_players = std::vector<std::string>();
}

void Room::SetHostId(int hostId)
{
	m_hostId = hostId;
}

void Room::SetMaxPlayers(int maxPlayers)
{
	m_maxPlayers = maxPlayers;
}

void Room::SetDrawTime(int drawTime)
{
	m_drawTime = drawTime;
}

void Room::SetRoomCode(const std::string& roomCode)
{
	m_roomCode = roomCode;
}

void Room::AddPlayer(const std::string& player)
{
	m_players.push_back(player);
}

void Room::RemovePlayer(const std::string& player)
{
	for (int i = 0; i < m_players.size(); i++)
	{
		if (m_players[i] == player)
		{
			m_players.erase(m_players.begin() + i);
			break;
		}
	}
}

int Room::GetHostId() const
{
	return m_hostId;
}

int Room::GetMaxPlayers() const
{
	return m_maxPlayers;
}

int Room::GetDrawTime() const
{
	return m_drawTime;
}

std::string Room::GetRoomCode() const
{
	return m_roomCode;
}

std::vector<std::string> Room::GetPlayers() const
{
	return m_players;
}