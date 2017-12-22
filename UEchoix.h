#ifndef UECHOIX_H
#define UECHOIX_H

#include <vector>
#include "UE.h"
#include "global.h"

namespace gestionUE
{
    class UEchoix : public UE
    {
        public:
            UEchoix(std::string code, int coefficient, int ECTS, std::string intitule);

            virtual ~UEchoix();

            virtual std::string intitule() const override ;
            virtual std::string code() const override ;

            virtual int coefficient() const override ;

            virtual int nombreHeuresCM() const override ;
            virtual int nombreHeuresTD() const override ;
            virtual int nombreHeuresTP() const override ;

            virtual void afficher(std::ostream& ost) const override ;
            virtual void sauver(std::ofstream& ost) const override ;

            virtual bool contientMatiere(const std::string& codeMatiere) const override ;
            virtual void supprimerMatiere(const std::string& codeMatiere) override ;

            bool contientUE(const std::string& codeUE) const ;
            void ajouterUE(const std::string& codeUE) ;
            void supprimerUE(const std::string& codeUE) ;

        private:
            std::string d_code ;
            int d_coefficient ;
            std::string d_intitule ;
            std::vector<UE*> d_listeUE ;
    };
}


#endif // UECHOIX_H
