#include "UEsimple.h"
#include "matiere.h"

namespace gestionUE
{
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

    void UEsimple::afficher(std::ostream& ost)const
    {
        d_matiere->afficher(ost);
    }

    void UEsimple::sauver(std::ofstream& ost) const
    {
        ost << UE_SIMPLE << " " << coefficient() << " " << coefficient() << " " ;
    }
}


