#ifndef MATIERE_H_INCLUDED
#define MATIERE_H_INCLUDED

#include <iostream>

class matiere
{
public:
    matiere() = default;
    ~matiere() = default;

    int nbrHtotal()const;
    int nbrHcours()const;
    int nbrHTD()const;
    int nbrHTP()const;
    int coef()const;

    std::string code()const;
    std::string nom()const;

    void modifCode(const std::string & code);
    void modifNom(const std::string & nom);
    void modifHcours(int nbrHcours);
    void modifHTD(int nbrHTD);
    void modifHTP(int nbrHTP);
    void modifCoef(int coef);

    void print(std::ostream & os)const;

private:
    std::string d_code, d_nom;
    int d_nbrHcours, d_nbrHTD, d_nbrHTP, d_coef;
};

#endif // MATIERE_H_INCLUDED
