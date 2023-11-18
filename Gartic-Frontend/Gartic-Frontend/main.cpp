#include "GarticFrontend.h"
#include <QtWidgets/QApplication>
#include <QStackedWidget>
#include "LoginWindow.h"
#include "RegisterWindow.h"
#include "MainMenuWindow.h"
#include "HostRoom.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   
    LoginWindow* m_loginWindow = new LoginWindow();
    RegisterWindow* m_registerWindow = new RegisterWindow();
    MainMenuWindow* m_mainMenu = new MainMenuWindow();
    HostRoom* m_hostRoom = new HostRoom();
    QStackedWidget stackedWidget;

    QObject::connect(m_loginWindow, &LoginWindow::showRegisterWindow, [m_loginWindow, m_registerWindow]() 
        {
        m_registerWindow->show();
        m_loginWindow->hide();
        });

    QObject::connect(m_registerWindow, &RegisterWindow::ShowLoginWindow, [m_loginWindow, m_registerWindow]() 
        {
        m_loginWindow->show();
        m_registerWindow->hide();
        });

    QObject::connect(m_mainMenu, &MainMenuWindow::showHostRoomWindow, [m_mainMenu, m_hostRoom]()
        {
            m_hostRoom->show();
            m_mainMenu->hide();
        });

    QObject::connect(m_hostRoom, &HostRoom::ShowMainMenuWindow, [m_hostRoom, m_mainMenu]()
        {
            m_mainMenu->show();
            m_hostRoom->hide();
        });

    m_loginWindow->show();

    
    return a.exec();
}
