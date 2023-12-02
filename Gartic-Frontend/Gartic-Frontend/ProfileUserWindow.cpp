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
        QPixmap originalAvatar(imagePath);

        // Get the label dimensions
        int labelWidth = ui.ProfilePicture->width();
        int labelHeight = ui.ProfilePicture->height();

        // Scale the image while maintaining aspect ratio
        QPixmap scaledAvatar = originalAvatar.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);

         QBitmap mask(scaledAvatar.size());
         mask.fill(Qt::white);
         QPainter painter(&mask);
         painter.setBrush(Qt::black);
         painter.setRenderHint(QPainter::Antialiasing, true);
         painter.drawEllipse(mask.rect());
         scaledAvatar.setMask(mask);

        // Set the scaled and cropped avatar as the profile picture
        ui.ProfilePicture->setPixmap(scaledAvatar);
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
//test