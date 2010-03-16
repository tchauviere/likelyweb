#include "ltabwidget.h"

LTabWidget::LTabWidget(QWidget *parent) : QWidget(parent)
{
    this->layout    = new QGridLayout();
    this->tab       = new TabWidgetDrag(this);
    LWebPage *page  = new LWebPage(this);

    //LProxy *proxy = new LProxy(this);
    //    tab->addTab(proxy, "Proxy");

    this->connect(this->tab, SIGNAL(tabCloseRequested(int)), this, SLOT(slotCloseTab(int)));
    this->connect(page, SIGNAL(sigOpenLinkInNewTab(QUrl)), this, SLOT(slotOpenLinkInNewTab(QUrl)));

    this->tab->setTabsClosable(true);
    this->tab->setUsesScrollButtons(true);

    this->layout->setSpacing(0);
    this->layout->setMargin(0);

    this->tab->setMovable(false);
    this->tab->setAcceptDrops(true);

    page->focusWidget();

    this->tab->addTab(page, "New Tab");

    this->layout->addWidget(this->tab, 1, 0);

    this->setLayout(this->layout);
}

void LTabWidget::slotOpenLinkInNewTab(QUrl url)
{
    LWebPage *newPage = new LWebPage(this);

    this->connect(newPage, SIGNAL(sigOpenLinkInNewTab(QUrl)), this, SLOT(slotOpenLinkInNewTab(QUrl)));

    newPage->setUrl(url.toString());

    int index = this->tab->addTab(newPage, "New Tab");
    this->tab->setCurrentIndex(index);
}

void LTabWidget::creatNewTab()
{
    LWebPage *newPage = new LWebPage(this);

    this->connect(newPage, SIGNAL(sigOpenLinkInNewTab(QUrl)), this, SLOT(slotOpenLinkInNewTab(QUrl)));

    int index = this->tab->addTab(newPage, "New Tab");
    if (this->tab->count() > 1)
        this->tab->setMovable(true);
    this->tab->setCurrentIndex(index);
}

void LTabWidget::slotCloseTab(int index)
{
    this->tab->removeTab(index);
    if (tab->count() == 0)
        this->window()->close();
    if (this->tab->count() == 1)
        this->tab->setMovable(false);
}

void LTabWidget::removeTab()
{
    if (this->tab->count() > 1)
        this->tab->removeTab(this->tab->currentIndex());
    else
        this->window()->close();
    if(this->tab->count() == 1)
        this->tab->setMovable(false);
}
