#include "UEsimple.h"
#include "matiere.h"

namespace gestionUE
{

    UEsimple::UEsimple(int ECTS, const std::string code) : UE{ECTS} , d_matiere{matiere::chercherMatiere(code)}
    {}

    std::string UEsimple::intitule() const
    {
        return d_matiere->nom();
    }

    std::string UEsimple::code() const
    {
        return d_matiere->code();
    }

    int UEsimple::coefficient() const
    {
        return d_matiere->coefficient();
    }

    int UEsimple::nombreHeuresCM() const
    {
        return d_matiere->nombreHeuresCM();
    }

    int UEsimple::nombreHeuresTD() const
    {
        return d_matiere->nombreHeuresTD();
    }

    int UEsimple::nombreHeuresTP() const
    {
        return d_matiere->nombreHeuresTP();
    }

    bool  UEsimple::contientMatiere(const std::string& codeMatiere) const
    {
        if(d_matiere == nullptr)
        {
            return false;
        }
        return d_matiere->code()  == codeMatiere ;
    }

    void UEsimple::supprimerMatiere(const std::string& codeMatiere)
    {
        if( d_matiere->code() == codeMatiere )
        {
            d_matiere = nullptr ;
        }
    }

    void UEsimple::afficher(std::ostream& ost)const
    {
        d_matiere->afficher(ost);
    }

    void UEsimple::sauver(std::ofstream& ost) const
    {
        ost << UE_SIMPLE << "\t" << ECTS() << "\t" << code() ;
    }
}
