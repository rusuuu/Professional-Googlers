#include "ProfileUserWindow.h"
#include "MainMenuWindow.h"

ProfileUserWindow::ProfileUserWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.BackToMainMenuFromProfileUser, &QPushButton::clicked, this, &ProfileUserWindow::OnBackToMainMenuClicked);
    connect(ui.UploadButton, &QPushButton::clicked, this, &ProfileUserWindow::UploadAvatar);

    ui.ProfileName->setText(ProfileName);
    ui.TotalGames->setText(TotalGames);
    ui.GamesWon->setText(GamesWon);
    ui.GamesLost->setText(GamesLost);
    ui.TotalPoints->setText(TotalPoints);

    SetDefaultAvatar();
}

ProfileUserWindow::~ProfileUserWindow()
{
}

void ProfileUserWindow::OnBackToMainMenuClicked()
{
    emit ShowMainMenuWindow();
}

void ProfileUserWindow::UploadAvatar()
{
    QString imagePath = QFileDialog::getOpenFileName(this, "Select Avatar", QDir::homePath(), "Images (*.png *.jpg *.bmp)");

    if (!imagePath.isEmpty()) {
        QPixmap avatar(imagePath);
        ui.ProfilePicture->setPixmap(avatar);
        ui.ProfilePicture->setScaledContents(true);
    }
}

void ProfileUserWindow::SetDefaultAvatar()
{
    // Set the path to your default avatar image
    QString defaultImagePath = ":/GarticFrontend/Images/profile_icon.png";

    QPixmap defaultAvatar(defaultImagePath);
    ui.ProfilePicture->setPixmap(defaultAvatar);
    ui.ProfilePicture->setScaledContents(true);

    // Set the QLabel as a circle
    ui.ProfilePicture->setStyleSheet("QLabel { border-radius: 50%; background-color: transparent; }");
}