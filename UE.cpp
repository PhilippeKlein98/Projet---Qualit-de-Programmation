#include "UE.h"

int UE::nbTotal() const
{
   return nbCM() + nbTD() + nbTP() ;
}

void UE::print(std::ostream& ost) const
{
    ost << code() << "\t" << coef() << "\t" << ECTS() << "\t" << intitule() << std::endl ;
}

UE::~UE()
{

}
