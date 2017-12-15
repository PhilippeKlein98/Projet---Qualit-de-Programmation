#include "UEcomposee.h"

namespace gestionUE
{
    UEcomposee::UEcomposee(const std::string & intitule, const std::string & code, int coefficient, int ECTS, const std::vector<matier*> & listMatieres) :
        UE{ECTS}, d_intitule{intitule}, d_code{code}, d_coefficient{coefficient}, d_listMatieres{listMatieres}
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

    int UEcomposee::nombreHeuresTotal() const
    {
        int resultat = 0;
        for(int i = 0; i < d_listeMatieres.size(); ++i)
        {
            resultat += d_listeMatieres[i]->nombreHeuresTotal();
        }
        return resultat;
    }

    double UEcomposee::nombreHeuresTotalEnTD() const
    {
        double resultat = 0;
        for(int i = 0; i < d_listeMatieres.size(); ++i)
        {
            resultat += d_listeMatieres[i]->nombreHeuresTotalEnTD();
        }
        return resultat;
    }

    int UEcomposee::nombreHeuresCM()const
    {
        int resultat = 0;
        for(int i = 0; i < d_listeMatieres.size(); ++i)
        {
            resultat += d_listeMatieres[i]->matiere::nombreHeuresCM();
        }
        return resultat;
    }

    int UEcomposee::nombreHeuresTD()const
    {
        int resultat = 0;
        for(int i = 0; i < d_listeMatieres.size(); ++i)
        {
            resultat += d_listeMatieres[i]->matiere::nombreHeuresTD();
        }
        return resultat;
    }

    int UEcomposee::nombreHeuresTP()const
    {
        int resultat = 0;
        for(int i = 0; i < d_listeMatieres.size(); ++i)
        {
            resultat += d_listeMatieres[i]->matiere::nombreHeuresTP();
        }
        return resultat;
    }

    void UEcomposee::afficher(std::ostream& ost)const
    {
        ost << d_code << "\t" << d_coefficient << "\t" << UE::afficher() << "\t" << d_intitule << "\t" << nombreHeuresCM() << "\t" << nombreHeuresTD() << "\t" << nombreHeuresTP() << "\t" << nombreHeuresTotal() << "\t" << nombreHeuresTotalEnTD() << std::endl;
        for(int i = 0; i < d_listeMatieres.size(); ++i)
        {
            d_listeMatieres[i]->afficher();
        }
    }
}
