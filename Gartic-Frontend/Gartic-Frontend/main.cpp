#include "GarticFrontend.h"
#include <QtWidgets/QApplication>
#include "LoginWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return a.exec();
}
