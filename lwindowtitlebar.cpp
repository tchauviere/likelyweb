#include "lwindowtitlebar.h"

LWindowTitleBar::LWindowTitleBar(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background-image: url(:background);");
}

void LWindowTitleBar::mousePressEvent(QMouseEvent *event)
{
    diff = event->pos();

    this->setCursor(QCursor(Qt::SizeAllCursor));
}

void LWindowTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    this->setCursor(QCursor(Qt::ArrowCursor));
}

void LWindowTitleBar::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p = event->globalPos();

    this->window()->move(p - diff);
}
