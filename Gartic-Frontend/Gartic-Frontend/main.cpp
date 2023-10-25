#include "GarticFrontend.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GarticFrontend w;
    w.show();
    return a.exec();
}
