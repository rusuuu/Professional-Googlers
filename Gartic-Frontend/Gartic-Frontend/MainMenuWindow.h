#pragma once
#include <QMainWindow>
#include "ui_MainMenuWindow.h"

class HostRoom; 
class MainMenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainMenuWindow(QWidget* parent = nullptr);
    ~MainMenuWindow();

private slots:
    void OnHostGameButtonClicked(); 

private:
    Ui::MainMenuWindow ui;
    HostRoom* hostRoomWindow; 
};
