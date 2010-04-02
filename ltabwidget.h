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
#include "LDlManage.h"

class LTabWidget : public QWidget
{
    Q_OBJECT

private:
    QGridLayout *layout;
    TabWidgetDrag  *tab;
    LProxy *proxy;
    QWidget *widgetPage;
    LWebPage *currentPage;
    LDlManage *dlManager;

public:
    LTabWidget(QWidget *parent = 0);
    void creatNewTab(QUrl url);
    void removeTab();

public slots:
    LWebPage *getCurrentPage();

private slots:
    void slotGetItemDl(itemDl *dl);
    void slotAffProxy();
    void slotWidgetChange(int index);
    void slotCloseOptWindow(QWidget *parent);
    void slotTitleChange(QString title, QWidget *parent);
    void slotCloseTab(int index);
    void slotOpenLinkInNewTab(QUrl url);
    void slotIconChange(QIcon icon, QWidget *parent);
};

#endif // LTABWIDGET_H
