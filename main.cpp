#include <QtGui/QApplication>
#include "LWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LWindow w;
    w.show();
    return a.exec();
}
