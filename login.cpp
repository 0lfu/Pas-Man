#include "login.h"
#include "ui_login.h"

#include <QShortcut>

#include "pas_list.h"
#include "encryption.h"
#include "licence.h"
#include "about.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->errorLabel->hide();
    setupUsernameLabel();
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginBtn_clicked()
{
    QString password = ui->password->text();
    if (password.isEmpty())
    {
        ui->errorLabel->show();
        ui->errorLabel->setText("Please enter a password");
        return;
    }
    Encryption file;
    if (file.verifyUser(password))
    {
        PasList *pasList = new PasList(this);
        pasList->show();
    }
    else
    {
        ui->errorLabel->show();
        ui->errorLabel->setText("Wrong password!");
    }
}

void Login::setupUsernameLabel()
{
    Encryption encryption;
    QString username = encryption.getUsername();

    if (!username.isEmpty()) {
        ui->welcomeLbl->setText("Welcome back, " + username + "!");
    }
}


void Login::on_licenseBtn_clicked()
{
    Licence *licence = new Licence(this);
    licence->show();
}

void Login::on_aboutBtn_clicked()
{
    About *about = new About(this);
    about->show();
}

void Login::on_password_returnPressed()
{
    ui->loginBtn->click();
}

