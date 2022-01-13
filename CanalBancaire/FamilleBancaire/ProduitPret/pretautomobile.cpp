#include "pretautomobile.h"

PretAutomobile::PretAutomobile(QString id, float prix, QDate datedebut, QDate datefin, int idbanquier)
{
    this->id = id;
    this->prix = prix;
    this->datedebut = datedebut;
    this->datefin = datefin;
    this->idBanquier = idbanquier;
}

QString PretAutomobile::getid()
{
    return this->id;
}

float PretAutomobile::getprix(){
    return this->prix;
}

int PretAutomobile::getidbanquier()
{
    return this->idBanquier;
}

QDate PretAutomobile::getdatedebut(){
    return this->datedebut;
}

QDate PretAutomobile::getdatefin(){
    return this->datefin;
}


