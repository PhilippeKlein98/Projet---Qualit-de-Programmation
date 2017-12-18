#include "UE.h"
#include "global.h"

namespace gestionUE
{
    UE::UE(int dECTS): d_ECTS{dECTS}
    {}

    int UE::nombreHeuresTotal() const
    {
       return nombreHeuresCM() + nombreHeuresTD() + nombreHeuresTP() ;
    }

    double UE::nombreHeuresTotalEnTD() const
    {
        return CM_VERS_TD*nombreHeuresCM() + nombreHeuresTD() + TP_VERS_TD*nombreHeuresTP() ;
    }

    int UE::ECTS() const
    {
        return d_ECTS ;
    }

    void UE::afficher(std::ostream& ost) const
    {
        ost << code() << "\t" << coefficient() << "\t" << ECTS() << "\t" << "UE " ;
    }


}



