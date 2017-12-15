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

    int UEcomposee::nombreHeuresCM()const
    {
        int resultat = 0;
        for(int i = 0; i < d_listeMatieres.size(); ++i)
        {
            resultat += d_listeMatieres[i].matiere::nombreHeuresCM();
        }
        return resultat;
    }
}
