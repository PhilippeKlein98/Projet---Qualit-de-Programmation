#ifndef MATIERE_H_INCLUDED
#define MATIERE_H_INCLUDED

#include "global.h"

namespace gestionUE
{

    class matiere
    {
    public:
        matiere() = default;
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

    private:
        std::string d_code, d_nom;
        int d_nombreHeuresCM, d_nombreHeuresTD, d_nombreHeuresTP, d_coefficient;
    };

}
#endif // MATIERE_H_INCLUDED
