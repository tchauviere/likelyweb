#include "ltabwidget.h"

LTabWidget::LTabWidget(QWidget *parent) : QWidget(parent)
{
    this->layout = new QGridLayout();
    this->tab = new TabWidgetDrag(this);
    LWebPage *page  = new LWebPage(this);

    this->tab->setTabsClosable(true);
    this->layout->setSpacing(0);
    this->layout->setMargin(0);

    this->tab->setMovable(true);
    this->tab->setAcceptDrops(true);
    this->tab->setDocumentMode(true);

    this->tab->setTabShape(QTabWidget::Triangular);
    this->tab->addTab(page, "New Tab");

    this->layout->addWidget(this->tab, 1, 0);

    this->setLayout(this->layout);
}

void LTabWidget::creatNewTab()
{
    LWebPage *newPage = new LWebPage(this);

    int index = this->tab->addTab(newPage, "New Tab");
    this->tab->setCurrentIndex(index);
}

void LTabWidget::removeTab()
{
    if (this->tab->count() > 1)
        this->tab->removeTab(this->tab->currentIndex());
    else
        this->window()->close();
}
