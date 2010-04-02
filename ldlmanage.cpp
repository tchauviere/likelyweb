#include "ldlmanage.h"
#include "itemdl.h"
#include "ui_ldlmanage.h"

#include <QDebug>
#include <QWidget>
#include <QScrollBar>

LDlManage::LDlManage(QWidget *parent) : QWidget(parent), ui(new Ui::LDlManage)
{
    this->boxWidget =   new QWidget(this);
    this->boxLayout =   new QVBoxLayout();
    this->count     =   0;

    this->ui->setupUi(this);
    this->ui->clearList->connect(this->ui->clearList, SIGNAL(clicked()), this, SLOT(slotClearDdl()));

    this->boxWidget->setLayout(this->boxLayout);
    this->ui->scrollArea->setWidget(this->boxWidget);
}

void LDlManage::addNewItem(itemDl *dl)
{
    if (count % 2 > 0)
        this->boxLayout->addWidget(dl, NULL, Qt::AlignCenter);
    count += 1;
}

LDlManage::~LDlManage()
{
    delete ui;
}

void LDlManage::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void    LDlManage::slotClearDdl()
{
 /*   this->boxLayout->removeWidget(this->boxWidget);
    delete this->boxWidget;
    this->boxWidget =   new QWidget(this);
    this->boxLayout =   new QVBoxLayout();
    this->boxWidget->setLayout(this->boxLayout);
*/
}
