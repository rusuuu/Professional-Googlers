#include "GarticFrontend.h"
#include <QtWidgets/QApplication>
#include <QStackedWidget>
#include "LoginWindow.h"
#include "RegisterWindow.h"
#include "MainMenuWindow.h"
#include "HostRoom.h"



int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    LoginWindow* m_loginWindow = new LoginWindow();
    RegisterWindow* m_registerWindow = new RegisterWindow();
    MainMenuWindow* m_mainMenu = new MainMenuWindow();
    HostRoom* m_hostRoom = new HostRoom();
    QStackedWidget stackedWidget;

    

    stackedWidget.addWidget(m_loginWindow);
    stackedWidget.addWidget(m_registerWindow);
    stackedWidget.addWidget(m_mainMenu);
    stackedWidget.addWidget(m_hostRoom);

  
    QObject::connect(m_loginWindow, &LoginWindow::showRegisterWindow, [&]()
        {
            stackedWidget.setCurrentWidget(m_registerWindow);
        });

    QObject::connect(m_registerWindow, &RegisterWindow::ShowLoginWindow, [&]()
        {
            stackedWidget.setCurrentWidget(m_loginWindow);
        });

    QObject::connect(m_mainMenu, &MainMenuWindow::showHostRoomWindow, [&]()
        {
            stackedWidget.setCurrentWidget(m_hostRoom);
        });

    QObject::connect(m_hostRoom, &HostRoom::ShowMainMenuWindow, [&]()
        {
            stackedWidget.setCurrentWidget(m_mainMenu);
        });
    
    QObject::connect(m_loginWindow, &LoginWindow::LoginSuccessful, [m_mainMenu]() 
        {
            m_mainMenu->show();
        });

    stackedWidget.setCurrentWidget(m_loginWindow);
    stackedWidget.show();

    return a.exec();
}
