#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_registerBtn_clicked();

    void on_aboutBtn_clicked();

    void on_licenseBtn_clicked();

    void on_password_returnPressed();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
