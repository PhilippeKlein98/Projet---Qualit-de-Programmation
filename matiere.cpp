#include "matiere.h"

namespace gestionUE
{

    int matiere::nombreHeureTotal()const
    {
        return d_nombreHeureCM + d_nombreHeureTD + d_nombreHeureTP;
    }

    double matiere::nombreHeureTotalEnTD() const
    {
        return d_nombreHeureTD + d_nombreHeureCM * CM_VERS_TD + d_nombreHeureTP * TP_VERS_TD;
    }

    int matiere::nombreHeureCM()const
    {
        return d_nombreHeureCM;
    }

    int matiere::nombreHeureTD()const
    {
        return d_nombreHeureTD;
    }

    int matiere::nombreHeureTP()const
    {
        return d_nombreHeureTP;
    }

    int matiere::coefficient()const
    {
        return d_coefficient;
    }

    std::string matiere::code()const
    {
        return d_code;
    }

    std::string matiere::nom()const
    {
        return d_nom;
    }

    void matiere::modifierCode(const std::string & code)
    {
        d_code = code;
    }

    void matiere::modifierNom(const std::string & nom)
    {
        d_nom = nom;
    }

    void matiere::modifierHeureCM(int nombreHeureCM)
    {
        d_nombreHeureCM = nombreHeureCM;
    }

    void matiere::modifierHeureTD(int nombreHeureTD)
    {
        d_nombreHeureTD = nombreHeureTD;
    }

    void matiere::modifierHeureTP(int nombreHeureTP)
    {
        d_nombreHeureTP = nombreHeureTP;
    }

    void matiere::modifierCoefficient(int coefficient)
    {
        d_coefficient = coefficient;
    }

    void matiere::afficher(std::ostream & os)const
    {
        os << d_nom << "\t" << d_coefficient << "\t" << d_nombreHeureCM << "\t" << d_nombreHeureTD << "\t" << d_nombreHeurTP << std::endl;
    }

}
