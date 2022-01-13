#ifndef AGENCE_H
#define AGENCE_H
#include <QString>
#include <CanalAssurance/canalassurance.h>
#include <CanalBancaire/canalbancaire.h>
#include <CanalBoursier/canalboursier.h>
#include <banquier.h>
#include <QVector>

class Agence
{
private :
    QString nom;
    QString adresse;
    int nbBanquier;
    QVector<Banquier> V_Banquier;
    CanalAssurance CAS;
    CanalBancaire CBA;
    CanalBoursier CBO;

public:
    Agence(QString , QString ,int );
    QString getnom();
    QString getadresse();
    int getnbBanquier();
    CanalBancaire getCanalBancaire();
    CanalAssurance getCanalAssurance();
    CanalBoursier getCanalBoursier();
    QVector<Banquier> getV_Banquier();
};

#endif
