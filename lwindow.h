#ifndef LWINDOW_H
#define LWINDOW_H

#include <QtGui/QWidget>
#include <QGridLayout>
#include <QFileDialog>
#include <QMenuBar>
#include <QLabel>
#include <QDir>

#include "LWindowTitleBar.h"
#include "LTabWidget.h"

class LWindow : public QWidget
{
    Q_OBJECT

private:
    QGridLayout *layout;
    LTabWidget  *tab;
    QMenuBar    *menuBar;
    QMenu       *files;
    QMenu       *edit;
    QMenu       *aff;
    QMenu       *history;
    QMenu       *favorites;
    QMenu       *tools;
    QMenu       *help;
    QWebView    *page;
    QNetworkReply *reply;

signals:
    void sigNewWindow();

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


public:
    LWindow(QWidget *parent = 0);
    ~LWindow();
};

#endif // LWINDOW_H
