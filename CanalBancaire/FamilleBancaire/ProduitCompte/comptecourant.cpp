#include "comptecourant.h"

CompteCourant::CompteCourant(QString id, float prix, QDate datedebut, QDate datefin, int idbanquier)
{
    this->id = id;
    this->prix = prix;
    this->datedebut = datedebut;
    this->datefin = datefin;
    this->idBanquier = idbanquier;
}

QString CompteCourant::getid()
{
    return this->id;
}

float CompteCourant::getprix()
{
    return this->prix;
}

int CompteCourant::getidbanquier()
{
    return this->idBanquier;
}

QDate CompteCourant::getdatedebut()
{
    return this->datedebut;
}

QDate CompteCourant::getdatefin()
{
    return this->datefin;
}


