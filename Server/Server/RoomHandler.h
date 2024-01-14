#pragma once
#include "Room.h"

#include <mutex>
#include <thread>
#include <unordered_map>

class RoomHandler
{
public:
    RoomHandler();
    ~RoomHandler();

    void CreateRoom(int roomId, int hostId);
    void DeleteRoom(int roomId);
    Room* GetRoom(int roomId);
    std::string GetRoomById(int roomId);
    std::string GetAllRooms();
    void HandleRoom(int roomId);

private:
    std::unordered_map<int, std::pair<std::unique_ptr<Room>, std::thread>> m_rooms;
    std::mutex roomsMutex;
};

