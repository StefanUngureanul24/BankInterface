#include "assuranceordi.h"

AssuranceOrdi::AssuranceOrdi(QString id, float prix, QDate datedebut, QDate datefin, int idbanquier)
{
    this->id = id;
    this->prix = prix;
    this->datedebut = datedebut;
    this->datefin = datefin;
    this->idBanquier = idbanquier;
}

QString AssuranceOrdi::getid()
{
    return this->id;
}

float AssuranceOrdi::getprix()
{
    return this->prix;
}

int AssuranceOrdi::getidbanquier()
{
    return this->idBanquier;
}

QDate AssuranceOrdi::getdatedebut()
{
    return this->datedebut;
}

QDate AssuranceOrdi::getdatefin()
{
    return this->datefin;
}


