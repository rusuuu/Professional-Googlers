#include "RegisterWindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.BackToLoginButton, &QPushButton::clicked, this, &RegisterWindow::OnBackToLoginClicked);
}

RegisterWindow::~RegisterWindow()
{}

void RegisterWindow::OnBackToLoginClicked()
{
	emit showLoginWindow();
}