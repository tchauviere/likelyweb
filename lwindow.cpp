#include "lwindow.h"

LWindow::LWindow(QWidget *parent) : QWidget(parent)
{
    this->layout = new QGridLayout();
    this->tab    = new LTabWidget(this);

    this->layout->setSpacing(0);
    this->layout->setMargin(0);

    this->layout->addWidget(this->tab, 0, 0);

    this->setLayout(this->layout);
}

LWindow::~LWindow()
{

}
