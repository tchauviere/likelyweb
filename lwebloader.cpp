#include "lwebloader.h"

LWebLoader::LWebLoader(QWidget *parent) : QWidget(parent)
{
    this->webView       = new QWebView(this);
    this->webPage       = this->webView->page();
    this->layout        = new QVBoxLayout();
    this->progressbar   = new QProgressBar(this);

    this->progressbar->setVisible(false);
    this->progressbar->setMaximumHeight(14);
    this->webView->setMouseTracking(true);

    /**
     ** Enable plugins and Javascript
     **/
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavaEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PrintElementBackgrounds, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalStorageDatabaseEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalStorageEnabled, true);

    this->webView->load(QUrl("http://google.fr"));

    this->connect(this->webView, SIGNAL(urlChanged(QUrl)), this, SLOT(slotUrlChange(QUrl)));
    this->connect(this->webView, SIGNAL(loadStarted()), this, SLOT(slotLoadStart()));
    this->connect(this->webView, SIGNAL(loadProgress(int)), this, SLOT(slotLoadMidl(int)));
    this->connect(this->webView, SIGNAL(loadFinished(bool)), this, SLOT(slotLoadFinich(bool)));
    this->connect(this->webView, SIGNAL(titleChanged(QString)), this, SLOT(slotTitleChange(QString)));

    this->layout->addWidget(this->webView);
    this->layout->addWidget(this->progressbar);

    this->setLayout(this->layout);
}

/**
 ** Function public
 **/
#include <QDebug>

void LWebLoader::slotTitleChange(QString title)
{
    emit  this->sigTitleChange(title);
}

void LWebLoader::setUrl(QString url)
{
    this->webView->load(QUrl(url));

    this->connect(this->webView->page(), SIGNAL(unsupportedContent(QNetworkReply*)), this, SLOT(slotUnsupportedContent(QNetworkReply*)));
    this->connect(this->webView->page(), SIGNAL(downloadRequested(QNetworkRequest)), this, SLOT(slotDownload(QNetworkRequest)));

    this->sendHistory(url);
    this->webView->page()->setForwardUnsupportedContent(true);
}

void LWebLoader::sendHistory(QString url)
{
    QList<QString>listUrl;
    listUrl.append(url);
    QWebHistory *history = this->webView->history();
    QList<QWebHistoryItem>listHistory = history->items();
    foreach (QWebHistoryItem item, listHistory)
        listUrl.append(item.url().toString());
    emit this->sigSendHistory(listUrl);
}

/**
 ** Slot
 **/

void LWebLoader::slotDownload(QNetworkRequest request)
{
    request = request;
}

void LWebLoader::slotUnsupportedContent(QNetworkReply *request)
{
    QFileInfo infosDL(request->url().toString());
    QString   emplacementDL = QDir::homePath() + "/" + infosDL.fileName();

    this->request = request;

    this->fileDl.setFileName(emplacementDL);
    this->fileDl.open(QIODevice::WriteOnly | QIODevice::Truncate);

    this->dialogueTelechargement = new QProgressDialog("Telechargement en cours...", "Annuler", 0, 100, this);
    this->dialogueTelechargement->setWindowTitle("Telechargement");
    this->dialogueTelechargement->setFixedSize(345, 110);
    this->dialogueTelechargement->show();

    this->connect(request, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(slotDownloadProgress(qint64,qint64)));
    this->connect(request, SIGNAL(finished()), this, SLOT(slotDlFinished()));
}


void LWebLoader::getIcon()
{
}

void LWebLoader::slotUrlChange(QUrl url)
{
    emit this->sigSendNewInfosPage(url, this->webView->icon());
}

void LWebLoader::slotLoadFinich(bool a)
{
    if (a == true)
        this->progressbar->setVisible(false);
}

void LWebLoader::slotLoadMidl(int pourcent)
{
    this->progressbar->setValue(pourcent);
}

void LWebLoader::slotLoadStart()
{
    this->progressbar->setVisible(true);
}

void LWebLoader::slotDlFinished()
{
    this->fileDl.write(this->request->readAll());
    this->fileDl.close();
    this->dialogueTelechargement->close();
}

void LWebLoader::slotDownloadProgress(qint64 progress, qint64 total)
{
    this->dialogueTelechargement->setRange(0, total);
    this->dialogueTelechargement->setValue(progress);
}

