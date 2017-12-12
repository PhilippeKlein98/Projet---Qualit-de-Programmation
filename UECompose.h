#ifndef UECOMPOSE_H
#define UECOMPOSE_H

#include "UE.h"
#include <vector>

class matiere;

class UECompose : public UE
{
    public:
        UECompose();

    private:
        std::vector<ECUE*> d_lm;
};

#endif // UECOMPOSE_H
