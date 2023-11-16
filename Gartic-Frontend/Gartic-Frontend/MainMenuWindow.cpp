#include "MainMenuWindow.h"
#include "HostRoom.h"

MainMenuWindow::MainMenuWindow(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.HostGameButton, &QPushButton::clicked, this, &MainMenuWindow::OnHostGameButtonClicked);
    connect(ui.ExitButton, &QPushButton::clicked, this, &MainMenuWindow::OnExitButtonClicked);

    transitionAnimationMainMenuToHostRoom = new QPropertyAnimation(this, "windowOpacity");
    transitionAnimationMainMenuToHostRoom->setDuration(100);
    transitionAnimationMainMenuToHostRoom->setStartValue(1.0);
    transitionAnimationMainMenuToHostRoom->setEndValue(1.0);

    connect(transitionAnimationMainMenuToHostRoom, &QPropertyAnimation::finished, this, &MainMenuWindow::OnTransitionAnimationToHostRoom);

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
    this->hide();

    HostRoom* m_HostRoomWindow = new HostRoom();
    m_HostRoomWindow->show();
}


void MainMenuWindow::OnHostGameButtonClicked()
{
    //if (!hostRoomWindow) 
        //m_hostRoomWindow = new HostRoom(this);
    transitionAnimationMainMenuToHostRoom->start();
    //m_hostRoomWindow->show(); 
}
