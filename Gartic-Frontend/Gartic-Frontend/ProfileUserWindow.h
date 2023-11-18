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

private:

	Ui::ProfileUserWindowClass ui;

	QPushButton* UploadButton;

private slots:

	void UploadAvatar();
};
