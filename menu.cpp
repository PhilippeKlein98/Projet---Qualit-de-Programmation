#include "menu.h"
#include "formation.h"
#include "maquette.h"
#include "UE.h"
#include "matiere.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

namespace gestionUE{

    menu::menu()
    {
        chargerDonnees() ;
    }

    void menu::chargerDonnees() const
    {
        matiere::chargerTout() ;
        UE::chargerTout() ;
        maquette::chargerTout() ;
        formation::chargerTout() ;
    }

    menu::~menu()
    {
        sauverDonnees() ;
        libererDonnees() ;
    }

    void menu::sauverDonnees() const
    {
        matiere::sauverTout() ;
        UE::sauverTout() ;
        maquette::sauverTout() ;
        formation::sauverTout() ;
    }

    void menu::libererDonnees() const
    {
        matiere::libererTout() ;
        UE::libererTout() ;
        maquette::libererTout() ;
        formation::libererTout() ;
    }

    void menu::menuPrincipal()
    {
        system("title Gestion des UEs");
        system("cls");
        int i;
        cout << "Gestionnaire d'UES : " << endl;
        cout << "Action sur les : " << endl;
        cout << "1. Formations" << endl;
        cout << "2. Maquettes" << endl;
        cout << "3. Matieres" << endl;
        cout << "0. Quitter" << endl;

        do
        {
            i = verifieEtRenvoieSaisieEntier("Choix: ");
            switch(i)
            {
                case 1 :
                    menuFormations();
                    break;
                case 2 :
                    //menuMaquettes();
                    break;
                case 3 :
                    //menuUEs();
                    break;
                case 0 :
                    exit(0);
                default :
                    cout << "Veuillez selectionner une option valide." << endl;
            }
        }
        while( i != 0 && i != 1 && i != 2 && i != 3 );
    }

    void menu::menuFormations()
    {
        system("title Gestion des formations");
        system("cls");
        int i;
        cout << "Gestionnaire de formations : " << endl;
        cout << "1. Afficher toutes les formations" << endl;
        cout << "2. Afficher une formation" << endl;
        cout << "3. Ajouter une formation" << endl;
        cout << "0. Retour" << endl;

        do
        {
            i = verifieEtRenvoieSaisieEntier("Choix: ");
            switch(i)
            {
                case 1 :
                    formation::afficherToutesLesFormations(cout);
                    system("PAUSE");
                    menuFormations();
                    break;
                case 2 :
                    {
                        std::string titreFormation = verifieEtRenvoieSaisieChaineDeCaractere("Entrer le nom d'une formation: ");
                        formation* elem = formation::rechercheFormation(titreFormation);

                        if(elem)
                            cout << *elem;
                        system("PAUSE");
                        menuFormations();

                    }
                    break;
                case 3 :
                    // to do
                    break;
                case 0 :
                    menuPrincipal();
                    break;
                default :
                    cout << "Veuillez selectionner une option valide." << endl;
            }
        }
        while( i != 0 && i != 1 && i != 2 && i != 3 );
    }


    /**
        Verifie si l'utilisateur entre bien un entier
        @return l'entier saisi
    */
    int menu::verifieEtRenvoieSaisieEntier(const std::string& message) const
    {
        int entier;
        do{
            cout << message;
            cin >> entier;
        }
        while(!saisieReussie());

        return entier;
    }


    /**
        Verifie si l'utilisateur entre bien une chaine de caractere
        @return la chaine de caractere saisie
    */
    std::string menu::verifieEtRenvoieSaisieChaineDeCaractere(const std::string& message) const
    {
        std::string chaineDeCaractere;
        do{
            cout << message;
            cin.ignore(256,'\n');
            std::getline(cin, chaineDeCaractere);
        }
        while(!saisieReussie());

        return chaineDeCaractere;
    }

    /**
        Verifie si la saisie est reussie
        @return Vrai si reussi, Faux sinon
    */
    bool menu::saisieReussie() const
    {

        if( cin.fail() )
        {
            cin.clear();
            cin.ignore(256,'\n');
            return false;
        }

        return true;
    }

}
