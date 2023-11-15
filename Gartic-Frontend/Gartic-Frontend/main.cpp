#include "GarticFrontend.h"
#include <QtWidgets/QApplication>
#include <QStackedWidget>
#include "LoginWindow.h"
#include "RegisterWindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   
    LoginWindow* loginWindow = new LoginWindow();
    RegisterWindow* registerWindow = new RegisterWindow();
    QStackedWidget stackedWidget;

    QObject::connect(loginWindow, &LoginWindow::showRegisterWindow, [loginWindow, registerWindow]() 
        {
        registerWindow->show();
        loginWindow->hide();
        });

    QObject::connect(registerWindow, &RegisterWindow::ShowLoginWindow, [loginWindow, registerWindow]() 
        {
        loginWindow->show();
        registerWindow->hide();
        });

    loginWindow->show();

    return a.exec();
}
