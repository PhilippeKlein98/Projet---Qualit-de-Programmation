#include "maquette.h"


namespace gestionUE
{
    long unsigned int maquette::identifiantSuivant = 1;

    std::vector<maquette*> maquette::listeMaquette;

    void maquette::sauverTout(std::ofstream& fout)
    {
        fout << identifiantSuivant;
        for(const maquette* maq : listeMaquette)
        {
            maq->sauver(fout);
            fout << std::endl;
        }
    }

    void maquette::chargerTout(std::ifstream& fin)
    {
        fin >> identifiantSuivant;
        while(!fin.eof())
        {
            maquette* maq = new maquette();
            listeMaquette.push_back(maq);

            std::string str;
            std::getline(fin,str);

            std::istringstream iss(str);

            iss >> str;
            while(!iss.eof())
            {
                UE* ue = UE::chercherUE(str);
                if(!ue)
                    return;
                maq->d_listeUE.push_back(ue);
                iss >> str;
            }
        }
    }

    void maquette::libererTout()
    {
        for(maquette* maq : listeMaquette)
            delete maq;
    }



    long unsigned int identifiant()const
    {
        return d_identifiant;
    }

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
        for(UE* ue : d_listeUE)
            ue->afficher(ost) ;
    }

    void maquette::sauver(std::ofstream& file) const
    {
        for(UE* ue : d_listeUE)
            file << ue->code() << '\t';
    }

}
