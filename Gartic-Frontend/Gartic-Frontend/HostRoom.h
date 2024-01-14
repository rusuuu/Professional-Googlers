#pragma once
#include <QRandomGenerator>
#include <QMainWindow>
#include <QClipboard>

#include "AppWindow.h"
#include "RoomWindow.h"
#include "RoomService.h"
#include "ui_HostRoom.h"
#include "MainMenuWindow.h"

class HostRoom : public QMainWindow
{
	Q_OBJECT

public:
	static int WindowIndex;
	static void SetUserName(QString&& name);

	HostRoom(QWidget *parent = nullptr);
	~HostRoom();

private slots:
	void OnBackToMainMenuClicked();
	void OnCopyInviteCodeClicked();
	void OnStartButtonClicked();
	void OnGenerateCodeButtonClicked();
	void OnCreateRoomResponseReceived(bool success, const QString& result);

private:
	static QString UserName;

	Ui::HostRoomClass ui;
	QString GenerateRandomCode();

	RoomService* roomService;
};
