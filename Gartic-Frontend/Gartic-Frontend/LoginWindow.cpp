#include "LoginWindow.h"
#include <QRegularExpression> 
#include <QMessageBox> 

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    connect(ui.LoginButton, &QPushButton::clicked, this, &LoginWindow::OnLoginButtonClicked);
    connect(ui.EmailInput, &QLineEdit::textChanged, this, &LoginWindow::ClearErrorMessage);
    connect(ui.PasswordInput, &QLineEdit::textChanged, this, &LoginWindow::ClearErrorMessage);
}

LoginWindow::~LoginWindow()
{}

void LoginWindow::OnLoginButtonClicked() 
{
    QString email = ui.EmailInput->text();
    QString password = ui.PasswordInput->text();

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
    QString email = ui.EmailInput->text();
    QString password = ui.PasswordInput->text();
    
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