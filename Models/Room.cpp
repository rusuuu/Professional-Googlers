#include "Room.h"

Room::Room()
{
	m_hostId = -1;
	m_maxPlayers = -1;
	m_drawTime = -1;
	m_roomCode = std::string();
}

void Room::SetId(int id)
{
	m_id = id;
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

int Room::GetId() const
{
	return m_id;
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