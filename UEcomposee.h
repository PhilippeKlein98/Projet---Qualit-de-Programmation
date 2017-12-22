#ifndef UECOMPOSEE_H
#define UECOMPOSEE_H

#include "UE.h"
#include <vector>
#include "global.h"

namespace gestionUE
{

    class matiere;

    class UEcomposee : public UE
    {
        public:
            UEcomposee(const std::string & intitule, const std::string & code, int coefficient, int ECTS, const std::vector<matiere*> & listMatieres);

            virtual std::string intitule() const override ;
            virtual std::string code() const override ;

            virtual int coefficient() const override;
            virtual int nombreHeuresCM() const override ;
            virtual int nombreHeuresTD() const override ;
            virtual int nombreHeuresTP() const override ;

            virtual void afficher(std::ostream& ost) const override ;
            virtual void sauver(std::ofstream& ost) const override ;

            virtual bool contientMatiere(const std::string& codeMatiere) const override ;
            virtual void supprimerMatiere(const std::string& codeMatiere) override ;

        private:
            std::string d_intitule ;
            std::string d_code ;
            int d_coefficient;
            std::vector<matiere*> d_listeMatieres;
    };

}

#endif // UECOMPOSEE_H
