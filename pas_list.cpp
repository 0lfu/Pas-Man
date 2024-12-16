#include "pas_list.h"
#include "ui_pas_list.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QClipboard>
#include <QGuiApplication>
#include <QShortcut>

#include "pas_add.h"
#include "pas_gen.h"
#include "pas_check.h"
#include "pas_edit.h"
#include "encryption.h"
#include "login.h"
#include "encryption.h"

PasList::PasList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasList)
{
    ui->setupUi(this);


    loadData();

    this->installEventFilter(this);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/res/icon.png"));
    trayIcon->show();
}

PasList::~PasList()
{
    delete ui;
}


void PasList::on_addPasswordBtn_clicked()
{
    PasAdd *pasAdd = new PasAdd(this, this);
    connect(pasAdd, &PasAdd::entryAdded, this, &PasList::loadData);
    pasAdd->show();
}


void PasList::on_pasGenBtn_clicked()
{
    PasGen *pasGen = new PasGen(this);
    pasGen->show();
}


void PasList::on_pasCheckBtn_clicked()
{
    PasCheck *pasCheck = new PasCheck(this);
    pasCheck->show();
}

void PasList::loadData() {
    Encryption encryptor;
    QJsonArray dataArray = encryptor.loadEntries();
    ui->passwordsList->clear();

    for (const QJsonValue &value : dataArray) {
        QJsonObject entry = value.toObject();
        QString itemText = entry["name"].toString();

        QListWidgetItem* item = new QListWidgetItem(itemText);
        item->setData(Qt::UserRole, entry["password"].toString());
        item->setData(Qt::UserRole + 1, entry["uid"].toString());
        item->setData(Qt::UserRole + 2, entry["username"].toString());
        item->setData(Qt::UserRole + 3, entry["URL"].toString());
        item->setData(Qt::UserRole + 4, entry["category"].toString());
        item->setData(Qt::UserRole + 5, entry["notes"].toString());

        ui->passwordsList->addItem(item);
    }
}


void PasList::on_refreshBtn_clicked()
{
    loadData();
}

void PasList::copyPassword() {
    QListWidgetItem* item = ui->passwordsList->currentItem();
    if (item) {
        QString password = item->data(Qt::UserRole).toString();
        QClipboard *clipboard = QGuiApplication::clipboard();
        clipboard->clear();
        clipboard->setText(password, QClipboard::Clipboard);

        trayIcon->showMessage("Powiadomienie", "Hasło skopiowane do schowka!",
                              QSystemTrayIcon::Information, 1000);
    }
}

void PasList::on_search_textChanged(const QString &arg1)
{
    QString search = arg1;
    for (int i = 0; i < ui->passwordsList->count(); i++) {
        QListWidgetItem* item = ui->passwordsList->item(i);
        QString itemText = item->text();
        if (itemText.contains(search, Qt::CaseInsensitive)) {
            item->setHidden(false);
        } else {
            item->setHidden(true);
        }
    }
}


void PasList::on_passwordsList_itemDoubleClicked(QListWidgetItem *item)
{
    item = ui->passwordsList->currentItem();
    if (item) {
        QJsonObject entryData;
        entryData["name"] = item->text();
        entryData["uid"] = item->data(Qt::UserRole + 1).toString();
        entryData["username"] = item->data(Qt::UserRole + 2).toString();
        entryData["password"] = item->data(Qt::UserRole).toString();
        entryData["URL"] = item->data(Qt::UserRole + 3).toString();
        entryData["category"] = item->data(Qt::UserRole + 4).toString();
        entryData["notes"] = item->data(Qt::UserRole + 5).toString();

        PasEdit *pasEdit = new PasEdit(this, entryData, this);
        connect(pasEdit, &PasEdit::entryUpdated, this, &PasList::loadData);
        pasEdit->show();
    }
}


void PasList::on_logOutBtn_clicked()
{
    Login *login = new Login(this);
    login->show();
}

bool PasList::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        // Ctrl + C do kopiowania hasła
        if (keyEvent->matches(QKeySequence::Copy)) {
            copyPassword();
            return true;
        }
    }
    return QWidget::eventFilter(obj, event);
}

