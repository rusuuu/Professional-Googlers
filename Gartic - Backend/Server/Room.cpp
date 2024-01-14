#include "Room.h"

Room::Room(int id, std::string hostName) : m_roomId(id), m_hostName(hostName), m_state(State::Waiting) {}

Room::~Room() 
{
   
}

bool Room::IsEmpty() const 
{
    return m_users.empty();
}

void Room::StartGame()
{
    std::lock_guard<std::mutex> lock(mutex);
    if (m_state == State::Waiting)
    {
        m_state = State::InProgress;
    }
}

std::vector<std::string> Room::GetUserNames() const
{
    return m_users;
}

void Room::AddUserName(const std::string& userName)
{
    m_users.push_back(userName);
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

bool Room::IsHost(std::string hostName) const
{
    return hostName == m_hostName;
}

int Room::GetId() const
{
    return m_roomId;
}

size_t Room::GetUserCount() const 
{
    return m_users.size();
}