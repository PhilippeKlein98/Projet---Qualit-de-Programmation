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

        int nombreHeureTotal()const;
        double nombreHeureTotalEnTD()const;
        int nombreHeureCM()const;
        int nombreHeureTD()const;
        int nombreHeureTP()const;
        int coefficient()const;

        std::string code()const;
        std::string nom()const;

        void modifierCode(const std::string & code);
        void modifierNom(const std::string & nom);
        void modifierHeureCM(int nombreHeureCM);
        void modifierHeureTD(int nombreHeureTD);
        void modifierHeureTP(int nombreHeureTP);
        void modifierCoefficient(int coefficient);

        void afficher(std::ostream & os)const;

    private:
        std::string d_code, d_nom;
        int d_nombreHeureCM, d_nombreHeureTD, d_nombreHeureTP, d_coefficient;
    };

}
#endif // MATIERE_H_INCLUDED
