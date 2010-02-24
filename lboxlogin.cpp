#include "lboxlogin.h"

LBoxLogin::LBoxLogin(QWidget *parent) :QWidget(parent)
{
    this->layout = new QGridLayout();
    this->bpQuit = new QPushButton(tr("Quiter"), this);
    this->bpValid = new QPushButton(tr("Valider"), this);
    this->remenber = new QCheckBox("Se souvenir de mon mot de passe", this);
    this->editPass = new QLineEdit(this);
    this->editUser = new QLineEdit(this);
    this->labelUser = new QLabel(tr("User"), this);
    this->labelPasswd = new QLabel(tr("Password"), this);
    this->settings = new QSettings("Proxy", "Likelyweb", this);

    this->checkInfos();

    this->connect(this->bpValid, SIGNAL(clicked()), this, SLOT(slotValid()));
    this->connect(this->bpQuit, SIGNAL(clicked()), this, SLOT(close()));

    this->editPass->setEchoMode(QLineEdit::Password);

    this->layout->addWidget(this->labelUser, 0, 0);
    this->layout->addWidget(this->labelPasswd, 1, 0);
    this->layout->addWidget(this->editUser, 0, 1);
    this->layout->addWidget(this->editPass, 1, 1);
    this->layout->addWidget(this->remenber, 2, 0, 1, 0);
    this->layout->addWidget(this->bpValid, 3, 0);
    this->layout->addWidget(this->bpQuit, 3, 1);

    this->setLayout(this->layout);
}

void LBoxLogin::slotValid()
{
    this->password = this->editPass->text();
    this->login = this->editUser->text();
    if (this->remenber->isChecked() == true)
    {
        this->settings->setValue("user_proxy", this->login);
        this->settings->setValue("passwd_proxy", this->password);
        this->settings->setValue("remember_info", this->remenber->isChecked());
    }
    emit this->sigSendInfos(this->password, this->login);

    this->close();
}

void LBoxLogin::checkInfos()
{
    if (this->settings->value("remember_info") == true)
    {
        this->editUser->setText(this->settings->value("user_proxy").toString());
        this->editPass->setText(this->settings->value("passwd_proxy").toString());
    }
}
