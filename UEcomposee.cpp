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
        for(int i = 0; i < d_listeMatieres.size(); ++i)
        {
            resultat += d_listeMatieres[i]->nombreHeuresCM();
        }
        return resultat;
    }

    int UEcomposee::nombreHeuresTD()const
    {
        int resultat = 0;
        for(int i = 0; i < d_listeMatieres.size(); ++i)
        {
            resultat += d_listeMatieres[i]->nombreHeuresTD();
        }
        return resultat;
    }

    int UEcomposee::nombreHeuresTP()const
    {
        int resultat = 0;
        for(int i = 0; i < d_listeMatieres.size(); ++i)
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
        for(int i = 0; i < d_listeMatieres.size(); ++i)
        {
            d_listeMatieres[i]->afficher(ost);
        }
    }
}
