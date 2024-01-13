#pragma once
#include <QtWidgets/QMainWindow>
#include <QRegularExpression>
#include <QJsonDocument>
#include <QJsonObject>

#include "AppWindow.h"
#include "UserStatsService.h"
#include "ui_RegisterWindow.h"
#include "AuthenticationService.h"

class RegisterWindow : public QMainWindow
{
	Q_OBJECT

public:
	static int WindowIndex;

	RegisterWindow(QWidget *parent = nullptr);
	~RegisterWindow();

private slots:
	void OnRegisterButtonClicked();
	void OnRegisterResponseReceived(bool success, const QString& result);
	void OnReturnToLoginButtonClicked();
	void OnCreateUserStatsResponseReceived(bool success, const QString& result);

private:
	Ui::RegisterWindowClass ui;
	AuthenticationService* authenticationService;
	UserStatsService* userStatsService;

	void ValidateCredentials();
	void ClearErrorMessage();
};