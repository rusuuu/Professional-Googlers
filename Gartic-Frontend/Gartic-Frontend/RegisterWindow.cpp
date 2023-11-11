#include "RegisterWindow.h"
#include "LoginWindow.h"
#include <QMessageBox>
#include <QRegularExpression> 

RegisterWindow::RegisterWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.BackToLoginButton, &QPushButton::clicked, this, &RegisterWindow::OnBackToLoginClicked);
    connect(ui.RegisterButton, &QPushButton::clicked, this, &RegisterWindow::OnRegisterButtonClicked);
    connect(ui.RegisterUsernameInput, &QLineEdit::textChanged, this, &RegisterWindow::ClearErrorLabel);
    connect(ui.RegisterEmailInput, &QLineEdit::textChanged, this, &RegisterWindow::ClearErrorLabel);
    connect(ui.RegisterPasswordInput, &QLineEdit::textChanged, this, &RegisterWindow::ClearErrorLabel);
    connect(ui.RegisterPasswordConfirmationInput, &QLineEdit::textChanged, this, &RegisterWindow::ClearErrorLabel);

    transitionAnimationRegisterToLogin = new QPropertyAnimation(this, "windowOpacity");
    transitionAnimationRegisterToLogin->setDuration(100);
    transitionAnimationRegisterToLogin->setStartValue(1.0);
    transitionAnimationRegisterToLogin->setEndValue(0.0);

    connect(transitionAnimationRegisterToLogin, &QPropertyAnimation::finished, this, &RegisterWindow::OnTransitionAnimationFinished);
}

RegisterWindow::~RegisterWindow()
{
	
}

void RegisterWindow::OnBackToLoginClicked()
{
    transitionAnimationRegisterToLogin->start();
}

void RegisterWindow::OnTransitionAnimationFinished()
{
    this->hide();

    LoginWindow* loginWindow = new LoginWindow();
    loginWindow->show();
}

void RegisterWindow::OnRegisterButtonClicked()
{
    QString username = ui.RegisterUsernameInput->text();
    QString email = ui.RegisterEmailInput->text();
    QString password = ui.RegisterPasswordInput->text();
    QString confirmPassword = ui.RegisterPasswordConfirmationInput->text();

    try
    {
        ValidateRegistration();
    }
    catch (std::exception exception)
    {
        ui.ErrorLabel->setText(exception.what());
    }
}

bool RegisterWindow::IsValidUsername(const QString& username)
{
    return !username.isEmpty() && username.length() >= 4;
}

bool RegisterWindow::IsValidEmail(const QString& email)
{
    QRegularExpression regex("^([a-zA-Z0-9._%-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4})*$");
    return regex.match(email).hasMatch();
}

bool RegisterWindow::IsValidPassword(const QString& password)
{
    QRegularExpression regex("^(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z])(?=.*[!@#$%^&*]).{8,}$");

    return regex.match(password).hasMatch();
}

bool RegisterWindow::IsPasswordConfirmed(const QString& password, const QString& confirmPassword)
{
    return password == confirmPassword;
}

void RegisterWindow::ValidateRegistration()
{
    QString username = ui.RegisterUsernameInput->text();
    QString email = ui.RegisterEmailInput->text();
    QString password = ui.RegisterPasswordInput->text();
    QString confirmPassword = ui.RegisterPasswordConfirmationInput->text();

    if (!IsValidUsername(username)) 
    {
        throw std::exception("Invalid username");
    }

    if (email.isEmpty())
    {
        throw std::exception("Email cannot be emtpy");
    }

    if (!IsValidEmail(email))
    {
        throw std::exception("Invalid email format");
    }

    if (password.isEmpty())
    {
        throw std::exception("Password cannot be empty");
    }

    if (!IsValidPassword(password))
    {
        throw std::runtime_error("Please ensure your password:\n- Is at least 8 characters long\n- Contains one uppercase letter\n- Contains one lowercase letter\n- Includes one number\n- Has one special character(e.g., !@#$%^&*)");
    } 
       
    if (!IsPasswordConfirmed(password, confirmPassword))
    {
        throw std::exception("Password and confirm password must match");
    }
}

void RegisterWindow::ClearErrorLabel()
{
    ui.ErrorLabel->clear();
}