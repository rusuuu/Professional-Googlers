#include "HostRoom.h"
#include "MainMenuWindow.h"

HostRoom::HostRoom(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.BackToMainMenuButton, &QPushButton::clicked, this, &HostRoom::OnBackToMainMenuClicked);

	transitionAnimationHostToMainMenu = new QPropertyAnimation(this, "windowOpacity");
	transitionAnimationHostToMainMenu->setDuration(100);
	transitionAnimationHostToMainMenu->setStartValue(1.0);
	transitionAnimationHostToMainMenu->setEndValue(1.0);

	connect(transitionAnimationHostToMainMenu, &QPropertyAnimation::finished, this, &HostRoom::OnTransitionAnimationToMainMenu);
}

HostRoom::~HostRoom()
{}

void HostRoom::OnBackToMainMenuClicked()
{
	this->close();
	transitionAnimationHostToMainMenu->start();
}

void HostRoom::OnTransitionAnimationToMainMenu()
{
	this->hide();

	MainMenuWindow* m_MainMenuWindow = new MainMenuWindow();
	m_MainMenuWindow->show();
	
}