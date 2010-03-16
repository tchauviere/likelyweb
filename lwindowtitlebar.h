#ifndef LWINDOWTITLEBAR_H
#define LWINDOWTITLEBAR_H

#include <QLabel>
#include <QPoint>
#include <QWidget>
#include <QMouseEvent>
#include <QGridLayout>
#include <QPushButton>
#include <QBitmap>

class LWindowTitleBar : public QWidget
{
private:
    QPoint diff;

protected:
    void mousePressEvent  (QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent   (QMouseEvent *event);

public:
    LWindowTitleBar(QWidget *parent = 0);
};

#endif // LWINDOWTITLEBAR_H
