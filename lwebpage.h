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
    QLineEdit   *editUrl;

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
};

#endif // LWEBPAGE_H
