#include <QtGui/QApplication>
#include <QFile>
#include <QTextStream>
#include "LWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setEffectEnabled(Qt::UI_AnimateMenu, true);
    a.setEffectEnabled(Qt::UI_FadeMenu, true);
    a.setEffectEnabled(Qt::UI_General, true);

    QFile file(":style");
    file.open(QIODevice::ReadOnly);
    QTextStream out(&file);

    LWindow w;

    qApp->setStyleSheet(out.readAll());
    w.show();
    return a.exec();
}
