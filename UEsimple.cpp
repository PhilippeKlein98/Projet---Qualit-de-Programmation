#include "UEsimple.h"
#include "matiere.h"

std::string UEsimple::code() const
{
    return d_m->code();
}

int UEsimple::coefficient() const
{
    return d_m->coef();
}

int UEsimple::ECTS() const
{
    return d_ETCS;
}

std::string UEsimple::intitule() const
{
    return d_m->nom();
}

bool UEsimple::estAChoix() const
{
    return d_estAChoix;
}

int UEsimple::nombreHeuresCM() const
{
    return d_m->nbrHcours();
}

int UEsimple::nombreHeuresTD() const
{
    return d_m->nbrHTD();
}

int UEsimple::nombreHeuresTP() const
{
    return d_m->nbrHTP();
}

void UEsimple::print(std::ostream& ost)const
{
    d_m->print(ost);
}
