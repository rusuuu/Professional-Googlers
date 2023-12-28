#pragma once
#include <vector>
#include <string>

#include "define.h"
class MODELS_API Room
{
public:
	Room();

	void SetHostId(int hostId);
	void SetMaxPlayers(int maxPlayers);
	void SetDrawTime(int drawTime);
	void SetRoomCode(const std::string& roomCode);

	void AddPlayer(const std::string& player);
	void RemovePlayer(const std::string& player);

	int GetHostId() const;
	int GetMaxPlayers() const;
	int GetDrawTime() const;
	std::string GetRoomCode() const;
	std::vector<std::string> GetPlayers() const;
private:
	int m_hostId;
	int m_maxPlayers;
	int m_drawTime;
	std::string m_roomCode;
	std::vector<std::string> m_players;
};

