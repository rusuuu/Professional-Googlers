#pragma once

#include <QMainWindow>
#include "ui_HostRoom.h"

class HostRoom : public QMainWindow
{
	Q_OBJECT

public:
	HostRoom(QWidget *parent = nullptr);
	~HostRoom();

private:
	Ui::HostRoomClass ui;
};
