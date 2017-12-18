#include "formation.h"
#include "maquette.h"
#include <vector>
#include<iostream>

namespace gestionUE{

    std::vector<formation*> formation::listeFormations;

formation::formation(int codeFormation, std::string &intituleFormation) : d_codeFormation{codeFormation}, d_intituleFormation{intituleFormation}, d_maquettes{}
{}

int formation::codeFormation() const
{
	return d_codeFormation;
}

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

 maquette* formation::operator[](int i) const
 {
	return ((d_maquettes.size()>i) ? nullptr : d_maquettes[i]);
 }

  maquette* formation::operator[](int i)
 {
	return ((d_maquettes.size()>i) ? nullptr : d_maquettes[i]);
 }

 void formation::afficher(std::ostream& ost) const
 {
	ost << "====================" << std::endl;
	for (auto m : d_maquettes)
		ost << m << std::endl;

	ost << "====================" << std::endl;

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

formation* formation::rechercheFormation(std::string &intituleFormation)
{
	for (auto f : listeFormations)
		if(f->intituleFormation()==intituleFormation)
			return f;
}

void formation::afficherToutesLesFormations(std::ostream& ost)
{
	for (auto f : listeFormations)
		ost << f->intituleFormation() << std::endl;
}


std::ostream& operator<<(std::ostream& ost, gestionUE::formation& f)
{
	f.afficher(ost);
}

}
