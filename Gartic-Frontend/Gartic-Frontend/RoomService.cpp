#include "RoomService.h"

RoomService::RoomService(QObject* parent)
{
}

void RoomService::CreateRoom(int roomId, int hostId)
{
    std::string url = "http://localhost:18080/createRoom" + std::to_string(roomId) + "/" + std::to_string(hostId);

    sendPostRequest(url, "");
}

void RoomService::GetRoom(int roomId)
{
    std::string url = "http://localhost:18080/room" + roomId;

    sendGetRequest(url, "");
}

void RoomService::UpdateRoom(int roomId, int userId)
{
    std::string url = "http://localhost:18080/joinRoom" + std::to_string(roomId) + "/" + std::to_string(userId);

    sendPutRequest(url, "");
}

void RoomService::DeleteRoom(int roomId)
{
    std::string url = "http://localhost:18080/deleteRoom" + roomId;

    sendDeleteRequest(url, "");
}

void RoomService::sendPostRequest(const std::string& url, const std::string& jsonPayload)
{
    cpr::Body body(jsonPayload);
    cpr::Header headers = { {"Content-Type", "application/json"} };
    cpr::Response response = cpr::Post(cpr::Url{ url }, body, headers);

    if (200 <= response.status_code && response.status_code < 300) 
    {        
        emit CreateRoomResponse(true, QString::fromUtf8(response.text.c_str()));
    }
    else
    {
        emit CreateRoomResponse(false, QString::fromUtf8(response.text.c_str()));
    }
}

void RoomService::sendPutRequest(const std::string& url, const std::string& jsonPayload)
{
    cpr::Body body(jsonPayload);
    cpr::Header headers = { {"Content-Type", "application/json"} };
    cpr::Response response = cpr::Put(cpr::Url{ url }, body, headers);

    if (200 <= response.status_code && response.status_code < 300) 
    {       
        emit UpdateRoomResponse(true, QString::fromUtf8(response.text.c_str()));
    }
    else
    {
        emit UpdateRoomResponse(false, QString::fromUtf8(response.text.c_str()));
    }
}

void RoomService::sendGetRequest(const std::string& url, const std::string& jsonPayload)
{
    cpr::Header headers = { {"Content-Type", "application/json"} };
    cpr::Response response = cpr::Get(cpr::Url{ url }, headers);

    if (200 <= response.status_code && response.status_code < 300) 
    {
        emit GetRoomResponse(true, QString::fromUtf8(response.text.c_str()));
    }
    else 
    {
        emit GetRoomResponse(false, QString::fromUtf8(response.text.c_str()));
    }
}

void RoomService::sendDeleteRequest(const std::string& url, const std::string& jsonPayload)
{
    cpr::Header headers = { {"Content-Type", "application/json"} };
    cpr::Response response = cpr::Delete(cpr::Url{ url }, headers);

    if (200 <= response.status_code && response.status_code < 300) 
    {
        emit DeleteRoomResponse(true, QString::fromUtf8(response.text.c_str()));
    }
    else
    {
        emit DeleteRoomResponse(false, QString::fromUtf8(response.text.c_str()));
    }
}
