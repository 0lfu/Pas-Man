#include "licence.h"
#include "ui_licence.h"

Licence::Licence(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Licence)
{
    ui->setupUi(this);
}

Licence::~Licence()
{
    delete ui;
}


void Licence::on_backBtn_clicked()
{
    this->close();
}

