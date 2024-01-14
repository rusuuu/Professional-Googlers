#pragma once
#include <QtWidgets/QMainWindow>
#include <QStackedWidget>
#include <QTimer>

#include "HostRoom.h"
#include "RoomWindow.h"
#include "LoginWindow.h"
#include "ui_AppWindow.h"
#include "RegisterWindow.h"
#include "ProfileUserWindow.h"
#include "ScribbleWindow.h"

class AppWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	AppWindow(QWidget* parent = nullptr);

	static void ChangeWidget(int index);
private:
	Ui::MainWindow ui;
	static QStackedWidget* stackedWidget;
};

