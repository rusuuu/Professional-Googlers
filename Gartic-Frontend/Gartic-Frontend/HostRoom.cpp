#include "HostRoom.h"
#include "MainMenuWindow.h"
#include "ScribbleWindow.h"
#include <QClipboard>
#include <QRandomGenerator>



HostRoom::HostRoom(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.BackToMainMenuButton, &QPushButton::clicked, this, &HostRoom::OnBackToMainMenuClicked);
	connect(ui.CopyInviteCodeButton, &QPushButton::clicked, this, &HostRoom::OnCopyInviteCodeClicked);
    connect(ui.StartButton, &QPushButton::clicked, this, &HostRoom::OnStartButtonClicked);
    connect(ui.GenerateCodeButton, &QPushButton::clicked, this, &HostRoom::OnGenerateCodeButtonClicked);

}

HostRoom::~HostRoom()
{}

void HostRoom::OnBackToMainMenuClicked()
{
	emit ShowMainMenuWindow();
}

void HostRoom::OnCopyInviteCodeClicked()
{
    
    QString inviteCode = ui.InviteCode->text();

    
    QClipboard* clipboard = QApplication::clipboard();

    
    clipboard->setText(inviteCode);
}
QString HostRoom::GenerateRandomCode()
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = 8; // For example, a code with 8 characters

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
    AppWindow::ChangeWidget(ScribbleWindow::WindowIndex);
}

void HostRoom::OnGenerateCodeButtonClicked()
{
    QString inviteCode = GenerateRandomCode();
    ui.InviteCode->setText(inviteCode);
}

