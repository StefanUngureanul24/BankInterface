#ifndef FAMILLEACTIONS_H
#define FAMILLEACTIONS_H
#include <CanalBoursier/FamilleActions/ProduitActions/bankaction.h>
#include <QVector>

class FamilleActions
{

private:
    QVector<BankAction> VBA;

public:
    FamilleActions();
    QVector<BankAction> getbankaction();
    float getCA_BA(QDate dd, QDate df);
    int getVolume_BA(QDate dd, QDate df);

    int y = 21;
};

#endif
