#include "formation.h"
#include "maquette.h"
#include <vector>
#include<iostream>

namespace gestionUE{

formation::formation()
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
		total += d_maquettes.totalCreditECTS();
	
	return total;
}

 maquette* formation::operator[](int i) const
 {
	return (d_maquettes.size()>i) ? nullptr : d_maquettes[i]);
 }
 
  maquette* formation::operator[](int i)
 {
	return (d_maquettes.size()>i) ? nullptr : d_maquettes[i]);
 }
 
 void formation::print(std::ostream& ost) const
 {
	ost << "====================" << std::endl;
		for (auto m : d_maquettes)
			ost << m << std::endl;
	
	ost << "====================" << std::endl;
	
 }
 
}

std::ostream& operator<<(std::ostream& ost, formation& f)
{
	f.print(ost);
}