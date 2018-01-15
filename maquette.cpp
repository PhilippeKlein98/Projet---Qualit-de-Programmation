#include "maquette.h"
#include "global.h"

namespace gestionUE
{

    long unsigned int maquette::identifiantSuivant = 1;

    std::vector<maquette*> maquette::listeMaquette;

    maquette:: maquette(): maquette{identifiantSuivant++} {}

    maquette::maquette(unsigned int identifiant) : d_identifiant{identifiant}, d_listeUE{}
    {
        listeMaquette.push_back(this);
    }

    void maquette::sauverTout()
    {
        std::ofstream fout {FICHIER_MAQUETTE.c_str()} ;
        fout << identifiantSuivant;
        for(const maquette* maq : listeMaquette)
        {
            maq->sauver(fout);
            fout << std::endl;
        }
    }

    void maquette::chargerTout()
    {
        std::ifstream fin {FICHIER_MAQUETTE.c_str()} ;
        fin >> identifiantSuivant;
        while(!fin.eof())
        {
            maquette* maq = new maquette();
            listeMaquette.push_back(maq);

            std::string str;
            std::getline(fin,str);

            std::istringstream iss(str);

            iss >> maq->d_identifiant; //identifiant de la maquette

            iss >> str;//premier code UE
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
        listeMaquette.resize(0) ;
    }

    maquette* maquette::chercherMaquette(long unsigned int identifiantMaquette)
    {
        unsigned int i = 0 ;
        while (i<listeMaquette.size() && listeMaquette[i]->identifiant() != identifiantMaquette)
        {
            ++i ;
        }
        if (i==listeMaquette.size())
        {
            return nullptr ;
        }
        return listeMaquette[i] ;
    }

    long unsigned int maquette::identifiant()const
    {
        return d_identifiant;
    }



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
        double total = 0;
        for(UE* ue : d_listeUE)
        {
            total +=  ue->nombreHeuresTotalEnTD();
        }

        return total;
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
        delete d_listeUE[index];
        for(int i=index; i<d_listeUE.size()-1; i++)
        {
            d_listeUE[i] = d_listeUE[i+1];
        }

        d_listeUE.pop_back();
    }

    void maquette::supprimerUE(const std::string& codeUE)
    {
        for(int i=0; i<d_listeUE.size(); i++)
        {
            if(codeUE == d_listeUE[i]->code())
            {
                supprimerUE(i);
            }
        }
    }

    bool maquette::contientUE(const std::string& codeUE) const
    {
        for(UE* ue : d_listeUE)
            if(codeUE == ue->code())
                return true;

        return false;
    }


    void maquette::afficher(std::ostream& ost) const
    {
        for(UE* ue : d_listeUE)
            ue->afficher(ost) ;
    }

    void maquette::sauver(std::ofstream& file) const
    {
        file << identifiant() << '\t' ;
        for(UE* ue : d_listeUE)
            file << ue->code() << '\t';
    }

    std::ostream& operator<<(std::ostream& ost, maquette& m)
    {
        m.afficher(ost);
        return ost;
    }

}
