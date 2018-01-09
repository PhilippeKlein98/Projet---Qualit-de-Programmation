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
            static UE* chercherUE (const std::string& codeUE) ;
            static void sauverTout();
            static void chargerTout() ;
            static void lireUE(unsigned int typeUE , std::ifstream& fin) ;
            static void supprimerUE(const std::string& codeUE) ;
            static void libererTout() ;

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

            virtual bool contientMatiere(const std::string& codeMatiere) const = 0 ;
            virtual void supprimerMatiere(const std::string& codeMatiere) = 0 ;

            virtual void afficher(std::ostream& ost) const ;
            virtual void sauver(std::ofstream& fout) const = 0;

        private:
            int d_ECTS;

    };
}



#endif // UE_H
