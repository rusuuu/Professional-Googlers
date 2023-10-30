#pragma once

#include <QMainWindow>
#include "ui_RegisterWindow.h"

class RegisterWindow : public QMainWindow
{
	Q_OBJECT

public:
	RegisterWindow(QWidget *parent = nullptr);
	~RegisterWindow();

private:
	Ui::RegisterWindowClass ui;
};
