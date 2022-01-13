#ifndef COMPTECOURANT_H
#define COMPTECOURANT_H
#include <QString>
#include <QDate>
class CompteCourant
{
private:
    QString id;
    float prix;
    int idBanquier;
    QDate datedebut;
    QDate datefin;


public:
    CompteCourant(QString ,float , QDate, QDate, int);
    QString getid();
    float getprix();
    int getidbanquier();
    QDate getdatedebut();
    QDate getdatefin();

};

#endif
