#ifndef FAMILLECHEQUIERS_H
#define FAMILLECHEQUIERS_H
#include <CanalBancaire/FamilleBancaire/ProduitChequier/demandeencours.h>
#include <CanalBancaire/FamilleBancaire/ProduitChequier/demandepassee.h>
#include <QVector>

class FamilleChequiers
{
private:
    QVector<demandeEnCours> VDC;
    QVector<demandePassee> VDP;

public:
    FamilleChequiers();
    QVector<demandeEnCours> getdemandeencours();
    QVector<demandePassee> getdemandepasse();
    float getCA_DC(QDate dd, QDate df);
    float getCA_DP(QDate dd, QDate df);
    int getVolume_DC(QDate dd, QDate df);
    int getVolume_DP(QDate dd, QDate df);

    int y = 21;
};

#endif
