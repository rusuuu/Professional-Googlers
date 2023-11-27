#include "MainMenuWindow.h"
#include "HostRoom.h"
#include "ProfileUserWindow.h"
#include <QLineEdit>


MainMenuWindow::MainMenuWindow(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.HostGameButton, &QPushButton::clicked, this, &MainMenuWindow::OnHostGameButtonClicked);
    connect(ui.ProfileButton, &QPushButton::clicked, this, &MainMenuWindow::OnProfileButtonClicked);
    connect(ui.ExitButton, &QPushButton::clicked, this, &MainMenuWindow::OnExitButtonClicked);
    connect(ui.JoinGameButton, &QPushButton::clicked, this, &MainMenuWindow::OnJoinGameButtonClicked);

    // Style sheet to make the button round
    int buttonSize = 75;
    ui.ProfileButton->setFixedSize(buttonSize, buttonSize);

    ui.ProfileButton->setStyleSheet("QPushButton {"
        "   border-image: url(':/GarticFrontend/Images/profile_icon.png') 0 0 0 0 stretch stretch;"
        "   border-radius: " + QString::number(buttonSize / 2) + "px;"
        "}"
        "QPushButton:hover {"
        "   background-color: rgb(231, 96, 131);"
        "   border-radius: " + QString::number(buttonSize / 2) + "px;"
        "}"
        "QPushButton:pressed {"
        "   background-color: rgb(225, 62, 103);"
        "   border-radius: " + QString::number(buttonSize / 2) + "px;"
        "}");

    ui.JoinGameLabel->hide();

}

MainMenuWindow::~MainMenuWindow()
{
}

void MainMenuWindow::OnHostGameButtonClicked()
{
    emit ShowHostRoomWindow();
}

void MainMenuWindow::OnProfileButtonClicked()
{
    emit ShowProfileUserWindow();
}

void MainMenuWindow::OnExitButtonClicked()
{
    qApp->quit();
}

void MainMenuWindow::OnJoinGameButtonClicked()
{
    ui.JoinGameLabel->show();    
    ui.JoinGameLabel->setFocus();
    ui.JoinGameButton->hide();
}






