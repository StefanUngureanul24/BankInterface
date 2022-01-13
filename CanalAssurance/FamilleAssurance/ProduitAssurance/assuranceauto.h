#ifndef ASSURANCEAUTO_H
#define ASSURANCEAUTO_H
#include <QString>
#include <QDate>

class AssuranceAuto
{
private:
    QString id;
    float prix;
    QDate datedebut;
    QDate datefin;
    int idBanquier;


public:
    AssuranceAuto(QString ,float , QDate, QDate, int);
    QString getid();
    float getprix();
    QDate getdatedebut();
    QDate getdatefin();
    int getidbanquier();
};

#endif // ASSURANCEAUTO_H
