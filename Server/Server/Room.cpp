#include "Room.h"

Room::Room(int id, int hostId) : m_roomId(id), m_hostId(hostId), m_state(State::Waiting) {}

Room::~Room() 
{
   
}

void Room::AddUser(int userId)
{
    std::lock_guard<std::mutex> lock(mutex);
    m_users.insert(userId);
}

void Room::RemoveUser(int userId)
{
    std::lock_guard<std::mutex> lock(mutex);
    m_users.erase(userId);
}

bool Room::IsEmpty() const 
{
    std::lock_guard<std::mutex> lock(mutex);
    return m_users.empty();
}

void Room::StartGame(int userId)
{
    std::lock_guard<std::mutex> lock(mutex);
    if (userId == m_hostId && m_state == State::Waiting)
    {
        m_state = State::InProgress;
    }
}

State Room::GetState() const
{
    return m_state;
}

void Room::SetState(State state)
{
    std::lock_guard<std::mutex> lock(mutex);
    m_state = state;
}

bool Room::IsHost(int userId) const
{
    return userId == m_hostId;
}

int Room::GetId() const
{
    return m_roomId;
}

size_t Room::GetUserCount() const 
{
    std::lock_guard<std::mutex> lock(mutex);
    return m_users.size();
}