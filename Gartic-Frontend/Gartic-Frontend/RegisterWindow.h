#pragma once
#include <QtWidgets/QMainWindow>
#include <QRegularExpression>

#include "AppWindow.h"
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

private:
	Ui::RegisterWindowClass ui;
	AuthenticationService* authenticationService;

	void ValidateCredentials();
	void ClearErrorMessage();
};