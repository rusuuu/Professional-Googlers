#pragma once

#include <QMainWindow>
#include <QPropertyAnimation>
#include "ui_HostRoom.h"

class HostRoom : public QMainWindow
{
	Q_OBJECT

public:
	HostRoom(QWidget *parent = nullptr);
	~HostRoom();
	void OnBackToMainMenuClicked();

signals:
	void ShowMainMenuWindow();

private:
	Ui::HostRoomClass ui;
	QPropertyAnimation* transitionAnimationHostToMainMenu;

private slots:
	void OnTransitionAnimationToMainMenu();


};
