#ifndef LBOXLOGIN_H
#define LBOXLOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QCheckBox>
#include <QGridLayout>
#include <QSettings>
#include <QLabel>
#include <QDebug>

class LBoxLogin : public QWidget
{
    Q_OBJECT

private:
    QGridLayout *layout;
    QPushButton *bpValid;
    QPushButton *bpQuit;
    QLineEdit   *editPass;
    QLineEdit   *editUser;
    QString     password;
    QString     login;
    QCheckBox   *remenber;
    QLabel      *labelUser;
    QLabel      *labelPasswd;
    QSettings   *settings;

public:
    LBoxLogin(QWidget *parent = 0);
    QString getPassword();
    QString getLogin();
    void checkInfos();

private slots:
    void slotValid();

    signals:
    void sigSendInfos(QString password, QString login);
};

#endif // LBOXLOGIN_H
