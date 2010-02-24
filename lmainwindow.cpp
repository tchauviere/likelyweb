#include "lmainwindow.h"

LMainWindow::LMainWindow(QWidget *parent) :QWidget(parent)
{
    this->mainLayout        = new QGridLayout();
    this->next              = new QPushButton(this);
    this->previous          = new QPushButton(this);
    this->stop              = new QPushButton(this);
    this->home              = new QPushButton(this);
    this->refresh           = new QPushButton(this);
    this->tabs              = new LTabWidget(this);
    this->editUrl           = new QLineEdit(this);
    this->slectMoteur       = new QComboBox(this);
    
    /** creat Menu
     */
    this->creatMenu();

    this->setMinimumSize(850, 600);
    this->setWindowIcon(QIcon(":lw"));
    this->setWindowTitle("LikeLyWeb");

    /** Widget signals connect
      */
    this->connect(this->tabs,           SIGNAL(sigSetNewHashIndex(QHash<int, LWebLoader *>)), this, SLOT(slotGetNewTabIndex(QHash<int,LWebLoader*>)));
    this->connect(this->editUrl,        SIGNAL(returnPressed()),                              this, SLOT(slotSendUrl()));
    this->connect(this->slectMoteur,    SIGNAL(currentIndexChanged(QString)),                 this, SLOT(slotMoteurChange(QString)));

    /** layout set Options
      */
    this->mainLayout->setMargin(0);
    this->mainLayout->setSpacing(2);

    /** add item in QComboBox
      */
    this->slectMoteur->setCurrentIndex(0);
    this->slectMoteur->addItem(QIcon(":google"), "Google");
    this->slectMoteur->addItem(QIcon(":yahoo"), "Yahoo");
    this->slectMoteur->addItem(QIcon(":bing"), "Bing");
    this->slectMoteur->addItem(QIcon(":wiki"), "Wikipedia");

    /** Set icon to button
      */
    this->next->setIcon(QIcon(":next"));
    this->previous->setIcon(QIcon(":back"));
    this->stop->setIcon(QIcon(":stop"));
    this->home->setIcon(QIcon(":home"));
    this->refresh->setIcon(QIcon(":refresh"));

    /** Set Widget in layout
      */
    this->mainLayout->addWidget(this->previous, 0, 0);
    this->mainLayout->addWidget(this->next, 0, 1);
    this->mainLayout->addWidget(this->refresh, 0, 2);
    this->mainLayout->addWidget(this->stop, 0, 3);
    this->mainLayout->addWidget(this->home, 0, 4);
    this->mainLayout->addWidget(this->editUrl, 0, 5);
    this->mainLayout->addWidget(this->slectMoteur, 0, 6);
    this->mainLayout->addWidget(this->mMenu, 1, 0, 1, 0);
    this->mainLayout->addWidget(this->tabs, 2, 0, 5, 0);

    /** Set layout
      */
    this->setLayout(this->mainLayout);
}

void LMainWindow::creatMenu()
{
    this->mMenu     = new QMenuBar(this);
    this->files     = new QMenu(this);
    this->edit      = new QMenu(this);
    this->aff       = new QMenu(this);
    this->history   = new QMenu(this);
    this->favorites = new QMenu(this);
    this->tools     = new QMenu(this);
    this->help      = new QMenu(this);

    this->mMenu->setFixedHeight(20);

    this->help->setTitle(tr("Aide"));
    this->files->setTitle(tr("Fichier"));
    this->edit->setTitle(tr("Edition"));
    this->aff->setTitle(tr("Affichage"));
    this->history->setTitle(tr("Historique"));
    this->favorites->setTitle(tr("Favoris"));
    this->tools->setTitle(tr("Outils"));

    this->mMenu->addMenu(this->files);
    this->mMenu->addMenu(this->edit);
    this->mMenu->addMenu(this->aff);
    this->mMenu->addMenu(this->history);
    this->mMenu->addMenu(this->favorites);
    this->mMenu->addMenu(this->tools);
    this->mMenu->addMenu(this->help);

    // Manage the file menu
    this->files->addAction(QIcon(":newwin"), "Nouvelle Fenetre",           this, SLOT(slotWindow()), QKeySequence("Ctrl+N"));
    this->files->addAction(QIcon(":newtab"), "Nouvel Onglet",              this, SLOT(slotTab()), QKeySequence("Ctrl+T"));
    this->files->addAction(QIcon(":navpriv"), "Fenetre Navigation Privee", this, SLOT(slotWinPrivate()), QKeySequence("Ctrl+Shift+N"));
    this->files->addAction("Aller a l'adresse ...",                        this, SLOT(slotGoto()), QKeySequence("Ctrl+L"));
    this->files->addAction("Ouvrir un fichier ...",                        this, SLOT(slotOpenFile()), QKeySequence("Ctrl+O"));
    this->files->addAction("Fermer la fenetre",                            this, SLOT(slotCloseWindow()), QKeySequence("Ctrl+Shift+W"));
    this->files->addAction("Fermer l'onglet",                              this, SLOT(slotCloseTab()), QKeySequence("Ctrl+W"));

    this->files->addSeparator();

    this->files->addAction("Enregistrer sous ...",        this, SLOT(slotSavePage()), QKeySequence("Ctrl+S"));
    this->files->addAction("Proprietes de la page",       this, SLOT(slotPagePoperties()));
    this->files->addAction("Apercu avant impression",     this, SLOT(slotPrintPreview()));
    this->files->addAction(QIcon(":printer"), "Imprimer", this, SLOT(slotPrint()), QKeySequence("Ctrl+P"));

    this->files->addSeparator();

    this->files->addAction("Importer preferences ...", this, SLOT(slotImportSpec()));

    this->files->addSeparator();

    this->files->addAction("Quitter", this, SLOT(slotQuit()));
    // Manage the file menu


    // Manage the edit menu
    this->edit->addAction("Annuler", this, SLOT(slotCancelAction()), QKeySequence("Ctrl+Z"));
    this->edit->addAction("Repeter", this, SLOT(slotRepeatAction()), QKeySequence("Ctrl+Y"));

    this->edit->addSeparator();

    this->edit->addAction("Couper",     this, SLOT(slotCut()), QKeySequence("Ctrl+X"));
    this->edit->addAction("Copier",     this, SLOT(slotCopy()), QKeySequence("Ctrl+C"));
    this->edit->addAction("Coller",     this, SLOT(slotPaste()), QKeySequence("Ctrl+V"));
    this->edit->addAction("Supprimer",  this, SLOT(slotDelete()), QKeySequence("Del"));

    this->edit->addSeparator();

    this->edit->addAction("Tout selectionner", this, SLOT(slotSelectAll()), QKeySequence("Ctrl+A"));

    this->edit->addSeparator();

    this->edit->addAction("Rechercher", this, SLOT(slotSearch()), QKeySequence("Ctrl+F"));

    this->edit->addSeparator();

    this->edit->addAction("Preferences", this, SLOT(slotMyConf()));
    // Manage the edit menu


    // Manage the aff menu
    this->aff->addAction("Barre d'outils");
    this->aff->addAction("Barre d'etat", this, SLOT(slotAffStatus()));
    this->aff->addAction("Panneau lateral");

    this->aff->addSeparator();

    this->aff->addAction("Arreter le chargement", this, SLOT(slotStopLoad()), QKeySequence("Esc"));
    this->aff->addAction("Acutaliser la page",    this, SLOT(slotReload()),   QKeySequence("F5"));

    this->aff->addAction("Taille du texte");
    this->aff->addAction("Style de la page");

    this->aff->addSeparator();

    this->aff->addAction("Encodage de caractere");

    this->aff->addSeparator();

    this->aff->addAction("Code source de la page", this, SLOT(slotCodeSource()), QKeySequence("Ctrl+U"));
    this->aff->addAction("Plein Ecran",            this, SLOT(slotFullScreen()), QKeySequence("F11"));
    // Manage the aff menu


    // Manage the history menu
    this->history->addAction("Page precedente",     this, SLOT(slotLastPage()), QKeySequence("Alt+Left"));
    this->history->addAction("Page Suivante",       this, SLOT(slotNextPage()), QKeySequence("Alt+Right"));
    this->history->addAction("Page d'accueil",      this, SLOT(slotBackHome()), QKeySequence("Alt+Home"));
    this->history->addAction("Afficher historique", this, SLOT(slotHistory()), QKeySequence("Ctrl+Shift+H"));

    this->history->addSeparator();

    this->history->addAction("Onglets recemment fermes");
    this->history->addAction("Fenetres recemment fermes");
    // Manage the history menu


    // Manage the favorites menu
    this->favorites->addAction("Ajouter cette page aux favoris",  this, SLOT(slotAddToFavorites()), QKeySequence("Ctrl+D"));
    this->favorites->addAction("S'abonner au RSS de la page ...", this, SLOT(slotSuscribeRss()));
    this->favorites->addAction("Ajouter les onglets aux favoris", this, SLOT(slotAddTabsToFavorites()), QKeySequence("Ctrl+Shift+D"));
    this->favorites->addAction("Organiser les favoris",           this, SLOT(slotFavoriteManage()), QKeySequence("Ctrl+Shift+B"));

    this->favorites->addSeparator();

    this->favorites->addAction("Barre d'outils des favoris");
    // Manage the favorites menu


    //Manage the tools menu
    this->tools->addAction("Recherche Web",     this, SLOT(slotWebSearch()), QKeySequence("Ctrl+L"));
    this->tools->addAction("Telechargements",   this, SLOT(slotDownloadManage()), QKeySequence("Ctrl+J"));
    this->tools->addAction("Manager d'erreurs", this, SLOT(slotErrorManage()), QKeySequence("Ctrl+Shift+J"));

    this->tools->addSeparator();

    this->tools->addAction("Effacer vos donnees personnelles", this, SLOT(slotErasePrivateData()), QKeySequence("Ctrl+Shift+Del"));

    this->tools->addSeparator();

    this->tools->addAction("Options Generales", this, SLOT(slotMainOptMenu()));
    //Manage the tools menu


    // Manage the help menu
    this->help->addAction("Aide LikelyWeb",           this, SLOT(slotHelpLikely()), QKeySequence("F1"));
    this->help->addAction("Recherche de mise a jour", this, SLOT(slotCheckUpdate()));
    this->help->addAction("Note de mise a jour",      this, SLOT(slotUpdateNote()));
    this->help->addAction("Rapporter un bug",         this, SLOT(slotBugReport()));

    this->help->addSeparator();

    this->help->addAction("Rapporter un site web mort",      this, SLOT(slotReportDeadLink()));
    this->help->addAction("Rapporter un site web dangereux", this, SLOT(slotReportDangerSite()));

    this->help->addSeparator();

    this->help->addAction("A propos", this, SLOT(slotAboutUs()));
    // Manage the help menu

}

void LMainWindow::slotNewInfoPage(QUrl url, QIcon icon)
{
    int index = this->tabs->currentIndex();

    //    this->tabs->setTabIcon(index, QIcon());
    //this->tabs->setTabEnabled(index, true);
    // this->editUrl->setText(url.toString());
}

void LMainWindow::slotGetNewTabIndex(QHash<int, LWebLoader *> hashIndex)
{
    this->tabIndex = hashIndex;
}

void LMainWindow::slotGetHistory(QList<QString>listUrl)
{
    this->listAllUrl.append(listUrl);
    QCompleter *completer = new QCompleter(this->listAllUrl, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    this->editUrl->setCompleter(completer);
}

void LMainWindow::slotClickedCloseTab(int index)
{
    //    this->tabs->removeTab(index);
}

void LMainWindow::slotMoteurChange(QString name)
{
    if (name == "Wikipedia")
        this->savMoteur = "http://fr.wikipedia.org/w/index.php?search=";
    else if (name == "Yahoo")
        this->savMoteur = "http://search." + name.toLower() + ".com/search?p=";
    else
        this->savMoteur = "http://" + name.toLower() + ".com/search?q=";
}

void LMainWindow::slotSendUrl()
{
    QString url = this->editUrl->text();

    if (url.contains(".") == false)
    {
        url = url.replace(" ", "+");
        url = url.replace("\"", "%22");
        url = this->savMoteur + url;
    }
    if (url.left(7) != "http://")
        url = "http://" + url;

    this->editUrl->setText(url);

    int currentIndex = this->tabs->currentIndex();
    LWebLoader *page = this->tabIndex.value(currentIndex);
    page->setUrl(url);
}

#include <QDebug>
//Slots of help menu
void LMainWindow::slotHelpLikely ()
{
    qDebug("On affiche l'aide LikelyWeb");
}
void LMainWindow::slotUpdateNote ()
{
    qDebug("On affiche le release-note");
}
void LMainWindow::slotBugReport ()
{
    qDebug("On afficche le menu de rapport de bug");
}
void LMainWindow::slotReportDeadLink ()
{
    qDebug("On affiche le menu de rapport de liens morts");
}
void LMainWindow::slotReportDangerSite ()
{
    qDebug("On affiche le rapport de site dangereux");
}
void LMainWindow::slotCheckUpdate ()
{
    qDebug("On affiche le menu de verification de MAJ");
}
void LMainWindow::slotAboutUs ()
{
    qDebug("On affiche le A propos");
}
//Slots of help menu


//Slots of tools menu
void LMainWindow::slotErrorManage ()
{
    qDebug("Ouvrir la console d'erreurs");
}
void LMainWindow::slotMainOptMenu ()
{
    qDebug("Ouvrir le menu d'option general");
}
void LMainWindow::slotErasePrivateData ()
{
    qDebug("Ouvrir le menu de supression des donnee persos");
}
void LMainWindow::slotWebSearch ()
{
    qDebug("Deplacer curseur dans Recherche avec son moteur de recherche");
}
void LMainWindow::slotDownloadManage ()
{
    qDebug("On ouvre le gestionnaire de download");
}
//Slots of tools menu


// Slots of favorites menu
void LMainWindow::slotFavoriteManage ()
{
    qDebug("on affiche le gestionnaire de favoris");
}
void LMainWindow::slotAddToFavorites ()
{
    qDebug("Ajouter page aux favoris");
}
void LMainWindow::slotSuscribeRss ()
{
    qDebug("Abonnement RSS de la page");
}
void LMainWindow::slotAddTabsToFavorites ()
{
    qDebug("Ajouter tous les onglet aux favoris");
}
// Slots of favorites menu


// Slots of history menu
void LMainWindow::slotHistory ()
{
    qDebug("On affiche le gestionnaire historique");
}
void LMainWindow::slotBackHome ()
{
    qDebug("REtour HomePage");
}
void LMainWindow::slotLastPage ()
{
    qDebug("Page Precedente");
}
void LMainWindow::slotNextPage ()
{
    qDebug("Page Suivante");
}
// Slots of history menu


// Slots of aff menu
void LMainWindow::slotCodeSource ()
{
    qDebug("Affichage Code Source");
}
void LMainWindow::slotFullScreen ()
{
    qDebug("Affichage plein ecran");
}
void LMainWindow::slotReload ()
{
    qDebug("Actualise la page");
}
void LMainWindow::slotStopLoad ()
{
    qDebug("Arrete le chargement de la page");
}
void LMainWindow::slotAffStatus ()
{
    qDebug("Affichage barre d'etat");
}
// Slots of aff menu


// Slots of edit menu
void LMainWindow::slotSearch ()
{
    qDebug("Rechercher sur la page");
}
void LMainWindow::slotMyConf()
{
    qDebug("Preferences");
}
void LMainWindow::slotDelete()
{
    qDebug("Supprimer");
}
void LMainWindow::slotSelectAll()
{
    qDebug("Tout Selectionner");
}
void LMainWindow::slotRepeatAction()
{
    qDebug("Repeter action");
}
void LMainWindow::slotCancelAction()
{
    qDebug("Annuler action");
}
void LMainWindow::slotCut()
{
    qDebug("On coupe !");
}
void LMainWindow::slotCopy()
{
    qDebug("On copie !");
}
void LMainWindow::slotPaste()
{
    qDebug("On colle !");
}
// Slots of edit menu


// Slots of file menu
void LMainWindow::slotImportSpec ()
{
    qDebug("On affiche l'importation des preference depuis IE");
}
void LMainWindow::slotPrint ()
{
    qDebug("Impression");
}
void LMainWindow::slotPrintPreview ()
{
    qDebug("On affiche l'apercu avant impression");
}
void LMainWindow::slotPagePoperties ()
{
    qDebug("On affiche les propriete de la page");
}
void LMainWindow::slotSavePage ()
{
    qDebug("On enregistre la papage");
}
void LMainWindow::slotCloseWindow ()
{
    qDebug("On close la fenetre en cours");
}

void LMainWindow::slotCloseTab ()
{
    this->tabs->closeTab(this->tabs->currentIndex());
}

void LMainWindow::slotOpenFile ()
{
    qDebug("On lance l'ouverture d'un fichier");
}
void LMainWindow::slotGoto ()
{
    qDebug("On va sur la barre d'adresse");
}
void LMainWindow::slotHelp()
{
    qDebug("On affiche l'aide");
}
void LMainWindow::slotQuit()
{
    this->close();
}
void LMainWindow::slotOption()
{
    qDebug("On affiche le gestionnaire d'options");
}

void LMainWindow::slotTitleChange(QString title)
{
    this->tabs->tabTitleChange(this->tabs->currentIndex(), title);
    /*
    int index = this->tabs->currentIndex();
    if (title.size() > 20)
        title.resize(20);
    else
    {
        while (title.size() > 20)
            title += " ";
    }
    this->tabs->setTabText(index, title);
*/
}

void LMainWindow::slotTab()
{
    LWebLoader *web   = new LWebLoader(this);

    this->connect(web, SIGNAL(sigSendNewInfosPage(QUrl, QIcon)), this, SLOT(slotNewInfoPage(QUrl, QIcon)));
    this->connect(web, SIGNAL(sigSendHistory(QList<QString>)),   this, SLOT(slotGetHistory(QList<QString>)));
    this->connect(web, SIGNAL(sigTitleChange(QString)),          this, SLOT(slotTitleChange(QString)));

    int index = this->tabs->addTabWidget("plo", "lol");
    this->tabs->addWidget(web, index);
    this->tabIndex.insert(index, web);
}

void LMainWindow::slotWindow ()
{
    qDebug("On cree une nouvelle fenetre");
}

void LMainWindow::slotWinPrivate ()
{
    qDebug("Nouvelle fenetre en private mode");
}
// Slots of file menu

