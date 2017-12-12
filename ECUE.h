#ifndef ECUE_H
#define ECUE_H

#include <iostream>

#include "UE.h"
class matiere;

class ECUE: public UE
{
    public:
        ECUE();
        virtual std::string code() const ;
        virtual int coef() const ;
        virtual int ECTS() const ;
        virtual std::string intitule() const ;
        virtual bool estAChoix() const ;
        virtual int nbCM() const ;
        virtual int nbTD() const ;
        virtual int nbTP() const ;
        int nbTotal() const ;
        virtual void print(std::ostream& ost) const ;
        virtual ~ECUE() = default;

    private:
        matiere* d_m;
};

#endif // ECUE_H
