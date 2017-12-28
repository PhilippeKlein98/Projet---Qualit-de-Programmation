#include "UE.h"
#include "global.h"
#include "maquette.h"

namespace gestionUE
{
    std::vector<UE*> UE::listeUE ;

    UE::UE(int ECTS): d_ECTS{ECTS}
    {
        listeUE.push_back(this);
    }

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

    void UE::supprimerUE(const std::string& codeUE)
    {
        unsigned int i=0 ;
        while (i<listeUE.size() && codeUE!=listeUE[i]->code())
        {
            ++i ;
        }
        if (i != listeUE.size())
        {
            for (auto m : maquette::listeMaquette)
            {
                if (m->contientUE(codeUE))
                {
                    m->supprimerUE(codeUE) ;
                }
            }
            std::swap(listeUE[listeUE.size()-1],listeUE[i]) ;
            listeUE.pop_back() ;
        }
    }

    void UE::sauverTout()
    {
        std::ofstream fout {FICHIER_UE.c_str()} ;
        for (auto ue : listeUE)
        {
            ue->sauver(fout) ;
            fout << std::endl ;
        }
    }

    UE* UE::chercherUE(const std::string& codeUE)
    {
        unsigned int i = 0 ;
        while (i<listeUE.size() && listeUE[i]->code() != codeUE)
        {
            ++i ;
        }
        if (i==listeUE.size())
        {
            return nullptr ;
        }
        return listeUE[i] ;
    }

    void UE::libererTout()
    {
        for(auto ue : listeUE)
        {
            delete ue ;
        }
    }
}
