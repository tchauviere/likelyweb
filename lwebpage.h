#ifndef LWEBPAGE_H
#define LWEBPAGE_H

#include <QHttp>
#include <QBuffer>

#include <QWidget>
#include <QWebView>
#include <QWebSettings>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QAction>
#include <QWebFrame>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSslError>
#include <QWebElementCollection>
#include <QFile>
#include <QSslCertificate>
#include <QNetworkProxy>
#include <QSettings>
#include <QAuthenticator>
#include <QInputDialog>
#include <QString>
#include <QUrl>
#include <QDir>
#include <QToolButton>
#include <QNetworkDiskCache>
#include <QMenu>

#include "LLineEdit.h"

class LWebPage : public QWidget
{
    Q_OBJECT

private:
    QMenu *menu;
    QWebView    *webView;
    QNetworkDiskCache *cache;
    QGridLayout *layout;
    QToolButton  *back;
    QPushButton *next;
    QPushButton *home;
    QPushButton *stop;
    QPushButton *refresh;
    LLineEdit   *editUrl;
    QNetworkProxy proxy;
    QNetworkAccessManager *manager;
    QSettings *proxyInfo;
    QAuthenticator *tmpAuthenticator;
    QNetworkReply *reply;
    QString login;
    QString password;
    bool    check;

public:
    LWebPage(QWidget *parent = 0);
    QString getUrl();
    void setUrl(QUrl url);

private slots:
    void slotTitleChange(QString title);
    void slotUnsupportedContent(QNetworkReply*reply);
    void slotIconChange();
    void slotLinlClicked(QUrl url);
    void slotEditUrl(QString url);
    void slotNextPage();
    void slotBackPage();
    void slotStopPage();
    void slotRefresh();
    void slotUrlChange(QUrl url);
    void slotSslError(QNetworkReply*reply,QList<QSslError>list);
    void slotProxyAuthenticationRequired(QNetworkProxy proxy,QAuthenticator*log);
    void slotUploadProgress(qint64 current,qint64 total);
    void slotDownloadFinish();
    void slotLoadStart();
    void slotLoadProgress(int progress);
    void slotLoadFinish();
    void slotFinished(QNetworkReply*reply);

signals:
    void sigOpenLinkInNewTab(QUrl url);

};

#endif // LWEBPAGE_H
