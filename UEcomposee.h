#ifndef UECOMPOSEE_H
#define UECOMPOSEE_H

#include "UE.h"
#include <vector>

class matiere;

class UEcomposee : public UE
{
    public:
        UEcomposee();
        virtual std::string intitule() const override ;
        virtual std::string code() const override ;
        virtual int coefficient() const override ;
        virtual int nombreHeuresCM() const override ;
        virtual int nombreHeuresTD() const override ;
        virtual int nombreHeuresTP() const override ;
        virtual void print(std::ostream& ost) const override ;

    private:
        std::string d_intitule ;
        std::string d_code ;
        std::vector<matiere*> d_listeMatieres;
};

#endif // UECOMPOSEE_H
