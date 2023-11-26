#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GarticFrontend.h"

#include <QPropertyAnimation>

#include "LoginWindow.h"
#include "RegisterWindow.h"
#include "MainMenuWindow.h"
#include "HostRoom.h"
#include "ProfileUserWindow.h"

class GarticFrontend : public QMainWindow
{
    Q_OBJECT

public:
    GarticFrontend(QWidget *parent = nullptr);
    ~GarticFrontend();

private:
    Ui::GarticFrontendClass ui;
};
