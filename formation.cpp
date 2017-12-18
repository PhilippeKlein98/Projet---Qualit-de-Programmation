#include "formation.h"
#include "maquette.h"
#include <vector>
#include<iostream>

namespace gestionUE{

formation::formation(int codeFormation, std::string &intituleFormation) : d_codeFormation{codeFormation}, d_intituleFormation{intituleFormation}, d_maquettes{}
{}

int formation::codeFormation() const
{
	return d_codeFormation;
}

std::string& formation::intituleFormation() const
{
	return d_intituleFormation;
}

int formation::totalCreditECTS() const
{
	int total = 0;
	for (auto m : d_maquettes)
		total += m->totalCreditECTS();
<<<<<<< HEAD

=======
	
>>>>>>> c3b8dd41e7094796ea86d4af8ad6c20d6523f53d
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
<<<<<<< HEAD

=======
	
void formation formation::ajouterFormation(formation* f)
{
	listeFormations.push_back(f);
}

void formation::supprimerFormation(std::string &intituleFormation)
{
	for (int i = 0; i<listeFormations.size(); i++)
		if(listeFormations[i].intituleFormation()==intituleFormation)
			listeFormations.erase(i);
}
	
formation* formation::rechercheFormation(std::string &intituleFormation)
{
	for (auto f : listeFormations)
		if(f.intituleFormation()==intituleFormation)
			return f;
}
	
void formation::afficherToutesLesFormations(std::ostream& ost)
{
	for (auto f : listeFormations)
		ost << f.intituleFormation() << endl;
}
	
 
>>>>>>> c3b8dd41e7094796ea86d4af8ad6c20d6523f53d
}

std::ostream& operator<<(std::ostream& ost, gestionUE::formation& f)
{
	f.afficher(ost);
}
