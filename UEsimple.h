#ifndef UESIMPLE_H
#define UESIMPLE_H

#include <iostream>

#include "UE.h"
class matiere;

class UEsimple: public UE
{
    public:
        UEsimple();
        virtual std::string code() const ;
        virtual int coefficient() const ;
        virtual int ECTS() const ;
        virtual std::string intitule() const ;
        virtual bool estAChoix() const ;
        virtual int nombreHeuresCM() const ;
        virtual int nombreHeuresTD() const ;
        virtual int nombreHeuresTP() const ;
        int nombreHeuresTotal() const ;
        virtual void print(std::ostream& ost) const ;
        virtual ~UEsimple() = default;

    private:
        matiere* d_m;
};

#endif // UESIMPLE_H
