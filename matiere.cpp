#include "matiere.h"
#include "UE.h"
#include <fstream>

namespace gestionUE
{
    std::vector<matiere*> matiere::listeMatieres ;

    matiere::matiere(const std::string& code , const std::string& nom , int coefficient , int heuresCM , int heuresTD , int heuresTP)  :
        d_code{code} , d_nom{nom} , d_coefficient{coefficient} , d_nombreHeuresCM{heuresCM} , d_nombreHeuresTD{heuresTD} , d_nombreHeuresTP{heuresTP}
    {}

    int matiere::nombreHeuresTotal()const
    {
        return d_nombreHeuresCM + d_nombreHeuresTD + d_nombreHeuresTP;
    }

    double matiere::nombreHeuresTotalEnTD() const
    {
        return d_nombreHeuresTD + d_nombreHeuresCM * CM_VERS_TD + d_nombreHeuresTP * TP_VERS_TD;
    }

    int matiere::nombreHeuresCM()const
    {
        return d_nombreHeuresCM;
    }

    int matiere::nombreHeuresTD()const
    {
        return d_nombreHeuresTD;
    }

    int matiere::nombreHeuresTP()const
    {
        return d_nombreHeuresTP;
    }

    int matiere::coefficient()const
    {
        return d_coefficient;
    }

    std::string matiere::code()const
    {
        return d_code;
    }

    std::string matiere::nom()const
    {
        return d_nom;
    }

    void matiere::modifierCode(const std::string & code)
    {
        d_code = code;
    }

    void matiere::modifierNom(const std::string & nom)
    {
        d_nom = nom;
    }

    void matiere::modifierHeuresCM(int nombreHeuresCM)
    {
        d_nombreHeuresCM = nombreHeuresCM;
    }

    void matiere::modifierHeuresTD(int nombreHeuresTD)
    {
        d_nombreHeuresTD = nombreHeuresTD;
    }

    void matiere::modifierHeuresTP(int nombreHeuresTP)
    {
        d_nombreHeuresTP = nombreHeuresTP;
    }

    void matiere::modifierCoefficient(int coefficient)
    {
        d_coefficient = coefficient;
    }

    void matiere::afficher(std::ostream & os)const
    {
        os << d_code << "\t" << d_nom << "\t" << d_coefficient << "\t" << d_nombreHeuresCM << "\t" << d_nombreHeuresTD << "\t" << d_nombreHeuresTP << "\t" << nombreHeuresTotal() << "\t" << nombreHeuresTotalEnTD() << std::endl;
    }

    void matiere::sauver(std::ofstream& fout) const
    {
        fout << d_code << "\t" << d_nom << "\t" << d_coefficient << "\t" << "\t" << d_nombreHeuresCM << "\t" << d_nombreHeuresTD << "\t" << d_nombreHeuresTP ;
    }

    void matiere::sauverTout(std::ofstream& fout)
    {
        for (auto matiere : listeMatieres)
        {
            matiere->sauver(fout) ;
            fout << std::endl ;
        }
    }

    void matiere::chargerTout(std::ifstream& fin)
    {
        std::string code , nom ;
        int coefficient , heuresCM , heuresTD , heuresTP ;
        listeMatieres.clear() ;
        while (!fin.eof())
        {
            fin >> code >> nom >> coefficient >> heuresCM >> heuresTD >> heuresTP ;
            matiere* mat = new matiere{code,nom,coefficient,heuresCM,heuresTD,heuresTP} ;
            listeMatieres.push_back(mat) ;
        }
    }

    void matiere::supprimerMatiere(const std::string& codeMatiere)
    {
        unsigned int i=0 ;
        while (i<listeMatieres.size() && codeMatiere!=listeMatieres[i]->code())
        {
            ++i ;
        }
        if (i!=listeMatieres.size())
        {
            for (auto ue : UE::listeUE)
            {
                if (ue->contientMatiere(codeMatiere))
                {
                    ue->supprimerMatiere(codeMatiere) ;
                }
            }
            std::swap(listeMatieres[listeMatieres.size()-1],listeMatieres[i]) ;
            listeMatieres.pop_back() ;
        }
    }

    matiere* matiere::chercherMatiere(const std::string& codeMatiere)
    {
        unsigned int i = 0 ;
        while (i<listeMatieres.size() && listeMatieres[i]->code() != codeMatiere)
        {
            ++i ;
        }
        if (i==listeMatieres.size())
        {
            return nullptr ;
        }
        return listeMatieres[i] ;
    }

    void matiere::libererTout()
    {
        for (auto m : listeMatieres)
        {
            delete m ;
        }
    }
}
