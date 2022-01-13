#ifndef ASSURANCEHABITATION_H
#define ASSURANCEHABITATION_H
#include <QString>
#include <QDate>

class AssuranceHabitation
{
private:
    QString id;
    float prix;
    QDate datedebut;
    QDate datefin;
    int idBanquier;


public:
    AssuranceHabitation(QString ,float , QDate, QDate, int);
    QString getid();
    float getprix();
    QDate getdatedebut();
    QDate getdatefin();
    int getidbanquier();
};

#endif // ASSURANCEHABITATION_H
