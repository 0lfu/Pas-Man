#ifndef PAS_LIST_H
#define PAS_LIST_H

#include "pas_add.h"
#include <QWidget>
#include <QListWidgetItem>
#include <QSystemTrayIcon>

namespace Ui {
class PasList;
}

class PasList : public QWidget
{
    Q_OBJECT

public:
    explicit PasList(QWidget *parent = nullptr);

    ~PasList();
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
public slots:
    void loadData();
private slots:
    void on_addPasswordBtn_clicked();

    void on_pasGenBtn_clicked();

    void on_pasCheckBtn_clicked();

    void on_refreshBtn_clicked();

    void copyPassword();

    void on_search_textChanged(const QString &arg1);

    void on_passwordsList_itemDoubleClicked(QListWidgetItem *item);

    void on_logOutBtn_clicked();

private:
    Ui::PasList *ui;
    QSystemTrayIcon *trayIcon;
};

#endif // PAS_LIST_H
