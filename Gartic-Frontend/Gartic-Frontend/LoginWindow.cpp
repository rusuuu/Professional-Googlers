#include "LoginWindow.h"
#include "RegisterWindow.h"
#include <QRegularExpression> 
#include <QMessageBox>
#include <QScreen>


LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    connect(ui.LoginButton, &QPushButton::clicked, this, &LoginWindow::OnLoginButtonClicked);
    connect(ui.LoginEmailInput, &QLineEdit::textChanged, this, &LoginWindow::ClearErrorMessage);
    connect(ui.LoginPasswordInput, &QLineEdit::textChanged, this, &LoginWindow::ClearErrorMessage);
    connect(ui.RegisterButton, &QPushButton::clicked, this, &LoginWindow::OnRegisterButtonClicked);
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
    // Create an instance of RegisterWindow
    RegisterWindow* registerWindow = new RegisterWindow(this);
    registerWindow->setWindowOpacity(0.0);

    // Set up the transition animation for the RegisterWindow
    QPropertyAnimation* transitionAnimation = new QPropertyAnimation(registerWindow, "windowOpacity");
    transitionAnimation->setDuration(100);
    transitionAnimation->setStartValue(0.0);
    transitionAnimation->setEndValue(1.0);

    // Connect the animation's finished signal to the transition finished slot
    connect(transitionAnimation, &QPropertyAnimation::finished, this, &LoginWindow::OnTransitionAnimationFinished);

    // Show the register window
    registerWindow->show();

    // Start the transition animation
    transitionAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void LoginWindow::OnTransitionAnimationFinished()
{
    hide();
}