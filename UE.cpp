#include "UE.h"
#include "UEsimple.h"
#include "UEcomposee.h"
#include "UEchoix.h"
#include "global.h"
#include "maquette.h"
#include "windows.h"
#include "matiere.h"

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

    void UE::afficherToutesLesUE(std::ostream& ost)
    {
        ost << "========================================" << std::endl;

        for (auto ue : listeUE)
        {
            ue->afficher(ost);
        }

        ost << "========================================" << std::endl;
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

    void UE::lireUE(unsigned int typeUE , std::ifstream& fin)
    {
        switch (typeUE)
        {
            int ects ;
            case UE_SIMPLE :
            {

                std::string codeMatiere ;
                fin >> ects >> codeMatiere ;
                UEsimple* ueSimple = new UEsimple{ects,codeMatiere} ;
                listeUE.push_back(ueSimple) ;
                break ;
            }
            case UE_COMPOSEE :
            {
                std::string intituleUE , codeUE , codeMatiere ;
                int coefficientUE , nombreMatieres ;
                fin >> ects >> intituleUE >> codeUE >> coefficientUE >> nombreMatieres ;
                std::vector<matiere*> listeMatiere (nombreMatieres) ;

                for (int i=0 ; i<nombreMatieres ; i++)
                {
                    fin >> codeMatiere ;
                    listeMatiere[i] = matiere::chercherMatiere(codeMatiere) ;
                }

                listeUE.push_back(new UEcomposee{intituleUE,codeUE,coefficientUE,ects,listeMatiere}) ;
                break ;
            }
            case UE_CHOIX :
            {
                std::string intituleUE , codeUEchoix , codeUE ;
                int coefficientUE , nombreUes ;
                fin >> ects >> intituleUE >> codeUEchoix >> coefficientUE >> nombreUes ;
                std::vector<UE*> listeUes (nombreUes) ;
                UEchoix* nouvelleUEchoix = new UEchoix{codeUEchoix,coefficientUE,ects,intituleUE} ;
                for (int i=0 ; i<nombreUes ; i++)
                {
                    fin >> codeUE ;
                    nouvelleUEchoix->ajouterUE(codeUE) ;
                }

                listeUE.push_back(nouvelleUEchoix) ;
                break ;
            }
        }
    }

    void UE::chargerTout()
    {
        std::ifstream fin{FICHIER_UE.c_str()} ;
        unsigned int typeUE ;
        fin >> typeUE ;
        while (!fin.eof())
        {
            lireUE(typeUE,fin) ;
            fin >> typeUE ;
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
        listeUE.resize(0) ;
    }
}
