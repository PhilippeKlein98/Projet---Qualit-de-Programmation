#include "menu.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;

namespace gestionUE{
	

void menu::menuPrincipal()
{
	system("title Gestion des UEs");
	system("cls");
    int i;
    cout << "Gestionnaire d'UES : " << endl;
    cout << "Action sur les : " << endl;
    cout << "1. Formations" << endl;
    cout << "2. Maquettes" << endl;
	cout << "3. UEs" << endl;
    cout << "0. Quitter" << endl;
    
    do
    {
    	i = testInt("Choix : ");
		cout << endl;
		switch(i)
	    {
	        case 1 :
	            menuFormations();
	            break;
	        case 2 :
	            menuMaquettes();
	            break;
			case 3 :
	            menuUEs();
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
    cout << "2. Rechercher une formation" << endl;
	cout << "3. Ajouter une formation" << endl;
    cout << "0. Quitter" << endl;
    
    do
    {
    	i = testInt("Choix : ");
		cout << endl;
		switch(i)
	    {
	        case 1 :
	            // to do
	            break;
	        case 2 :
	            // to do
	            break;
			case 3 :
	            // to do
	            break;
	        case 0 :
                exit(0);
	        default :
	            cout << "Veuillez selectionner une option valide." << endl;
		}
	}
	while( i != 0 && i != 1 && i != 2 && i != 3 );
}


/**
	Test si l'utilisateur entre bien un entier
	@param s - La chaine de caractere que l'on veut afficher avant la saisie
	@return l'entier saisi
*/
int menu::testInt(const std::string& s)
{
	int i;
	do
    {
	    cout << s;
	    cin >> i;
		if( cin.fail() )
	    {
			cin.clear();
			cin.ignore(256,'\n');
			i = -1;
		}
	}
	while( i == -1 );
	return i;
}



}