#include "demandepassee.h"

demandePassee::demandePassee(QString id, float prix, QDate datedebut, QDate datefin, int idbanquier)
{
    this->id = id;
    this->prix = prix;
    this->datedebut = datedebut;
    this->datefin = datefin;
    this->idBanquier = idbanquier;
}

QString demandePassee::getid()
{
    return this->id;
}

float demandePassee::getprix()
{
    return this->prix;
}

int demandePassee::getidbanquier()
{
    return this->idBanquier;
}

QDate demandePassee::getdatedebut()
{
    return this->datedebut;
}

QDate demandePassee::getdatefin()
{
    return this->datefin;
}

