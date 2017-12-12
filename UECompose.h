#ifndef UECOMPOSE_H
#define UECOMPOSE_H

#include "UE.h"
class matiere;

class UECompose : public UE
{
    public:
        UECompose();

    private:
        std::vector<matiere*> d_lm;
};

#endif // UECOMPOSE_H
