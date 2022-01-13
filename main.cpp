#include "banksupervision.h"
#include "login.h"
#include <QApplication>
#include <QtCharts>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login w;
    w.show();

    return a.exec();
}
