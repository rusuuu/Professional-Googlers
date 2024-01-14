#pragma once
#include <QMainWindow>

#include "ui_MainMenuWindow.h"

class MainMenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    static int WindowIndex;
    static void SetUserName(QString&& name);

    MainMenuWindow(QWidget* parent = nullptr);
    ~MainMenuWindow();

private slots:
    void OnJoinGameButtonClicked();
    void OnHostGameButtonClicked();
    void OnExitButtonClicked();
    void OnProfileButtonClicked();

private:
    static QString UserName;

    Ui::MainMenuWindow ui;
    QLineEdit* JoinGameLabel;

    void StyleProfileButton();
};
