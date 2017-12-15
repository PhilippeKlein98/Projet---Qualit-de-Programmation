#include "matiere.h"

namespace gestionUE
{

    int matiere::nombreHeuresTotal()const
    {
        return d_nombreHeuresCM + d_nombreHeuresTD + d_nombreHeuresTP;
    }

    double matiere::nombreHeuresTotalEnTD() const
    {
        return d_nombreHeuresTD + d_nombreHeuresCM * CM_VERS_TD + d_nombreHeuresTP * TP_VERS_TD;
    }

    int matiere::nombreHeuresCM()const
    {
        return d_nombreHeuresCM;
    }

    int matiere::nombreHeuresTD()const
    {
        return d_nombreHeuresTD;
    }

    int matiere::nombreHeuresTP()const
    {
        return d_nombreHeuresTP;
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

    void matiere::modifierHeuresCM(int nombreHeuresCM)
    {
        d_nombreHeuresCM = nombreHeuresCM;
    }

    void matiere::modifierHeuresTD(int nombreHeuresTD)
    {
        d_nombreHeuresTD = nombreHeuresTD;
    }

    void matiere::modifierHeuresTP(int nombreHeuresTP)
    {
        d_nombreHeuresTP = nombreHeuresTP;
    }

    void matiere::modifierCoefficient(int coefficient)
    {
        d_coefficient = coefficient;
    }

    void matiere::afficher(std::ostream & os)const
    {
        os << d_nom << "\t" << d_coefficient << "\t" << d_nombreHeuresCM << "\t" << d_nombreHeuresTD << "\t" << d_nombreHeuresTP << std::endl;
    }

}
