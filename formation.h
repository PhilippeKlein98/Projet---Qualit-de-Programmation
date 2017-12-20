#ifndef FORMATION_H
#define FORMATION_H
#include<iostream>
#include <vector>
#include "maquette.h"

namespace gestionUE{

class formation
{
    public:
        formation(std::string intituleFormation);

        std::string intituleFormation() const;
        int totalCreditECTS() const;

	void ajouterMaquette(maquette* m);
	void supprimerDerniereMaquette();

        maquette* operator[](int i) const;
        maquette* operator[](int i);

        void afficher(std::ostream& ost) const;

	static std::vector<formation*> listeFormations;
	static void ajouterFormation(formation* f);
	static void supprimerFormation(std::string &intituleFormation);
	static formation* rechercheFormation(std::string &intituleFormation);

    	static void afficherToutesLesFormations(std::ostream& ost);


    private:
        std::vector<maquette*> d_maquettes;
	std::string d_intituleFormation;

};

std::ostream& operator<<(std::ostream& ost, formation& f);

}

std::ostream& operator<<(std::ostream& ost, gestionUE::formation& f);


#endif // FORMATION_H
