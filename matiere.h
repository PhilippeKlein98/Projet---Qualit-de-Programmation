#ifndef MATIERE_H_INCLUDED
#define MATIERE_H_INCLUDED

#include <vector>
#include "global.h"

namespace gestionUE
{
    class matiere
    {
    public:
        static std::vector<matiere*> listeMatieres ;
        static void sauverTout(std::ofstream& fout) ;
        static void chargerTout(std::ifstream& fin) ;
        static void supprimerMatiere(const std::string& codeMatiere) ;
        static matiere* chercherMatiere(const std::string& codeMatiere) ;

        matiere() = default;
        matiere(const std::string& code , const std::string& nom , int coefficient , int heuresCM , int heuresTD , int heuresTP) ;
        ~matiere() = default;

        int nombreHeuresTotal()const;
        double nombreHeuresTotalEnTD()const;
        int nombreHeuresCM()const;
        int nombreHeuresTD()const;
        int nombreHeuresTP()const;
        int coefficient()const;

        std::string code()const;
        std::string nom()const;

        void modifierCode(const std::string & code);
        void modifierNom(const std::string & nom);
        void modifierHeuresCM(int nombreHeuresCM);
        void modifierHeuresTD(int nombreHeuresTD);
        void modifierHeuresTP(int nombreHeuresTP);
        void modifierCoefficient(int coefficient);

        void afficher(std::ostream & os)const;
        void sauver(std::ofstream & fout) const;

    private:

        std::string d_code, d_nom;
        int d_coefficient, d_nombreHeuresCM, d_nombreHeuresTD, d_nombreHeuresTP;
    };

}
#endif // MATIERE_H_INCLUDED
