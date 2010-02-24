#ifndef LWEBLOADER_H
#define LWEBLOADER_H

#include <QWidget>
#include <QWebPage>
#include <QWebSettings>
#include <QWebView>
#include <QVBoxLayout>
#include <QWebSettings>
#include <QProgressBar>
#include <QWebHistory>
#include <QWebHistoryItem>
#include <QList>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QProgressDialog>

class LWebLoader : public QWidget
{
    Q_OBJECT

private:
    QWebPage *webPage;
    QWebView *webView;
    QVBoxLayout *layout;
    QProgressBar *progressbar;
    QProgressDialog *dialogueTelechargement;
    QFile fileDl;
    QNetworkReply *request;

    //functions
    void sendHistory(QString url);

public:
    LWebLoader(QWidget *parent = 0);
    void setUrl(QString url);
    void getIcon();

private slots:
    void slotTitleChange(QString title);
    void slotLoadStart();
    void slotUrlChange(QUrl url);
    void slotDlFinished();
    void slotDownloadProgress(qint64 progress, qint64 total);
    void slotLoadMidl(int nb);
    void slotLoadFinich(bool a);
    void slotDownload(QNetworkRequest request);
    void slotUnsupportedContent(QNetworkReply *request);

signals:
    void sigSendHistory(QList<QString>listUrl);
    void sigTitleChange(QString title);
    void sigSendNewInfosPage(QUrl url, QIcon icon);
};

#endif // LWEBLOADER_H
