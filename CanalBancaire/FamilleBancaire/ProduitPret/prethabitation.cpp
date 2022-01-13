#include "prethabitation.h"

PretHabitation::PretHabitation(QString id, float prix, QDate datedebut, QDate datefin, int idbanquier)
{
    this->id = id;
    this->prix = prix;
    this->datedebut = datedebut;
    this->datefin = datefin;
    this->idBanquier = idbanquier;
}

QString PretHabitation::getid()
{
    return this->id;
}

float PretHabitation::getprix()
{
    return this->prix;
}

int PretHabitation::getidbanquier()
{
    return this->idBanquier;
}

QDate PretHabitation::getdatedebut()
{
    return this->datedebut;
}

QDate PretHabitation::getdatefin()
{
    return this->datefin;
}


