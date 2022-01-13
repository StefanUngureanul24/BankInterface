#ifndef CANALBANCAIRE_H
#define CANALBANCAIRE_H
#include <CanalBancaire/FamilleBancaire/famillechequiers.h>
#include <CanalBancaire/FamilleBancaire/famillecomptes.h>
#include <CanalBancaire/FamilleBancaire/famillepret.h>


class CanalBancaire
{
private:
    FamilleChequiers FCE;
    FamilleComptes FCO;
    FamillePret FPR;

public:
    CanalBancaire();
    FamilleChequiers getfamillechequier();
    FamilleComptes getfamillecomptes();
    FamillePret getfamillepret();
};

#endif // CANALBANCAIRE_H
