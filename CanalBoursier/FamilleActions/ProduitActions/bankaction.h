#ifndef BANKACTION_H
#define BANKACTION_H
#include <QString>
#include <QDate>
class BankAction
{

private:
    QString id;
    float prix;
    int idBanquier;
    QDate datedebut;
    QDate datefin;

public:
    BankAction(QString , float , QDate , QDate , int );
    QString getid();
    float getprix();
    int getidbanquier();
    QDate getdatedebut();
    QDate getdatefin();

};

#endif
