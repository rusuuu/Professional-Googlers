#pragma once

#include <QtWidgets/QMainWindow>
#include <QPropertyAnimation>
#include "ui_LoginWindow.h"


class LoginWindow : public QMainWindow
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = nullptr);
	~LoginWindow();

	void OnRegisterButtonClicked();

signals:
	void ShowRegisterWindow();
	void LoginSuccessful();

private:
	Ui::LoginWindowClass ui;

	void ValidateCredentials();
	void ClearErrorMessage();

	QPropertyAnimation* transitionAnimationLoginToRegister;

private slots:
	void OnLoginButtonClicked();
};
