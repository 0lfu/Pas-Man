#ifndef LICENCE_H
#define LICENCE_H

#include <QWidget>

namespace Ui {
class Licence;
}

class Licence : public QWidget
{
    Q_OBJECT

public:
    explicit Licence(QWidget *parent = nullptr);
    ~Licence();

private slots:
    void on_backBtn_clicked();

private:
    Ui::Licence *ui;
};

#endif // LICENCE_H
