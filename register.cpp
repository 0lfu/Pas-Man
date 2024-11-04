#include "register.h"
#include "ui_register.h"

#include <QFile>
#include <QShortcut>

#include "login.h"
#include "pas_list.h"
#include "encryption.h"
#include "about.h"
#include "licence.h"


Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->errorLabel->hide();
    QFile file("user.enc");
    if (file.exists())
    {
        Login *login = new Login(this);
        login->show();
    }
}

Register::~Register()
{
    delete ui;
}


void Register::on_registerBtn_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    if (username.isEmpty() || password.isEmpty())
    {
        ui->errorLabel->show();
        ui->errorLabel->setText("Please enter a username and password");
        return;
    }

    Encryption file;
    if (file.createUserEntry(username, password))
    {
        PasList *pasList = new PasList(this);
        pasList->show();
    }
    else
    {
        ui->errorLabel->show();
        ui->errorLabel->setText("An error occured while creating the user entry");
    }
}


void Register::on_aboutBtn_clicked()
{
    About *about = new About(this);
    about->show();
}


void Register::on_licenseBtn_clicked()
{
    Licence *licence = new Licence(this);
    licence->show();
}


void Register::on_password_returnPressed()
{
    ui->registerBtn->click();
}

