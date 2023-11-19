#include "LoginWindow.h"
#include "RegisterWindow.h"
#include <QRegularExpression> 
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    connect(ui.LoginButton, &QPushButton::clicked, this, &LoginWindow::OnLoginButtonClicked);
    connect(ui.LoginEmailInput, &QLineEdit::textChanged, this, &LoginWindow::ClearErrorMessage);
    connect(ui.LoginPasswordInput, &QLineEdit::textChanged, this, &LoginWindow::ClearErrorMessage);
    connect(ui.RegisterButton, &QPushButton::clicked, this, &LoginWindow::OnRegisterButtonClicked);

    
    transitionAnimationLoginToRegister = new QPropertyAnimation(this, "windowOpacity");
    transitionAnimationLoginToRegister->setDuration(100); 
    transitionAnimationLoginToRegister->setStartValue(1.0);
    transitionAnimationLoginToRegister->setEndValue(1.0);

    connect(transitionAnimationLoginToRegister, &QPropertyAnimation::finished, this, &LoginWindow::OnTransitionAnimationFinished);

}

LoginWindow::~LoginWindow()
{}

void LoginWindow::OnLoginButtonClicked() 
{
    QString email = ui.LoginEmailInput->text();
    QString password = ui.LoginPasswordInput->text();

    try
    {
        ValidateCredentials();
        emit LoginSuccessful();
    }
    catch (std::exception exception)
    {
        ui.ErrorLabel->setText(exception.what());
    }
}

void LoginWindow::ValidateCredentials() 
{
    QString email = ui.LoginEmailInput->text();
    QString password = ui.LoginPasswordInput->text();
    
    if (email.isEmpty())
    {
        throw std::exception("Email field cannot be empty");
    }

    if (password.isEmpty())
    {
        throw std::exception("Password cannot be empty");
    }
}

void LoginWindow::ClearErrorMessage()
{
    ui.ErrorLabel->clear();
}

void LoginWindow::OnRegisterButtonClicked()
{
    transitionAnimationLoginToRegister->start();
}


void LoginWindow::OnTransitionAnimationFinished()
{
    this->hide();

    RegisterWindow* registerWindow = new RegisterWindow();
    registerWindow->show();
}