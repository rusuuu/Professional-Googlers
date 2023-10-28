#include "LoginWindow.h"
#include <QRegularExpression> 
#include <QMessageBox> 

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    connect(ui.LoginButton, &QPushButton::clicked, this, &LoginWindow::OnLoginButtonClicked);
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
    
    if (IsValidEmail(email) == false) 
    {
        QMessageBox::warning(this, "Invalid", "Email is not valid!");
        return false;
    }

    if (password.isEmpty() == true)
    {
        QMessageBox::warning(this, "Invalid", "Password is not valid!");
        return false;
    }

    return true;
}