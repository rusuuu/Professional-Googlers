#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LoginWindow.h"


class LoginWindow : public QMainWindow
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = nullptr);
	~LoginWindow();

	bool IsValidEmail(const QString& email); 

signals:
	void showRegisterWindow();

private:
	Ui::LoginWindowClass ui;
	bool ValidateCredentials();

	void ClearErrorMessage();

	void OnRegisterButtonClicked();

private slots:
	void OnLoginButtonClicked();

};
