#pragma once

#include <QMainWindow>
#include "ui_ScribbleWindow.h"

class ScribbleWindow : public QMainWindow
{
	Q_OBJECT

public:
	ScribbleWindow(QWidget *parent = nullptr);
	~ScribbleWindow();

private:
	Ui::ScribbleWindowClass ui;
};
