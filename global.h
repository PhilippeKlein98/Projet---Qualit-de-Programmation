#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <iostream>
#include <string>

namespace gestionUE
{
    const double CM_VERS_TD = 2.0/3.0 ;
    const double TP_VERS_TD = 3.0/2.0 ;

    const unsigned int UE_SIMPLE = 1 ;
    const unsigned int UE_COMPOSEE = 2 ;
    const unsigned int UE_CHOIX = 3 ;

    const std::string FICHIER_MATIERE = "matieres.txt" ;
    const std::string FICHIER_UE = "ues.txt" ;
    const std::string FICHIER_MAQUETTE = "maquettes.txt" ;
    const std::string FICHIER_FORMATION = "formations.txt" ;
}


#endif // GLOBAL_H_INCLUDED
