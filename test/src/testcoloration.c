#include "testcoloration.h"

static CouleursGraphe cg0 = NULL;
static CouleursGraphe cg1 = NULL;
static CouleursGraphe cg2 = NULL;
static CouleursGraphe cg3 = NULL;
static CouleursGraphe cg4 = NULL;
static CouleursGraphe cg5 = NULL;

int init_suiteColoration(void)
{
    cg1 = MALLOC(cg1);
    cg1->sommet = copieSommet("azer");
    cg1->couleur = BLANC;
    cg1->suivant = NULL;

    cg2 = MALLOC(cg2);
    cg3 = MALLOC(cg3);
    cg4 = MALLOC(cg4);
    cg5 = MALLOC(cg5);
    cg2->sommet = copieSommet("azer");
    cg3->sommet = copieSommet("qsdf");
    cg4->sommet = copieSommet("wxcv");
    cg5->sommet = copieSommet("uiop");
    cg2->couleur = BLANC;
    cg3->couleur = NOIR;
    cg4->couleur = BLANC;
    cg5->couleur = GRIS;
    cg2->suivant = NULL;
    cg3->suivant = cg2;
    cg4->suivant = cg3;
    cg5->suivant = cg4;

    return 0;
}

int clean_suiteColoration(void)
{
    cg1->sommet = libererSommet(cg1->sommet);
    free(cg1);

    cg2->sommet = libererSommet(cg2->sommet);
    free(cg2);
    cg3->sommet = libererSommet(cg3->sommet);
    free(cg3);
    cg4->sommet = libererSommet(cg4->sommet);
    free(cg4);
    cg5->sommet = libererSommet(cg5->sommet);
    free(cg5);

    return 0;
}

void test_couleursgraphe_cgNouv(void)
{
    CU_ASSERT(cgNouv() == NULL);
}

void test_couleursgraphe_cgAjouterSommet(void);

void test_couleursgraphe_cgSupprimerTete(void);

void test_couleursgraphe_cgSupprimerSommet(void);

void test_couleursgraphe_cgModifierSommet(void);

void test_couleursgraphe_cgInit(void);

void test_couleursgraphe_cgEstVide(void)
{
    CU_ASSERT(cgEstVide(cgNouv()) == VRAI);
    CU_ASSERT(cgEstVide(cg0) == VRAI);
    CU_ASSERT(cgEstVide(cg1) == FAUX);
    CU_ASSERT(cgEstVide(cg2) == FAUX);
    CU_ASSERT(cgEstVide(cg3) == FAUX);
    CU_ASSERT(cgEstVide(cg4) == FAUX);
    CU_ASSERT(cgEstVide(cg5) == FAUX);
}

void test_couleursgraphe_cgSuivant(void)
{
    CU_ASSERT(cgSuivant(cgNouv()) == NULL);
    CU_ASSERT(cgSuivant(cg0) == NULL);
    CU_ASSERT(cgSuivant(cg1) == NULL);
    CU_ASSERT(cgSuivant(cg2) == NULL);
    CU_ASSERT(cgSuivant(cg3) == cg2);
    CU_ASSERT(cgSuivant(cg4) == cg3);
    CU_ASSERT(cgSuivant(cg5) == cg4);
}

void test_couleursgraphe_cgSommetTete(void)
{
    CU_ASSERT(egalSom(cgSommetTete(cg1), "azer") == VRAI);
    CU_ASSERT(egalSom(cgSommetTete(cg1), "qsdf") == FAUX);
    CU_ASSERT(egalSom(cgSommetTete(cg5), "uiop") == VRAI);
    CU_ASSERT(egalSom(cgSommetTete(cg4), "wxcv") == VRAI);
    CU_ASSERT(egalSom(cgSommetTete(cg3), "qsdf") == VRAI);
    CU_ASSERT(egalSom(cgSommetTete(cg2), "azer") == VRAI);

    CU_ASSERT(egalSom(cgSommetTete(cg2), "uiop") == FAUX);
    CU_ASSERT(egalSom(cgSommetTete(cg2), "wxcv") == FAUX);
    CU_ASSERT(egalSom(cgSommetTete(cg2), "qsdf") == FAUX);
    CU_ASSERT(egalSom(cgSommetTete(cg3), "uiop") == FAUX);
    CU_ASSERT(egalSom(cgSommetTete(cg3), "wxcv") == FAUX);
    CU_ASSERT(egalSom(cgSommetTete(cg3), "azer") == FAUX);
    CU_ASSERT(egalSom(cgSommetTete(cg4), "uiop") == FAUX);
    CU_ASSERT(egalSom(cgSommetTete(cg4), "azer") == FAUX);
    CU_ASSERT(egalSom(cgSommetTete(cg4), "qsdf") == FAUX);
    CU_ASSERT(egalSom(cgSommetTete(cg5), "azer") == FAUX);
    CU_ASSERT(egalSom(cgSommetTete(cg5), "wxcv") == FAUX);
    CU_ASSERT(egalSom(cgSommetTete(cg5), "qsdf") == FAUX);
}

void test_couleursgraphe_cgCouleurTete(void)
{
    CU_ASSERT(cgCouleurTete(cg1) == BLANC);
    CU_ASSERT(cgCouleurTete(cg2) == BLANC);
    CU_ASSERT(cgCouleurTete(cg3) == NOIR);
    CU_ASSERT(cgCouleurTete(cg4) == BLANC);
    CU_ASSERT(cgCouleurTete(cg5) == GRIS);
}

void test_couleursgraphe_cgCouleurSommet(void)
{
    CU_ASSERT(cgCouleurSommet(cg1, "azer") == BLANC);
    CU_ASSERT(cgCouleurSommet(cg5, "azer") == BLANC);
    CU_ASSERT(cgCouleurSommet(cg5, "qsdf") == NOIR);
    CU_ASSERT(cgCouleurSommet(cg5, "wxcv") == BLANC);
    CU_ASSERT(cgCouleurSommet(cg5, "uiop") == GRIS);
}

void test_couleursgraphe_cgPremierSommetNoir(void)
{
    CU_ASSERT(egalSom(cgPremierSommetNoir(cg0), NULL) == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetNoir(cg1), NULL) == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetNoir(cg2), NULL) == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetNoir(cg3), "qsdf") == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetNoir(cg4), "qsdf") == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetNoir(cg5), "qsdf") == VRAI);
}

void test_couleursgraphe_cgPremierSommetGris(void)
{
    CU_ASSERT(egalSom(cgPremierSommetGris(cg0), NULL) == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetGris(cg1), NULL) == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetGris(cg2), NULL) == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetGris(cg3), NULL) == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetGris(cg4), NULL) == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetGris(cg5), "uiop") == VRAI);
}

void test_couleursgraphe_cgPremierSommetBlanc(void)
{
    CU_ASSERT(egalSom(cgPremierSommetBlanc(cg0), NULL) == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetBlanc(cg1), "azer") == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetBlanc(cg2), "azer") == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetBlanc(cg3), "azer") == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetBlanc(cg4), "wxcv") == VRAI);
    CU_ASSERT(egalSom(cgPremierSommetBlanc(cg5), "wxcv") == VRAI);
}

void test_couleursgraphe_cgNombreSommetsNoirs(void)
{
    CU_ASSERT(cgNombreSommetsNoirs(cg0) == 0);
    CU_ASSERT(cgNombreSommetsNoirs(cg1) == 0);
    CU_ASSERT(cgNombreSommetsNoirs(cg2) == 0);
    CU_ASSERT(cgNombreSommetsNoirs(cg3) == 1);
    CU_ASSERT(cgNombreSommetsNoirs(cg4) == 1);
    CU_ASSERT(cgNombreSommetsNoirs(cg5) == 1);
}

void test_couleursgraphe_cgNombreSommetsGris(void)
{
    CU_ASSERT(cgNombreSommetsGris(cg0) == 0);
    CU_ASSERT(cgNombreSommetsGris(cg1) == 0);
    CU_ASSERT(cgNombreSommetsGris(cg2) == 0);
    CU_ASSERT(cgNombreSommetsGris(cg3) == 0);
    CU_ASSERT(cgNombreSommetsGris(cg4) == 0);
    CU_ASSERT(cgNombreSommetsGris(cg5) == 1);
}

void test_couleursgraphe_cgNombreSommetsBlancs(void)
{
    CU_ASSERT(cgNombreSommetsBlancs(cg0) == 0);
    CU_ASSERT(cgNombreSommetsBlancs(cg1) == 1);
    CU_ASSERT(cgNombreSommetsBlancs(cg2) == 1);
    CU_ASSERT(cgNombreSommetsBlancs(cg3) == 1);
    CU_ASSERT(cgNombreSommetsBlancs(cg4) == 2);
    CU_ASSERT(cgNombreSommetsBlancs(cg5) == 2);
}

void test_couleursgraphe_cgPSommet(void)
{
    CU_ASSERT(cgPSommet(cgNouv(), "azer") == NULL);
    CU_ASSERT(cgPSommet(cg1, "azer") == cg1);
    CU_ASSERT(cgPSommet(cg1, "qsdf") == NULL);

    CU_ASSERT(cgPSommet(cg5, "azer") == cg2);
    CU_ASSERT(cgPSommet(cg5, "qsdf") == cg3);
    CU_ASSERT(cgPSommet(cg5, "wxcv") == cg4);
    CU_ASSERT(cgPSommet(cg5, "uiop") == cg5);
    CU_ASSERT(cgPSommet(cg5, "hjkl") == NULL);
    CU_ASSERT(cgPSommet(cg4, "azer") == cg2);
    CU_ASSERT(cgPSommet(cg4, "qsdf") == cg3);
    CU_ASSERT(cgPSommet(cg4, "wxcv") == cg4);
    CU_ASSERT(cgPSommet(cg4, "uiop") == NULL);
    CU_ASSERT(cgPSommet(cg4, "hjkl") == NULL);
    CU_ASSERT(cgPSommet(cg3, "azer") == cg2);
    CU_ASSERT(cgPSommet(cg3, "qsdf") == cg3);
    CU_ASSERT(cgPSommet(cg3, "wxcv") == NULL);
    CU_ASSERT(cgPSommet(cg3, "uiop") == NULL);
    CU_ASSERT(cgPSommet(cg3, "hjkl") == NULL);
    CU_ASSERT(cgPSommet(cg2, "azer") == cg2);
    CU_ASSERT(cgPSommet(cg2, "qsdf") == NULL);
    CU_ASSERT(cgPSommet(cg2, "wxcv") == NULL);
    CU_ASSERT(cgPSommet(cg2, "uiop") == NULL);
    CU_ASSERT(cgPSommet(cg2, "hjkl") == NULL);
}

int add_testcoloration(void)
{
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("Tests Coloration", init_suiteColoration, clean_suiteColoration);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "cgNouv", test_couleursgraphe_cgNouv) == NULL
        || CU_add_test(pSuite, "cgEstVide", test_couleursgraphe_cgEstVide) == NULL
        || CU_add_test(pSuite, "cgSuivant", test_couleursgraphe_cgSuivant) == NULL
        || CU_add_test(pSuite, "cgSommetTete", test_couleursgraphe_cgSommetTete) == NULL
        || CU_add_test(pSuite, "cgCouleurTete", test_couleursgraphe_cgCouleurTete) == NULL
        || CU_add_test(pSuite, "cgPSommet", test_couleursgraphe_cgPSommet) == NULL
        || CU_add_test(pSuite, "cgPremierSommetNoir", test_couleursgraphe_cgPremierSommetNoir) == NULL
        || CU_add_test(pSuite, "cgPremierSommetGris", test_couleursgraphe_cgPremierSommetGris) == NULL
        || CU_add_test(pSuite, "cgPremierSommetBlanc", test_couleursgraphe_cgPremierSommetBlanc) == NULL
        || CU_add_test(pSuite, "cgNombreSommetsNoirs", test_couleursgraphe_cgNombreSommetsNoirs) == NULL
        || CU_add_test(pSuite, "cgNombreSommetsGris", test_couleursgraphe_cgNombreSommetsGris) == NULL
        || CU_add_test(pSuite, "cgNombreSommetsBlancs", test_couleursgraphe_cgNombreSommetsBlancs) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
