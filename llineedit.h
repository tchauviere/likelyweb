#ifndef LLINEEDIT_H
#define LLINEEDIT_H

#include <QLineEdit>
#include <QPaintEvent>
#include <QPalette>
#include <QPainter>
#include <qprogressbar.h>
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>

class LLineEdit : public QProgressBar
{
    Q_OBJECT

private:
    QHBoxLayout *layout;
    QPainter p;
    QLineEdit *champs;
    int progress;

public:
    LLineEdit(QWidget *parent = 0);
    void loadStart();
    void loadProgress(int progress);
    void loadFinish();
    void setIcon(QIcon icon);
    void setChampsText(QString url);

private slots:
    void slotChampsReturnPressed();

signals:
    void sigReturnPressed(QString url);
};

#endif // LLINEEDIT_H
