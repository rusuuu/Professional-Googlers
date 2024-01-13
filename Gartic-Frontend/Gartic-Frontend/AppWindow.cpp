#include "AppWindow.h"

#include "HostRoom.h"
#include "ProfileUserWindow.h"

QStackedWidget* AppWindow::stackedWidget = nullptr;

AppWindow::AppWindow(QWidget* parent)
{
	ui.setupUi(this);

	stackedWidget = new QStackedWidget(this);
	setCentralWidget(stackedWidget);

	LoginWindow* loginPage = new LoginWindow();
	RegisterWindow* registerPage = new RegisterWindow();
	MainMenuWindow* mainMenuPage = new MainMenuWindow();
	ProfileUserWindow* profilePage = new ProfileUserWindow();
	HostRoom* hostPage = new HostRoom();

	stackedWidget->addWidget(loginPage);
	stackedWidget->addWidget(registerPage);
	stackedWidget->addWidget(mainMenuPage);
	stackedWidget->addWidget(profilePage);
	stackedWidget->addWidget(hostPage);

	ChangeWidget(LoginWindow::WindowIndex);
}

void AppWindow::ChangeWidget(int index)
{
	stackedWidget->setCurrentIndex(index);
}
