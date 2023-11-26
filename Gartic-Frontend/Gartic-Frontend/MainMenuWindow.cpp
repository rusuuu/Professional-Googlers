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






