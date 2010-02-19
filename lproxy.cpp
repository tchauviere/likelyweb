#include "lproxy.h"

LProxy::LProxy(QWidget *parent) : QWidget(parent)
{
    this->layout    = new QGridLayout();
    this->proxyAuto = new QCheckBox(tr("Configuration manuelle du proxy"), this);
    this->proxyManu = new QCheckBox(tr("Deection automatique des parametres de proxy de ce reseau"), this);
    this->proxyNone = new QCheckBox(tr("Pas de proxy"), this);
    this->portFtp   = new QSpinBox(this);
    this->portHttp  = new QSpinBox(this);
    this->portSsl   = new QSpinBox(this);
    this->proxyFtp  = new QLineEdit(this);
    this->proxyHttp = new QLineEdit(this);
    this->proxySsl  = new QLineEdit(this);

    QLabel *lblFtp  = new QLabel(tr("Proxy Ftp : "), this);
    QLabel *lblHttp = new QLabel(tr("Proxy Http : "), this);;
    QLabel *lblSsl  = new QLabel(tr("Proxy Ssl : "), this);;

    this->layout->addWidget(this->proxyNone, 0, 0, 1, 2);
    this->layout->addWidget(this->proxyAuto, 1, 0, 1, 2);
    this->layout->addWidget(this->proxyManu, 2, 0, 1, 2);

    this->layout->addWidget(lblHttp, 3, 0);
    this->layout->addWidget(this->proxyHttp, 3, 1);
    this->layout->addWidget(this->portHttp, 3, 2);

    this->layout->addWidget(lblFtp, 4, 0);
    this->layout->addWidget(this->proxyFtp, 4, 1);
    this->layout->addWidget(this->portFtp, 4, 2);

    this->layout->addWidget(lblSsl, 5, 0);
    this->layout->addWidget(this->proxySsl, 5, 1);
    this->layout->addWidget(this->portSsl, 5, 2);

    this->setLayout(this->layout);
}
