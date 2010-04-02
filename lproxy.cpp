#include "lproxy.h"

LProxy::LProxy(QWidget *parent) : QWidget(parent)
{
    this->layout        = new QGridLayout();
    this->groupLayout   = new QGridLayout();
    this->groupBox      = new QGroupBox(tr("Reglages Proxy"), this);
    this->proxyAuto     = new QRadioButton(tr("Detection automatique des parametres de proxy"), this);
    this->proxyManu     = new QRadioButton(tr("Configuration manuelle du proxy"), this);
    this->proxyNone     = new QRadioButton(tr("Pas de proxy"), this);
    this->portFtp       = new QSpinBox(this);
    this->portHttp      = new QSpinBox(this);
    this->portSsl       = new QSpinBox(this);
    this->proxyFtp      = new QLineEdit(this);
    this->proxyHttp     = new QLineEdit(this);
    this->proxySsl      = new QLineEdit(this);
    this->validProxy    = new QPushButton(this);
    this->quitProxy     = new QPushButton(this);
    this->infoProxy     = new QSettings("Proxy", "LikelyWeb", this);

    QLabel *lblFtp      = new QLabel(tr("Proxy Ftp : "), this);
    QLabel *lblHttp     = new QLabel(tr("Proxy Http : "), this);;
    QLabel *lblSsl      = new QLabel(tr("Proxy Ssl : "), this);;

    this->proxyNone->setChecked(true);
    this->disableItem(true);

    this->portFtp->setMaximum(99999);
    this->portHttp->setMaximum(99999);
    this->portSsl->setMaximum(99999);

    this->setSettings();

    this->connect(this->proxyNone, SIGNAL(clicked(bool)), this, SLOT(slotProxyNone(bool)));
    this->connect(this->proxyAuto, SIGNAL(clicked(bool)), this, SLOT(slotProxyAuto(bool)));
    this->connect(this->proxyManu, SIGNAL(clicked(bool)), this, SLOT(slotProxyManu(bool)));

    this->connect(this->validProxy, SIGNAL(clicked()), this, SLOT(slotValide()));
    this->connect(this->quitProxy, SIGNAL(clicked()), this, SLOT(slotClose()));


    this->validProxy->setText(tr("Valider"));
    this->quitProxy->setText(tr("Fermer"));

    this->portFtp->setFixedWidth(60);
    this->portHttp->setFixedWidth(60);
    this->portSsl->setFixedWidth(60);

    this->groupBox->setFixedHeight(350);
    this->groupBox->setFixedWidth(450);
    this->groupBox->setLayout(this->groupLayout);

    this->layout->addWidget(this->groupBox, 0, 0);

    this->groupLayout->addWidget(this->proxyNone, 0, 0, 1, 2);
    this->groupLayout->addWidget(this->proxyAuto, 1, 0, 1, 2);
    this->groupLayout->addWidget(this->proxyManu, 2, 0, 1, 2);


    this->groupLayout->addWidget(lblHttp, 3, 0);
    this->groupLayout->addWidget(this->proxyHttp, 3, 1);
    this->groupLayout->addWidget(this->portHttp, 3, 2);

    this->groupLayout->addWidget(lblFtp, 4, 0);
    this->groupLayout->addWidget(this->proxyFtp, 4, 1);
    this->groupLayout->addWidget(this->portFtp, 4, 2);

    this->groupLayout->addWidget(lblSsl, 5, 0);
    this->groupLayout->addWidget(this->proxySsl, 5, 1);
    this->groupLayout->addWidget(this->portSsl, 5, 2);

    this->groupLayout->addWidget(this->validProxy, 6, 1, Qt::AlignRight);
    this->groupLayout->addWidget(this->quitProxy, 6, 1, Qt::AlignLeft);

    this->setLayout(this->layout);
}

void LProxy::disableItem(bool a)
{
    if (a == true)
    {
        this->portFtp->setDisabled(true);
        this->portHttp->setDisabled(true);
        this->portSsl->setDisabled(true);
        this->proxyFtp->setDisabled(true);
        this->proxyHttp->setDisabled(true);
        this->proxySsl->setDisabled(true);
    }
    else
    {
        this->portFtp->setDisabled(false);
        this->portHttp->setDisabled(false);
        this->portSsl->setDisabled(false);
        this->proxyFtp->setDisabled(false);
        this->proxyHttp->setDisabled(false);
        this->proxySsl->setDisabled(false);
    }
}

void LProxy::slotProxyAuto(bool a)
{
    if (a == true)
        this->disableItem(true);
    else
        this->disableItem(false);
}

void LProxy::slotProxyManu(bool a)
{
    if (a == true)
        this->disableItem(false);
}

void LProxy::slotProxyNone(bool a)
{
    if (a == true)
        this->disableItem(true);
    else
        this->disableItem(false);

}

void LProxy::setSettings()
{
    this->proxyNone->setChecked(this->infoProxy->value("proxy_none").toBool());
    this->proxyAuto->setChecked(this->infoProxy->value("proxy_auto").toBool());
    this->proxyManu->setChecked(this->infoProxy->value("proxy_manu").toBool());

    if (this->proxyManu->isChecked() == true)
        this->disableItem(false);

    this->proxyHttp->setText(this->infoProxy->value("addr_proxy_http").toString());
    this->portHttp->setValue(this->infoProxy->value("port_proxy_http").toInt());

    this->proxyFtp->setText(this->infoProxy->value("addr_proxy_ftp").toString());
    this->portFtp->setValue(this->infoProxy->value("port_proxy_ftp").toInt());

    this->proxySsl->setText(this->infoProxy->value("addr_proxy_ssl").toString());
    this->portSsl->setValue(this->infoProxy->value("port_proxy_ssl").toInt());
}

void LProxy::slotValide()
{
    this->infoProxy->setValue("proxy_none", this->proxyNone->isChecked());
    this->infoProxy->setValue("proxy_auto", this->proxyAuto->isChecked());
    this->infoProxy->setValue("proxy_manu", this->proxyManu->isChecked());

    this->infoProxy->setValue("addr_proxy_http", this->proxyHttp->text());
    this->infoProxy->setValue("port_proxy_http", this->portHttp->value());

    this->infoProxy->setValue("addr_proxy_ftp", this->proxyFtp->text());
    this->infoProxy->setValue("port_proxy_ftp", this->portFtp->value());

    this->infoProxy->setValue("addr_proxy_ssl", this->proxySsl->text());
    this->infoProxy->setValue("port_proxy_ssl", this->portSsl->value());

    this->slotClose();
}

void LProxy::slotClose()
{
    emit this->sigCloseProxy(this);
}
