#ifndef ITEMDL_H
#define ITEMDL_H

#include <QWidget>
#include <QNetworkReply>
#include <QString>
#include <QIcon>

namespace Ui {
    class itemDl;
}

class itemDl : public QWidget
{
    Q_OBJECT
public:
    itemDl(QWidget *parent = 0);
    ~itemDl();

protected:
    void changeEvent(QEvent *e);

public slots:
    void slotSetText(QString text, QString url);
    void slotStopDl();
    void setReply(QNetworkReply *reply);
    void setIconFile(QIcon icon);
    void slotSetProgress(qint64 current,qint64 total);

signals:
    void sigStopDl();

private:
    QNetworkReply *reply;
    Ui::itemDl *ui;
};

#endif // ITEMDL_H
