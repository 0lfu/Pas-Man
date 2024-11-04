#ifndef PAS_EDIT_H
#define PAS_EDIT_H

#include <QWidget>
#include <QJsonObject>

namespace Ui {
class PasEdit;
}

class PasList;

class PasEdit : public QWidget
{
    Q_OBJECT

public:
    explicit PasEdit(PasList *pasListInstance, const QJsonObject &entryData = QJsonObject(), QWidget *parent = nullptr);
    ~PasEdit();

private slots:
    void on_cancelBtn_clicked();

    void on_pasListBtn_clicked();

    void on_pasGenBtn_clicked();

    void on_pasCheckBtn_clicked();

    void on_updateBtn_clicked();

    void on_removeBtn_clicked();

    void on_logOutBtn_clicked();

signals:
    void entryUpdated();

private:
    Ui::PasEdit *ui;
    QJsonObject entryData;
};

#endif // PAS_EDIT_H
