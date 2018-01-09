#include "catch.hpp"
#include "matiere.h"
#include "global.h"

TEST_CASE("Tests sur la classe matiere", "[matiere]")
{
    std::string code = "123456789";
    std::string nom = "Matiere";
    int coefficient = 5;
    int heuresCM = 10;
    int heuresTD = 11;
    int heuresTP = 12;
    int taille = gestionUE::matiere::listeMatieres.size();

    SECTION("La matiere est bien construite", "[matiere]")
    {
        gestionUE::matiere::creerMatiere( code , nom , coefficient , heuresCM , heuresTD , heuresTP );

        REQUIRE(gestionUE::matiere::listeMatieres[taille]->code() == code);
        REQUIRE(gestionUE::matiere::listeMatieres[taille]->nom() == nom);
        REQUIRE(gestionUE::matiere::listeMatieres[taille]->coefficient() == coefficient);
        REQUIRE(gestionUE::matiere::listeMatieres[taille]->nombreHeuresCM() == heuresCM);
        REQUIRE(gestionUE::matiere::listeMatieres[taille]->nombreHeuresTD() == heuresTD);
        REQUIRE(gestionUE::matiere::listeMatieres[taille]->nombreHeuresTP() == heuresTP);
    }

    SECTION("Le nombre total d'heure bien calcule", "[matiere]")
    {
        int heuresTotal = heuresTD + heuresCM + heuresTP;

        gestionUE::matiere::creerMatiere( code , nom , coefficient , heuresCM , heuresTD , heuresTP );

        REQUIRE(gestionUE::matiere::listeMatieres[taille-1]->nombreHeuresTotal() == heuresTotal);
    }

    SECTION("Le nombre total d'heure TD bien calcule", "[matiere]")
    {
        double heuresTotalEnTD = heuresCM * gestionUE::CM_VERS_TD + heuresTD + heuresTP * gestionUE::TP_VERS_TD;

        gestionUE::matiere::creerMatiere( code , nom , coefficient , heuresCM , heuresTD , heuresTP );

        REQUIRE(gestionUE::matiere::listeMatieres[taille]->nombreHeuresTotalEnTD() == heuresTotalEnTD);
    }
}
