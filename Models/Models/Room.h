#pragma once
#include <vector>
#include <string>

#include "define.h"
class MODELS_API Room
{
public:
	Room();

	void SetId(int id);
	void SetHostId(int hostId);
	void SetMaxPlayers(int maxPlayers);
	void SetDrawTime(int drawTime);
	void SetRoomCode(const std::string& roomCode);

	int GetId() const;
	int GetHostId() const;
	int GetMaxPlayers() const;
	int GetDrawTime() const;
	std::string GetRoomCode() const;
private:
	int m_id;
	int m_hostId;
	int m_maxPlayers;
	int m_drawTime;
	std::string m_roomCode;
};

