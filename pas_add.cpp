#include "pas_add.h"
#include "ui_pas_add.h"

#include <QMessageBox>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QUuid>

#include "pas_gen.h"
#include "pas_list.h"
#include "pas_check.h"
#include "login.h"
#include "encryption.h"

PasAdd::PasAdd(PasList *pasListInstance, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::PasAdd)
{
    ui->setupUi(this);
    ui->category->addItems({"Work", "School", "Education", "Personal", "Finance"});
}

PasAdd::~PasAdd()
{
    delete ui;
}


void PasAdd::on_cancelBtn_clicked()
{
    this->close();
}

void PasAdd::on_pasListBtn_clicked()
{
    PasList *pasList = new PasList(this);
    pasList->show();
}


void PasAdd::on_pasGenBtn_clicked()
{
    PasGen *pasGen = new PasGen(this);
    pasGen->show();
}


void PasAdd::on_pasCheckBtn_clicked()
{
    PasCheck *pasCheck = new PasCheck(this);
    pasCheck->show();
}


void PasAdd::on_addBtn_clicked()
{
    Encryption file;
    QUuid uniqueId = QUuid::createUuid();

    QJsonObject entry;
    entry["uid"] = uniqueId.toString();
    entry["name"] = ui->name->text();
    entry["username"] = ui->username->text();
    entry["password"] = ui->password->text();
    entry["URL"] = ui->URL->text();
    entry["category"] = ui->category->currentText();
    entry["notes"] = ui->notes->text();

    if (file.addOrUpdateEntry(entry)) {
        emit entryAdded();
        QMessageBox::information(this, "Success", "Data saved successfully!");
    } else {
        QMessageBox::warning(this, "Error", "Unknown error! Failed to save data!");
    }

    ui->name->clear();
    ui->username->clear();
    ui->password->clear();
    ui->URL->clear();
    ui->category->setCurrentIndex(0);
    ui->notes->clear();

    this->close();
}



void PasAdd::on_logOutBtn_clicked()
{
    Login *login = new Login(this);
    login->show();
}

