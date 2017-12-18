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
<<<<<<< HEAD
	void supprimerDerniereMaquette();
=======
	void supprimerDeniereMaquette();
	
>>>>>>> c3b8dd41e7094796ea86d4af8ad6c20d6523f53d
        maquette* operator[](int i) const;
        maquette* operator[](int i);
	
        void afficher(std::ostream& ost) const;
<<<<<<< HEAD

=======
	
	static std::vector<formation*> listeFormations;
	static void ajouterFormation(formation* f);
	static void supprimerFormation(std::string &intituleFormation);
	static formation* rechercheFormation(std::string &intituleFormation);
	static void consulterToutesLesFormations();
	
>>>>>>> c3b8dd41e7094796ea86d4af8ad6c20d6523f53d

    private:
        std::vector<maquette*> d_maquettes;
	int d_codeFormation;
	std::string d_intituleFormation;

};

std::ostream& operator<<(std::ostream& ost, formation& f);
	
}

<<<<<<< HEAD
std::ostream& operator<<(std::ostream& ost, gestionUE::formation& f);
=======

>>>>>>> c3b8dd41e7094796ea86d4af8ad6c20d6523f53d

#endif // FORMATION_H
