#include "GarticFrontend.h"
#include <QtWidgets/QApplication>

#include <QPropertyAnimation>

#include "LoginWindow.h"
#include "RegisterWindow.h"
#include "MainMenuWindow.h"
#include "HostRoom.h"


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    LoginWindow* loginWindow = new LoginWindow();
    RegisterWindow* registerWindow = new RegisterWindow();
    MainMenuWindow* mainMenuWindow = new MainMenuWindow();  // Create an instance of MainMenuWindow

    // Connect LoginWindow to show theRegisterWindow
    QObject::connect(loginWindow, &LoginWindow::ShowRegisterWindow, [=]() {
        QPropertyAnimation* fadeOut = new QPropertyAnimation(loginWindow, "windowOpacity");
        fadeOut->setStartValue(1.0);
        fadeOut->setEndValue(0.0);
        fadeOut->setDuration(500);
        fadeOut->start(QPropertyAnimation::DeleteWhenStopped);

        QPropertyAnimation* fadeIn = new QPropertyAnimation(registerWindow, "windowOpacity");
        fadeIn->setStartValue(0.0);
        fadeIn->setEndValue(1.0);
        fadeIn->setDuration(500);
        QObject::connect(fadeOut, &QPropertyAnimation::finished, [=]() {
            loginWindow->hide();
            registerWindow->show();
            fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
            });
        fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
        });

    // Connect RegisterWindow to show the LoginWindow
    QObject::connect(registerWindow, &RegisterWindow::ShowLoginWindow, [=]() {
        QPropertyAnimation* fadeOut = new QPropertyAnimation(registerWindow, "windowOpacity");
        fadeOut->setStartValue(1.0);
        fadeOut->setEndValue(0.0);
        fadeOut->setDuration(500);
        fadeOut->start(QPropertyAnimation::DeleteWhenStopped);

        QPropertyAnimation* fadeIn = new QPropertyAnimation(loginWindow, "windowOpacity");
        fadeIn->setStartValue(0.0);
        fadeIn->setEndValue(1.0);
        fadeIn->setDuration(500);
        QObject::connect(fadeOut, &QPropertyAnimation::finished, [=]() {
            registerWindow->hide();
            loginWindow->show();
            fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
            });
        fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
        });

    // Connect successful login to show the MainMenuWindow
    QObject::connect(loginWindow, &LoginWindow::LoginSuccessful, [=]() {
        QPropertyAnimation* fadeOut = new QPropertyAnimation(loginWindow, "windowOpacity");
        fadeOut->setStartValue(1.0);
        fadeOut->setEndValue(0.0);
        fadeOut->setDuration(500);
        fadeOut->start(QPropertyAnimation::DeleteWhenStopped);

        QPropertyAnimation* fadeIn = new QPropertyAnimation(mainMenuWindow, "windowOpacity");
        fadeIn->setStartValue(0.0);
        fadeIn->setEndValue(1.0);
        fadeIn->setDuration(500);
        QObject::connect(fadeOut, &QPropertyAnimation::finished, [=]() {
            loginWindow->hide();
            mainMenuWindow->show();
            fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
            });
        fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
        });

    // Show the initial login window
    loginWindow->show();

    return a.exec();



    /*QApplication a(argc, argv);

    LoginWindow* m_loginWindow = new LoginWindow();
    RegisterWindow* m_registerWindow = new RegisterWindow();
    MainMenuWindow* m_mainMenu = new MainMenuWindow();
    HostRoom* m_hostRoom = new HostRoom();
    QStackedWidget stackedWidget;

    

    stackedWidget.addWidget(m_loginWindow);
    stackedWidget.addWidget(m_registerWindow);
    stackedWidget.addWidget(m_mainMenu);
    stackedWidget.addWidget(m_hostRoom);

  
    QObject::connect(m_loginWindow, &LoginWindow::ShowRegisterWindow, [&]()
        {
            stackedWidget.setCurrentWidget(m_registerWindow);
        });

    QObject::connect(m_registerWindow, &RegisterWindow::ShowLoginWindow, [&]()
        {
            stackedWidget.setCurrentWidget(m_loginWindow);
        });

    QObject::connect(m_mainMenu, &MainMenuWindow::ShowHostRoomWindow, [&]()
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

    return a.exec();*/
}
