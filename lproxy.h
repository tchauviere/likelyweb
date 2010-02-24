#ifndef LPROXY_H
#define LPROXY_H

#include <QWidget>
#include <QGridLayout>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>
#include <QSettings>

class LProxy : public QWidget
{
    Q_OBJECT

private:
    QGridLayout    *layout;
    QGridLayout    *groupLayout;
    QRadioButton   *proxyNone;
    QRadioButton   *proxyAuto;
    QRadioButton   *proxyManu;
    QLineEdit      *proxySsl;
    QLineEdit      *proxyFtp;
    QLineEdit      *proxyHttp;
    QSpinBox       *portFtp;
    QSpinBox       *portHttp;
    QSpinBox       *portSsl;
    QGroupBox      *groupBox;
    QPushButton    *validProxy;
    QPushButton    *quitProxy;
    QSettings      *infoProxy;

    void disableItem(bool a);
    void setSettings();

public:
    LProxy(QWidget *proxy = 0);

private slots:
    void slotProxyNone(bool a);
    void slotProxyManu(bool a);
    void slotProxyAuto(bool a);
    void slotValide();
    void slotClose();
};

#endif // LPROXY_H
