#include "RoomHandler.h"

RoomHandler::RoomHandler()
{
}

RoomHandler::~RoomHandler()
{
    for (auto& roomPair : m_rooms)
    {
        if (roomPair.second.second.joinable())
        {
            roomPair.second.second.join();
        }
    }
}

void RoomHandler::CreateRoom(int roomId, std::string hostName)
{
    std::lock_guard<std::mutex> lock(roomsMutex);
    if (m_rooms.find(roomId) == m_rooms.end())
    {
        std::unique_ptr<Room> newRoom = std::make_unique<Room>(roomId, hostName);
        newRoom->AddUserName(hostName);
        std::thread roomThread(&RoomHandler::HandleRoom, this, roomId);
        m_rooms[roomId] = std::make_pair(std::move(newRoom), std::move(roomThread));
    }
}

void RoomHandler::DeleteRoom(int roomId)
{
    std::lock_guard<std::mutex> lock(roomsMutex);
    auto it = m_rooms.find(roomId);
    if (it != m_rooms.end())
    {
        if (it->second.second.joinable())
        {
            it->second.second.join();
        }

        m_rooms.erase(it);
    }
}

Room* RoomHandler::GetRoom(int roomId)
{
    std::lock_guard<std::mutex> lock(roomsMutex);
    auto it = m_rooms.find(roomId);
    if (it != m_rooms.end())
    {
        return it->second.first.get();
    }
    return nullptr;
}

std::string RoomHandler::GetRoomById(int roomId)
{
    std::lock_guard<std::mutex> lock(roomsMutex);
    auto it = m_rooms.find(roomId);
    if (it != m_rooms.end())
    {
        Room* room = it->second.first.get();
        std::string roomDetails = "Room ID: " + std::to_string(roomId) + ", Users: ";

        const auto& userNames = room->GetUserNames(); 
        for (const auto& name : userNames)
        {
            roomDetails += name + ", ";
        }

        if (!userNames.empty())
        {
            roomDetails.pop_back(); 
            roomDetails.pop_back(); 
        }

        return roomDetails;
    }
    return "Room not found";
}

std::string RoomHandler::GetAllRooms()
{
    std::lock_guard<std::mutex> lock(roomsMutex);
    std::string roomList = "Rooms:\n";
    for (const auto& roomPair : m_rooms)
    {
        roomList += "Room ID: " + std::to_string(roomPair.first) + ", Users: " + std::to_string(roomPair.second.first->GetUserCount()) + "\n";
    }
    return roomList;
}

void RoomHandler::HandleRoom(int roomId)
{
    Room* room = m_rooms[roomId].first.get();

    while (room->GetState() != State::Finished)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    room->SetState(State::Finished);
}