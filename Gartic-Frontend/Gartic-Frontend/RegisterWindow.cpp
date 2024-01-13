#include "RegisterWindow.h"

int RegisterWindow::WindowIndex = 1;

RegisterWindow::RegisterWindow(QWidget* parent): QMainWindow(parent)
{
	ui.setupUi(this);

	authenticationService = new AuthenticationService(this);
	userStatsService = new UserStatsService(this);

	connect(ui.ReturnToLoginButton, &QPushButton::clicked, this, &RegisterWindow::OnReturnToLoginButtonClicked);
	connect(ui.RegisterButton, &QPushButton::clicked, this, &RegisterWindow::OnRegisterButtonClicked);
	connect(ui.UsernameInput, &QLineEdit::textChanged, this, &RegisterWindow::ClearErrorMessage);
	connect(ui.EmailInput, &QLineEdit::textChanged, this, &RegisterWindow::ClearErrorMessage);
	connect(ui.PasswordInput, &QLineEdit::textChanged, this, &RegisterWindow::ClearErrorMessage);
	connect(ui.ConfirmPasswordInput, &QLineEdit::textChanged, this, &RegisterWindow::ClearErrorMessage);

	connect(authenticationService, &AuthenticationService::registerResponseReceived, this, &RegisterWindow::OnRegisterResponseReceived);
	connect(userStatsService, &UserStatsService::CreateUserStatsResponse, this, &RegisterWindow::OnCreateUserStatsResponseReceived);
}

RegisterWindow::~RegisterWindow()
{

}

void::RegisterWindow::OnRegisterButtonClicked()
{
	ui.UsernameInput->setText("Model");
	ui.EmailInput->setText("model@email.com");
	ui.PasswordInput->setText("Model!01");
	ui.ConfirmPasswordInput->setText("Model!01");

	QString username = ui.UsernameInput->text();
	QString email = ui.EmailInput->text();
	QString password = ui.PasswordInput->text();
	QString confirmPassword = ui.ConfirmPasswordInput->text();

	std::string usernameString = username.toUtf8().constData();
	std::string emailString = email.toUtf8().constData();
	std::string passwordString = password.toUtf8().constData();

	try
	{
		ValidateCredentials();
		authenticationService->registerUser(usernameString, emailString, passwordString);
	}
	catch (std::exception exception)
	{
		ui.ErrorLabel->setText(exception.what());
	}
}

void RegisterWindow::ValidateCredentials()
{
	QString username = ui.UsernameInput->text();
	QString email = ui.EmailInput->text();
	QString password = ui.PasswordInput->text();
	QString confirmPassword = ui.ConfirmPasswordInput->text();

	if (username.isEmpty() || email.isEmpty() || password.isEmpty() || confirmPassword.isEmpty())
	{
		throw std::runtime_error("All fields are required.");
	}

	QRegularExpression emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4})");
	if (!emailRegex.match(email).hasMatch())
	{
		throw std::runtime_error("Please enter a valid email address.");
	}

	QRegularExpression passwordRegex(R"((?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[\W_]).{8,})");
	if (!passwordRegex.match(password).hasMatch())
	{
		throw std::runtime_error("Password must be at least 8 characters and include: 1 uppercase, 1 lowercase, 1 number, 1 special character.");
	}

	if (password != confirmPassword)
	{
		throw std::runtime_error("Passwords do not match.");
	}
}

void RegisterWindow::ClearErrorMessage()
{
	ui.ErrorLabel->clear();
}

void RegisterWindow::OnReturnToLoginButtonClicked()
{
	AppWindow::ChangeWidget(LoginWindow::WindowIndex);
}

void RegisterWindow::OnCreateUserStatsResponseReceived(bool success, const QString& result)
{
	if (success)
	{
		AppWindow::ChangeWidget(LoginWindow::WindowIndex);
	}
	else
	{
		ui.ErrorLabel->setText(result);
	}
}

void RegisterWindow::OnRegisterResponseReceived(bool success, const QString& result)
{
	if (success)
	{
		std::string name = ui.UsernameInput->text().toUtf8().constData();
		try
		{
			userStatsService->CreateUserStats(name, -1, -1, -1, -1);
		}
		catch(std::exception e)
		{
			ui.ErrorLabel->setText(e.what());
		}
	}
	else
	{
		ui.ErrorLabel->setText(result);
	}
}