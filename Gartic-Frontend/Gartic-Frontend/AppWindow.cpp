#include "AppWindow.h"

#include "HostRoom.h"
#include "ProfileUserWindow.h"
#include "ScribbleWindow.h"

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
	ScribbleWindow* scribblePage = new ScribbleWindow;

	stackedWidget->addWidget(loginPage);
	stackedWidget->addWidget(registerPage);
	stackedWidget->addWidget(mainMenuPage);
	stackedWidget->addWidget(profilePage);
	stackedWidget->addWidget(hostPage);
	stackedWidget->addWidget(scribblePage);

	ChangeWidget(LoginWindow::WindowIndex);
}

void AppWindow::ChangeWidget(int index)
{
	stackedWidget->setCurrentIndex(index);
}
