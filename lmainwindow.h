#ifndef LMAINWINDOW_H
#define LMAINWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QGraphicsEffect>
#include <QHash>
#include <QAction>
#include <QLineEdit>
#include <QList>
#include <QComboBox>
#include <QUrl>
#include <QCompleter>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QTabBar>

#include "LTabWidget.h"
#include "LWebLoader.h"

class LMainWindow : public QWidget
{
    Q_OBJECT

private:
    QComboBox *slectMoteur;
    QString   savMoteur;
    QHash<int, LWebLoader *>tabIndex;
    QGridLayout *mainLayout;
    QPushButton *next;
    QPushButton *previous;
    QPushButton *refresh;
    QPushButton *stop;
    QPushButton *home;
    QLineEdit   *editUrl;
    LTabWidget *tabs;
    QGraphicsEffect *effectTab;
    QList<QString> listAllUrl;

    //Menu
    QMenuBar *mMenu;
    QMenu *files;
    QMenu *edit;
    QMenu *aff;
    QMenu *history;
    QMenu *favorites;
    QMenu *tools;
    QMenu *help;
    QPrinter *print;

    void creatMenu();

public:
    LMainWindow(QWidget *parent = 0);

private slots:
    void slotSendUrl();
    void slotMoteurChange(QString name);
    void slotGetHistory(QList<QString>listUrl);
    void slotNewInfoPage(QUrl url, QIcon icon);
    void slotClickedCloseTab(int index);
    void slotTitleChange(QString title);
    void slotGetNewTabIndex(QHash<int, LWebLoader *>hashIndex);

    //slot Menu
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

#endif // LMAINWINDOW_H
