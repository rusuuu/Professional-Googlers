#include "AppWindow.h"

QStackedWidget* AppWindow::stackedWidget = nullptr;

AppWindow::AppWindow(QWidget* parent)
{
	ui.setupUi(this);

	stackedWidget = new QStackedWidget(this);
	setCentralWidget(stackedWidget);

	LoginWindow* loginPage = new LoginWindow();
	RegisterWindow* registerPage = new RegisterWindow();
	MainMenuWindow* mainMenuPage = new MainMenuWindow();
	ProfileUserWindow* profileUserPage = new ProfileUserWindow();
	HostRoom* hostRoomPage = new HostRoom();
	ScribbleWindow* scribblePage = new ScribbleWindow();

	stackedWidget->addWidget(loginPage);
	stackedWidget->addWidget(registerPage);
	stackedWidget->addWidget(mainMenuPage);	
	stackedWidget->addWidget(profileUserPage);
	stackedWidget->addWidget(hostRoomPage);
	stackedWidget->addWidget(scribblePage);


	ChangeWidget(LoginWindow::WindowIndex);

	connect(loginPage, &LoginWindow::UserLoggedIn, profileUserPage, &ProfileUserWindow::GetUserStats);
}

void AppWindow::ChangeWidget(int index)
{
	stackedWidget->setCurrentIndex(index);
}
