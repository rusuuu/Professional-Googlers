#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GarticFrontend.h"

class GarticFrontend : public QMainWindow
{
    Q_OBJECT

public:
    GarticFrontend(QWidget *parent = nullptr);
    ~GarticFrontend();

private:
    Ui::GarticFrontendClass ui;
};
