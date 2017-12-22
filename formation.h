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



        maquette* operator[](unsigned int i) const;
        maquette* operator[](unsigned int i);

        void afficher(std::ostream& ost) const;

	static std::vector<formation*> listeFormations;
	static void ajouterFormation(formation* f);
	static void supprimerFormation(std::string &intituleFormation);
	static formation* rechercheFormation(const std::string &intituleFormation);

    static void afficherToutesLesFormations(std::ostream& ost);
    static void sauverTout(std::ofstream& ofst);


    private:
        std::string d_intituleFormation;
        std::vector<maquette*> d_maquettes;


};

std::ostream& operator<<(std::ostream& ost, formation& f);

}



#endif // FORMATION_H
