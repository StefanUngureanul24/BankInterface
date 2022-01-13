#include "compteepargne.h"

CompteEpargne::CompteEpargne(QString id, float prix, QDate datedebut, QDate datefin, int idbanquier)
{
    this->id = id;
    this->prix = prix;
    this->datedebut = datedebut;
    this->datefin = datefin;
    this->idBanquier = idbanquier;
}

QString CompteEpargne::getid()
{
    return this->id;
}

float CompteEpargne::getprix()
{
    return this->prix;
}

int CompteEpargne::getidbanquier()
{
    return this->idBanquier;
}

QDate CompteEpargne::getdatedebut()
{
    return this->datedebut;
}

QDate CompteEpargne::getdatefin()
{
    return this->datefin;
}


