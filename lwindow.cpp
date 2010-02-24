#include "lwindow.h"

LWindow::LWindow(QWidget *parent) : QWidget(parent)
{
    this->layout = new QGridLayout();
    this->tab    = new LTabWidget(this);

    this->layout->setSpacing(0);
    this->layout->setMargin(0);

    this->menuBar    = new QMenuBar(this);
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
    this->menuBar->addMenu(this->files);
    this->menuBar->addMenu(this->edit);
    this->menuBar->addMenu(this->aff);
    this->menuBar->addMenu(this->history);
    this->menuBar->addMenu(this->favorites);
    this->menuBar->addMenu(this->tools);
    this->menuBar->addMenu(this->help);
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

    this->layout->addWidget(this->menuBar, 0, 0);
    this->layout->addWidget(this->tab, 1, 0);

    this->setLayout(this->layout);
}


//Slots of help menu
void LWindow::slotHelpLikely ()
{
    qDebug("On affiche l'aide LikelyWeb");
}
void LWindow::slotUpdateNote ()
{
    qDebug("On affiche le release-note");
}
void LWindow::slotBugReport ()
{
    qDebug("On afficche le menu de rapport de bug");
}
void LWindow::slotReportDeadLink ()
{
    qDebug("On affiche le menu de rapport de liens morts");
}
void LWindow::slotReportDangerSite ()
{
    qDebug("On affiche le rapport de site dangereux");
}
void LWindow::slotCheckUpdate ()
{
    qDebug("On affiche le menu de verification de MAJ");
}
void LWindow::slotAboutUs ()
{
    qDebug("On affiche le A propos");
}
//Slots of help menu

//Slots of tools menu
void LWindow::slotErrorManage ()
{
    qDebug("Ouvrir la console d'erreurs");
}
void LWindow::slotMainOptMenu ()
{
    qDebug("Ouvrir le menu d'option general");
}
void LWindow::slotErasePrivateData ()
{
    qDebug("Ouvrir le menu de supression des donnee persos");
}
void LWindow::slotWebSearch ()
{
    qDebug("Deplacer curseur dans Recherche avec son moteur de recherche");
}
void LWindow::slotDownloadManage ()
{
    qDebug("On ouvre le gestionnaire de download");
}
//Slots of tools menu

// Slots of favorites menu
void LWindow::slotFavoriteManage ()
{
    qDebug("on affiche le gestionnaire de favoris");
}
void LWindow::slotAddToFavorites ()
{
    qDebug("Ajouter page aux favoris");
}
void LWindow::slotSuscribeRss ()
{
    qDebug("Abonnement RSS de la page");
}
void LWindow::slotAddTabsToFavorites ()
{
    qDebug("Ajouter tous les onglet aux favoris");
}
// Slots of favorites menu

// Slots of history menu
void LWindow::slotHistory ()
{
    qDebug("On affiche le gestionnaire historique");
}
void LWindow::slotBackHome ()
{
    //    this->page->setUrl(QUrl("http://www.google.fr"));
    qDebug("Retour HomePage");
}
void LWindow::slotLastPage ()
{
    //  this->page->back();
}
void LWindow::slotNextPage ()
{
    //    this->page->forward();
}
// Slots of history menu

// Slots of aff menu

void LWindow::slotCodeSource ()
{
    qDebug("Affichage Code Source");
}
void LWindow::slotFullScreen ()
{
    qDebug("Affichage plein ecran");
}
void LWindow::slotReload ()
{
    //this->page->reload();
}

void LWindow::slotStopLoad ()
{
    //    this->page->stop();
}

void LWindow::slotAffStatus ()
{
    qDebug("Affichage barre d'etat");
}
// Slots of aff menu

// Slots of edit menu
void LWindow::slotSearch ()
{
    qDebug("Rechercher sur la page");
}
void LWindow::slotMyConf()
{
    qDebug("Preferences");
}
void LWindow::slotDelete()
{
    qDebug("Supprimer");
}
void LWindow::slotSelectAll()
{
    //  w8 menu n2 de chauvichauva .-)
    qDebug("Tout Selectionner");
}
void LWindow::slotRepeatAction()
{
    qDebug("Repeter action");
}
void LWindow::slotCancelAction()
{
    //    this->page->stop();
}
void LWindow::slotCut()
{
    qDebug("On coupe !");
}
void LWindow::slotCopy()
{
    qDebug("On copie !");
}
void LWindow::slotPaste()
{
    qDebug("On colle !");
}
// Slots of edit menu

// Slots of file menu
void LWindow::slotImportSpec ()
{
    qDebug("On affiche l'importation des preference depuis IE");
}
void LWindow::slotPrint ()
{
    qDebug("Impression");
}
void LWindow::slotPrintPreview ()
{
    qDebug("On affiche l'apercu avant impression");
}
void LWindow::slotPagePoperties ()
{
    qDebug("On affiche les propriete de la page");
}
void LWindow::slotSavePage ()
{
    /*    QString html = this->page->page()->currentFrame()->toHtml();
    QFile file(QDir::homePath() + "/nouveau_fichier.html");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream flux(&file);

    flux.setCodec("UTF-8");
    flux << html << endl;
*/
}
void LWindow::slotCloseWindow ()
{
    this->window()->close();
}
void LWindow::slotCloseTab ()
{
    this->tab->removeTab();
    qDebug("On ferme l'onglet courant");
}
void LWindow::slotOpenFile ()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::homePath(),
                                                    tr("Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)"));
    //  this->page->setUrl(QUrl(fileName));
}
void LWindow::slotGoto ()
{
    qDebug("On va sur la barre d'adresse");
}
void LWindow::slotHelp ()
{
    qDebug("On affiche l'aide");
}
void LWindow::slotQuit ()
{
    this->close();
}
void LWindow::slotOption ()
{
    qDebug("On affiche le gestionnaire d'options");
}
void LWindow::slotTab ()
{
    this->tab->creatNewTab();
}
void LWindow::slotWindow ()
{
    LWindow *w = new LWindow();

    w->show();
}
void LWindow::slotWinPrivate ()
{
    qDebug("Nouvelle fenetre en private mode");
}
// Slots of file menu

LWindow::~LWindow()
{

}
