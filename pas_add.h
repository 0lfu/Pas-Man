#ifndef PAS_ADD_H
#define PAS_ADD_H

#include <QWidget>
#include <QJsonObject>

namespace Ui {
class PasAdd;
}

class PasList;

class PasAdd : public QWidget
{
    Q_OBJECT

public:
    explicit PasAdd(PasList *pasListInstance, QWidget *parent = nullptr);
    ~PasAdd();

private slots:
    void on_cancelBtn_clicked();

    void on_pasListBtn_clicked();

    void on_pasGenBtn_clicked();

    void on_pasCheckBtn_clicked();

    void on_addBtn_clicked();

    void on_logOutBtn_clicked();

signals:
    void entryAdded();

    void entryUpdated();

private:
    Ui::PasAdd *ui;
};

#endif // PAS_ADD_H
