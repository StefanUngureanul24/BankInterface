#include "demandeencours.h"

demandeEnCours::demandeEnCours(QString id, float prix, QDate datedebut, QDate datefin, int idbanquier)
{
    this->id = id;
    this->prix = prix;
    this->datedebut = datedebut;
    this->datefin = datefin;
    this->idBanquier = idbanquier;
}

QString demandeEnCours::getid()
{
    return this->id;
}

float demandeEnCours::getprix()
{
    return this->prix;
}

int demandeEnCours::getidbanquier()
{
    return this->idBanquier;
}

QDate demandeEnCours::getdatedebut()
{
    return this->datedebut;
}

QDate demandeEnCours::getdatefin()
{
    return this->datefin;
}


