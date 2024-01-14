#pragma once
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "AppWindow.h"
#include "RoomService.h"
#include "ui_RoomWindow.h"
#include "ScribbleWindow.h"
#include "MainMenuWindow.h"
class RoomWindow : public QMainWindow
{
	Q_OBJECT

public:
	static int WindowIndex;

	RoomWindow(QWidget* parent = nullptr);
	~RoomWindow();



private slots:
	void OnReturnToMainMenuButtonClicked();
	void OnStartGameButtonClicked();

	void HandleCreateRoomResponse(bool success, const QString& result);
	void HandleGetRoomResponse(const QJsonObject& jsonObject);
	void HandleUpdateRoomResponse(const QJsonObject& jsonObject);
	void HandleDeleteRoomResponse(const QJsonObject& jsonObject);

	void AddUserToRoomUI(int roomId, int userId);
	void ClearRoomInformation();

private:
	Ui::RoomWindow ui;
	RoomService* roomService;

	int currentRoomId;
	QJsonArray currentPlayerNames;

};

