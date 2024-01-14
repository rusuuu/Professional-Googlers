#pragma once
#include <set>
#include <mutex>
#include <string>
#include <vector>

enum class State { Waiting, InProgress, Finished };
class Room
{
public:
    Room(int id, std::string hostName);
    ~Room();

    int GetId() const;
    size_t GetUserCount() const;
    State GetState() const;

    void SetState(State state);

    bool IsEmpty() const;
    bool IsHost(std::string userName) const;

    void StartGame();
    std::vector<std::string> GetUserNames() const;
    void AddUserName(const std::string& userName);

private:
    int m_roomId;
    std::string m_hostName;
    State m_state;
    std::vector<std::string> m_users;
    std::mutex mutex;
};