#include "RoomWindow.h"

int RoomWindow::WindowIndex = 5;

RoomWindow::RoomWindow(QWidget* parent) : QMainWindow(parent)
{
    ui.setupUi(this);

    roomService = new RoomService();

    connect(ui.ReturnToMainMenuButton, &QPushButton::clicked, this, &RoomWindow::OnReturnToMainMenuButtonClicked);
    connect(ui.StartGameButton, &QPushButton::clicked, this, &RoomWindow::OnStartGameButtonClicked);
    connect(roomService, &RoomService::CreateRoomResponse, this, &RoomWindow::HandleCreateRoomResponse);
}

RoomWindow::~RoomWindow()
{
}

void RoomWindow::OnStartGameButtonClicked()
{
	AppWindow::ChangeWidget(ScribbleWindow::WindowIndex);
}

void RoomWindow::OnReturnToMainMenuButtonClicked()
{
	AppWindow::ChangeWidget(MainMenuWindow::WindowIndex);
}

void RoomWindow::HandleCreateRoomResponse(bool success, const QString& result)
{
    if (success)
    {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(result.toUtf8().constData());
        if (!jsonDoc.isNull() && jsonDoc.isObject())
        {
            QJsonObject jsonObject = jsonDoc.object();

            int roomId = jsonObject["roomId"].toInt();
            std::string hostName = jsonObject["hostName"].toString().toStdString();

            ui.RoomCodeLabel->setText(QString::number(roomId));
            ui.Player1->setText(QString::fromStdString(hostName));
        }
    }
    else
    {
        qDebug() << "Failed to create room. Error: " << result;
    }
}

void RoomWindow::HandleGetRoomResponse(const QJsonObject& jsonObject)
{
    bool success = jsonObject["success"].toBool();
    if (success) 
    {
        int roomId = jsonObject["roomId"].toInt();
        QJsonArray userNames = jsonObject["userNames"].toArray();

        currentRoomId = roomId;
        currentPlayerNames = userNames;
    }
    else 
    {
        QString errorMessage = jsonObject["message"].toString();
        qDebug() << "Failed to get room information: " << errorMessage;
    }
}

void RoomWindow::HandleUpdateRoomResponse(const QJsonObject& jsonObject)
{
    bool success = jsonObject["success"].toBool();
    if (success) 
    {
        QString event = jsonObject["event"].toString();
        if (event == "user_joined")
        {
            int roomId = jsonObject["room_id"].toInt();
            int userId = jsonObject["user_id"].toInt();

            AddUserToRoomUI(roomId, userId);
        }
    }
    else
    {
        QString errorMessage = jsonObject["message"].toString();
        qDebug() << "Failed to update room: " << errorMessage;
    }
}

void RoomWindow::HandleDeleteRoomResponse(const QJsonObject& jsonObject)
{
    bool success = jsonObject["success"].toBool();
    QString responseMessage = jsonObject["message"].toString();

    if (success)
    {
        qDebug() << "Room deleted successfully.";
        ClearRoomInformation();
    }
    else 
    {
        qDebug() << "Failed to delete room:" << responseMessage;
    }
}

void RoomWindow::AddUserToRoomUI(int roomId, int userId)
{
    if (roomId == currentRoomId) 
    {
        for (int i = 0; i < 4; ++i) 
        {
            QLabel* playerLabel = findChild<QLabel*>(QString("Player%1").arg(i + 1));
            if (playerLabel && playerLabel->text().isEmpty())
            {
                playerLabel->setText(QString::number(userId));
                break;
            }

        }
    }
    else 
    {
        qDebug() << "User joined a different room. Current Room ID:" << currentRoomId << "Joined Room ID:" << roomId;
    }
}

void RoomWindow::ClearRoomInformation()
{
    ui.RoomCodeLabel->setText("");
    for (int i = 1; i <= 4; ++i)
    {
        QLabel* playerLabel = findChild<QLabel*>(QString("Player%1").arg(i));
        if (playerLabel)
        {
            playerLabel->setText("");
        }
    }
}
