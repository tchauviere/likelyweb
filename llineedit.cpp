#include "llineedit.h"

LLineEdit::LLineEdit(QWidget *parent) : QProgressBar(parent)
{
    this->layout = new QHBoxLayout(this);

    this->champs = new QLineEdit(this);

    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    layout->setSpacing(0);
    layout->setMargin(0);

    this->connect(this->champs, SIGNAL(returnPressed()), this, SLOT(slotChampsReturnPressed()));

    this->champs->setStyleSheet("background: transparent");

    layout->addWidget(this->champs);

    this->setLayout(layout);
}

#include <QDebug>
#include <QPushButton>
void LLineEdit::setIcon(QIcon icon)
{
    qDebug() << icon.cacheKey();
    qDebug() << "ICON:" << icon;
}

void LLineEdit::slotChampsReturnPressed()
{
   emit this->sigReturnPressed(this->champs->text());
}

void LLineEdit::setChampsText(QString url)
{
    this->champs->setText(url);
    this->champs->home(false);
}

void LLineEdit::loadStart()
{
    this->setVisible(true);
}

void LLineEdit::loadProgress(int progress)
{
    this->setValue(progress);
}

void LLineEdit::loadFinish()
{
    this->setValue(0);
}
