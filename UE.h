#ifndef UE_H
#define UE_H
#include<iostream>

class UE
{
    public:
        UE(int dETCS, bool estAChoix = false);
        virtual ~UE() = default;
        virtual std::string code() const = 0 ;
        virtual int coefficient() const = 0 ;
        virtual int ECTS() const ;
        virtual std::string intitule() const = 0 ;
        virtual int nombreHeuresCM() const = 0 ;
        virtual int nombreHeuresTD() const = 0 ;
        virtual int nombreHeuresTP() const = 0 ;
        int nombreHeuresTotal() const ;
        virtual void print(std::ostream& ost) const ;

    protected:
        int d_ETCS;
};

#endif // UE_H