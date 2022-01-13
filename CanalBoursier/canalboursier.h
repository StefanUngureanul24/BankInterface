#ifndef CANALBOURSIER_H
#define CANALBOURSIER_H
#include<CanalBoursier/FamilleActions/familleactions.h>

class CanalBoursier
{

private:
    FamilleActions FAC;

public:
    CanalBoursier();
    FamilleActions getfamilleaction();
};

#endif
