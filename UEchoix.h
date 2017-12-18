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
            UEchoix();
            virtual ~UEchoix();
            virtual std::string intitule() const override ;
            virtual int nombreHeuresCM() const override ;
            virtual int nombreHeuresTD() const override ;
            virtual int nombreHeuresTP() const override ;
        private:
            std::string d_intitule ;
            std::vector<UE*> d_listeUE ;
    };
}


#endif // UECHOIX_H
