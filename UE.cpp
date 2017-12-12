#include "UE.h"

UE::UE(int dETCS, bool estACHoix): d_ETCS{dECTS}, d_estAChoix{estACHoix}
{}

int UE::nbTotal() const
{
   return nbCM() + nbTD() + nbTP() ;
}

void UE::print(std::ostream& ost) const
{
    ost << code() << "\t" << coef() << "\t" << ECTS() << "\t" << "UE " ;
}

