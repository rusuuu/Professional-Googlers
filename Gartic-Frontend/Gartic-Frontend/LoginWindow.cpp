#include <QScreen>
#include <QRegularExpression> 
#include <QMessageBox>

#include "LoginWindow.h"
#include "RegisterWindow.h"

int LoginWindow::WindowIndex = 0;

LoginWindow::LoginWindow(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);

    authenticationService = new AuthenticationService(this);

    connect(ui.LoginButton, &QPushButton::clicked, this, &LoginWindow::OnLoginButtonClicked);
    connect(ui.EmailInput, &QLineEdit::textChanged, this, &LoginWindow::ClearErrorMessage);
    connect(ui.PasswordInput, &QLineEdit::textChanged, this, &LoginWindow::ClearErrorMessage);
    connect(ui.CreateAccountButton, &QPushButton::clicked, this, &LoginWindow::OnCreateAccountButtonClicked);

    connect(authenticationService, &AuthenticationService::loginResponseReceived, this, &LoginWindow::OnLoginResponseReceived);
}

LoginWindow::~LoginWindow()
{

}

void LoginWindow::OnLoginButtonClicked() 
{
    ui.EmailInput->setText("model@email.com");
    ui.PasswordInput->setText("Model!01");

    QString email = ui.EmailInput->text();
    QString password = ui.PasswordInput->text();

    std::string emailString = email.toUtf8().constData();
    std::string passwordString = password.toUtf8().constData();

    try
    {
        ValidateCredentials();
        authenticationService->loginUser(emailString, passwordString);
    }
    catch (std::exception exception)
    {
        ui.ErrorLabel->setText(exception.what());
    }
}

void LoginWindow::ValidateCredentials() 
{
    QString email = ui.EmailInput->text();
    QString password = ui.PasswordInput->text();
    
    if (email.isEmpty())
    {
        throw std::exception("Email field cannot be empty");
    }

    if (password.isEmpty())
    {
        throw std::exception("Password cannot be empty");
    }

    QRegularExpression emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4})");
    if (!emailRegex.match(email).hasMatch()) 
    {
        throw std::exception("Please enter a valid email address");
    }
}

void LoginWindow::ClearErrorMessage()
{
    ui.ErrorLabel->clear();
}

void LoginWindow::OnCreateAccountButtonClicked()
{
    AppWindow::ChangeWidget(RegisterWindow::WindowIndex);
}

void LoginWindow::OnLoginResponseReceived(bool success, const QString& result)
{
    if (success)
    {
        auto name = result;
        MainMenuWindow::SetUserName(std::move(name));
        AppWindow::ChangeWidget(MainMenuWindow::WindowIndex);

        emit UserLoggedIn(name);
    }
    else
    {
		ui.ErrorLabel->setText(result);
	}
}
