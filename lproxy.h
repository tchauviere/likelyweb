#ifndef LPROXY_H
#define LPROXY_H

#include <QWidget>
#include <QGridLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>

class LProxy : public QWidget
{
    Q_OBJECT
private:
    QGridLayout *layout;
    QCheckBox   *proxyNone;
    QCheckBox   *proxyAuto;
    QCheckBox   *proxyManu;
    QLineEdit   *proxySsl;
    QLineEdit   *proxyFtp;
    QLineEdit   *proxyHttp;
    QSpinBox    *portFtp;
    QSpinBox    *portHttp;
    QSpinBox    *portSsl;

public:
    LProxy(QWidget *proxy = 0);
};

#endif // LPROXY_H
