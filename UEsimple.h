#ifndef UESIMPLE_H
#define UESIMPLE_H
#include "global.h"

#include "UE.h"

namespace gestionUE
{
    class matiere;

    class UEsimple: public UE
    {
        public:
            UEsimple();

            virtual std::string intitule() const override ;
            virtual std::string code() const override ;

            virtual int coefficient() const override ;

            virtual int nombreHeuresCM() const override ;
            virtual int nombreHeuresTD() const override ;
            virtual int nombreHeuresTP() const override ;

            virtual void afficher(std::ostream& ost) const override ;
            virtual void sauver(std::ofstream& ist) const override ;

        private:
            matiere* d_matiere;
    };
}


#endif // UESIMPLE_H
