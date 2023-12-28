#pragma once

#include <string>

#include "define.h"
class MODELS_API RoomPlayer
{
public:
	RoomPlayer();

	void SetId(int id);
	void SetRoomId(int roomId);
	void SetUser(std::string userName);

	int GetId() const;
	int GetRoomId() const;
	std::string GetUser() const;

private:
	int m_id;
	int m_roomId;
	std::string m_userName;
};