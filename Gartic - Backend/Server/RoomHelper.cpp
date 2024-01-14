#include "RoomHelper.h"

std::vector<std::string> ExtractPlayerNamesFromRoom(const std::vector<RoomPlayer>& roomPlayers)
{
	std::vector<std::string> players;

	for (auto player : roomPlayers)
	{
		players.push_back(player.GetUser());
	}

	return players;
}
