#include "pas_gen.h"
#include "ui_pas_gen.h"

#include <QRandomGenerator>

#include "pas_add.h"
#include "pas_list.h"
#include "pas_check.h"
#include "login.h"

PasGen::PasGen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasGen)
{
    ui->setupUi(this);
    generatePassword();
}

PasGen::~PasGen()
{
    delete ui;
}


void PasGen::on_pasListBtn_clicked()
{
    PasList *pasList = new PasList(this);
    pasList->show();
}


void PasGen::on_pasCheckBtn_clicked()
{
    PasCheck *pasCheck = new PasCheck(this);
    pasCheck->show();
}

void PasGen::on_addBtn_clicked()
{
    generatePassword();
}


void PasGen::on_charCountSlider_valueChanged(int value)
{
    ui->counter->setText(QString::number(value));
    generatePassword();
}

void PasGen::generatePassword()
{
    QString password;
    QString smallLetters = "abcdefghijklmnopqrstuvwxyz";
    QString capitalLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString numbers = "0123456789";
    QString symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    QString possibleChars;
    if (ui->smallRad->isChecked())
        possibleChars += smallLetters;
    if (ui->capitalRad->isChecked())
        possibleChars += capitalLetters;
    if (ui->numberRad->isChecked())
        possibleChars += numbers;
    if (ui->charRad->isChecked())
        possibleChars += symbols;

    if (possibleChars.isEmpty()) {
        ui->pasGenEdit->setText("Select at least one option");
        return;
    }

    int charCount = ui->charCountSlider->value();
    for (int i = 0; i < charCount; ++i) {
        int index = QRandomGenerator::global()->bounded(possibleChars.size());
        password += possibleChars[index];
    }

    ui->pasGenEdit->setText(password);
}

void PasGen::on_logOutBtn_clicked()
{
    Login *login = new Login(this);
    login->show();
}

