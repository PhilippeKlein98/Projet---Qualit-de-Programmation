#include <iostream>
#include <vector>
#include "formation.h"
#include "menu.h"

int main()
{

    gestionUE::formation::ajouterFormation(new gestionUE::formation{"Licence mathematiques"});
    gestionUE::formation::ajouterFormation(new gestionUE::formation{"Licence informatique"});
    gestionUE::formation::ajouterFormation(new gestionUE::formation{"Licence miage"});


    gestionUE::menu m{};
    m.menuPrincipal();


    return 0;
}
