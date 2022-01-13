#ifndef DEMANDEENCOURS_H
#define DEMANDEENCOURS_H
#include <QString>
#include <QDate>

class demandeEnCours
{

private:
    QString id;
    float prix;
    int idBanquier;
    QDate datedebut;
    QDate datefin;

public:
    demandeEnCours(QString ,float , QDate, QDate, int);
    QString getid();
    float getprix();
    int getidbanquier();
    QDate getdatedebut();
    QDate getdatefin();


};

#endif
