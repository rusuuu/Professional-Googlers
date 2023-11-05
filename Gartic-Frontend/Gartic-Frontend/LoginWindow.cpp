#include "LoginWindow.h"
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

}

LoginWindow::~LoginWindow()
{}

void LoginWindow::OnLoginButtonClicked() 
{
    QString email = ui.LoginEmailInput->text();
    QString password = ui.LoginPasswordInput->text();

    if (ValidateCredentials()) 
    {
        // Attempt to login or any other logic
    }
    else 
    {
        // Show error or validation message
    }
}

bool LoginWindow::IsValidEmail(const QString& email) 
{
    
    QRegularExpression regex("^([a-zA-Z0-9._%-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4})*$");

   
    return regex.match(email).hasMatch();
}


bool LoginWindow::ValidateCredentials() 
{
    QString email = ui.LoginEmailInput->text();
    QString password = ui.LoginPasswordInput->text();
    
    if ((!IsValidEmail(email)) || email.isEmpty())
    {
        ui.EmailErrorLabel->setText("Invalid email address.");
        return false;
    }

    if (password.isEmpty())
    {
        ui.PasswordErrorLabel->setText("Password cannot be empty.");
        return false;
    }

    ui.EmailErrorLabel->clear();
    ui.PasswordErrorLabel->clear();
    return true;
}
void LoginWindow::ClearErrorMessage()
{
    ui.EmailErrorLabel->clear();
    ui.PasswordErrorLabel->clear();
}

void LoginWindow::OnRegisterButtonClicked()
{
    emit showRegisterWindow();
}