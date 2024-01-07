#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_LoginWindow.h"

#include "AppWindow.h"
#include "AuthenticationService.h"

class LoginWindow : public QMainWindow
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = nullptr);
	~LoginWindow();


private slots:
	void OnLoginButtonClicked();
	void OnLoginResponseReceived(bool success, const QString& result);
	void OnCreateAccountButtonClicked();

private:
	Ui::LoginWindowClass ui;
	AuthenticationService* authenticationService;

	void ValidateCredentials();
	void ClearErrorMessage();


};
