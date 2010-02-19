#ifndef LWINDOW_H
#define LWINDOW_H

#include <QtGui/QWidget>
#include <QGridLayout>

#include "LTabWidget.h"

class LWindow : public QWidget
{
    Q_OBJECT

private:
    QGridLayout *layout;
    LTabWidget  *tab;

public:
    LWindow(QWidget *parent = 0);
    ~LWindow();
};

#endif // LWINDOW_H
