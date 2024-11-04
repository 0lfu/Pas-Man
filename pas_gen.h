#ifndef PAS_GEN_H
#define PAS_GEN_H

#include <QWidget>

namespace Ui {
class PasGen;
}

class PasGen : public QWidget
{
    Q_OBJECT

public:
    explicit PasGen(QWidget *parent = nullptr);
    ~PasGen();

private slots:
    void on_pasListBtn_clicked();

    void on_pasCheckBtn_clicked();

    void on_addBtn_clicked();

    void on_charCountSlider_valueChanged(int value);

    void generatePassword();

    void on_logOutBtn_clicked();

private:
    Ui::PasGen *ui;
};

#endif // PAS_GEN_H
