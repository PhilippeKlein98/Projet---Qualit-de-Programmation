#include "programme.h"
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

    programme::programme()
    {
        chargerDonnees() ;
    }

    void programme::chargerDonnees() const
    {
        matiere::chargerTout() ;
        UE::chargerTout() ;
        //maquette::chargerTout() ;
        //formation::chargerTout() ;
    }

    programme::~programme()
    {

    }

    void programme::sauverDonnees() const
    {
        matiere::sauverTout() ;
        UE::sauverTout() ;
        //maquette::sauverTout() ;
        //formation::sauverTout() ;
    }

    void programme::libererDonnees() const
    {
        matiere::libererTout() ;
        UE::libererTout() ;
        maquette::libererTout() ;
        formation::libererTout() ;
    }

    void programme::menuPrincipal()
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
                    menuMaquettes();
                    break;
                case 3 :
                    menuUE();
                    break;
                case 0 :
                    sauverDonnees() ;
                    libererDonnees() ;
                    exit(0);
                default :
                    cout << "Veuillez selectionner une option valide." << endl;
            }
        }
        while( i != 0 && i != 1 && i != 2 && i != 3 );
    }

    void programme::menuFormations()
    {
        system("title Gestion des formations");
        system("cls");
        int i;
        cout << "Gestionnaire de formations : " << endl;
        cout << "1. Afficher la liste des formations" << endl;
        cout << "2. Afficher en detail une formation" << endl;
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
                    {
                        std::string titreFormation = verifieEtRenvoieSaisieChaineDeCaractere("Entrer le nom de la nouvelle formation: ");
                        formation* nouvelleFormation = new formation{titreFormation};
                        cout << nouvelleFormation->intituleFormation() << " a bien ete creee" << endl;
                        formation::ajouterFormation(nouvelleFormation);
                        system("PAUSE");
                        menuFormations();
                    }
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


        void programme::menuMaquettes()
        {
        system("title Gestion des maquettes");
        system("cls");
        int i;
        cout << "Gestionnaire de formations : " << endl;
        cout << "1. Modifier une maquette" << endl;
        cout << "2. Supprimer une maquette" << endl;
        cout << "0. Retour" << endl;

        do
        {
            i = verifieEtRenvoieSaisieEntier("Choix: ");
            switch(i)
            {
                case 1 :
                    {
                        std::string titreFormation = verifieEtRenvoieSaisieChaineDeCaractere("Entrer le nom d'une formation: ");
                        formation* elem = formation::rechercheFormation(titreFormation);

                        int numSemestre = verifieEtRenvoieSaisieEntier("Quelle maquette souhaitez-vous modifier (numero du semestre) ? ");
                        maquette* maquetteAModifier = (*elem).operator[](numSemestre-1);
                        maquetteAModifier->afficher(std::cout);

                        int positionUEAModifier = verifieEtRenvoieSaisieEntier("Quelle UE a modifier ou supprimer (position dans la liste) ? ");
                        UE* UEAModifier = (*maquetteAModifier).operator[](positionUEAModifier-1);
                        UEAModifier->afficher(std::cout);

                        int choixAction = verifieEtRenvoieSaisieEntier("Souhaitez-vous supprimer (1) ou modifier (TODO) cette UE ? ");

                        do{
                            switch(choixAction)
                            {
                                case 1:
                                    maquetteAModifier->supprimerUE(positionUEAModifier-1);
                                    cout << "L'UE a bien ete supprimee" << endl;
                                    maquetteAModifier->afficher(cout);
                                    break;
                                case 2:
                                    //TODO
                                    break;
                                default:
                                    cout << "Veuillez selectionner une option valide." << endl;

                            }
                        }
                        while(choixAction != 1 && choixAction != 2);

                        system("PAUSE");
                        menuMaquettes();

                    }
                    break;
                case 2 :
                    {
                        std::string titreFormation = verifieEtRenvoieSaisieChaineDeCaractere("Entrer le nom d'une formation: ");
                        formation* elem = formation::rechercheFormation(titreFormation);

                        int numSemestre = verifieEtRenvoieSaisieEntier("Quelle maquette souhaitez-vous supprimer (numero du semestre) ?");
                        maquette* maquetteASupprimer = (*elem).operator[](numSemestre-1);
                        maquetteASupprimer->afficher(cout);

                        elem->supprimerMaquette(numSemestre-1);

                        cout << "La maquette a bien ete supprimee" << endl;
                        cout << *elem;

                        system("PAUSE");
                        menuMaquettes();
                    }
                    break;
                case 0 :
                    menuPrincipal();
                    break;
                default :
                    cout << "Veuillez selectionner une option valide." << endl;
            }
        }
        while( i != 0 && i != 1 && i != 2);
    }


    void programme::menuUE()
    {
        system("title Gestion des UE");
        system("cls");
        int i;
        cout << "Gestionnaire d'UE : " << endl;
        cout << "1. Afficher toutes les UE" << endl;
        cout << "0. Retour" << endl;

        do
        {
            i = verifieEtRenvoieSaisieEntier("Choix: ");
            switch(i)
            {
                case 1 :
                    UE::afficherToutesLesUE(cout);
                    system("PAUSE");
                    menuUE();
                    break;

                case 0 :
                    menuPrincipal();
                    break;
                default :
                    cout << "Veuillez selectionner une option valide." << endl;
            }
        }
        while( i != 0 && i != 1);
    }


    /**
        Verifie si l'utilisateur entre bien un entier
        @return l'entier saisi
    */
    int programme::verifieEtRenvoieSaisieEntier(const std::string& message) const
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
    std::string programme::verifieEtRenvoieSaisieChaineDeCaractere(const std::string& message) const
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
    bool programme::saisieReussie() const
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
