#pragma once

#include <QMainWindow>
#include "ui_ProfileUserWindow.h"

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QVBoxLayout>

class ProfileUserWindow : public QMainWindow
{
	Q_OBJECT

public:

	ProfileUserWindow(QWidget *parent = nullptr);
	~ProfileUserWindow();

	void OnBackToMainMenuClicked();

signals:
	void ShowMainMenuWindow();

private:

	Ui::ProfileUserWindowClass ui;

	QPushButton* UploadButton;

	QString ProfileName;
	QString TotalGames;
	QString GamesWon;
	QString GamesLost;
	QString TotalPoints;

private slots:

	void UploadAvatar();
};
