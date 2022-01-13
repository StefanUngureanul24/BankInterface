#ifndef FAMILLEPRET_H
#define FAMILLEPRET_H
#include <CanalBancaire/FamilleBancaire/ProduitPret/pretautomobile.h>
#include <CanalBancaire/FamilleBancaire/ProduitPret/prethabitation.h>
#include <QVector>

class FamillePret
{
private:
    QVector<PretAutomobile> VPA;
    QVector<PretHabitation> VPH;

public:
    FamillePret();
    QVector<PretAutomobile> getpretautomobile();
    QVector<PretHabitation> getprethabitation();
    float getCA_PA(QDate dd, QDate df);
    float getCA_PH(QDate dd, QDate df);
    int getVolume_PA(QDate dd, QDate df);
    int getVolume_PH(QDate dd, QDate df);

    int y = 21;
};

#endif
