#ifndef FORMATION_H
#define FORMATION_H
#include<iostream>
#include <vector>
#include "maquette.h"

namespace gestionUE{
	
class formation
{
    public:
        formation(int codeFormation, std::string& intituleFormation);
        int codeFormation() const;
        std::string& intituleFormation() const;
        int totalCreditECTS() const;
	void ajouterMaquette(maquette* m);
	void supprimerDeniereMaquette();
        maquette* operator[](int i) const;
        maquette* operator[](int i);
        void afficher(std::ostream& ost) const;
	

    private:
        std::vector<maquette*> d_maquettes;
	int d_codeFormation;
	std::string d_intituleFormation;

};

}

std::ostream& operator<<(std::ostream& ost, formation& f);

#endif // FORMATION_H
