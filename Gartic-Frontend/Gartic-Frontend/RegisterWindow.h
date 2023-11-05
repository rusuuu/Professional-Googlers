#pragma once

#include <QMainWindow>
#include "ui_RegisterWindow.h"

class RegisterWindow : public QMainWindow
{
	Q_OBJECT

public:
	RegisterWindow(QWidget *parent = nullptr);
	~RegisterWindow();

	void OnBackToLoginClicked();

signals:
	void ShowLoginWindow();

private slots:
	void OnRegisterButtonClicked();
	void ValidateRegistration();
	void ClearErrorLabel();

private:
	Ui::RegisterWindowClass ui;
	bool IsValidUsername(const QString& username);
	bool IsValidEmail(const QString& email);
	bool IsValidPassword(const QString& password);
	bool IsPasswordConfirmed(const QString& password, const QString& confirmPassword);
};
