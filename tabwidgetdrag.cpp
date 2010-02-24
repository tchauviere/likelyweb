#include "tabwidgetdrag.h"
#include <QDebug>

TabWidgetDrag::TabWidgetDrag(QWidget *parent) : QTabWidget (parent)
{
    this->setAcceptDrops(true);
    //    this->textBrowser = new QTextBrowser(this);
}

void TabWidgetDrag::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() && Qt::LeftButton))
    {
        qDebug() << "quit";
        return;
    }
    if ((event->pos() - dragStartPosition).manhattanLength()< QApplication::startDragDistance())
        return;
    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;

    QWidget *widget = this->currentWidget();
    LWebPage *page = (LWebPage *)widget;
    QString url = page->getUrl();
    qDebug() << "url" << url;

    mimeData->setData("text/plain", url.toUtf8());
    drag->setMimeData(mimeData);
    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
    this->removeTab(this->currentIndex());
    if (this->count() == 0)
        this->window()->close();
}

void    TabWidgetDrag::mousePressEvent(QMouseEvent * event)
{
    if (event->button() == Qt::RightButton)
    {
        dragStartPosition = event->pos();
        qDebug() << "mouse press envent";
    }
}

void	TabWidgetDrag::dragEnterEvent ( QDragEnterEvent * event )
{
    //    if (event->mimeData()->hasFormat("text/plain"))
    event->acceptProposedAction();
    qDebug() << "drag enter event";
}
void	TabWidgetDrag::dragLeaveEvent ( QDragLeaveEvent * event )
{
    qDebug() << "leave";
    event->accept();
}
void	TabWidgetDrag::dragMoveEvent ( QDragMoveEvent * event )
{
    event->acceptProposedAction();
    qDebug() << "move";
}
void	TabWidgetDrag::dropEvent ( QDropEvent * event )
{
    LWebPage *page = new LWebPage(this);

    page->setUrl(event->mimeData()->text());
    this->addTab(page, "New Tab");
    event->acceptProposedAction();
    qDebug() << "drop event";
}
void	TabWidgetDrag::enterEvent ( QEvent * event )
{
    qDebug() << "enter event";

    event->accept();
}
