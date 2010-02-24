#ifndef LMENUBAR_H
#define LMENUBAR_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QKeySequence>
#include <QIcon>
#include <QMenu>
#include <QMenuBar>
#include <QWebView>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QDir>
#include <QNetworkAccessManager>
#include <QTextStream>
#include <QFileDialog>
#include <QPrintPreviewDialog>

class LMenuBar : public QWidget
{
    Q_OBJECT

private:
    QGridLayout *layout;
    QPushButton *openMenu;
    QMenuBar    *mMenu;
    QMenu       *files;
    QMenu       *edit;
    QMenu       *aff;
    QMenu       *history;
    QMenu       *favorites;
    QMenu       *tools;
    QMenu       *help;
    QWebView    *page;
    QNetworkReply *reply;

public:
    explicit LMenuBar(QWidget *parent = 0);
    void setPageInMenu(QWebView *page);

private slots:
    void slotTab();
    void slotWindow();
    void slotWinPrivate();
    void slotFullScreen();
    void slotHistory();
    void slotFavoriteManage();
    void slotDownloadManage();
    void slotOption();
    void slotAboutUs();
    void slotQuit();
    void slotHelp();
    void slotCut();
    void slotCopy();
    void slotPaste();
    void slotOpenFile();
    void slotGoto();
    void slotCloseWindow();
    void slotCloseTab();
    void slotSavePage();
    void slotPagePoperties();
    void slotImportSpec();
    void slotPrintPreview();
    void slotPrint();
    void slotSearch();
    void slotSelectAll();
    void slotCancelAction();
    void slotRepeatAction();
    void slotDelete();
    void slotMyConf();
    void slotStopLoad();
    void slotReload();
    void slotAffStatus();
    void slotCodeSource();
    void slotLastPage();
    void slotNextPage();
    void slotBackHome();
    void slotAddToFavorites();
    void slotSuscribeRss();
    void slotAddTabsToFavorites();
    void slotWebSearch();
    void slotErasePrivateData();
    void slotMainOptMenu();
    void slotHelpLikely();
    void slotUpdateNote();
    void slotBugReport();
    void slotReportDangerSite();
    void slotReportDeadLink();
    void slotCheckUpdate();
    void slotErrorManage();
};

#endif // LMENUBAR_H
