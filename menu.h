#ifndef MENU_H
#define MENU_H
#include <string>

namespace gestionUE{

class menu
{
    public:
        menu();
        ~menu();
        void menuPrincipal();
		void menuFormations();
		//void menuMaquettes();
		//void menuUEs();

        void chargerDonnees() const ;
        void sauverDonnees() const ;
        void libererDonnees() const ;
		int verifieEtRenvoieSaisieEntier(const std::string& message) const;
		std::string verifieEtRenvoieSaisieChaineDeCaractere(const std::string& message) const;
		bool saisieReussie() const;

    private:

};

}


#endif // MENU_H
