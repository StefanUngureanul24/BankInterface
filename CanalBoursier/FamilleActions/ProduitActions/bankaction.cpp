#include "bankaction.h"

BankAction::BankAction(QString id, float prix, QDate datedebut, QDate datefin, int idbanquier)
{
    this->id = id;
    this->prix = prix;
    this->datedebut = datedebut;
    this->datefin = datefin;
    this->idBanquier = idbanquier;
}

QString BankAction::getid()
{
    return this->id;
}

float BankAction::getprix()
{
    return this->prix;
}

int BankAction::getidbanquier()
{
    return this->idBanquier;
}

QDate BankAction::getdatedebut()
{
    return this->datedebut;
}

QDate BankAction::getdatefin()
{
    return this->datefin;
}

