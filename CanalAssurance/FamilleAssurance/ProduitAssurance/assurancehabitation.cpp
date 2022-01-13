#include "assurancehabitation.h"

AssuranceHabitation::AssuranceHabitation(QString id, float prix, QDate datedebut, QDate datefin, int idbanquier)
{
    this->id = id;
    this->prix = prix;
    this->datedebut = datedebut;
    this->datefin = datefin;
    this->idBanquier = idbanquier;
}

QString AssuranceHabitation::getid()
{
    return this->id;
}

float AssuranceHabitation::getprix()
{
    return this->prix;
}

int AssuranceHabitation::getidbanquier()
{
    return this->idBanquier;
}

QDate AssuranceHabitation::getdatedebut()
{
    return this->datedebut;
}

QDate AssuranceHabitation::getdatefin()
{
    return this->datefin;
}

