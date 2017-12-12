#include "ECUE.h"

ECUE::ECUE()
{
    //ctor
}

std::string ECUE::code() const
{
    return d_m->code();
}

std::string ECUE::coef() const
{
    return d_m->coef();
}

int ECUE::ECTS() const
{
    return d_ETCS;
}

std::string ECUE::intitule() const
{
    return d_m->nom();
}

bool ECUE::estAChoix() const
{
    return d_estAChoix;
}

int ECUE::nbCm() const
{
    return d_m->nbrHCours();
}

int ECUE::nbTD() const
{
    return d_m->nbrHTD();
}

int ECUE::nbTP() const
{
    return d_m->nbrHTP();
}

void ECUE::print(std::ostream& ost)
{
    ost << *d_m;
}
