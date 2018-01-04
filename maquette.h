#ifndef MAQUETTE_H_INCLUDED
#define MAQUETTE_H_INCLUDED
#include <vector>
#include <iostream>
#include <sstream>
#include "UE.h"

namespace gestionUE
{
    class maquette
    {
    public:
        static long unsigned int identifiantSuivant;
        static std::vector<maquette*> listeMaquette;
        static void sauverTout();
        static void chargerTout();
        static void libererTout();
        static maquette* chercherMaquette(long unsigned int identifiantMaquette) ;

    public:
        maquette();
        maquette(unsigned int identifiant);
        int totalCreditECTS() const;
        double nombreHeuresTotalEnTD() const ;
        int nombreHeuresTotal()const;
        int nombreHeuresCM()const;
        int nombreHeuresTD()const;
        int nombreHeuresTP()const;
        UE* operator[](int index) const;
        UE* operator[](int index);
        long unsigned int identifiant()const;
        bool contientUE(const std::string& codeUE) const ;
        void ajouterUE(UE*);
        void supprimerUE(int index);
        void supprimerUE(const std::string& codeUE) ;
        void afficher(std::ostream& ost) const ;
        void sauver(std::ofstream& file) const;

    private:

        long unsigned int d_identifiant;
        std::vector<UE*> d_listeUE;
    };

    std::ostream& operator<<(std::ostream& ost, maquette& m);
}



#endif // MAQUETTE_H_INCLUDED
