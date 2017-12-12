#ifndef MAQUETTE_H_INCLUDED
#define MAQUETTE_H_INCLUDED
#include <vector>
#include <iostream>
#include "UE.h"

class maquette
{
public:
	maquette();
	int totalCreditECTS() const;
    int volumeHoraireTotal()const;
	int nombreHeureDeCours()const;
	int nombreHeureDeTD()const;
	int nombreHeureDeTP()const;
	UE* operator[](int codeUE) const;
    UE* operator[](int codeUE);
	void ajouterUE(UE*);
	void supprimerUE(int codeUE);
	void print(std::ostream& ost) const ;

private:
    std::vector<UE*> d_listeUE;
};

#endif // MAQUETTE_H_INCLUDED