#include "ProfileUserWindow.h"

int ProfileUserWindow::WindowIndex = 3;
QString ProfileUserWindow::UserName = "";

void ProfileUserWindow::SetUserName(QString&& name)
{
    UserName = name;
}

ProfileUserWindow::ProfileUserWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    userStatsService = new UserStatsService();

	connect(ui.ReturnToMainMenuButton, &QPushButton::clicked, this, &ProfileUserWindow::OnReturnToMainMenuButtonClicked);
    //connect(ui.UploadButton, &QPushButton::clicked, this, &ProfileUserWindow::UploadAvatar);
    
    connect(userStatsService, &UserStatsService::GetUserStatsResponse, this, &ProfileUserWindow::OnGetUserStatsResponseReceived);
}

ProfileUserWindow::~ProfileUserWindow()
{
}

void ProfileUserWindow::OnGetUserStatsResponseReceived(bool success, const QString& result)
{
    if (success)
    {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(result.toUtf8().constData());
        if (!jsonDoc.isNull() && jsonDoc.isObject())
        {
            QJsonObject jsonObject = jsonDoc.object();

            QString name = jsonObject["name"].toString();
            int totalGames = jsonObject["totalGames"].toInt();
            int gamesWon = jsonObject["gamesWon"].toInt();
            int gamesLost = jsonObject["gamesLost"].toInt();
            int totalPoints = jsonObject["totalPoints"].toInt();

            ui.ProfileName->setText(name);
            ui.TotalGames->setText(QString::number(totalGames));
            ui.GamesWon->setText(QString::number(gamesWon));
            ui.GamesLost->setText(QString::number(gamesLost));
            ui.TotalPoints->setText(QString::number(totalPoints));
        }
    }
    else
    {

    }
}

void ProfileUserWindow::GetUserStats(const QString& name)
{
    try
    {
        std::string username = name.toUtf8().constData();
        userStatsService->GetUserStats(username);
    }
    catch (std::exception e)
    {

    }
}

void ProfileUserWindow::OnReturnToMainMenuButtonClicked()
{
    AppWindow::ChangeWidget(MainMenuWindow::WindowIndex);
}

//void ProfileUserWindow::UploadAvatar()
//{
//    QString imagePath = QFileDialog::getOpenFileName(this, "Select Avatar", QDir::homePath(), "Images (*.png *.jpg *.bmp)");
//
//    if (!imagePath.isEmpty()) {
//        QPixmap originalAvatar(imagePath);
//
//        // Get the label dimensions
//        int labelWidth = ui.ProfilePicture->width();
//        int labelHeight = ui.ProfilePicture->height();
//
//        // Scale the image while maintaining aspect ratio
//        QPixmap scaledAvatar = originalAvatar.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//
//         QBitmap mask(scaledAvatar.size());
//         mask.fill(Qt::white);
//         QPainter painter(&mask);
//         painter.setBrush(Qt::black);
//         painter.setRenderHint(QPainter::Antialiasing, true);
//         painter.drawEllipse(mask.rect());
//         scaledAvatar.setMask(mask);
//
//        // Set the scaled and cropped avatar as the profile picture
//        ui.ProfilePicture->setPixmap(scaledAvatar);
//        ui.ProfilePicture->setScaledContents(true);
//    }
//}

//void ProfileUserWindow::SetDefaultAvatar()
//{
//    // Set the path to your default avatar image
//    QString defaultImagePath = ":/GarticFrontend/Images/profile_icon.png";
//
//    QPixmap defaultAvatar(defaultImagePath);
//    ui.ProfilePicture->setPixmap(defaultAvatar);
//    ui.ProfilePicture->setScaledContents(true);
//
//    // Set the QLabel as a circle
//    ui.ProfilePicture->setStyleSheet("QLabel { border-radius: 50%; background-color: transparent; }");
//}
