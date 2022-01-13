#include "assurancevelo.h"

AssuranceVelo::AssuranceVelo(QString id, float prix, QDate datedebut, QDate datefin, int idbanquier)
{
    this->id = id;
    this->prix = prix;
    this->datedebut = datedebut;
    this->datefin = datefin;
    this->idBanquier = idbanquier;
}

QString AssuranceVelo::getid()
{
    return this->id;
}

float AssuranceVelo::getprix()
{
    return this->prix;
}

int AssuranceVelo::getidbanquier()
{
    return this->idBanquier;
}


QDate AssuranceVelo::getdatedebut()
{
    return this->datedebut;
}

QDate AssuranceVelo::getdatefin()
{
    return this->datefin;
}

