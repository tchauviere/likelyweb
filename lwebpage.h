#ifndef LWEBPAGE_H
#define LWEBPAGE_H

#include <QWidget>
#include <QWebView>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QWebFrame>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSslError>
#include <QSslCertificate>
#include <QNetworkProxy>
#include <QSettings>
#include <QAuthenticator>
#include <QInputDialog>

#include "LBoxLogin.h"

class LWebPage : public QWidget
{
    Q_OBJECT

private:
    QWebView    *webView;
    QGridLayout *layout;
    QPushButton *back;
    QPushButton *next;
    QPushButton *home;
    QPushButton *stop;
    QPushButton *refresh;
    QPushButton *openMenu;
    QLineEdit   *editUrl;
    QNetworkProxy proxy;
    QNetworkAccessManager *manager;
    QSettings *proxyInfo;
    QAuthenticator *tmpAuthenticator;
    bool    check;

public:
    LWebPage(QWidget *parent = 0);

private slots:
    void slotEditUrl();
    void slotNextPage();
    void slotBackPage();
    void slotStopPage();
    void slotRefresh();
    void slotUrlChange(QUrl url);
    void slotSslError(QNetworkReply*reply,QList<QSslError>list);
    void slotProxyAuthenticationRequired(QNetworkProxy proxy,QAuthenticator*log);
    void slotGetInfos(QString password, QString login);
};

#endif // LWEBPAGE_H
