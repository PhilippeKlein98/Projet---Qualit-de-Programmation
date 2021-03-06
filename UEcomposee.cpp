#include "UEcomposee.h"
#include "matiere.h"

namespace gestionUE
{
    UEcomposee::UEcomposee(const std::string & intitule, const std::string & code, int coefficient, int ECTS, const std::vector<matiere*> & listMatieres) :
        UE{ECTS}, d_intitule{intitule}, d_code{code}, d_coefficient{coefficient}, d_listeMatieres{listMatieres}
    {}

    std::string UEcomposee::intitule()const
    {
        return d_intitule;
    }

    std::string UEcomposee::code()const
    {
        return d_code;
    }

    int UEcomposee::coefficient()const
    {
        return d_coefficient;
    }

    int UEcomposee::nombreHeuresCM()const
    {
        int resultat = 0;
        for(unsigned int i = 0; i < d_listeMatieres.size(); ++i)
        {
            resultat += d_listeMatieres[i]->nombreHeuresCM();
        }
        return resultat;
    }

    int UEcomposee::nombreHeuresTD()const
    {
        int resultat = 0;
        for(unsigned int i = 0; i < d_listeMatieres.size(); ++i)
        {
            resultat += d_listeMatieres[i]->nombreHeuresTD();
        }
        return resultat;
    }

    int UEcomposee::nombreHeuresTP()const
    {
        int resultat = 0;
        for(unsigned int i = 0; i < d_listeMatieres.size(); ++i)
        {
            resultat += d_listeMatieres[i]->nombreHeuresTP();
        }
        return resultat;
    }

    void UEcomposee::afficher(std::ostream& ost)const
    {
        ost << d_code << "\t" << d_coefficient << "\t" ;
        UE::afficher(ost) ;
        ost << "\t" << d_intitule << "\t" << nombreHeuresCM() << "\t" << nombreHeuresTD() << "\t" << nombreHeuresTP() << "\t" << nombreHeuresTotal() << "\t" << nombreHeuresTotalEnTD() << std::endl;
        for(unsigned int i = 0; i < d_listeMatieres.size(); ++i)
        {
            d_listeMatieres[i]->afficher(ost);
        }
    }

    void UEcomposee::sauver(std::ofstream& ost) const
    {
        ost << UE_COMPOSEE << "\t" << ECTS() << "\t" << d_intitule << "\t" << d_code << "\t" << d_coefficient << "\t" << d_listeMatieres.size() << "\t" ;
        for(unsigned int i = 0; i < d_listeMatieres.size(); ++i)
        {
            ost << d_listeMatieres[i]->code() << "\t" ;
        }
    }

    bool UEcomposee::contientMatiere(const std::string& codeMatiere) const
    {
        int i=0 ;
        while (i<d_listeMatieres.size() && d_listeMatieres[i]->code()!=codeMatiere)
        {
            ++i ;
        }
        return i!=d_listeMatieres.size() ;
    }

    void UEcomposee::supprimerMatiere(const std::string& codeMatiere)
    {
        int i=0 ;
        while (i<d_listeMatieres.size() && d_listeMatieres[i]->code()!=codeMatiere)
        {
            ++i ;
        }
        d_listeMatieres[i] = nullptr ;
        std::swap(d_listeMatieres[i],d_listeMatieres[d_listeMatieres.size()-1]) ;
        d_listeMatieres.pop_back() ;
    }
}
