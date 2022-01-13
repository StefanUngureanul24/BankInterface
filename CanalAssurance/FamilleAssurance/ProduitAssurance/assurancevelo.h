#ifndef ASSURANCEVELO_H
#define ASSURANCEVELO_H
#include <QString>
#include <QDate>

class AssuranceVelo
{
private:
    QString id;
    float prix;
    QDate datedebut;
    QDate datefin;
    int idBanquier;


public:
    AssuranceVelo(QString ,float , QDate, QDate, int);
    QString getid();
    float getprix();
    QDate getdatedebut();
    QDate getdatefin();
    int getidbanquier();
};

#endif // ASSURANCEVELO_H
