#ifndef LTABWIDGET_H
#define LTABWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QWebHistoryInterface>
#include <QMultiHash>

#include "TabWidgetDrag.h"
#include "LProxy.h"
#include "LWebPage.h"


class LTabWidget : public QWidget
{
    Q_OBJECT

private:
    QGridLayout *layout;
    TabWidgetDrag  *tab;

public:
    LTabWidget(QWidget *parent = 0);
    void creatNewTab();
    void removeTab();
};

#endif // LTABWIDGET_H
