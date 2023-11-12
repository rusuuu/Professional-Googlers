#include "MainMenuWindow.h"
#include "HostRoom.h"

MainMenuWindow::MainMenuWindow(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.HostGameButton, &QPushButton::clicked, this, &MainMenuWindow::OnHostGameButtonClicked);
}

MainMenuWindow::~MainMenuWindow()
{
}

void MainMenuWindow::OnHostGameButtonClicked()
{
    if (!hostRoomWindow) 
        hostRoomWindow = new HostRoom(this);

    hostRoomWindow->show(); 
}
