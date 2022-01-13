#include "canalbancaire.h"

CanalBancaire::CanalBancaire()
{}

FamilleChequiers CanalBancaire::getfamillechequier()
{
    return this->FCE;
}

FamilleComptes CanalBancaire::getfamillecomptes()
{
    return this->FCO;
}

FamillePret CanalBancaire::getfamillepret()
{
    return this->FPR;
}
