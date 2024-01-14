#pragma once

#include <QMainWindow>
#include "ui_ScribbleWindow.h"
#include "ScribbleArea.h"

#include <QColorDialog>
#include <QInputDialog>

class ScribbleWindow : public QMainWindow
{
	Q_OBJECT

public:
	static int WindowIndex;

	ScribbleWindow(QWidget* parent = nullptr);
	~ScribbleWindow();

public slots:
	void ClearImage();

private slots:
	void PenColor();
	void PenWidth();

private:
	Ui::ScribbleWindowClass ui;

	void CreateActions();
	void CreateMenus();
	ScribbleArea* scribbleArea;
	QMenu* optionMenu;
	QAction* penColorAct;
	QAction* penWidthAct;
	QAction* clearScreenAct;
};
