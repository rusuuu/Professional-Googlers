#include "GarticFrontend.h"
#include <QtWidgets/QApplication>
#include <QStackedWidget>
#include "LoginWindow.h"
#include "RegisterWindow.h"
#include "MainMenuWindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   
    LoginWindow* m_loginWindow = new LoginWindow();
    RegisterWindow* m_registerWindow = new RegisterWindow();
    MainMenuWindow* m_mainMenu = new MainMenuWindow();
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

    m_mainMenu->show();

    
    return a.exec();
}
