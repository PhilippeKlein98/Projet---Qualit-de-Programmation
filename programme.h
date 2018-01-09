#ifndef PROGRAMME_H
#define PROGRAMME_H
#include <string>

namespace gestionUE{

class programme
{
    public:
        programme();
        ~programme();
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


#endif // PROGRAMME_H
