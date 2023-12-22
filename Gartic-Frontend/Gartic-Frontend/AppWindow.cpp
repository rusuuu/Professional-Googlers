#include "AppWindow.h"

QStackedWidget* AppWindow::stackedWidget = nullptr;

AppWindow::AppWindow(QWidget* parent)
{
	ui.setupUi(this);

	stackedWidget = new QStackedWidget(this);
	setCentralWidget(stackedWidget);

	LoginWindow* loginPage = new LoginWindow();
	RegisterWindow* registerPage = new RegisterWindow();

	stackedWidget->addWidget(loginPage);
	stackedWidget->addWidget(registerPage);

	ChangeWidget(0);
}

void AppWindow::ChangeWidget(int index)
{
	stackedWidget->setCurrentIndex(index);
}
