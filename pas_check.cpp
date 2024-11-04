#include "pas_check.h"
#include "ui_pas_check.h"

#include <cmath>
#include <algorithm>

#include "pas_add.h"
#include "pas_list.h"
#include "pas_gen.h"
#include "login.h"

PasCheck::PasCheck(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasCheck)
{
    ui->setupUi(this);

    ui->checkPasEdit->setEchoMode(QLineEdit::Password);
}

PasCheck::~PasCheck()
{
    delete ui;
}


void PasCheck::on_pasListBtn_clicked()
{
    PasList *pasList = new PasList(this);
    pasList->show();
}


void PasCheck::on_pasGenBtn_clicked()
{
    PasGen *pasGen = new PasGen(this);
    pasGen->show();
}

void PasCheck::on_checkPasEdit_textChanged(const QString &arg1)
{
    evaluatePasswordStrength();
}

void PasCheck::evaluatePasswordStrength() {
    QString password = ui->checkPasEdit->text();
    int score = 0;
    int length = password.length();

    if (length == 0) {
        ui->strengthBar->setValue(0);
        ui->timeToBreak->setText("N/A");
        ui->bits->setText("0 bits");
        return;
    }

    if (length >= 2) score += 5;
    if (length >= 6) score += 5;
    if (length >= 8) score += 20;
    if (length >= 12) score += 20;

    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    for (const auto &ch : password) {
        if (ch.isLower()) hasLower = true;
        else if (ch.isUpper()) hasUpper = true;
        else if (ch.isDigit()) hasDigit = true;
        else hasSpecial = true;
    }

    if (hasLower && hasUpper) score += 20;
    if (hasDigit) score += 15;
    if (hasSpecial) score += 15;

    hasLower ? ui->lowerCheck->setChecked(true) : ui->lowerCheck->setChecked(false);
    hasUpper ? ui->capitalCheck->setChecked(true) : ui->capitalCheck->setChecked(false);
    hasDigit ? ui->numberCheck->setChecked(true) : ui->numberCheck->setChecked(false);
    hasSpecial ? ui->specialCheck->setChecked(true) : ui->specialCheck->setChecked(false);

    ui->strengthBar->setValue(std::min(score, 100));
    if (score < 50) {
        ui->strengthBar->setStyleSheet("QProgressBar::chunk { background-color: red; }");
    } else if (score < 75) {
        ui->strengthBar->setStyleSheet("QProgressBar::chunk { background-color: orange; }");
    } else {
        ui->strengthBar->setStyleSheet("QProgressBar::chunk { background-color: green; }");
    }

    int charSetSize = (hasLower + hasUpper) * 26 + hasDigit * 10 + hasSpecial * 10;
    double entropyBits = (charSetSize > 0) ? length * std::log2(charSetSize) : 0;
    ui->bits->setText(QString::number(static_cast<int>(entropyBits)) + " bits");

    double timeToCrackSeconds = (entropyBits > 0) ? std::pow(2, entropyBits) / 1e9 : 0;
    QString timeToBreakText;

    if (timeToCrackSeconds >= 60LL * 60 * 24 * 365 * 1000) { // 100+ lat
        timeToBreakText = "100+ years";
    } else if (timeToCrackSeconds >= 60 * 60 * 24 * 365) {  // Lata
        timeToBreakText = QString::number(static_cast<int>(timeToCrackSeconds / (60 * 60 * 24 * 365))) + " years";
    } else if (timeToCrackSeconds >= 60 * 60 * 24) { // Dni
        timeToBreakText = QString::number(static_cast<int>(timeToCrackSeconds / (60 * 60 * 24))) + " days";
    } else if (timeToCrackSeconds >= 60 * 60) { // Godziny
        timeToBreakText = QString::number(static_cast<int>(timeToCrackSeconds / (60 * 60))) + " hours";
    } else if (timeToCrackSeconds >= 60) { // Minuty
        timeToBreakText = QString::number(static_cast<int>(timeToCrackSeconds / 60)) + " minutes";
    } else {
        timeToBreakText = QString::number(static_cast<int>(timeToCrackSeconds)) + " seconds";
    }

    ui->timeToBreak->setText(timeToBreakText);
}


void PasCheck::on_logOutBtn_clicked()
{
    Login *login = new Login(this);
    login->show();
}

