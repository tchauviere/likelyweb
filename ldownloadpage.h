#ifndef LDOWNLOADPAGE_H
#define LDOWNLOADPAGE_H

#include <QWidget>
#include <QGridLayout>

class LDownloadPage : public QWidget
{
    Q_OBJECT

private:
    QGridLayout *mainLayout;


public:
    LDownloadPage(QWidget *parent = 0);

    void setNewDL();
};

#endif // LDOWNLOADPAGE_H
