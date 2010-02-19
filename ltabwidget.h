#ifndef LTABWIDGET_H
#define LTABWIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <QGridLayout>
#include <QWebHistoryInterface>

#include "LProxy.h"
#include "LWebPage.h"

class LTabWidget : public QWidget
{
    Q_OBJECT

private:
    QGridLayout *layout;
    QTabWidget  *tab;

public:
    LTabWidget(QWidget *parent = 0);
};

#endif // LTABWIDGET_H
