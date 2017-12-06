#include "matiere.h"

int matiere::nbrHtotal()const
{
    return d_nbrHcours + d_nbrHTD + d_nbrHTP;
}

int matiere::nbrHcours()const
{
    return d_nbrHcours;
}

int matiere::nbrHTD()const
{
    return d_nbrHTD;
}

int matiere::nbrHTP()const
{
    return d_nbrHTP;
}

int matiere::coef()const
{
    return d_coef;
}

std::string matiere::code()const
{
    return d_code;
}

std::string matiere::nom()const
{
    return d_nom;
}

void matiere::modifCode(const std::string & code)
{
    d_code = code;
}

void matiere::modifNom(const std::string & nom)
{
    d_nom = nom;
}

void matiere::modifHcours(int nbrHcours)
{
    d_nbrHcours = nbrHcours;
}

void matiere::modifHTD(int nbrHTD)
{
    d_nbrHTD = nbrHTD;
}

void matiere::modifHTP(int nbrHTP)
{
    d_nbrHTP = nbrHTP;
}

void matiere::modifCoef(int coef)
{
    d_coef = coef;
}

void matiere::print(std::ostream & os)
{
    os << d_nom << "\t" << d_coef << "\t" << d_nbrHcours << "\t" << d_nbrHTD << "\t" << d_nbrHTP << std::endl;
}
