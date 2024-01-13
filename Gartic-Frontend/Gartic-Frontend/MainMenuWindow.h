#pragma once
#include <QMainWindow>

#include "AppWindow.h"
#include "ui_MainMenuWindow.h"

class MainMenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    static int WindowIndex;

    MainMenuWindow(QWidget* parent = nullptr);
    ~MainMenuWindow();

private slots:
    void OnJoinGameButtonClicked();
    void OnHostGameButtonClicked();
    void OnExitButtonClicked();
    void OnProfileButtonClicked();

private:
    Ui::MainMenuWindow ui;
    QLineEdit* JoinGameLabel;

    void StyleProfileButton();
};
