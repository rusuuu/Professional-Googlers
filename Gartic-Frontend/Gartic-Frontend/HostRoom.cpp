#include "HostRoom.h"

int HostRoom::WindowIndex = 4;
QString HostRoom::UserName = "";

void HostRoom::SetUserName(QString&& name)
{
    UserName = name;
}

HostRoom::HostRoom(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    roomService = new RoomService(this);

	connect(ui.BackToMainMenuButton, &QPushButton::clicked, this, &HostRoom::OnBackToMainMenuClicked);
	connect(ui.CopyInviteCodeButton, &QPushButton::clicked, this, &HostRoom::OnCopyInviteCodeClicked);
    connect(ui.StartButton, &QPushButton::clicked, this, &HostRoom::OnStartButtonClicked);
    connect(ui.GenerateCodeButton, &QPushButton::clicked, this, &HostRoom::OnGenerateCodeButtonClicked);
    
    connect(roomService, &RoomService::CreateRoomResponse, this, &HostRoom::OnCreateRoomResponseReceived);
}

HostRoom::~HostRoom()
{}

void HostRoom::OnBackToMainMenuClicked()
{
    AppWindow::ChangeWidget(MainMenuWindow::WindowIndex);
}

void HostRoom::OnCopyInviteCodeClicked()
{
    
    QString inviteCode = ui.InviteCode->text();

    
    QClipboard* clipboard = QApplication::clipboard();

    
    clipboard->setText(inviteCode);
}

QString HostRoom::GenerateRandomCode()
{
    const QString possibleCharacters("0123456789");
    const int randomStringLength = 8; 

    QString randomString;
    for (int i = 0; i < randomStringLength; ++i)
    {
        int index = QRandomGenerator::global()->bounded(possibleCharacters.length());
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}

void HostRoom::OnStartButtonClicked()
{
    try
    {
        roomService->CreateRoom(ui.InviteCode->text().toInt(), UserName);
    }
    catch (std::exception e)
    {

    }
}

void HostRoom::OnGenerateCodeButtonClicked()
{
    QString inviteCode = GenerateRandomCode();
    ui.InviteCode->setText(inviteCode);
}

void HostRoom::OnCreateRoomResponseReceived(bool success, const QString& result)
{
    if (success)
    {
        AppWindow::ChangeWidget(RoomWindow::WindowIndex);
    }
    else
    {

    }
}

