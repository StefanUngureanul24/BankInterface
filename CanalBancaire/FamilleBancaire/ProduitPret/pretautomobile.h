#ifndef PRETAUTOMOBILE_H
#define PRETAUTOMOBILE_H
#include <QString>
#include <QDate>

class PretAutomobile
{

private:
    QString id;
    float prix;
    int idBanquier;
    QDate datedebut;
    QDate datefin;


public:
    PretAutomobile(QString ,float , QDate, QDate, int);
    QString getid();
    float getprix();
    int getidbanquier();
    QDate getdatedebut();
    QDate getdatefin();

};

#endif
