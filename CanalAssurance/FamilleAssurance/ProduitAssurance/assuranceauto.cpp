#include "assuranceauto.h"

AssuranceAuto::AssuranceAuto(QString id, float prix, QDate datedebut, QDate datefin, int idbanquier)
{
    this->id = id;
    this->prix = prix;
    this->datedebut = datedebut;
    this->datefin = datefin;
    this->idBanquier = idbanquier;
}

QString AssuranceAuto::getid()
{
    return this->id;
}

float AssuranceAuto::getprix()
{
    return this->prix;
}

int AssuranceAuto::getidbanquier()
{
    return this->idBanquier;
}

QDate AssuranceAuto::getdatedebut()
{
    return this->datedebut;
}

QDate AssuranceAuto::getdatefin()
{
    return this->datefin;
}
