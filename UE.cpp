#include "UE.h"
#include "global.h"

namespace gestionUE
{
    std::vector<UE*> UE::listeUE ;

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

    void UE::sauver(std::ofstream& fout) const
    {

    }

    void UE::supprimerUE(const std::string& codeUE)
    {
        unsigned int i=0 ;
        while (i<listeUE.size() && codeUE!=listeUE[i]->code())
        {
            ++i ;
        }
        if (i!=listeUE.size())
        {
            std::swap(listeUE[listeUE.size()-1],listeUE[i]) ;
            listeUE.pop_back() ;
        }
    }
}



