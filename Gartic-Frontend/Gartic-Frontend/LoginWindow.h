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

signals:
	void showRegisterWindow();

private:
	Ui::LoginWindowClass ui;

	void ValidateCredentials();
	void ClearErrorMessage();
	void OnRegisterButtonClicked();

	QPropertyAnimation* transitionAnimationLoginToRegister;

private slots:
	void OnLoginButtonClicked();
	void OnTransitionAnimationFinished();

};
