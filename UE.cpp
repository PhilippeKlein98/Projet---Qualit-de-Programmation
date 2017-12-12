#include "UE.h"

UE::UE(int dECTS, bool estAChoix): d_ETCS(dECTS), d_estAChoix{estACHoix}
{}

int UE::nombreHeuresTotal() const
{
   return nombreHeuresCM() + nombreHeuresTD() + nombreHeuresTP() ;
}

void UE::print(std::ostream& ost) const
{
    ost << code() << "\t" << coefficient() << "\t" << ECTS() << "\t" << "UE " ;
}

