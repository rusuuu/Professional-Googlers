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

	stackedWidget->addWidget(loginPage);
	stackedWidget->addWidget(registerPage);
	stackedWidget->addWidget(mainMenuPage);	

	ChangeWidget(LoginWindow::WindowIndex);
}

void AppWindow::ChangeWidget(int index)
{
	stackedWidget->setCurrentIndex(index);
}
