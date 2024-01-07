#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_RegisterWindow.h"

#include "AppWindow.h"
#include "AuthenticationService.h"

class RegisterWindow : public QMainWindow
{
	Q_OBJECT

public:
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