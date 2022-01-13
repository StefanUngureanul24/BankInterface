#ifndef PRETHABITATION_H
#define PRETHABITATION_H
#include <QString>
#include <QDate>
class PretHabitation
{
private:
    QString id;
    float prix;
    int idBanquier;
    QDate datedebut;
    QDate datefin;


public:
    PretHabitation(QString ,float , QDate, QDate, int);
    QString getid();
    float getprix();
    int getidbanquier();
    QDate getdatedebut();
    QDate getdatefin();

};

#endif // PRETHABITATION_H
