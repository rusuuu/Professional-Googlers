#include "GarticFrontend.h"


GarticFrontend::GarticFrontend(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Create instances of Windows
    LoginWindow* loginWindow = new LoginWindow();
    RegisterWindow* registerWindow = new RegisterWindow();
    MainMenuWindow* mainMenuWindow = new MainMenuWindow();
    HostRoom* hostRoomWindow = new HostRoom();
    ProfileUserWindow* profileUserWindow = new ProfileUserWindow();

    // Connect LoginWindow to show theRegisterWindow
    QObject::connect(loginWindow, &LoginWindow::ShowRegisterWindow, [=]() {
        QPropertyAnimation* fadeOut = new QPropertyAnimation(loginWindow, "windowOpacity");
        fadeOut->setStartValue(1.0);
        fadeOut->setEndValue(0.0);
        fadeOut->setDuration(100);
        fadeOut->start(QPropertyAnimation::DeleteWhenStopped);

        QPropertyAnimation* fadeIn = new QPropertyAnimation(registerWindow, "windowOpacity");
        fadeIn->setStartValue(0.0);
        fadeIn->setEndValue(1.0);
        fadeIn->setDuration(100);
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
        fadeOut->setDuration(100);
        fadeOut->start(QPropertyAnimation::DeleteWhenStopped);

        QPropertyAnimation* fadeIn = new QPropertyAnimation(loginWindow, "windowOpacity");
        fadeIn->setStartValue(0.0);
        fadeIn->setEndValue(1.0);
        fadeIn->setDuration(100);
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
        fadeOut->setDuration(100);
        fadeOut->start(QPropertyAnimation::DeleteWhenStopped);

        QPropertyAnimation* fadeIn = new QPropertyAnimation(mainMenuWindow, "windowOpacity");
        fadeIn->setStartValue(0.0);
        fadeIn->setEndValue(1.0);
        fadeIn->setDuration(100);
        QObject::connect(fadeOut, &QPropertyAnimation::finished, [=]() {
            loginWindow->hide();
            mainMenuWindow->show();
            fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
            });
        fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
        });

    // Connect MainMenuWindow to show HostRoom
    QObject::connect(mainMenuWindow, &MainMenuWindow::ShowHostRoomWindow, [=]() {
        QPropertyAnimation* fadeOut = new QPropertyAnimation(mainMenuWindow, "windowOpacity");
        fadeOut->setStartValue(1.0);
        fadeOut->setEndValue(0.0);
        fadeOut->setDuration(100);
        fadeOut->start(QPropertyAnimation::DeleteWhenStopped);

        QPropertyAnimation* fadeIn = new QPropertyAnimation(hostRoomWindow, "windowOpacity");
        fadeIn->setStartValue(0.0);
        fadeIn->setEndValue(1.0);
        fadeIn->setDuration(100);
        QObject::connect(fadeOut, &QPropertyAnimation::finished, [=]() {
            mainMenuWindow->hide();
            hostRoomWindow->show();
            fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
            });
        fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
        });

    // Connect MainMenuWindow to show ProfileUserWindow
    QObject::connect(mainMenuWindow, &MainMenuWindow::ShowProfileUserWindow, [=]() {
        QPropertyAnimation* fadeOut = new QPropertyAnimation(mainMenuWindow, "windowOpacity");
        fadeOut->setStartValue(1.0);
        fadeOut->setEndValue(0.0);
        fadeOut->setDuration(100);
        fadeOut->start(QPropertyAnimation::DeleteWhenStopped);

        QPropertyAnimation* fadeIn = new QPropertyAnimation(profileUserWindow, "windowOpacity");
        fadeIn->setStartValue(0.0);
        fadeIn->setEndValue(1.0);
        fadeIn->setDuration(100);
        QObject::connect(fadeOut, &QPropertyAnimation::finished, [=]() {
            mainMenuWindow->hide();
            profileUserWindow->show();
            fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
            });
        fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
        });

    // Connect HostRoom to show MainMenuWindow
    QObject::connect(hostRoomWindow, &HostRoom::ShowMainMenuWindow, [=]() {
        QPropertyAnimation* fadeOut = new QPropertyAnimation(hostRoomWindow, "windowOpacity");
        fadeOut->setStartValue(1.0);
        fadeOut->setEndValue(0.0);
        fadeOut->setDuration(100);
        fadeOut->start(QPropertyAnimation::DeleteWhenStopped);

        QPropertyAnimation* fadeIn = new QPropertyAnimation(mainMenuWindow, "windowOpacity");
        fadeIn->setStartValue(0.0);
        fadeIn->setEndValue(1.0);
        fadeIn->setDuration(100);
        QObject::connect(fadeOut, &QPropertyAnimation::finished, [=]() {
            hostRoomWindow->hide();
            mainMenuWindow->show();
            fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
            });
        fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
        });

    // Connect ProfileUserWindow to show MainWindow
    QObject::connect(profileUserWindow, &ProfileUserWindow::ShowMainMenuWindow, [=]() {
        QPropertyAnimation* fadeOut = new QPropertyAnimation(profileUserWindow, "windowOpacity");
        fadeOut->setStartValue(1.0);
        fadeOut->setEndValue(0.0);
        fadeOut->setDuration(100);
        fadeOut->start(QPropertyAnimation::DeleteWhenStopped);

        QPropertyAnimation* fadeIn = new QPropertyAnimation(mainMenuWindow, "windowOpacity");
        fadeIn->setStartValue(0.0);
        fadeIn->setEndValue(1.0);
        fadeIn->setDuration(100);
        QObject::connect(fadeOut, &QPropertyAnimation::finished, [=]() {
            profileUserWindow->hide();
            mainMenuWindow->show();
            fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
            });
        fadeIn->start(QPropertyAnimation::DeleteWhenStopped);
        });

    // Show the initial login window
    loginWindow->show();
}

GarticFrontend::~GarticFrontend()
{}
