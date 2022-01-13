#include "banquier.h"

Banquier::Banquier(QString nom, QString prenom,int age)
{
    this->nom = nom;
    this->prenom = prenom;
    this->age = age;
}

QString Banquier::getnom()
{
    return this->nom;
}

QString Banquier::getprenom()
{
    return this->prenom;
}

int Banquier::getage()
{
    return this->age;
}
