#include "testgrapheconnexe.h"

static GrapheConnexe gc0 = NULL;
static GrapheConnexe gc1 = NULL;
static GrapheConnexe gc2 = NULL;
static GrapheConnexe gc3 = NULL;
static GrapheConnexe gc4 = NULL;
static GrapheConnexe gc5 = NULL;
static GrapheConnexe gc6 = NULL;
static GrapheConnexe gc7 = NULL;
static GrapheConnexe gc8 = NULL;
static GrapheConnexe gc9 = NULL;
static GrapheConnexe gc10 = NULL;
static GrapheConnexe gc11 = NULL;
static GrapheConnexe gc12 = NULL;


int init_suiteGrapheConnexe(void)
{
    gc0 = gcNouv();

    gc1 = gcAjouterSommet(gcNouv(), "a");
    gc2 = gcAjouterSommet(gcAjouterSommet(gcNouv(), "a"), "b");


    gc3 = gcAjouterSommet(gcNouv(), "a");
    gc3 = gcAjouterArete(gcAjouterArete(gc3, "a", "b", 1), "a", "c", 2);
    gc3 = gcAjouterArete(gc3, "b", "d", 1);

    gc4 = gcAjouterArete(gcNouv(), "a", "b", 1);
    gc4 = gcAjouterArete(gcAjouterArete(gc4, "a", "c", 2), "b", "d", 1);

    gc5 = gcAjouterSommet(gcNouv(), "a");
    gc5 = gcAjouterArete(gcAjouterArete(gc5, "a", "b", 1), "a", "c", 2);
    gc5 = gcAjouterArete(gcAjouterArete(gc5, "b", "d", 1), "a", "c", 4);

    gc6 = gcAjouterSommet(gcNouv(), "a");
    gc6 = gcAjouterArete(gcAjouterArete(gc6, "a", "b", 1), "b", "c", 2);
    gc6 = gcAjouterArete(gcAjouterArete(gc6, "b", "d", 1), "e", "f", 2);

    gc7 = gcAjouterArete(gcAjouterArete(gcNouv(), "a", "b", 1), "a", "c", 2);
    gc7 = gcAjouterArete(gcAjouterArete(gc7, "b", "d", 2), "d", "e", 1);
    gc7 = gcSupprimerSommet(gc7, "a");

    gc8 = gcAjouterArete(gcAjouterArete(gcNouv(), "a", "b", 1), "a", "c", 2);
    gc8 = gcAjouterArete(gcAjouterArete(gc8, "b", "d", 2), "d", "e", 1);
    gc8 = gcSupprimerSommet(gc8, "e");

    gc9 = gcAjouterArete(gcAjouterArete(gcNouv(), "a", "b", 1), "a", "c", 2);
    gc9 = gcAjouterArete(gcAjouterArete(gc9, "b", "d", 6), "d", "e", 4);
    gc9 = gcAjouterArete(gcAjouterArete(gc9, "a", "d", 7), "b", "e", 9);
    gc9 = gcSupprimerArete(gc9, "a", "c");

    gc10 = gcAjouterArete(gcAjouterArete(gcNouv(), "a", "b", 1), "a", "c", 2);
    gc10 = gcAjouterArete(gcAjouterArete(gc10, "b", "d", 6), "d", "e", 4);
    gc10 = gcAjouterArete(gcAjouterArete(gc10, "a", "d", 7), "b", "e", 9);
    gc10 = gcSupprimerArete(gc10, "d", "e");

    gc11 = gcAjouterArete(gcAjouterArete(gcNouv(), "a", "b", 1), "a", "c", 2);
    gc11 = gcAjouterArete(gcAjouterArete(gc11, "b", "d", 6), "d", "e", 4);
    gc11 = gcAjouterArete(gcAjouterArete(gc11, "a", "d", 7), "b", "e", 9);
    gc11 = gcModifierArete(gc11, "a", "e", 10);

    gc12 = gcAjouterArete(gcAjouterArete(gcNouv(), "a", "b", 1), "a", "c", 2);
    gc12 = gcAjouterArete(gcAjouterArete(gc12, "b", "d", 6), "d", "e", 4);
    gc12 = gcAjouterArete(gcAjouterArete(gc12, "a", "d", 7), "b", "e", 9);
    gc12 = gcModifierArete(gc12, "a", "d", 10);

    return 0;
}

int clean_suiteGrapheConnexe(void)
{
    gc0 = gLiberer(gc0);
    gc1 = gLiberer(gc1);
    gc2 = gLiberer(gc2);
    gc3 = gLiberer(gc3);
    gc4 = gLiberer(gc4);
    gc5 = gLiberer(gc5);
    gc6 = gLiberer(gc6);
    gc7 = gLiberer(gc7);
    gc8 = gLiberer(gc8);
    gc9 = gLiberer(gc9);
    gc10 = gLiberer(gc10);
    gc11 = gLiberer(gc11);
    gc12 = gLiberer(gc12);

    return 0;
}

void test_grapheconnexe_gcNouv(void)
{
    CU_ASSERT(gEstVide(gc0) == VRAI);
}

void test_grapheconnexe_gcAjouterSommet(void)
{
    CU_ASSERT(gEstVide(gc1) == FAUX);
    CU_ASSERT(gEstVide(gc2) == FAUX);
    CU_ASSERT(gEstConnexe(gc1) == VRAI);
    CU_ASSERT(gEstConnexe(gc2) == VRAI);
    CU_ASSERT(gNombreSommets(gc2) == 1);
    CU_ASSERT(gExisteSommet(gc2, "a") == VRAI);
    CU_ASSERT(gExisteSommet(gc2, "b") == FAUX);
}

void test_grapheconnexe_gcAjouterArete(void)
{
    CU_ASSERT(gEstVide(gc3) == FAUX);
    CU_ASSERT(gEstConnexe(gc3) == VRAI);
    CU_ASSERT(gNombreSommets(gc3) == 4);
    CU_ASSERT(gExisteSommet(gc3, "a") == VRAI);
    CU_ASSERT(gExisteSommet(gc3, "b") == VRAI);
    CU_ASSERT(gExisteSommet(gc3, "c") == VRAI);
    CU_ASSERT(gExisteSommet(gc3, "d") == VRAI);
    CU_ASSERT(gNombreAretes(gc3) == 3);
    CU_ASSERT(gExisteArete(gc3, "a", "b") == VRAI);
    CU_ASSERT(gExisteArete(gc3, "a", "c") == VRAI);
    CU_ASSERT(gExisteArete(gc3, "b", "d") == VRAI);
    CU_ASSERT(gPoidsArete(gc3, "a", "b") == 1);
    CU_ASSERT(gPoidsArete(gc3, "a", "c") == 2);
    CU_ASSERT(gPoidsArete(gc3, "b", "d") == 1);

    CU_ASSERT(gEstVide(gc4) == FAUX);
    CU_ASSERT(gEstConnexe(gc4) == VRAI);
    CU_ASSERT(gNombreSommets(gc4) == 4);
    CU_ASSERT(gExisteSommet(gc4, "a") == VRAI);
    CU_ASSERT(gExisteSommet(gc4, "b") == VRAI);
    CU_ASSERT(gExisteSommet(gc4, "c") == VRAI);
    CU_ASSERT(gExisteSommet(gc4, "d") == VRAI);
    CU_ASSERT(gNombreAretes(gc4) == 3);
    CU_ASSERT(gExisteArete(gc4, "a", "b") == VRAI);
    CU_ASSERT(gExisteArete(gc4, "a", "c") == VRAI);
    CU_ASSERT(gExisteArete(gc4, "b", "d") == VRAI);
    CU_ASSERT(gPoidsArete(gc4, "a", "b") == 1);
    CU_ASSERT(gPoidsArete(gc4, "a", "c") == 2);
    CU_ASSERT(gPoidsArete(gc4, "b", "d") == 1);

    CU_ASSERT(gEstVide(gc5) == FAUX);
    CU_ASSERT(gEstConnexe(gc5) == VRAI);
    CU_ASSERT(gNombreSommets(gc5) == 4);
    CU_ASSERT(gExisteSommet(gc5, "a") == VRAI);
    CU_ASSERT(gExisteSommet(gc5, "b") == VRAI);
    CU_ASSERT(gExisteSommet(gc5, "c") == VRAI);
    CU_ASSERT(gExisteSommet(gc5, "d") == VRAI);
    CU_ASSERT(gNombreAretes(gc5) == 3);
    CU_ASSERT(gExisteArete(gc5, "a", "b") == VRAI);
    CU_ASSERT(gExisteArete(gc5, "a", "c") == VRAI);
    CU_ASSERT(gExisteArete(gc5, "b", "d") == VRAI);
    CU_ASSERT(gPoidsArete(gc5, "a", "b") == 1);
    CU_ASSERT(gPoidsArete(gc5, "a", "c") == 2);
    CU_ASSERT(gPoidsArete(gc5, "b", "d") == 1);
    CU_ASSERT(gPoidsArete(gc5, "a", "c") != 4);

    CU_ASSERT(gEstVide(gc6) == FAUX);
    CU_ASSERT(gEstConnexe(gc6) == VRAI);
    CU_ASSERT(gNombreSommets(gc6) == 4);
    CU_ASSERT(gExisteSommet(gc6, "a") == VRAI);
    CU_ASSERT(gExisteSommet(gc6, "b") == VRAI);
    CU_ASSERT(gExisteSommet(gc6, "c") == VRAI);
    CU_ASSERT(gExisteSommet(gc6, "d") == VRAI);
    CU_ASSERT(gExisteSommet(gc6, "e") == FAUX);
    CU_ASSERT(gExisteSommet(gc6, "f") == FAUX);
    CU_ASSERT(gNombreAretes(gc6) == 3);
    CU_ASSERT(gExisteArete(gc6, "a", "b") == VRAI);
    CU_ASSERT(gExisteArete(gc6, "a", "c") == VRAI);
    CU_ASSERT(gExisteArete(gc6, "b", "d") == VRAI);
    CU_ASSERT(gExisteArete(gc6, "e", "f") == FAUX);
    CU_ASSERT(gPoidsArete(gc6, "a", "b") == 1);
    CU_ASSERT(gPoidsArete(gc6, "a", "c") == 2);
    CU_ASSERT(gPoidsArete(gc6, "b", "d") == 1);
}

void test_grapheconnexe_gcSupprimerSommet(void)
{
    CU_ASSERT(gEstConnexe(gc7) == VRAI);
    CU_ASSERT(gNombreSommets(gc7) == 5);
    CU_ASSERT(gExisteSommet(gc7, "a") == VRAI);
    CU_ASSERT(gExisteSommet(gc7, "b") == VRAI);
    CU_ASSERT(gExisteSommet(gc7, "c") == VRAI);
    CU_ASSERT(gExisteSommet(gc7, "d") == VRAI);
    CU_ASSERT(gExisteSommet(gc7, "e") == VRAI);
    CU_ASSERT(gNombreAretes(gc7) == 4);
    CU_ASSERT(gExisteArete(gc7, "a", "b") == VRAI);
    CU_ASSERT(gExisteArete(gc7, "a", "c") == VRAI);
    CU_ASSERT(gExisteArete(gc7, "b", "d") == VRAI);
    CU_ASSERT(gExisteArete(gc7, "d", "e") == VRAI);
    CU_ASSERT(gPoidsArete(gc7, "a", "b") == 1);
    CU_ASSERT(gPoidsArete(gc7, "a", "c") == 2);
    CU_ASSERT(gPoidsArete(gc7, "b", "d") == 2);
    CU_ASSERT(gPoidsArete(gc7, "d", "e") == 1);

    CU_ASSERT(gEstConnexe(gc8) == VRAI);
    CU_ASSERT(gNombreSommets(gc8) == 4);
    CU_ASSERT(gExisteSommet(gc8, "a") == VRAI);
    CU_ASSERT(gExisteSommet(gc8, "b") == VRAI);
    CU_ASSERT(gExisteSommet(gc8, "c") == VRAI);
    CU_ASSERT(gExisteSommet(gc8, "d") == VRAI);
    CU_ASSERT(gExisteSommet(gc8, "e") == FAUX);
    CU_ASSERT(gNombreAretes(gc8) == 3);
    CU_ASSERT(gExisteArete(gc8, "a", "b") == VRAI);
    CU_ASSERT(gExisteArete(gc8, "a", "c") == VRAI);
    CU_ASSERT(gExisteArete(gc8, "b", "d") == VRAI);
    CU_ASSERT(gExisteArete(gc8, "d", "e") == FAUX);
    CU_ASSERT(gPoidsArete(gc8, "a", "b") == 1);
    CU_ASSERT(gPoidsArete(gc8, "a", "c") == 2);
    CU_ASSERT(gPoidsArete(gc8, "b", "d") == 2);
}

void test_grapheconnexe_gcSupprimerArete(void)
{
    CU_ASSERT(gEstConnexe(gc9) == VRAI);
    CU_ASSERT(gNombreSommets(gc9) == 5);
    CU_ASSERT(gExisteSommet(gc9, "a") == VRAI);
    CU_ASSERT(gExisteSommet(gc9, "b") == VRAI);
    CU_ASSERT(gExisteSommet(gc9, "c") == VRAI);
    CU_ASSERT(gExisteSommet(gc9, "d") == VRAI);
    CU_ASSERT(gExisteSommet(gc9, "e") == VRAI);
    CU_ASSERT(gNombreAretes(gc9) == 6);
    CU_ASSERT(gExisteArete(gc9, "a", "b") == VRAI);
    CU_ASSERT(gExisteArete(gc9, "a", "c") == VRAI);
    CU_ASSERT(gExisteArete(gc9, "b", "d") == VRAI);
    CU_ASSERT(gExisteArete(gc9, "d", "e") == VRAI);
    CU_ASSERT(gExisteArete(gc9, "a", "d") == VRAI);
    CU_ASSERT(gExisteArete(gc9, "b", "e") == VRAI);
    CU_ASSERT(gPoidsArete(gc9, "a", "b") == 1);
    CU_ASSERT(gPoidsArete(gc9, "a", "c") == 2);
    CU_ASSERT(gPoidsArete(gc9, "b", "d") == 6);
    CU_ASSERT(gPoidsArete(gc9, "d", "e") == 4);
    CU_ASSERT(gPoidsArete(gc9, "a", "d") == 7);
    CU_ASSERT(gPoidsArete(gc9, "b", "e") == 9);

    CU_ASSERT(gEstConnexe(gc10) == VRAI);
    CU_ASSERT(gNombreSommets(gc10) == 5);
    CU_ASSERT(gExisteSommet(gc10, "a") == VRAI);
    CU_ASSERT(gExisteSommet(gc10, "b") == VRAI);
    CU_ASSERT(gExisteSommet(gc10, "c") == VRAI);
    CU_ASSERT(gExisteSommet(gc10, "d") == VRAI);
    CU_ASSERT(gExisteSommet(gc10, "e") == VRAI);
    CU_ASSERT(gNombreAretes(gc10) == 5);
    CU_ASSERT(gExisteArete(gc10, "a", "b") == VRAI);
    CU_ASSERT(gExisteArete(gc10, "a", "c") == VRAI);
    CU_ASSERT(gExisteArete(gc10, "b", "d") == VRAI);
    CU_ASSERT(gExisteArete(gc10, "d", "e") == FAUX);
    CU_ASSERT(gExisteArete(gc10, "a", "d") == VRAI);
    CU_ASSERT(gExisteArete(gc10, "b", "e") == VRAI);
    CU_ASSERT(gPoidsArete(gc10, "a", "b") == 1);
    CU_ASSERT(gPoidsArete(gc10, "a", "c") == 2);
    CU_ASSERT(gPoidsArete(gc10, "b", "d") == 6);
    CU_ASSERT(gPoidsArete(gc10, "a", "d") == 7);
    CU_ASSERT(gPoidsArete(gc10, "b", "e") == 9);
}

void test_grapheconnexe_gcModifierArete(void)
{
    CU_ASSERT(gEstConnexe(gc11) == VRAI);
    CU_ASSERT(gNombreSommets(gc11) == 5);
    CU_ASSERT(gExisteSommet(gc11, "a") == VRAI);
    CU_ASSERT(gExisteSommet(gc11, "b") == VRAI);
    CU_ASSERT(gExisteSommet(gc11, "c") == VRAI);
    CU_ASSERT(gExisteSommet(gc11, "d") == VRAI);
    CU_ASSERT(gExisteSommet(gc11, "e") == VRAI);
    CU_ASSERT(gNombreAretes(gc11) == 6);
    CU_ASSERT(gExisteArete(gc11, "a", "b") == VRAI);
    CU_ASSERT(gExisteArete(gc11, "a", "c") == VRAI);
    CU_ASSERT(gExisteArete(gc11, "b", "d") == VRAI);
    CU_ASSERT(gExisteArete(gc11, "d", "e") == VRAI);
    CU_ASSERT(gExisteArete(gc11, "a", "d") == VRAI);
    CU_ASSERT(gExisteArete(gc11, "b", "e") == VRAI);
    CU_ASSERT(gPoidsArete(gc11, "a", "b") == 1);
    CU_ASSERT(gPoidsArete(gc11, "a", "c") == 2);
    CU_ASSERT(gPoidsArete(gc11, "b", "d") == 6);
    CU_ASSERT(gPoidsArete(gc11, "d", "e") == 4);
    CU_ASSERT(gPoidsArete(gc11, "a", "d") == 7);
    CU_ASSERT(gPoidsArete(gc11, "b", "e") == 9);
    CU_ASSERT(gExisteArete(gc11, "a", "e") == FAUX);

    CU_ASSERT(gEstConnexe(gc12) == VRAI);
    CU_ASSERT(gNombreSommets(gc12) == 5);
    CU_ASSERT(gExisteSommet(gc12, "a") == VRAI);
    CU_ASSERT(gExisteSommet(gc12, "b") == VRAI);
    CU_ASSERT(gExisteSommet(gc12, "c") == VRAI);
    CU_ASSERT(gExisteSommet(gc12, "d") == VRAI);
    CU_ASSERT(gExisteSommet(gc12, "e") == VRAI);
    CU_ASSERT(gNombreAretes(gc12) == 6);
    CU_ASSERT(gExisteArete(gc12, "a", "b") == VRAI);
    CU_ASSERT(gExisteArete(gc12, "a", "c") == VRAI);
    CU_ASSERT(gExisteArete(gc12, "b", "d") == VRAI);
    CU_ASSERT(gExisteArete(gc12, "d", "e") == VRAI);
    CU_ASSERT(gExisteArete(gc12, "a", "d") == VRAI);
    CU_ASSERT(gExisteArete(gc12, "b", "e") == VRAI);
    CU_ASSERT(gPoidsArete(gc12, "a", "b") == 1);
    CU_ASSERT(gPoidsArete(gc12, "a", "c") == 2);
    CU_ASSERT(gPoidsArete(gc12, "b", "d") == 6);
    CU_ASSERT(gPoidsArete(gc12, "d", "e") == 4);
    CU_ASSERT(gPoidsArete(gc12, "b", "e") == 9);
    CU_ASSERT(gPoidsArete(gc12, "a", "d") != 7);
    CU_ASSERT(gPoidsArete(gc12, "a", "d") == 10);
}

int add_testgrapheconnexe(void)
{
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("Tests Graphes Connexes", init_suiteGrapheConnexe, clean_suiteGrapheConnexe);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "gcNouv", test_grapheconnexe_gcNouv) == NULL
        || CU_add_test(pSuite, "gcAjouterSommet", test_grapheconnexe_gcAjouterSommet) == NULL
        || CU_add_test(pSuite, "gcAjouterArete", test_grapheconnexe_gcAjouterArete) == NULL
        || CU_add_test(pSuite, "gcSupprimerSommet", test_grapheconnexe_gcSupprimerSommet) == NULL
        || CU_add_test(pSuite, "gcSupprimerArete", test_grapheconnexe_gcSupprimerArete) == NULL
        || CU_add_test(pSuite, "gcModifierArete", test_grapheconnexe_gcModifierArete) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
