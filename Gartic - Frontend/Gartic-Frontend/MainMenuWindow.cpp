#include "MainMenuWindow.h"

int MainMenuWindow::WindowIndex = 2;
QString MainMenuWindow::UserName = "";

MainMenuWindow::MainMenuWindow(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.HostGameButton, &QPushButton::clicked, this, &MainMenuWindow::OnHostGameButtonClicked);
    connect(ui.ProfileButton, &QPushButton::clicked, this, &MainMenuWindow::OnProfileButtonClicked);
    connect(ui.ExitButton, &QPushButton::clicked, this, &MainMenuWindow::OnExitButtonClicked);
    connect(ui.JoinGameButton, &QPushButton::clicked, this, &MainMenuWindow::OnJoinGameButtonClicked);
    connect(ui.HostGameButton_2, &QPushButton::clicked, this, &MainMenuWindow::OnJoinGameCodeButtonClicked);

    StyleProfileButton();

    ui.JoinGameLabel->hide();
    ui.HostGameButton_2->hide();

}

void MainMenuWindow::SetUserName(QString&& name)
{
    UserName = name;
}

MainMenuWindow::~MainMenuWindow()
{
}

void MainMenuWindow::StyleProfileButton()
{
    int buttonSize = 75;
    ui.ProfileButton->setFixedSize(buttonSize, buttonSize);

    ui.ProfileButton->setStyleSheet("QPushButton {"
        "   border-image: url(':/GarticFrontend/Images/profile_icon.png') 0 0 0 0 stretch stretch;"
        "   border-radius: " + QString::number(buttonSize / 2) + "px;"
        "}"
        "QPushButton:hover {"
        "   background-color: rgb(231, 96, 131);"
        "   border-radius: " + QString::number(buttonSize / 2) + "px;"
        "}"
        "QPushButton:pressed {"
        "   background-color: rgb(225, 62, 103);"
        "   border-radius: " + QString::number(buttonSize / 2) + "px;"
        "}");
}

void MainMenuWindow::OnJoinGameButtonClicked()
{
    ui.JoinGameLabel->show();
    ui.JoinGameLabel->setFocus();
    ui.JoinGameButton->hide();
    ui.HostGameButton_2->show();
    ui.HostGameButton_2->setFocus();
}

void MainMenuWindow::OnHostGameButtonClicked()
{
    HostRoom::SetUserName(std::move(UserName));
    AppWindow::ChangeWidget(HostRoom::WindowIndex);
}

void MainMenuWindow::OnJoinGameCodeButtonClicked()
{
    AppWindow::ChangeWidget(RoomWindow::WindowIndex);
}

void MainMenuWindow::OnProfileButtonClicked()
{
    ProfileUserWindow::SetUserName(std::move(UserName));
    AppWindow::ChangeWidget(ProfileUserWindow::WindowIndex);
}

void MainMenuWindow::OnExitButtonClicked()
{
    QCoreApplication::quit();
}