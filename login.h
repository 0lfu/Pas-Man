#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

    ~Login();
private slots:
    void on_loginBtn_clicked();

    void on_licenseBtn_clicked();

    void on_aboutBtn_clicked();

    void on_password_returnPressed();

private:
    Ui::Login *ui;

    void setupUsernameLabel();

};

#endif // LOGIN_H
