#pragma once

#include <QtWidgets/QMainWindow>
#include <QPropertyAnimation>
#include "ui_LoginWindow.h"

#include "AppWindow.h"

class LoginWindow : public QMainWindow
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = nullptr);
	~LoginWindow();

	void OnRegisterButtonClicked();

signals:
	void openRegisterWindow();
	void LoginSuccessful();

private:
	Ui::LoginWindowClass ui;

	void ValidateCredentials();
	void ClearErrorMessage();
private slots:
	void OnLoginButtonClicked();
};
