#include "lmenubar.h"

LMenuBar::LMenuBar(QWidget *parent) : QWidget(parent)
{
    this->layout     = new QGridLayout();
    this->mMenu      = new QMenuBar(this);
    this->files      = new QMenu(this);
    this->edit       = new QMenu(this);
    this->aff        = new QMenu(this);
    this->history    = new QMenu(this);
    this->favorites  = new QMenu(this);
    this->tools      = new QMenu(this);
    this->help       = new QMenu(this);

    // Give name to menus
    this->help->setTitle(tr("Aide"));
    this->tools->setTitle(tr("Outils"));
    this->favorites->setTitle(tr("Favoris"));
    this->history->setTitle(tr("Historique"));
    this->aff->setTitle(tr("Affichage"));
    this->edit->setTitle(tr("Edition"));
    this->files->setTitle(tr("Fichier"));
    // Give name to menus

    // Add menus to MenuBar
    this->mMenu->addMenu(this->files);
    this->mMenu->addMenu(this->edit);
    this->mMenu->addMenu(this->aff);
    this->mMenu->addMenu(this->history);
    this->mMenu->addMenu(this->favorites);
    this->mMenu->addMenu(this->tools);
    this->mMenu->addMenu(this->help);
    // Add menus to MenuBar

    // Manage the file menu
    this->files->addAction(QIcon(":newwin"), tr("Nouvelle Fenetre"), this, SLOT(slotWindow()), QKeySequence("Ctrl+N"));
    this->files->addAction(QIcon(":newtab"), tr("Nouvel Onglet"), this, SLOT(slotTab()), QKeySequence("Ctrl+T"));
    this->files->addAction(QIcon(":navpriv"), tr("Fenetre Navigation Privee"), this, SLOT(slotWinPrivate()), QKeySequence("Ctrl+Shift+N"));
    this->files->addAction(tr("Aller a l'adresse ..."), this, SLOT(slotGoto()), QKeySequence("Ctrl+L"));
    this->files->addAction(tr("Ouvrir un fichier ..."), this, SLOT(slotOpenFile()), QKeySequence("Ctrl+O"));
    this->files->addAction(tr("Fermer la fenetre"), this, SLOT(slotCloseWindow()), QKeySequence("Ctrl+Shift+W"));
    this->files->addAction(tr("Fermer l'onglet"), this, SLOT(slotCloseTab()), QKeySequence("Ctrl+W"));
    this->files->addSeparator();
    this->files->addAction(tr("Enregistrer sous ..."), this, SLOT(slotSavePage()), QKeySequence("Ctrl+S"));
    this->files->addAction(tr("Proprietes de la page"), this, SLOT(slotPagePoperties()));
    this->files->addAction(tr("Apercu avant impression"), this, SLOT(slotPrintPreview()));
    this->files->addAction(QIcon(":printer"), tr("Imprimer"), this, SLOT(slotPrint()), QKeySequence("Ctrl+P"));
    this->files->addSeparator();
    this->files->addAction(tr("Importer preferences ..."), this, SLOT(slotImportSpec()));
    this->files->addSeparator();
    this->files->addAction(tr("Quitter"), this, SLOT(slotQuit()));
    // Manage the file menu

    // Manage the edit menu
    this->edit->addAction(tr("Annuler"), this, SLOT(slotCancelAction()), QKeySequence("Ctrl+Z"));
    this->edit->addAction(tr("Repeter"), this, SLOT(slotRepeatAction()), QKeySequence("Ctrl+Y"));
    this->edit->addSeparator();
    this->edit->addAction(tr("Couper"), this, SLOT(slotCut()), QKeySequence("Ctrl+X"));
    this->edit->addAction(tr("Copier"), this, SLOT(slotCopy()), QKeySequence("Ctrl+C"));
    this->edit->addAction(tr("Coller"), this, SLOT(slotPaste()), QKeySequence("Ctrl+V"));
    this->edit->addAction(tr("Supprimer"), this, SLOT(slotDelete()), QKeySequence("Del"));
    this->edit->addSeparator();
    this->edit->addAction(tr("Tout selectionner"), this, SLOT(slotSelectAll()), QKeySequence("Ctrl+A"));
    this->edit->addSeparator();
    this->edit->addAction(tr("Rechercher"), this, SLOT(slotSearch()), QKeySequence("Ctrl+F"));
    this->edit->addSeparator();
    this->edit->addAction(tr("Preferences"), this, SLOT(slotMyConf()));
    // Manage the edit menu

    // Manage the aff menu
    this->aff->addAction(tr("Barre d'outils"));
    this->aff->addAction(tr("Barre d'etat"), this, SLOT(slotAffStatus()));
    this->aff->addAction(tr("Panneau lateral"));
    this->aff->addSeparator();
    this->aff->addAction(tr("Arreter le chargement"), this, SLOT(slotStopLoad()), QKeySequence("Esc"));
    this->aff->addAction(tr("Acutaliser la page"), this, SLOT(slotReload()), QKeySequence("F5"));
    this->aff->addAction(tr("Taille du texte"));
    this->aff->addAction(tr("Style de la page"));
    this->aff->addSeparator();
    this->aff->addAction(tr("Encodage de caractere"));
    this->aff->addSeparator();
    this->aff->addAction(tr("Code source de la page"), this, SLOT(slotCodeSource()), QKeySequence("Ctrl+U"));
    this->aff->addAction(tr("Plein Ecran"), this, SLOT(slotFullScreen()), QKeySequence("F11"));
    // Manage the aff menu

    // Manage the history menu
    this->history->addAction(tr("Page precedente"), this, SLOT(slotLastPage()), QKeySequence("Alt+Left"));
    this->history->addAction(tr("Page Suivante"), this, SLOT(slotNextPage()), QKeySequence("Alt+Right"));
    this->history->addAction(tr("Page d'accueil"), this, SLOT(slotBackHome()), QKeySequence("Alt+Home"));
    this->history->addAction(tr("Afficher historique"), this, SLOT(slotHistory()), QKeySequence("Ctrl+Shift+H"));
    this->history->addSeparator();
    this->history->addAction(tr("Onglets recemment fermes"));
    this->history->addAction(tr("Fenetres recemment fermes"));
    // Manage the history menu

    // Manage the favorites menu
    this->favorites->addAction(tr("Ajouter cette page aux favoris"), this, SLOT(slotAddToFavorites()), QKeySequence("Ctrl+D"));
    this->favorites->addAction(tr("S'abonner au RSS de la page ..."), this, SLOT(slotSuscribeRss()));
    this->favorites->addAction(tr("Ajouter les onglets aux favoris"), this, SLOT(slotAddTabsToFavorites()), QKeySequence("Ctrl+Shift+D"));
    this->favorites->addAction(tr("Organiser les favoris"), this, SLOT(slotFavoriteManage()), QKeySequence("Ctrl+Shift+B"));
    this->favorites->addSeparator();
    this->favorites->addAction(tr("Barre d'outils des favoris"));
    // Manage the favorites menu

    //Manage the tools menu
    this->tools->addAction(tr("Recherche Web"), this, SLOT(slotWebSearch()), QKeySequence("Ctrl+L"));
    this->tools->addAction(tr("Telechargements"), this, SLOT(slotDownloadManage()), QKeySequence("Ctrl+J"));
    this->tools->addAction(tr("Manager d'erreurs"), this, SLOT(slotErrorManage()), QKeySequence("Ctrl+Shift+J"));
    this->tools->addSeparator();
    this->tools->addAction(tr("Effacer vos donnees personnelles"), this, SLOT(slotErasePrivateData()), QKeySequence("Ctrl+Shift+Del"));
    this->tools->addSeparator();
    this->tools->addAction(tr("Options Generales"), this, SLOT(slotMainOptMenu()));
    //Manage the tools menu

    // Manage the help menu
    this->help->addAction(tr("Aide LikelyWeb"), this, SLOT(slotHelpLikely()), QKeySequence("F1"));
    this->help->addAction(tr("Recherche de mise a jour"), this, SLOT(slotCheckUpdate()));
    this->help->addAction(tr("Note de mise a jour"), this, SLOT(slotUpdateNote()));
    this->help->addAction(tr("Rapporter un bug"), this, SLOT(slotBugReport()));
    this->help->addSeparator();
    this->help->addAction(tr("Rapporter un site web mort"), this, SLOT(slotReportDeadLink()));
    this->help->addAction(tr("Rapporter un site web dangereux"), this, SLOT(slotReportDangerSite()));
    this->help->addSeparator();
    this->help->addAction(tr("A propos"), this, SLOT(slotAboutUs()));
    // Manage the help menu

    this->layout->setSpacing(0);
    this->layout->setMargin(0);

    // this->layout->addWidget(this->openMenu, 0, 0, 1, 0, Qt::AlignCenter);
    this->layout->addWidget(this->mMenu, 1, 0);
    this->setLayout(this->layout);
}

//Slots of help menu
void LMenuBar::slotHelpLikely ()
{
    qDebug("On affiche l'aide LikelyWeb");
}
void LMenuBar::slotUpdateNote ()
{
    qDebug("On affiche le release-note");
}
void LMenuBar::slotBugReport ()
{
    qDebug("On afficche le menu de rapport de bug");
}
void LMenuBar::slotReportDeadLink ()
{
    qDebug("On affiche le menu de rapport de liens morts");
}
void LMenuBar::slotReportDangerSite ()
{
    qDebug("On affiche le rapport de site dangereux");
}
void LMenuBar::slotCheckUpdate ()
{
    qDebug("On affiche le menu de verification de MAJ");
}
void LMenuBar::slotAboutUs ()
{
    qDebug("On affiche le A propos");
}
//Slots of help menu

//Slots of tools menu
void LMenuBar::slotErrorManage ()
{
    qDebug("Ouvrir la console d'erreurs");
}
void LMenuBar::slotMainOptMenu ()
{
    qDebug("Ouvrir le menu d'option general");
}
void LMenuBar::slotErasePrivateData ()
{
    qDebug("Ouvrir le menu de supression des donnee persos");
}
void LMenuBar::slotWebSearch ()
{
    qDebug("Deplacer curseur dans Recherche avec son moteur de recherche");
}
void LMenuBar::slotDownloadManage ()
{
    qDebug("On ouvre le gestionnaire de download");
}
//Slots of tools menu

// Slots of favorites menu
void LMenuBar::slotFavoriteManage ()
{
    qDebug("on affiche le gestionnaire de favoris");
}
void LMenuBar::slotAddToFavorites ()
{
    qDebug("Ajouter page aux favoris");
}
void LMenuBar::slotSuscribeRss ()
{
    qDebug("Abonnement RSS de la page");
}
void LMenuBar::slotAddTabsToFavorites ()
{
    qDebug("Ajouter tous les onglet aux favoris");
}
// Slots of favorites menu

// Slots of history menu
void LMenuBar::slotHistory ()
{
    qDebug("On affiche le gestionnaire historique");
}
void LMenuBar::slotBackHome ()
{
    this->page->setUrl(QUrl("http://www.google.fr"));
    qDebug("Retour HomePage");
}
void LMenuBar::slotLastPage ()
{
    this->page->back();
}
void LMenuBar::slotNextPage ()
{
    this->page->forward();
}
// Slots of history menu

// Slots of aff menu
#include <QWebFrame>
#include <QDebug>

void LMenuBar::slotCodeSource ()
{
    qDebug("Affichage Code Source");
}
void LMenuBar::slotFullScreen ()
{
    qDebug("Affichage plein ecran");
}
void LMenuBar::slotReload ()
{
    this->page->reload();
}

void LMenuBar::slotStopLoad ()
{
    this->page->stop();
}

void LMenuBar::slotAffStatus ()
{
    qDebug("Affichage barre d'etat");
}
// Slots of aff menu

// Slots of edit menu
void LMenuBar::slotSearch ()
{
    qDebug("Rechercher sur la page");
}
void LMenuBar::slotMyConf()
{
    qDebug("Preferences");
}
void LMenuBar::slotDelete()
{
    qDebug("Supprimer");
}
void LMenuBar::slotSelectAll()
{
    //  w8 menu n2 de chauvichauva .-)
    qDebug("Tout Selectionner");
}
void LMenuBar::slotRepeatAction()
{
    qDebug("Repeter action");
}
void LMenuBar::slotCancelAction()
{
    this->page->stop();
}
void LMenuBar::slotCut()
{
    qDebug("On coupe !");
}
void LMenuBar::slotCopy()
{
    qDebug("On copie !");
}
void LMenuBar::slotPaste()
{
    qDebug("On colle !");
}
// Slots of edit menu

// Slots of file menu
void LMenuBar::slotImportSpec ()
{
    qDebug("On affiche l'importation des preference depuis IE");
}
void LMenuBar::slotPrint ()
{
    qDebug("Impression");
}
void LMenuBar::slotPrintPreview ()
{
   qDebug("On affiche l'apercu avant impression");
}
void LMenuBar::slotPagePoperties ()
{
    qDebug("On affiche les propriete de la page");
}
void LMenuBar::slotSavePage ()
{
    QString html = this->page->page()->currentFrame()->toHtml();
    QFile file(QDir::homePath() + "/nouveau_fichier.html");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream flux(&file);

    flux.setCodec("UTF-8");
    flux << html << endl;
}
void LMenuBar::slotCloseWindow ()
{
    this->window()->close();
}
void LMenuBar::slotCloseTab ()
{
    qDebug("On ferme l'onglet courant");
}
void LMenuBar::slotOpenFile ()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::homePath(),
                                                    tr("Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)"));
    this->page->setUrl(QUrl(fileName));
}
void LMenuBar::slotGoto ()
{
    qDebug("On va sur la barre d'adresse");
}
void LMenuBar::slotHelp ()
{
    qDebug("On affiche l'aide");
}
void LMenuBar::slotQuit ()
{
    close();
}
void LMenuBar::slotOption ()
{
    qDebug("On affiche le gestionnaire d'options");
}
void LMenuBar::slotTab ()
{
    qDebug("On cree un nouvel onglet");
}
void LMenuBar::slotWindow ()
{
    qDebug("On cree une nouvelle fenetre");
}
void LMenuBar::slotWinPrivate ()
{
    qDebug("Nouvelle fenetre en private mode");
}
// Slots of file menu

void LMenuBar::setPageInMenu(QWebView *page)
{
    this->page = page;
}
