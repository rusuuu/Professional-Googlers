#pragma once
#include <QJsonDocument>
#include <QJsonObject>

#include "ui_ProfileUserWindow.h"
#include "UserStatsService.h"
#include "MainMenuWindow.h"
#include "LoginWindow.h"
#include "AppWindow.h"

class ProfileUserWindow : public QMainWindow
{
	Q_OBJECT

public:
	static int WindowIndex;
	static void SetUserName(QString&& name);

	ProfileUserWindow(QWidget *parent = nullptr);
	~ProfileUserWindow();

public slots:
	void GetUserStats(const QString& name);

private slots:
	//void OnUploadButtonClicked();
	void OnReturnToMainMenuButtonClicked();
	void OnGetUserStatsResponseReceived(bool success, const QString& result);

private:
	static QString UserName;

	Ui::ProfileUserWindowClass ui;
	UserStatsService* userStatsService;
};
