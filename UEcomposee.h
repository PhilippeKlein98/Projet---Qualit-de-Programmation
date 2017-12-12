#ifndef UECOMPOSEE_H
#define UECOMPOSEE_H

#include "UE.h"
#include <vector>

class matiere;

class UEcomposee : public UE
{
    public:
        UEcomposee();

    private:
        std::vector<matiere*> d_tabMatieres;
};

#endif // UECOMPOSEE_H
