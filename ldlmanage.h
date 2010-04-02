#ifndef LDLMANAGE_H
#define LDLMANAGE_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollBar>

#include "itemdl.h"


namespace Ui {
    class LDlManage;
}

class LDlManage : public QWidget
{
    Q_OBJECT

public:
    LDlManage(QWidget *parent = 0);
    ~LDlManage();

protected:
    void changeEvent(QEvent *e);
    void addDdlInWidget();
    void addDdl();

private:
    int count;
    Ui::LDlManage *ui;
    QWidget *boxWidget;
    QVBoxLayout *boxLayout;

    public slots:
    void addNewItem(itemDl *dl);

private slots:
    void slotClearDdl();
};

#endif // LDLMANAGE_H
