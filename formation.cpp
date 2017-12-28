#include "formation.h"
#include "maquette.h"
#include "global.h"
#include <vector>
#include<iostream>

namespace gestionUE{

    std::vector<formation*> formation::listeFormations;

formation::formation(std::string intituleFormation) : d_intituleFormation{intituleFormation}, d_maquettes{}
{}


std::string formation::intituleFormation() const
{
	return d_intituleFormation;
}

int formation::totalCreditECTS() const
{
	int total = 0;
	for (auto m : d_maquettes)
		total += m->totalCreditECTS();
	return total;
}

void formation::ajouterMaquette(maquette* m)
{
	d_maquettes.push_back(m);
}

void formation::supprimerDerniereMaquette()
{
	d_maquettes.pop_back();
}

 maquette* formation::operator[](unsigned int i) const
 {
	return ((d_maquettes.size()>i) ? nullptr : d_maquettes[i]);
 }

  maquette* formation::operator[](unsigned int i)
 {
	return ((d_maquettes.size()>i) ? nullptr : d_maquettes[i]);
 }

 void formation::afficher(std::ostream& ost) const
 {

	ost << "=======" << d_intituleFormation << "=======" << std::endl;
	for (auto m : d_maquettes)
		ost << *m << std::endl;

	ost << "========================================" << std::endl;

 }

void formation::ajouterFormation(formation* f)
{
	listeFormations.push_back(f);
}

void formation::supprimerFormation(std::string &intituleFormation)
{
        int i=0 ;
        while (i<listeFormations.size() && intituleFormation!=listeFormations[i]->intituleFormation())
        {
            ++i ;
        }
        if (i!=listeFormations.size())
        {
            std::swap(listeFormations[listeFormations.size()-1],listeFormations[i]) ;
            listeFormations.pop_back() ;
        }
}

formation* formation::rechercheFormation(const std::string &intituleFormation)
{
	for (auto f : listeFormations)
		if(f->intituleFormation()==intituleFormation)
			return f;

    std::cout << "Aucune formation correspondante." << std::endl;
    return nullptr;
}

void formation::afficherToutesLesFormations(std::ostream& ost)
{
    ost << "========================================" << std::endl;

	for (auto f : listeFormations)
		ost << f->intituleFormation() << std::endl;

    ost << "========================================" << std::endl;
}


void formation::sauverTout()
{
    std::ofstream ofst{FICHIER_FORMATION.c_str()} ;
    for (auto f : listeFormations)
    {
        ofst << f->intituleFormation() <<  '\t';

        for (auto maquette : f->d_maquettes)
            ofst << maquette->identifiant() <<  '\t';

        ofst << std::endl;
    }
}

void formation::libererTout()
{
    for (auto form : listeFormations)
    {
        delete form ;
    }
}

std::ostream& operator<<(std::ostream& ost, formation& f)
{
	f.afficher(ost);
	return ost;
}

}
