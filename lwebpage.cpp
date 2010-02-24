#include "lwebpage.h"

LWebPage::LWebPage(QWidget *parent) : QWidget(parent)
{
    this->proxyInfo = new QSettings("Proxy", "LikelyWeb", this);
    this->proxy.setHostName(this->proxyInfo->value("addr_proxy_http").toString());
    this->proxy.setPort(this->proxyInfo->value("port_proxy_http").toInt());

    this->manager = new QNetworkAccessManager(this);
    this->proxy.setType(QNetworkProxy::HttpProxy);
    this->manager->setProxy(this->proxy);

    this->layout  = new QGridLayout();
    this->webView = new QWebView(this);
    this->editUrl = new QLineEdit(this);
    this->next    = new QPushButton(this);
    this->stop    = new QPushButton(this);
    this->back    = new QPushButton(this);
    this->home    = new QPushButton(this);
    this->refresh = new QPushButton(this);
    this->mMenu   = new LMenuBar(this);
    this->openMenu = new QPushButton(this);

    this->mMenu->setFixedHeight(0);
    this->mMenu->setEnabled(true);

    this->connect(this->editUrl,  SIGNAL(returnPressed()),  this, SLOT(slotEditUrl()));
    this->connect(this->next,     SIGNAL(clicked()),        this, SLOT(slotNextPage()));
    this->connect(this->back,     SIGNAL(clicked()),        this, SLOT(slotBackPage()));
    this->connect(this->stop,     SIGNAL(clicked()),        this, SLOT(slotStopPage()));
    this->connect(this->refresh,  SIGNAL(clicked()),        this, SLOT(slotRefresh()));
    this->connect(this->webView,  SIGNAL(urlChanged(QUrl)), this, SLOT(slotUrlChange(QUrl)));
    this->connect(this->openMenu, SIGNAL(clicked()),        this, SLOT(slotAffMenu()));

    this->webView->page()->setNetworkAccessManager(this->manager);

    this->mMenu->setPageInMenu(this->webView);

    this->layout->setSpacing(2);
    this->layout->setMargin(0);

    this->check = true;

    this->connect(this->webView->page()->networkAccessManager(), SIGNAL(proxyAuthenticationRequired(QNetworkProxy,QAuthenticator*)), this, SLOT(slotProxyAuthenticationRequired(QNetworkProxy,QAuthenticator*)));
    this->connect(this->webView->page()->networkAccessManager(), SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)), this, SLOT(slotSslError(QNetworkReply*,QList<QSslError>)));

    /**
     ** Set Button icon
     **/

    this->next->setIcon(QIcon(":next"));
    this->stop->setIcon(QIcon(":stop"));
    this->back->setIcon(QIcon(":back"));
    this->home->setIcon(QIcon(":home"));
    this->refresh->setIcon(QIcon(":refresh"));
    this->openMenu->setIcon(QIcon(":menu"));

    /**
     ** Enable plugins and Javascript
     **/
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavaEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);

    this->layout->addWidget(this->mMenu, 1, 0, 1, 7);
    this->layout->addWidget(this->back, 0, 0);
    this->layout->addWidget(this->next, 0, 1);
    this->layout->addWidget(this->refresh, 0, 2);
    this->layout->addWidget(this->stop, 0, 3);
    this->layout->addWidget(this->home, 0, 4);
    this->layout->addWidget(this->editUrl, 0, 5);
    this->layout->addWidget(this->openMenu,0 ,6);

    this->webView->setUrl(QUrl("http://www.google.fr"));

    this->webView->page()->focusNextPrevChild(true);

    this->layout->addWidget(this->webView, 2, 0, 4, 0);

    this->setLayout(this->layout);
}

void LWebPage::slotAffMenu()
{
    QSize size = this->mMenu->size();

    if (size.rheight() > 0)
        this->mMenu->setFixedHeight(0);
    else
        this->mMenu->setFixedHeight(20);
}

void LWebPage::slotEditUrl()
{
    QString url = this->editUrl->text();

    if (url.left(7) != "http://")
        url = "http://" + url;

    this->webView->setUrl(QUrl(url));
}

void LWebPage::slotBackPage()
{
    this->webView->back();
}

void LWebPage::slotNextPage()
{
    this->webView->forward();
}

void LWebPage::slotStopPage()
{
    this->webView->stop();
}

void LWebPage::slotRefresh()
{
    this->webView->reload();
}

void LWebPage::slotUrlChange(QUrl url)
{
    this->editUrl->setText(url.toString());
}

void LWebPage::slotSslError(QNetworkReply*reply,QList<QSslError>list)
{
    QSslCertificate certificate;

    foreach (QSslError item, list)
        reply->ignoreSslErrors();
}


void LWebPage::slotProxyAuthenticationRequired(QNetworkProxy proxy,QAuthenticator *log)
{
    if (this->check == true)
    {
        QString text;
        text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("User name:"), QLineEdit::Normal);
        log->setUser(text);

        text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("User password:"), QLineEdit::Password);
        log->setPassword(text);

        this->check = false;
    }
}

void LWebPage::slotGetInfos(QString password, QString login)
{
    /*   this->tmpAuthenticator->setPassword(password);
    this->tmpAuthenticator->setUser(login);

    this->webView->reload();
    this->webView->reload();
    this->webView->reload();
    this->webView->reload();
    */
}
