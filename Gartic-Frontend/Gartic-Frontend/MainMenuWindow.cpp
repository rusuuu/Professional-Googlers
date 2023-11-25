#include "MainMenuWindow.h"
#include "HostRoom.h"

MainMenuWindow::MainMenuWindow(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.HostGameButton, &QPushButton::clicked, this, &MainMenuWindow::OnHostGameButtonClicked);
    connect(ui.ExitButton, &QPushButton::clicked, this, &MainMenuWindow::OnExitButtonClicked);
}

MainMenuWindow::~MainMenuWindow()
{
}


void MainMenuWindow::OnExitButtonClicked()
{
    qApp->quit();
}

void MainMenuWindow::OnTransitionAnimationToHostRoom()
{
    emit ShowHostRoomWindow();
}


void MainMenuWindow::OnHostGameButtonClicked()
{
    this->hide();
    transitionAnimationMainMenuToHostRoom->start();

   // this->deleteLater();
}
