#include "UE.h"

UE::UE(int dECTS): d_ETCS(dECTS)
{}

int UE::nombreHeuresTotal() const
{
   return nombreHeuresCM() + nombreHeuresTD() + nombreHeuresTP() ;
}

void UE::print(std::ostream& ost) const
{
    ost << code() << "\t" << coefficient() << "\t" << ECTS() << "\t" << "UE " ;
}

