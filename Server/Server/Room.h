#pragma once
#include <set>
#include <mutex>

enum class State { Waiting, InProgress, Finished };
class Room 
{
public:
    Room(int id, int hostId);
    ~Room();

    void AddUser(int userId);
    int GetId() const;
    size_t GetUserCount() const;
    void RemoveUser(int userId);
    bool IsEmpty() const;   
    void StartGame(int userId);
    State GetState() const;
    void SetState(State state);
    bool IsHost(int userId) const;

private:
    int m_roomId;
    int m_hostId;
    State m_state;
    std::set<int> m_users;
    mutable std::mutex mutex; 
};
