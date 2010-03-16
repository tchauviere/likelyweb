#include "lwebpage.h"

LWebPage::LWebPage(QWidget *parent) : QWidget(parent)
{
    this->proxyInfo = new QSettings("Proxy", "LikelyWeb", this);
    this->proxy.setHostName(this->proxyInfo->value("addr_proxy_http").toString());
    this->proxy.setPort(this->proxyInfo->value("port_proxy_http").toInt());

    this->manager = new QNetworkAccessManager(this);
    this->proxy.setType(QNetworkProxy::HttpProxy);
    this->manager->setProxy(this->proxy);

    this->cache = new QNetworkDiskCache(this);
    this->layout   = new QGridLayout();
    this->webView  = new QWebView(this);
    this->editUrl  = new LLineEdit(this);
    this->next     = new QPushButton(this);
    this->stop     = new QPushButton(this);
    this->menu     = new QMenu(this);
    this->back     = new QToolButton (this);
    this->home     = new QPushButton(this);
    this->refresh  = new QPushButton(this);

    if (!QDir(QDir::homePath() + "/cache/").exists())
    {
        QDir dir;
        dir.mkdir(QDir::homePath() + "/cache/");
    }

    QWebSettings::setIconDatabasePath(QDir::homePath() +  "/cache/");

    this->back->setMenu(this->menu);

    this->connect(this->editUrl,  SIGNAL(sigReturnPressed(QString)),  this, SLOT(slotEditUrl(QString)));
    this->connect(this->next,     SIGNAL(clicked()),        this, SLOT(slotNextPage()));
    this->connect(this->back,     SIGNAL(clicked()),        this, SLOT(slotBackPage()));
    this->connect(this->stop,     SIGNAL(clicked()),        this, SLOT(slotStopPage()));
    this->connect(this->refresh,  SIGNAL(clicked()),        this, SLOT(slotRefresh()));
    this->connect(this->webView,  SIGNAL(urlChanged(QUrl)), this, SLOT(slotUrlChange(QUrl)));

    this->connect(this->webView, SIGNAL(iconChanged()), this, SLOT(slotIconChange()));
    this->connect(this->webView->page(), SIGNAL(linkClicked(QUrl)), this, SLOT(slotLinlClicked(QUrl)));

    this->connect(this->webView, SIGNAL(titleChanged(QString)), this, SLOT(slotTitleChange(QString)));
    this->connect(this->webView, SIGNAL(loadStarted()), this, SLOT(slotLoadStart()));
    this->connect(this->webView, SIGNAL(loadProgress(int)), this, SLOT(slotLoadProgress(int)));
    this->connect(this->webView, SIGNAL(loadFinished(bool)), this, SLOT(slotLoadFinish()));

    this->connect(this->webView->page(), SIGNAL(unsupportedContent(QNetworkReply*)), this, SLOT(slotUnsupportedContent(QNetworkReply*)));

    this->webView->page()->setNetworkAccessManager(this->manager);

    this->layout->setSpacing(2);
    this->layout->setMargin(0);

    this->check = false;

    this->connect(this->webView->page()->networkAccessManager(), SIGNAL(proxyAuthenticationRequired(QNetworkProxy,QAuthenticator*)), this, SLOT(slotProxyAuthenticationRequired(QNetworkProxy,QAuthenticator*)));
    this->connect(this->webView->page()->networkAccessManager(), SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)), this, SLOT(slotSslError(QNetworkReply*,QList<QSslError>)));
    this->connect(this->webView->page()->networkAccessManager(), SIGNAL(finished(QNetworkReply*)), this, SLOT(slotFinished(QNetworkReply*)));

    /**
     ** Set Button icon
     **/

    this->next->setIcon(QIcon(":next"));
    this->stop->setIcon(QIcon(":stop"));
    this->back->setIcon(QIcon(":back"));
    this->home->setIcon(QIcon(":home"));
    this->refresh->setIcon(QIcon(":refresh"));

    this->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateExternalLinks);
    /**
     ** Enable plugins and Javascript
     **/

    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavaEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);

    this->layout->addWidget(this->back, 0, 0);
    this->layout->addWidget(this->next, 0, 1);
    this->layout->addWidget(this->refresh, 0, 2);
    this->layout->addWidget(this->stop, 0, 3);
    this->layout->addWidget(this->home, 0, 4);
    this->layout->addWidget(this->editUrl, 0, 5);

    this->webView->page()->focusNextPrevChild(true);;

    this->webView->setUrl(QUrl("http://facebook.fr"));

    this->layout->addWidget(this->webView, 2, 0, 4, 0);

    this->setLayout(this->layout);
}

#include <QDebug>

void LWebPage::slotLoadStart()
{
    this->editUrl->loadStart();
}
void LWebPage::slotLoadProgress(int progress)
{
    this->editUrl->loadProgress(progress);
}

void LWebPage::slotLoadFinish()
{
    this->menu->setFixedWidth(200);

    this->menu->addAction(this->webView->url().toString());
    this->editUrl->loadFinish();
}

void LWebPage::slotTitleChange(QString title)
{
}

void LWebPage::slotLinlClicked(QUrl url)
{
    if (url.hasQuery() == false)
    {
        this->webView->setUrl(url);
    }
    else
    {
        qDebug() << "ok";;
        emit this->sigOpenLinkInNewTab(url);
    }
}

void LWebPage::setUrl(QUrl url)
{
    this->webView->setUrl(QUrl(url));
}

void LWebPage::slotEditUrl(QString url)
{
    QUrl urlUser;
    QUrl newUrl;

    newUrl = urlUser.fromUserInput(url);
    newUrl.isDetached();
    if (newUrl.isValid() == true)
        this->webView->setUrl(newUrl);
    else
        qDebug() << "error";
}

void LWebPage::slotUnsupportedContent(QNetworkReply *reply)
{
    this->reply = reply;

    this->connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(slotUploadProgress(qint64,qint64)));
    this->connect(reply, SIGNAL(finished()), this, SLOT(slotDownloadFinish()));
}

void LWebPage::slotDownloadFinish()
{
    QFile file("/download/file");
    file.write(this->reply->readAll());
}

void LWebPage::slotUploadProgress(qint64 current,qint64 total)
{
}

void LWebPage::slotIconChange()
{
    QIcon pageIcon = QWebSettings::iconForUrl(this->webView->url());
    if ( pageIcon.isNull() )
    {
        qDebug() << "icon NULL";
        qDebug() << QWebSettings::iconDatabasePath();
    }/*    qDebug() << this->webView->settings()->iconForUrl(this->webView->url());
    this->editUrl->setIcon(this->webView->icon());
    QPushButton *bp = new QPushButton(QWebSettings::iconForUrl(this->webView->url()), "icon");
    bp->show();
    */
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
    this->editUrl->setChampsText(url.toString());
}

void LWebPage::slotSslError(QNetworkReply*reply,QList<QSslError>list)
{
    QSslCertificate certificate;

    foreach (QSslError item, list)
        reply->ignoreSslErrors();
}

QString LWebPage::getUrl()
{
    return this->webView->url().toString();
}

void LWebPage::slotFinished(QNetworkReply *reply)
{
}

void LWebPage::slotProxyAuthenticationRequired(QNetworkProxy proxy,QAuthenticator *log)
{
    QString text;

    log->setUser("berard_g");
    log->setPassword("i)Xvfy:t");
    /*    text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("User name:"), QLineEdit::Normal);
    log->setUser(text);
    this->login = text;

    text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("User password:"), QLineEdit::Password);
    log->setPassword(text);
    this->password = text;
*/
}
