#include "ProfileUserWindow.h"

ProfileUserWindow::ProfileUserWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.UploadButton, &QPushButton::clicked, this, &ProfileUserWindow::UploadAvatar);
    
    ui.ProfileNameLabel->setText(ProfileName);
    ui.ProfileNameLabel->setText(TotalGames);
    ui.ProfileNameLabel->setText(GamesWon);
    ui.ProfileNameLabel->setText(GamesLost);
    ui.ProfileNameLabel->setText(TotalPoints);
}

ProfileUserWindow::~ProfileUserWindow()
{}

void ProfileUserWindow::UploadAvatar()
{
    QString imagePath = QFileDialog::getOpenFileName(this, "Select Avatar", QDir::homePath(), "Images (*.png *.jpg *.bmp)");

    if (!imagePath.isEmpty()) {
        QPixmap avatar(imagePath);
        ui.ProfilePictureLabel->setPixmap(avatar);
        ui.ProfilePictureLabel->setScaledContents(true);
    }
}
