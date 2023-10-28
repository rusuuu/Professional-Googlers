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

private:
	Ui::LoginWindowClass ui;
	bool ValidateCredentials();

private slots:
	void OnLoginButtonClicked();

};
