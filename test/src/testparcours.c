#include "testparcours.h"

static Graphe g0 = NULL;
static Graphe g1 = NULL;
static Graphe g2 = NULL;
static Graphe g3 = NULL;
static Graphe g4 = NULL;

int init_suiteParcours(void)
{
    g0 = gNouv();

    g1 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "a"), "b"), "c"), "d");
    g1 = gAjouterArete(gAjouterArete(g1, "a", "b", 1), "a", "c", 2);

    g2 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "a"), "b"), "c"), "d");
    g2 = gAjouterArete(gAjouterArete(gAjouterArete(g2, "a", "b", 1), "a", "c", 2), "b", "d", 3);

    g3 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "a"), "b"), "c"), "d");
    g3 = gAjouterArete(gAjouterArete(gAjouterArete(g2, "a", "b", 1), "a", "c", 2), "b", "c", 3);

    g4 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "a"), "b"), "c"), "d");
    g4 = gAjouterArete(gAjouterArete(gAjouterArete(gAjouterArete(g4, "a", "b", 1), "a", "c", 2), "b", "c", 3), "b", "d", 4);

    return 0;
}

int clean_suiteParcours(void)
{
    g0 = gLiberer(g0);
    g1 = gLiberer(g1);
    g2 = gLiberer(g2);
    g3 = gLiberer(g3);
    g4 = gLiberer(g4);

    return 0;
}

void test_parcours_gEstConnexe(void)
{
    CU_ASSERT(gEstConnexe(g0) == FAUX);
    CU_ASSERT(gEstConnexe(g1) == FAUX);
    CU_ASSERT(gEstConnexe(g2) == VRAI);
    CU_ASSERT(gEstConnexe(g3) == FAUX);
    CU_ASSERT(gEstConnexe(g4) == VRAI);
}

void test_parcours_gACycle(void)
{
    CU_ASSERT(gACycle(g0) == FAUX);
    CU_ASSERT(gACycle(g1) == FAUX);
    CU_ASSERT(gACycle(g2) == FAUX);
    CU_ASSERT(gACycle(g3) == VRAI);
    CU_ASSERT(gACycle(g4) == VRAI);
}

int add_testparcours(void)
{
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("Tests Parcours", init_suiteParcours, clean_suiteParcours);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "gEstConnexe", test_parcours_gEstConnexe) == NULL
        || CU_add_test(pSuite, "gACycle", test_parcours_gACycle) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}

