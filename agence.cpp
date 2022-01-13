#include "agence.h"

Agence::Agence(QString nom, QString adresse, int nbBanquier)
{
    this->nom = nom;
    this->adresse = adresse;
    this->nbBanquier = nbBanquier;
}

QString Agence::getnom()
{
    return this->nom;
}

QString Agence::getadresse()
{
    return this->adresse;
}

int Agence::getnbBanquier()
{
    return this->nbBanquier;
}

QVector<Banquier> Agence::getV_Banquier()
{
    return this->V_Banquier;
}

CanalBancaire Agence::getCanalBancaire()
{
    return this->CBA;
}

CanalAssurance Agence::getCanalAssurance()
{
    return this->CAS;
}

CanalBoursier Agence::getCanalBoursier()
{
    return this->CBO;
}
