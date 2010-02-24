#ifndef TABWIDGETDRAG_H
#define TABWIDGETDRAG_H

#include <QTabWidget>
#include <QMouseEvent>
#include <QMimeData>
#include <QPoint>
#include <QApplication>
#include <QTextBrowser>

#include "LWebPage.h"


class TabWidgetDrag : public QTabWidget
{
public:
    TabWidgetDrag(QWidget *parent = 0);
private:
    QPoint dragStartPosition;
    QTextBrowser *textBrowser;

protected:
    virtual void	dragEnterEvent ( QDragEnterEvent * event );
    virtual void	dragLeaveEvent ( QDragLeaveEvent * event );
    virtual void	dragMoveEvent ( QDragMoveEvent * event );
    virtual void	dropEvent ( QDropEvent * event );
    virtual void	enterEvent ( QEvent * event );
    virtual void        mousePressEvent(QMouseEvent *event);
    virtual void   mouseMoveEvent(QMouseEvent *event);

};

#endif // TABWIDGETDRAG_H
