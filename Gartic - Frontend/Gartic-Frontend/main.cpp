#include "AppWindow.h"
#include <QtWidgets/QApplication>

#include <QPropertyAnimation>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    AppWindow* garticFrontend = new AppWindow();
    garticFrontend->show();

    a.setActiveWindow(garticFrontend);
    return a.exec();
}
