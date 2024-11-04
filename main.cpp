#include "register.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Register view;
    view.show();
    return a.exec();
}
