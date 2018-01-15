#include "catch.hpp"
#include "UEsimple.h"
#include "matiere.h"
#include "global.h"
#include <fstream>

TEST_CASE("Tests sur la classe UEsimple", "[UEsimple]")
{
    std::string code = "1234";
    std::string nom = "Matiere";
    int coefficient = 5;
    int heuresCM = 10;
    int heuresTD = 11;
    int heuresTP = 12;
    int ECTS = 3;

    gestionUE::matiere::creerMatiere( code , nom , coefficient , heuresCM , heuresTD , heuresTP );
    gestionUE::UEsimple uneUEsimple{ECTS, code};

    SECTION("L'UEsimple est bien construite", "[UEsimple]")
    {
        REQUIRE(uneUEsimple.ECTS() == ECTS);
        REQUIRE(uneUEsimple.code() == code);
        REQUIRE(uneUEsimple.coefficient() == coefficient);
        REQUIRE(uneUEsimple.nombreHeuresCM() == heuresCM);
        REQUIRE(uneUEsimple.nombreHeuresTD() == heuresTD);
        REQUIRE(uneUEsimple.nombreHeuresTP() == heuresTP);
    }

    SECTION("Test du contenu de l'UEsimple", "[UEsimple]")
    {
        REQUIRE(uneUEsimple.contientMatiere(code));
    }

    SECTION("Test de calcule du total d'heure", "[UEsimple]")
    {
        int heuresTotal = heuresTD + heuresCM + heuresTP;

        REQUIRE(uneUEsimple.nombreHeuresTotal() == heuresTotal);
    }

    SECTION("Test de calcule du total d'heure en TD", "[UEsimple]")
    {
        double heuresTotalEnTD = heuresCM * gestionUE::CM_VERS_TD + heuresTD + heuresTP * gestionUE::TP_VERS_TD;

        REQUIRE(uneUEsimple.nombreHeuresTotalEnTD() == heuresTotalEnTD);
    }

    SECTION("Supprimer le lien de l'UEsimple vers la matiere", "[UEsimple]")
    {
        uneUEsimple.supprimerMatiere(code);

        REQUIRE(uneUEsimple.contientMatiere(code) == false);
    }

    gestionUE::UEsimple::libererTout();
}

TEST_CASE("Test de la sauvegarde de l'UEsimple", "[UEsimple]")
{
    std::string code = "1234";
    std::string nom = "Matiere";
    int coefficient = 5;
    int heuresCM = 10;
    int heuresTD = 11;
    int heuresTP = 12;
    int ECTS = 3;

    gestionUE::matiere::creerMatiere( code , nom , coefficient , heuresCM , heuresTD , heuresTP );
    gestionUE::UEsimple uneUEsimple{ECTS, code};

    gestionUE::UEsimple::sauverTout();

    gestionUE::UEsimple::libererTout();
}

TEST_CASE("Tests chargement des UEsimple", "[UEsimple]")
{
    gestionUE::UEsimple::chargerTout();
    gestionUE::UEsimple::sauverTout();
}
