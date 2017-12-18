#include "maquette.h"

namespace gestionUE
{
    maquette:: maquette() {}

    int maquette::totalCreditECTS() const
    {
        int tot = 0;
        for(UE* ue : d_listeUE)
        {
            tot +=  ue->ECTS();
        }

        return tot;
    }

    double maquette::nombreHeuresTotalEnTD() const
    {
        double tot = 0;
        for(UE* ue : d_listeUE)
        {
            tot +=  ue->nombreHeuresTotalEnTD();
        }

        return tot;
    }

    int maquette::nombreHeuresTotal()const
    {
        int tot = 0;
        for(UE* ue : d_listeUE)
        {
            tot +=  ue->nombreHeuresTotal();
        }

        return tot;
    }

    int maquette::nombreHeuresCM()const
    {
        int tot = 0;
        for(UE* ue : d_listeUE)
        {
            tot +=  ue->nombreHeuresCM();
        }

        return tot;
    }

    int maquette::nombreHeuresTD()const
    {
        int tot = 0;
        for(UE* ue : d_listeUE)
        {
            tot +=  ue->nombreHeuresTD();
        }

        return tot;
    }

    int maquette::nombreHeuresTP()const
    {
        int tot = 0;
        for(UE* ue : d_listeUE)
        {
            tot +=  ue->nombreHeuresTP();
        }

        return tot;
    }


    UE* maquette::operator[](int index) const
    {
        return d_listeUE[index];
    }


    UE* maquette::operator[](int index)
    {
        return d_listeUE[index];
    }

    void maquette::ajouterUE(UE* ue)
    {
        d_listeUE.push_back(ue);
    }


    void maquette::supprimerUE(int index)
    {
        for(int i=index; i<d_listeUE.size()-1; i++)
        {
            d_listeUE[index] = d_listeUE[index+1];
        }

        d_listeUE.pop_back();
    }


    void maquette::print(std::ostream& ost) const
    {

    }

}
