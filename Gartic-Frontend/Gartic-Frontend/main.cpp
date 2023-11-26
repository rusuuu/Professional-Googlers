#include "GarticFrontend.h"
#include <QtWidgets/QApplication>

#include <QPropertyAnimation>



int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    GarticFrontend* garticFrontend = new GarticFrontend();

    return a.exec();
}
