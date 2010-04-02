#include "itemdl.h"
#include "ui_itemdl.h"

itemDl::itemDl(QWidget *parent) : QWidget(parent), ui(new Ui::itemDl)
{
    this->ui->setupUi(this);
    this->connect(ui->stopDl, SIGNAL(clicked()), this, SLOT(slotStopDl()));
}

itemDl::~itemDl()
{
    delete ui;
}

void itemDl::setReply(QNetworkReply *reply)
{
    this->reply = reply;
}

void itemDl::slotSetText(QString text, QString url)
{
    this->ui->label_2->setText(url);
    this->ui->label_2->setOpenExternalLinks(true);
    this->ui->label->setOpenExternalLinks(true);
    this->ui->label->setText(text);
}

void itemDl::slotStopDl()
{
    this->reply->abort();
}

void itemDl::setIconFile(QIcon icon)
{
    this->ui->icoDl->setPixmap(icon.pixmap(QSize(40, 40)));
}

void itemDl::slotSetProgress(qint64 current,qint64 total)
{
    this->ui->progressDl->setRange(0, total);
    this->ui->progressDl->setValue(current);
}


void itemDl::changeEvent(QEvent *e)
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
