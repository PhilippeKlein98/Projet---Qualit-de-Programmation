#ifndef UE_H
#define UE_H
#include<iostream>
#include <fstream>
#include<vector>

namespace gestionUE
{

    class UE
    {
        public:
            static std::vector<UE*> listeUE ;
            static void sauverTout(std::ofstream& fout);
            static void chargerTout(std::ifstream& fin) ;
            static void supprimerUE(const std::string& codeUE) ;

            UE(int ECTS);
            virtual ~UE() = default;
            virtual std::string code() const = 0 ;
            virtual int coefficient() const = 0 ;
            int ECTS() const ;
            virtual std::string intitule() const = 0 ;
            virtual int nombreHeuresCM() const = 0 ;
            virtual int nombreHeuresTD() const = 0 ;
            virtual int nombreHeuresTP() const = 0 ;
            int nombreHeuresTotal() const ;
            double nombreHeuresTotalEnTD() const ;
            virtual void afficher(std::ostream& ost) const ;
            virtual void sauver(std::ofstream& fout) const ;

        private:
            int d_ECTS;

    };
}



#endif // UE_H
