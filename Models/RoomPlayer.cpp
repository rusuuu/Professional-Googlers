#include "RoomPlayer.h"

RoomPlayer::RoomPlayer()
{
	m_id = -1;
	m_roomId = -1;
	m_userName = "";
}

void RoomPlayer::SetId(int id)
{
	m_id = id;
}

void RoomPlayer::SetRoomId(int roomId)
{
	m_roomId = roomId;
}

void RoomPlayer::SetUser(std::string userName)
{
	m_userName = userName;
}

int RoomPlayer::GetId() const
{
	return m_id;
}

int RoomPlayer::GetRoomId() const
{
	return m_roomId;
}

std::string RoomPlayer::GetUser() const
{
	return m_userName;
}