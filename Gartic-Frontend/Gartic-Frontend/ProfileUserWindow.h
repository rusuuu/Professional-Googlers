#pragma once

#include <QMainWindow>
#include "ui_ProfileUserWindow.h"

class ProfileUserWindow : public QMainWindow
{
	Q_OBJECT

public:
	ProfileUserWindow(QWidget *parent = nullptr);
	~ProfileUserWindow();

private:
	Ui::ProfileUserWindowClass ui;
};
