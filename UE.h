#ifndef UE_H
#define UE_H
#include<iostream>

class UE
{
    public:
        UE(int dETCS, bool estACHoix = false);
        virtual ~UE() = default;
        virtual std::string code() const = 0 ;
        virtual int coef() const = 0 ;
        int ECTS() const = 0 ;
        virtual std::string intitule() const = 0 ;
        bool estAChoix() const = 0 ;
        virtual int nbCM() const = 0 ;
        virtual int nbTD() const = 0 ;
        virtual int nbTP() const = 0 ;
        int nbTotal() const ;
        virtual void print(std::ostream& ost) const ;
        virtual ~UE();

    private:
        bool d_estAChoix ;
        int d_ETCS
};

#endif // UE_H
