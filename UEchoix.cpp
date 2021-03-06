#include "UEchoix.h"

namespace gestionUE
{

    UEchoix::UEchoix(std::string code, int coefficient, int ECTS, std::string intitule) : UE(ECTS), d_code{code}, d_coefficient{coefficient}, d_intitule{intitule}
    {}

    UEchoix::~UEchoix()
    {
        for(unsigned int i = 0; i < d_listeUE.size(); ++i)
        {
            delete d_listeUE[i];
        }
    }

    std::string UEchoix::intitule() const
    {
        return d_intitule;
    }

    std::string UEchoix::code() const
    {
        return d_code;
    }

    int UEchoix::coefficient() const
    {
        return d_coefficient;
    }

    int UEchoix::nombreHeuresCM() const
    {
        int resultat = 0;
        for(unsigned int i = 0; i < d_listeUE.size(); ++i)
        {
            resultat += d_listeUE[i]->nombreHeuresCM();
        }
        return resultat;
    }

    int UEchoix::nombreHeuresTD() const
    {
        int resultat = 0;
        for(unsigned int i = 0; i < d_listeUE.size(); ++i)
        {
            resultat += d_listeUE[i]->nombreHeuresTD();
        }
        return resultat;
    }

    int UEchoix::nombreHeuresTP() const
    {
        int resultat = 0;
        for(unsigned int i = 0; i < d_listeUE.size(); ++i)
        {
            resultat += d_listeUE[i]->nombreHeuresTP();
        }
        return resultat;
    }

    void UEchoix::afficher(std::ostream& ost) const
    {
        ost << d_code << "\t" << d_coefficient << "\t" << d_intitule << "\t" << nombreHeuresCM() << "\t" << nombreHeuresTD() << "\t" << nombreHeuresTP() << "\t" << nombreHeuresTotal() << "\t" << nombreHeuresTotalEnTD() << std::endl;
        for(unsigned int i = 0; i < d_listeUE.size(); ++i)
        {
            d_listeUE[i]->afficher(ost);
        }
    }

    void UEchoix::sauver(std::ofstream& ost) const
    {
        ost << UE_CHOIX << "\t" << ECTS() << "\t" << d_intitule << "\t" << d_code << "\t" << d_coefficient << "\t" << d_listeUE.size() << "\t" ;
        for(unsigned int i = 0; i < d_listeUE.size(); ++i)
        {
            ost << d_listeUE[i]->code() << "\t" ;
        }
    }

    bool UEchoix::contientMatiere(const std::string& codeMatiere) const
    {
        int i=0 ;
        while(i<d_listeUE.size() && !d_listeUE[i]->contientMatiere(codeMatiere))
        {
            ++i ;
        }
        return i!=d_listeUE.size() ;
    }

    void UEchoix::supprimerMatiere(const std::string& codeMatiere)
    {
        for(auto ue : d_listeUE)
        {
            ue->supprimerMatiere(codeMatiere) ;
        }
    }

    bool UEchoix::contientUE(const std::string& codeUE) const
    {
        int i=0 ;
        while (i<d_listeUE.size() && d_listeUE[i]->code()!=codeUE)
        {
            i++ ;
        }
        return i<d_listeUE.size() ;
    }

    void UEchoix::ajouterUE(const std::string& codeUE)
    {
        UE* ue = UE::chercherUE(codeUE) ;
        if (ue != nullptr && !contientUE(ue->code()))
        {
            d_listeUE.push_back(ue) ;
        }
    }

    void UEchoix::supprimerUE(const std::string& codeUE)
    {
        int i=0 ;
        while (i<d_listeUE.size() && d_listeUE[i]->code()!=codeUE)
        {
            i++ ;
        }
        if (i!=d_listeUE.size())
        {
            d_listeUE[i] = nullptr ;
            std::swap(d_listeUE[i],d_listeUE[d_listeUE.size()-1]) ;
            d_listeUE.pop_back() ;
        }

    }
}
