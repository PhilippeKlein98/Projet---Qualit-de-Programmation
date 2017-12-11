#ifndef FORMATION_H
#define FORMATION_H
#include<iostream>
#include <vector>
#include "maquette.h"

class formation
{
    public:
        formation();
        std::string codeFormation() const;
        std::string intituleFormation() const;
        int creditECTS() const;
        maquette* operator[](int i) const;
        maquette* operator[](int i);
        void print(std::ostream& ost) const ;

    private:
        std::vector<maquette*> d_maquettes;

};

#endif // FORMATION_H