#ifndef FAMILLECOMPTES_H
#define FAMILLECOMPTES_H
#include <CanalBancaire/FamilleBancaire/ProduitCompte/comptecourant.h>
#include <CanalBancaire/FamilleBancaire/ProduitCompte/compteepargne.h>
#include <QVector>

class FamilleComptes
{
private:
    QVector<CompteCourant> VCC;
    QVector<CompteEpargne> VCE;

public:
    FamilleComptes();
    QVector<CompteCourant> getcompteCourant();
    QVector<CompteEpargne> getcompteEpargne();
    float getCA_CC(QDate dd, QDate df);
    float getCA_CE(QDate dd, QDate df);
    int getVolume_CC(QDate dd, QDate df);
    int getVolume_CE(QDate dd, QDate df);

    int y = 21;
};

#endif
