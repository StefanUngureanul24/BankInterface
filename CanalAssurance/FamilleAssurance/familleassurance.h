#ifndef FAMILLEASSURANCE_H
#define FAMILLEASSURANCE_H
#include <CanalAssurance/FamilleAssurance/ProduitAssurance/assurancehabitation.h>
#include <CanalAssurance/FamilleAssurance/ProduitAssurance/assurancevelo.h>
#include <CanalAssurance/FamilleAssurance/ProduitAssurance/assuranceordi.h>
#include <CanalAssurance/FamilleAssurance/ProduitAssurance/assuranceauto.h>
#include <QVector>

class FamilleAssurance
{
private:
    QVector<AssuranceHabitation> VAH;
    QVector<AssuranceVelo> VAV;
    QVector<AssuranceAuto> VAA;
    QVector<AssuranceOrdi> VAO;


public:
    FamilleAssurance();
    QVector<AssuranceHabitation> getassurancehabitation();
    QVector<AssuranceVelo> getassurancevelo();
    QVector<AssuranceOrdi> getassuranceordi();
    QVector<AssuranceAuto> getassuranceauto();
    float getCA_AH(QDate dd, QDate df);
    float getCA_AV(QDate dd, QDate df);
    float getCA_AA(QDate dd, QDate df);
    float getCA_AO(QDate dd, QDate df);
    int getVolume_AH(QDate dd, QDate df);
    int getVolume_AV(QDate dd, QDate df);
    int getVolume_AA(QDate dd, QDate df);
    int getVolume_AO(QDate dd, QDate df);
    int y = 21;
};

#endif // FAMILLEASSURANCE_H
