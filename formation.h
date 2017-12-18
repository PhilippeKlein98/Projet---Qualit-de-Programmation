#ifndef FORMATION_H
#define FORMATION_H
#include<iostream>
#include <vector>
#include "maquette.h"

namespace gestionUE{
	
class formation
{
    public:
        formation();
        int	 codeFormation() const;
        std::string intituleFormation() const;
        int totalCreditECTS() const;
        maquette* operator[](int i) const;
        maquette* operator[](int i);
        void print(std::ostream& ost) const;
	

    private:
        std::vector<maquette*> d_maquettes;
		int d_codeFormation;
		std::string d_intituleFormation;

};

}

std::ostream& operator<<(std::ostream& ost, formation& f);

#endif // FORMATION_H
