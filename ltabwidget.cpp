#include "ltabwidget.h"

LTabWidget::LTabWidget(QWidget *parent) : QWidget(parent)
{
    this->layout    = new QGridLayout();
    this->dlManager = new LDlManage(this);
    this->tab       = new TabWidgetDrag(this);

    this->tab->addTab(this->dlManager, "Download");

    this->connect(this->tab, SIGNAL(tabCloseRequested(int)), this, SLOT(slotCloseTab(int)));
    this->connect(this->tab, SIGNAL(currentChanged(int)), this, SLOT(slotWidgetChange(int)));

    this->tab->setTabsClosable(true);
    this->tab->setUsesScrollButtons(true);

    LProxy *proxy = new LProxy(this);
    this->tab->addTab(proxy, "proxy");

    this->layout->setSpacing(0);
    this->layout->setMargin(0);

    this->tab->setMovable(false);
    this->tab->setAcceptDrops(true);

    this->creatNewTab(QUrl(""));

    this->layout->addWidget(this->tab, 1, 0);

    this->setLayout(this->layout);
}

void LTabWidget::slotOpenLinkInNewTab(QUrl url)
{
    this->creatNewTab(url);
}

void LTabWidget::slotGetItemDl(itemDl *dl)
{
    this->dlManager->addNewItem(dl);
}

void LTabWidget::slotWidgetChange(int index)
{
    this->widgetPage = this->tab->widget(index);
    this->currentPage = (LWebPage*)this->widgetPage;
}

LWebPage  *LTabWidget::getCurrentPage()
{
    return this->currentPage;
}

void LTabWidget::creatNewTab(QUrl url)
{
    LWebPage *newPage = new LWebPage(this);

    this->connect(newPage, SIGNAL(sigOpenLinkInNewTab(QUrl)), this, SLOT(slotOpenLinkInNewTab(QUrl)));
    this->connect(newPage, SIGNAL(sigTitleChange(QString, QWidget*)), this, SLOT(slotTitleChange(QString,QWidget*)));
    this->connect(newPage, SIGNAL(sigSendIcon(QIcon, QWidget *)), this, SLOT(slotIconChange(QIcon, QWidget*)));
    this->connect(newPage, SIGNAL(sigSendItemDl(itemDl*)), this, SLOT(slotGetItemDl(itemDl*)));

    newPage->focusWidget();

    int index = this->tab->addTab(newPage, "Sans titre");
    if (this->tab->count() > 1)
        this->tab->setMovable(true);
    if (url.isValid())
        newPage->setUrl(url);
    this->tab->setCurrentIndex(index);
}

void LTabWidget::slotIconChange(QIcon icon, QWidget *parent)
{
    int a = this->tab->indexOf(parent);
    if (icon.isNull())
        this->tab->setTabIcon(a, QIcon(":lw"));
    else
        this->tab->setTabIcon(a, icon);
}

void LTabWidget::slotAffProxy()
{
    if (!this->proxy)
    {
        this->proxy = new LProxy(this);
        this->connect(this->proxy, SIGNAL(sigCloseProxy(QWidget *)), this, SLOT(slotCloseOptWindow(QWidget*)));
        this->tab->addTab(this->proxy, "Proxy");
    }
}

void LTabWidget::slotTitleChange(QString title, QWidget *parent)
{
    int a = this->tab->indexOf(parent);
    this->tab->setTabToolTip(a, title);
    this->tab->setTabText(a, title);
}

void LTabWidget::slotCloseOptWindow(QWidget *parent)
{
    int a = this->tab->indexOf(parent);
    this->tab->removeTab(a);
}

void LTabWidget::slotCloseTab(int index)
{
    this->tab->removeTab(index);
    if (tab->count() == 0)
        this->window()->close();
    if (this->tab->count() == 1)
        this->tab->setMovable(false);
    this->tab->addTab(this->dlManager, "Download");
}

void LTabWidget::removeTab()
{
    if (this->tab->count() > 1)
        this->tab->removeTab(this->tab->currentIndex());
    else
        this->window()->close();
    if (this->tab->count() == 1)
        this->tab->setMovable(false);
}
