#ifndef PAS_CHECK_H
#define PAS_CHECK_H

#include <QWidget>

namespace Ui {
class PasCheck;
}

class PasCheck : public QWidget
{
    Q_OBJECT

public:
    explicit PasCheck(QWidget *parent = nullptr);
    ~PasCheck();

private slots:
    void on_pasListBtn_clicked();

    void on_pasGenBtn_clicked();

    void on_checkPasEdit_textChanged(const QString &arg1);

    void evaluatePasswordStrength();

    void on_logOutBtn_clicked();

private:
    Ui::PasCheck *ui;
};

#endif // PAS_CHECK_H
