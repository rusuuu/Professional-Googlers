#pragma once
#include <string>
#include <QObject>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

class RoomService: public QObject
{
	Q_OBJECT;

public:
	explicit RoomService(QObject* parent = nullptr);

	void CreateRoom(int roomId, int hostId);
	void GetRoom(int roomId);
	void UpdateRoom(int roomId, int userId);
	void DeleteRoom(int roomId);

signals:
	void CreateRoomResponse(bool success, const QString& result);
	void GetRoomResponse(bool success, const QString& result);
	void DeleteRoomResponse(bool success, const QString& result);
	void UpdateRoomResponse(bool success, const QString& result);

private:
	void sendPostRequest(const std::string& url, const std::string& jsonPayload);
	void sendPutRequest(const std::string& url, const std::string& jsonPayload);
	void sendGetRequest(const std::string& url, const std::string& jsonPayload);
	void sendDeleteRequest(const std::string& url, const std::string& jsonPayload);
};

