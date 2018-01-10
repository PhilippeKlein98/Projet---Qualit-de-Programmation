#include "catch.hpp"
#include "matiere.h"
#include "global.h"
#include <fstream>

TEST_CASE("Tests sur la classe matiere", "[matiere]")
{
    std::string code = "123456789";
    std::string nom = "Matiere";
    int coefficient = 5;
    int heuresCM = 10;
    int heuresTD = 11;
    int heuresTP = 12;

    gestionUE::matiere::creerMatiere( code , nom , coefficient , heuresCM , heuresTD , heuresTP );

    int taille = gestionUE::matiere::listeMatieres.size() - 1;

    SECTION("La matiere est bien construite", "[matiere]")
    {
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

        REQUIRE(gestionUE::matiere::listeMatieres[taille]->nombreHeuresTotal() == heuresTotal);
    }

    SECTION("Le nombre total d'heure TD bien calcule", "[matiere]")
    {
        double heuresTotalEnTD = heuresCM * gestionUE::CM_VERS_TD + heuresTD + heuresTP * gestionUE::TP_VERS_TD;

        REQUIRE(gestionUE::matiere::listeMatieres[taille]->nombreHeuresTotalEnTD() == heuresTotalEnTD);
    }

    SECTION("Tests des modifications de la matiere", "[matiere]")
    {
        std::string code2 = "987654321";
        std::string nom2 = "Test";
        int coefficient2 = 1;
        int heuresCM2 = 4;
        int heuresTD2 = 5;
        int heuresTP2 = 6;

        gestionUE::matiere::listeMatieres[taille]->modifierCode(code2);
        gestionUE::matiere::listeMatieres[taille]->modifierNom(nom2);
        gestionUE::matiere::listeMatieres[taille]->modifierHeuresCM(heuresCM2);
        gestionUE::matiere::listeMatieres[taille]->modifierHeuresTD(heuresTD2);
        gestionUE::matiere::listeMatieres[taille]->modifierHeuresTP(heuresTP2);
        gestionUE::matiere::listeMatieres[taille]->modifierCoefficient(coefficient2);

        REQUIRE(gestionUE::matiere::listeMatieres[taille]->code() == code2);
        REQUIRE(gestionUE::matiere::listeMatieres[taille]->nom() == nom2);
        REQUIRE(gestionUE::matiere::listeMatieres[taille]->coefficient() == coefficient2);
        REQUIRE(gestionUE::matiere::listeMatieres[taille]->nombreHeuresCM() == heuresCM2);
        REQUIRE(gestionUE::matiere::listeMatieres[taille]->nombreHeuresTD() == heuresTD2);
        REQUIRE(gestionUE::matiere::listeMatieres[taille]->nombreHeuresTP() == heuresTP2);
    }

    SECTION("Test sauvegarde d'une seul matiere", "[matiere]")
    {
        std::string fichier_matiere_test = "matiere_test.txt";
        std::ofstream fout{fichier_matiere_test.c_str()};

        gestionUE::matiere::listeMatieres[taille]->sauver(fout);
    }

    SECTION("Test de la recherche d'une matiere", "[matiere]")
    {
        REQUIRE(gestionUE::matiere::chercherMatiere(code) == gestionUE::matiere::listeMatieres[taille]);
    }

    SECTION("Test de la suppression de la matiere", "[matiere]")
    {
        gestionUE::matiere::supprimerMatiere(code);
        REQUIRE(gestionUE::matiere::chercherMatiere(code) == nullptr);
    }

    gestionUE::matiere::libererTout();
}

TEST_CASE("Tests sauvegarde des matieres", "[matiere]")
{
    std::string code1 = "123";
    std::string code2 = "456";
    std::string code3 = "789";

    std::string nom1 = "abc";
    std::string nom2 = "def";
    std::string nom3 = "ghi";

    int coefficient1 = 1;
    int coefficient2 = 2;
    int coefficient3 = 3;

    int heuresCM1 = 10;
    int heuresCM2 = 11;
    int heuresCM3 = 12;

    int heuresTD1 = 13;
    int heuresTD2 = 14;
    int heuresTD3 = 15;

    int heuresTP1 = 16;
    int heuresTP2 = 17;
    int heuresTP3 = 18;

    gestionUE::matiere::creerMatiere( code1 , nom1 , coefficient1 , heuresCM1 , heuresTD1 , heuresTP1 );
    gestionUE::matiere::creerMatiere( code2 , nom2 , coefficient2 , heuresCM2 , heuresTD2 , heuresTP2 );
    gestionUE::matiere::creerMatiere( code3 , nom3 , coefficient3 , heuresCM3 , heuresTD3 , heuresTP3 );

    SECTION("Test de la sauvegarde des matieres", "[matiere]")
    {
        gestionUE::matiere::sauverTout();
    }

    SECTION("Test de la liberation de memoire", "[matiere]")
    {
        gestionUE::matiere::libererTout();
        REQUIRE(gestionUE::matiere::listeMatieres.size() == 0);
    }
}

TEST_CASE("Tests chargement des matieres", "[matiere]")
{
    gestionUE::matiere::chargerTout();
    gestionUE::matiere::sauverTout();
}

