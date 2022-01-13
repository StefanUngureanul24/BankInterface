#ifndef DEMANDEPASSEE_H
#define DEMANDEPASSEE_H
#include <QString>
#include <QDate>

class demandePassee
{
private:
    QString id;
    float prix;
    int idBanquier;
    QDate datedebut;
    QDate datefin;


public:
    demandePassee(QString ,float , QDate, QDate, int);
    QString getid();
    float getprix();
    int getidbanquier();
    QDate getdatedebut();
    QDate getdatefin();


};

#endif
