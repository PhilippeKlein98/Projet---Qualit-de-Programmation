#ifndef UECHOIX_H
#define UECHOIX_H

#include "global.h"

namespace gestionUE
{
    class UEchoix : public UE
    {
        public:
            UEchoix();
            virtual ~UEchoix();
            virtual std::string intitule() const override ;
            virtual int nombreHeuresCM() const = 0 ;
            virtual int nombreHeuresTD() const = 0 ;
            virtual int nombreHeuresTP() const = 0 ;
        private:
            std::string intitule ;
            std::vector<UE*> d_listeUE ;
    };
}


#endif // UECHOIX_H
