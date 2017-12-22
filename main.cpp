#include <iostream>
#include <vector>
#include "formation.h"
#include "menu.h"
#include "matiere.h"
#include "maquette.h"
#include "UEsimple.h"

int main()
{
    // creation formation
    gestionUE::formation::ajouterFormation(new gestionUE::formation{"Licence mathematiques"});
    gestionUE::formation::ajouterFormation(new gestionUE::formation{"Licence informatique"});
    gestionUE::formation::ajouterFormation(new gestionUE::formation{"Licence miage"});

    //creation matiere
    gestionUE::matiere::creerMatiere("13IUQUAM", "Qualite de programmation", 1, 12, 6, 6);
    gestionUE::matiere::creerMatiere("13IUQUAM1", "Qualite de programmation 1", 1, 12, 6, 6);
    gestionUE::matiere::creerMatiere("13IUQUAM2", "Qualite de programmation 2", 1, 12, 6, 6);
    gestionUE::matiere::creerMatiere("13IUQUAM3", "Qualite de programmation 3", 1, 12, 6, 6);

    //creation UEsimple
    gestionUE::UEsimple u1{3, "13IUQUAM"};
    gestionUE::UEsimple u2{3, "13IUQUAM1"};
    gestionUE::UEsimple u3{3, "13IUQUAM2"};
    gestionUE::UEsimple u4{3, "13IUQUAM3"};

    //creation maquette
    gestionUE::maquette m1{1};
    m1.ajouterUE(&u1);

    gestionUE::formation* f = gestionUE::formation::rechercheFormation("Licence miage");
    f->ajouterMaquette(&m1);



    gestionUE::menu m{};
    m.menuPrincipal();


    return 0;
}
