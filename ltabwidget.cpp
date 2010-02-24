#include "ltabwidget.h"

LTabWidget::LTabWidget(QWidget *parent) : QWidget(parent)
{
    this->layout = new QGridLayout();
    this->tab = new QTabWidget(this);

    this->tab->setTabsClosable(true);
    this->layout->setSpacing(0);
    this->layout->setMargin(0);

    this->tab->setMovable(true);
    this->tab->setAcceptDrops(true);
    this->tab->setDocumentMode(true);

    LWebPage *page  = new LWebPage(this);
//    LWebPage *page1 = new LWebPage(this);
 //   LWebPage *page2 = new LWebPage(this);
    LProxy *proxy   = new LProxy(this);

    this->tab->setTabShape(QTabWidget::Triangular);
    this->tab->addTab(page, "lol");
    this->tab->addTab(proxy, "Proxy");
   //  this->tab->addTab(page1, "lol");
  //  this->tab->addTab(page2, "lol");

    this->layout->addWidget(this->tab, 1, 0);

    this->setLayout(this->layout);
}
