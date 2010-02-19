#include "lwebpage.h"

LWebPage::LWebPage(QWidget *parent) : QWidget(parent)
{
    QNetworkProxy proxy;
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    proxy.setHostName("proxy.epitech.net");
    proxy.setPassword("i)Xvfy:t");
    proxy.setUser("berard_g");
    proxy.setPort(3128);
    proxy.setType(QNetworkProxy::HttpProxy);
    manager->setProxy(proxy);

    this->layout  = new QGridLayout();
    this->webView = new QWebView(this);
    this->editUrl = new QLineEdit(this);
    this->next    = new QPushButton(this);
    this->stop    = new QPushButton(this);
    this->back    = new QPushButton(this);
    this->home    = new QPushButton(this);
    this->refresh = new QPushButton(this);

    this->connect(this->editUrl, SIGNAL(returnPressed()),  this, SLOT(slotEditUrl()));
    this->connect(this->next,    SIGNAL(clicked()),        this, SLOT(slotNextPage()));
    this->connect(this->back,    SIGNAL(clicked()),        this, SLOT(slotBackPage()));
    this->connect(this->stop,    SIGNAL(clicked()),        this, SLOT(slotStopPage()));
    this->connect(this->refresh, SIGNAL(clicked()),        this, SLOT(slotRefresh()));
    this->connect(this->webView, SIGNAL(urlChanged(QUrl)), this, SLOT(slotUrlChange(QUrl)));

    //    this->connect(this->webView->page()->networkAccessManager(), SIGNAL(proxyAuthenticationRequired(QNetworkProxy,QAuthenticator*)), this, SLOT(slotSslError(QNetworkProxy ,QAuthenticator*)));

    this->webView->page()->setNetworkAccessManager(manager);
    this->webView->setFocus(Qt::MouseFocusReason);
    this->layout->setSpacing(2);
    this->layout->setMargin(0);
    this->connect(this->webView->page()->networkAccessManager(), SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)), this, SLOT(slotSslError(QNetworkReply*,QList<QSslError>)));

    /**
     ** Set Button icon
     **/

    this->next->setIcon(QIcon(":next"));
    this->stop->setIcon(QIcon(":stop"));
    this->back->setIcon(QIcon(":back"));
    this->home->setIcon(QIcon(":home"));
    this->refresh->setIcon(QIcon(":refresh"));

    /**
     ** Enable plugins and Javascript
     **/
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavaEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);

    this->layout->addWidget(this->back, 0, 0);
    this->layout->addWidget(this->next, 0, 1);
    this->layout->addWidget(this->refresh, 0, 2);
    this->layout->addWidget(this->stop, 0, 3);
    this->layout->addWidget(this->home, 0, 4);
    this->layout->addWidget(this->editUrl, 0, 5);
    //this->layout->addWidget(this->slectMoteur, 0, 6);
    this->webView->setUrl(QUrl("http://www.google.fr"));

    this->layout->addWidget(this->webView, 1, 0, 4, 0);

    this->setLayout(this->layout);
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
    {
        item.SelfSignedCertificate;

        QSslError::SelfSignedCertificate;
//        certificate = item.certificate();
    }
}
