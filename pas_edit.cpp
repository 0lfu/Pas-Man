#include "pas_edit.h"
#include "ui_pas_edit.h"

#include <QMessageBox>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "pas_gen.h"
#include "pas_list.h"
#include "pas_check.h"
#include "login.h"
#include "encryption.h"

PasEdit::PasEdit(PasList *pasListInstance, const QJsonObject &entryData, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::PasEdit),
    entryData(entryData)
{
    ui->setupUi(this);
    ui->category->addItems({"Work", "School", "Education", "Personal", "Finance"});

    ui->name->setText(entryData["name"].toString());
    ui->username->setText(entryData["username"].toString());
    ui->password->setText(entryData["password"].toString());
    ui->URL->setText(entryData["URL"].toString());
    ui->category->setCurrentText(entryData["category"].toString());
    ui->notes->setText(entryData["notes"].toString());
}

PasEdit::~PasEdit()
{
    delete ui;
}

void PasEdit::on_cancelBtn_clicked()
{
    this->close();
}

void PasEdit::on_pasListBtn_clicked()
{
    PasList *pasList = new PasList(this);
    pasList->show();
}

void PasEdit::on_pasGenBtn_clicked()
{
    PasGen *pasGen = new PasGen(this);
    pasGen->show();
}

void PasEdit::on_pasCheckBtn_clicked()
{
    PasCheck *pasCheck = new PasCheck(this);
    pasCheck->show();
}

void PasEdit::on_updateBtn_clicked()
{
    Encryption file;

    QJsonObject updatedEntry;
    updatedEntry["uid"] = entryData["uid"].toString();
    updatedEntry["name"] = ui->name->text();
    updatedEntry["username"] = ui->username->text();
    updatedEntry["password"] = ui->password->text();
    updatedEntry["URL"] = ui->URL->text();
    updatedEntry["category"] = ui->category->currentText();
    updatedEntry["notes"] = ui->notes->text();

    if (file.addOrUpdateEntry(updatedEntry)) {
        QMessageBox::information(this, "Success", "Data updated and encrypted successfully!");
        emit entryUpdated();
    } else {
        QMessageBox::warning(this, "Error", "Failed to update data!");
    }

    this->close();
}

void PasEdit::on_removeBtn_clicked()
{
    Encryption file;

    if (file.removeEntry(entryData["uid"].toString())) {
        QMessageBox::information(this, "Success", "Data removed and encrypted successfully!");
        emit entryUpdated();
    } else {
        QMessageBox::warning(this, "Error", "Failed to remove data!");
    }

    this->close();
}


void PasEdit::on_logOutBtn_clicked()
{
    Login *login = new Login(this);
    login->show();
}

