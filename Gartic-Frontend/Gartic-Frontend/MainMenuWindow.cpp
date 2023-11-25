#include "MainMenuWindow.h"
#include "HostRoom.h"
#include "ProfileUserWindow.h"

MainMenuWindow::MainMenuWindow(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.HostGameButton, &QPushButton::clicked, this, &MainMenuWindow::OnHostGameButtonClicked);
    connect(ui.ProfileButton, &QPushButton::clicked, this, &MainMenuWindow::OnProfileButtonClicked);
    connect(ui.ExitButton, &QPushButton::clicked, this, &MainMenuWindow::OnExitButtonClicked);
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

