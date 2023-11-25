#pragma once
#include <QMainWindow>
#include <QPropertyAnimation>
#include "ui_MainMenuWindow.h"

class HostRoom; 
class MainMenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainMenuWindow(QWidget* parent = nullptr);
    ~MainMenuWindow();

signals:
    void ShowHostRoomWindow();

private:
    Ui::MainMenuWindow ui;

    HostRoom* m_hostRoomWindow;

    QPropertyAnimation* transitionAnimationMainMenuToHostRoom;

private slots:

    void OnHostGameButtonClicked();
    void OnExitButtonClicked();
    void OnTransitionAnimationToHostRoom();

};
