#ifndef ASSURANCEORDI_H
#define ASSURANCEORDI_H
#include <QString>
#include <QDate>

class AssuranceOrdi
{
private:
    QString id;
    float prix;
    QDate datedebut;
    QDate datefin;
    int idBanquier;


public:
    AssuranceOrdi(QString ,float , QDate, QDate, int);
    QString getid();
    float getprix();
    QDate getdatedebut();
    QDate getdatefin();
    int getidbanquier();
};

#endif // ASSURANCEORDI_H
