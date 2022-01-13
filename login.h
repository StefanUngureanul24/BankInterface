#ifndef LOGIN_H
#define LOGIN_H
#include "banksupervision.h"
#include <QDialog>

namespace Ui
{
    class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_connexion_clicked();
    void DateTime();

private:
    Ui::Login *ui;
    BankSupervision *w;
    QTimer *timer;
    QString loginas;
    QDate dd;
    QDate df;
};

#endif
