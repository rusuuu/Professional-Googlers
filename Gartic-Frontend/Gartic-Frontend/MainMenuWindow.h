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
    void ShowProfileUserWindow();

private:
    Ui::MainMenuWindow ui;
    HostRoom* m_hostRoomWindow;
    QPropertyAnimation* transitionAnimationMainMenuToHostRoom;
    QLineEdit* JoinGameLabel = nullptr;

private slots:

    void OnHostGameButtonClicked();
    void OnProfileButtonClicked();
    void OnExitButtonClicked();
    void OnJoinGameButtonClicked();
    
};
