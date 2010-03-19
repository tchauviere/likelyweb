#ifndef LTABWIDGET_H
#define LTABWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QWebHistoryInterface>
#include <QMultiHash>
#include <QPropertyAnimation>

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
    void creatNewTab(QUrl url);
    void removeTab();

private slots:
    void slotTitleChange(QString title, QWidget *parent);
    void slotCloseTab(int index);
    void slotOpenLinkInNewTab(QUrl url);
    void slotIconChange(QIcon icon, QWidget *parent);
};

#endif // LTABWIDGET_H
