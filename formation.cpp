#include "formation.h"
#include "maquette.h"
#include "global.h"
#include <vector>
#include<iostream>

namespace gestionUE{

    std::vector<formation*> formation::listeFormations;

formation::formation(std::string intituleFormation) : d_intituleFormation{intituleFormation}, d_maquettes()
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

void formation::supprimerMaquette(int index)
{
        delete d_maquettes[index];
        for(int i=index; i<d_maquettes.size()-1; i++)
        {
            d_maquettes[i] = d_maquettes[i+1];
        }

        d_maquettes.pop_back();
}

void formation::supprimerDerniereMaquette()
{
	d_maquettes.pop_back();
}

 maquette* formation::operator[](unsigned int i) const
 {
	return (((d_maquettes.size()-1)>i) ? nullptr : d_maquettes[i]);
 }

  maquette* formation::operator[](unsigned int i)
 {
	return (((d_maquettes.size()-1)>i) ? nullptr : d_maquettes[i]);
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

void formation::chargerTout()
{
    std::ifstream fin {FICHIER_FORMATION.c_str()} ;
    while(!fin.eof())
    {
        std::string intitule ;
        fin >> intitule ;
        formation* form = new formation (intitule);

        std::string informationsFormation;
        std::getline(fin,informationsFormation);

        std::istringstream iss(informationsFormation);

        long unsigned int codesMaquettes ;
        iss >> codesMaquettes;
        while(!iss.eof())
        {
            maquette* nouvelleMaquette = maquette::chercherMaquette(codesMaquettes) ;
            if (nouvelleMaquette)
            {
                form->d_maquettes.push_back(nouvelleMaquette) ;
            }
            iss >> codesMaquettes ;
        }
        listeFormations.push_back(form) ;
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
