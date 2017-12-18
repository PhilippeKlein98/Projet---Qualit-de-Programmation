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

        private:
            std::string d_intitule , d_code ;
            std::vector<UE*> d_listeUE ;
            int d_coefficient;
    };
}


#endif // UECHOIX_H
