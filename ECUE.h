#ifndef ECUE_H
#define ECUE_H

#include <iostream>

#include "UE.h"
class matiere;

class ECUE: public UE
{
    public:
        ECUE();
        virtual std::string code() const = 0 ;
        virtual int coef() const = 0 ;
        virtual int ECTS() const = 0 ;
        virtual std::string intitule() const = 0 ;
        virtual bool estAChoix() const = 0 ;
        virtual int nbCM() const = 0 ;
        virtual int nbTD() const = 0 ;
        virtual int nbTP() const = 0 ;
        int nbTotal() const ;
        virtual void print(std::ostream& ost) const ;
        virtual ~ECUE() = default;

    private:
        matiere* d_m;
};

#endif // ECUE_H
