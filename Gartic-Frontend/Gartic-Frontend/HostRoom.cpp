#include "HostRoom.h"
#include "MainMenuWindow.h"

HostRoom::HostRoom(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.BackToMainMenuButton, &QPushButton::clicked, this, &HostRoom::OnBackToMainMenuClicked);
}

HostRoom::~HostRoom()
{}

void HostRoom::OnBackToMainMenuClicked()
{
	emit ShowMainMenuWindow();
}