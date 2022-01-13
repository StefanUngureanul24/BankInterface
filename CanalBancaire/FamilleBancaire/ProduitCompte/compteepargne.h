#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H
#include <QString>
#include <QDate>

class CompteEpargne
{

private:
    QString id;
    float prix;
    int idBanquier;
    QDate datedebut;
    QDate datefin;


public:
    CompteEpargne(QString ,float , QDate, QDate, int);
    QString getid();
    float getprix();
    int getidbanquier();
    QDate getdatedebut();
    QDate getdatefin();

};

#endif
