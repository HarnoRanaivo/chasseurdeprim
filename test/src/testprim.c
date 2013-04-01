#include "testprim.h"

static Graphe * g0 = NULL;
static CouleursGraphe * cg0 = NULL;
static CouleursGraphe * cg1 = NULL;
static FileAreteTriee * ft0 = NULL;
static FileAreteTriee * ft1 = NULL;
static FileAreteTriee * ft2 = NULL;
static Graphe * a0 = NULL;
static Graphe * g1 = NULL;
static Graphe * a1 = NULL;
static Graphe * a2 = NULL;
static Graphe * a3 = NULL;
static Graphe * a4 = NULL;
static Graphe * a5 = NULL;
static Graphe * a6 = NULL;
static Graphe * a7 = NULL;

int init_suitePrim(void)
{
    g0 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "a"), "b"), "c");
    g0 = gAjouterSommet(gAjouterSommet(gAjouterSommet(g0, "d"), "e"), "f");
    g0 = gAjouterArete(gAjouterArete(g0, "a", "b", 1), "a", "c", 3);
    g0 = gAjouterArete(gAjouterArete(g0, "a", "d", 1), "a", "e", 1);
    g0 = gAjouterArete(gAjouterArete(g0, "b", "c", 2), "b", "f", 4);
    g0 = gAjouterArete(gAjouterArete(g0, "c", "e", 5), "c", "f", 4);
    g0 = gAjouterArete(gAjouterArete(g0, "d", "e", 2), "e", "f", 3);

    cg0 = cgInit(g0);
    cg0 = cgModifierSommet(cg0, "a", NOIR);

    cg1 = cgInit(g0);
    cg1 = cgModifierSommet(cgModifierSommet(cg1, "a", NOIR), "e", NOIR);

    ft0 = ftAjouterAretesIncidentes(ft0, g0, cg0, "a");

    ft1 = ftAjouterAretesIncidentes(ft1, g0, cg1, "e");

    ft2 = ftAjouterAretesIncidentes(ft2, g0, cg0, "a");
    ft2 = larSupprimerArete(ft2, "a", "e");
    ft2 = ftAjouterAretesIncidentes(ft2, g0, cg1, "e");

    a0 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "a"), "b"), "c");
    a0 = gAjouterSommet(gAjouterSommet(gAjouterSommet(a0, "d"), "e"), "f");
    a0 = gAjouterArete(gAjouterArete(a0, "a", "b", 1), "a", "d", 1);
    a0 = gAjouterArete(gAjouterArete(a0, "a", "e", 1), "b", "c", 2);
    a0 = gAjouterArete(a0, "e", "f", 3);

    g1 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "a"), "b"), "c");
    g1 = gAjouterSommet(gAjouterSommet(gAjouterSommet(g1, "d"), "e"), "f");
    g1 = gAjouterArete(gAjouterArete(g1, "a", "b", 2), "a", "c", 1);
    g1 = gAjouterArete(gAjouterArete(g1, "a", "d", 3), "a", "f", 5);
    g1 = gAjouterArete(gAjouterArete(g1, "b", "c", 2), "b", "d", 1);
    g1 = gAjouterArete(gAjouterArete(g1, "b", "e", 1), "c", "e", 1);
    g1 = gAjouterArete(gAjouterArete(g1, "c", "f", 2), "d", "e", 1);
    g1 = gAjouterArete(gAjouterArete(g1, "d", "f", 1), "e", "f", 1);

    a1 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "a"), "b"), "c");
    a1 = gAjouterSommet(gAjouterSommet(gAjouterSommet(a1, "d"), "e"), "f");
    a1 = gAjouterArete(gAjouterArete(a1, "a", "c", 1), "c", "e", 1);
    a1 = gAjouterArete(gAjouterArete(a1, "e", "f", 1), "d", "f", 1);
    a1 = gAjouterArete(a1, "b", "d", 1);
    
    a2 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "a"), "b"), "c");
    a2 = gAjouterSommet(gAjouterSommet(gAjouterSommet(a2, "d"), "e"), "f");
    a2 = gAjouterArete(gAjouterArete(a2, "a", "c", 1), "c", "e", 1);
    a2 = gAjouterArete(gAjouterArete(a2, "b", "e", 1), "e", "f", 1);
    a2 = gAjouterArete(a2, "d", "f", 1);

    a3 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "a"), "b"), "c");
    a3 = gAjouterSommet(gAjouterSommet(gAjouterSommet(a3, "d"), "e"), "f");
    a3 = gAjouterArete(gAjouterArete(a3, "a", "c", 1), "c", "e", 1);
    a3 = gAjouterArete(gAjouterArete(a3, "b", "e", 1), "e", "d", 1);
    a3 = gAjouterArete(a3, "d", "f", 1);

    a4 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "a"), "b"), "c");
    a4 = gAjouterSommet(gAjouterSommet(gAjouterSommet(a4, "d"), "e"), "f");
    a4 = gAjouterArete(gAjouterArete(a4, "a", "c", 1), "c", "e", 1);
    a4 = gAjouterArete(gAjouterArete(a4, "b", "d", 1), "e", "d", 1);
    a4 = gAjouterArete(a4, "e", "f", 1);

    a5 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "a"), "b"), "c");
    a5 = gAjouterSommet(gAjouterSommet(gAjouterSommet(a5, "d"), "e"), "f");
    a5 = gAjouterArete(gAjouterArete(a5, "a", "c", 1), "c", "e", 1);
    a5 = gAjouterArete(gAjouterArete(a5, "b", "d", 1), "e", "d", 1);
    a5 = gAjouterArete(a5, "d", "f", 1);

    a6 = gArbreCouvrantMinimum(g0, "a");
    a7 = gArbreCouvrantMinimum(g1, "b");

    return 0;
}

int clean_suitePrim(void)
{
    g0 = gLiberer(g0);
    cg0 = cgLiberer(cg0);
    cg1 = cgLiberer(cg1);
    ft0 = larLiberer(ft0);
    ft1 = larLiberer(ft1);
    ft2 = larLiberer(ft2);
    a0 = gLiberer(a0);
    g1 = gLiberer(g1);
    a1 = gLiberer(a1);
    a2 = gLiberer(a2);
    a3 = gLiberer(a3);
    a4 = gLiberer(a4);
    a5 = gLiberer(a5);
    a6 = gLiberer(a6);
    a7 = gLiberer(a7);

    return 0;
}

void test_prim_ftAjouterAretesIncidentes(void)
{
    CU_ASSERT(larEstVide(ft0) == FAUX);
    CU_ASSERT(larNombreAretes(ft0) == 4);
    CU_ASSERT(larExisteArete(ft0, "a", "b") == VRAI);
    CU_ASSERT(larExisteArete(ft0, "a", "c") == VRAI);
    CU_ASSERT(larExisteArete(ft0, "a", "d") == VRAI);
    CU_ASSERT(larExisteArete(ft0, "a", "e") == VRAI);
    CU_ASSERT(aPoids(larAreteTete(ft0)) == 1);
    CU_ASSERT(aPoids(larAreteTete(larSuivante(ft0))) == 1);
    CU_ASSERT(aPoids(larAreteTete(larSuivante(larSuivante(ft0)))) == 1);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(larSuivante(larSuivante(ft0)))), "a", "c", 3) == VRAI);

    CU_ASSERT(larEstVide(ft1) == FAUX);
    CU_ASSERT(larNombreAretes(ft1) == 3);
    CU_ASSERT(larExisteArete(ft1, "e", "a") == FAUX);
    CU_ASSERT(larExisteArete(ft1, "e", "c") == VRAI);
    CU_ASSERT(larExisteArete(ft1, "e", "d") == VRAI);
    CU_ASSERT(larExisteArete(ft1, "e", "f") == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(ft1), "e", "d", 2) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(ft1)), "e", "f", 3) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(larSuivante(ft1))), "e", "c", 5) == VRAI);

    CU_ASSERT(larEstVide(ft2) == FAUX);
    CU_ASSERT(larNombreAretes(ft2) == 6);
    CU_ASSERT(larExisteArete(ft2, "e", "a") == FAUX);
    CU_ASSERT(larExisteArete(ft2, "a", "b") == VRAI);
    CU_ASSERT(larExisteArete(ft2, "a", "c") == VRAI);
    CU_ASSERT(larExisteArete(ft2, "a", "d") == VRAI);
    CU_ASSERT(larExisteArete(ft2, "e", "c") == VRAI);
    CU_ASSERT(larExisteArete(ft2, "e", "d") == VRAI);
    CU_ASSERT(larExisteArete(ft2, "e", "f") == VRAI);
    CU_ASSERT(aPoids(larAreteTete(ft2)) == 1);
    CU_ASSERT(aPoids(larAreteTete(larSuivante(ft2))) == 1);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(larSuivante(ft2))), "e", "d", 2) == VRAI);
    CU_ASSERT(aPoids(larAreteTete(larSuivante(larSuivante(larSuivante(ft2))))) == 3);
    CU_ASSERT(aPoids(larAreteTete(larSuivante(larSuivante(larSuivante(larSuivante(ft2)))))) == 3);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(larSuivante(larSuivante(larSuivante(larSuivante(ft2)))))), "e", "c", 5) == VRAI);
}

void test_prim_gArbreCouvrantMinimum(void)
{
    CU_ASSERT(gEstVide(a6) == FAUX);
    CU_ASSERT(gNombreSommets(a6) == gNombreSommets(g0));
    CU_ASSERT(gNombreAretes(a6) == gNombreSommets(a6) - 1);
    CU_ASSERT(gEstConnexe(a6) == VRAI);
    CU_ASSERT(gACycle(a6) == FAUX);
    CU_ASSERT(gEgalite(a0, a6) == VRAI);

    CU_ASSERT(gEstVide(a7) == FAUX);
    CU_ASSERT(gNombreSommets(a7) == gNombreSommets(g1));
    CU_ASSERT(gNombreAretes(a7) == gNombreSommets(a7) - 1);
    CU_ASSERT(gEstConnexe(a7) == VRAI);
    CU_ASSERT(gACycle(a7) == FAUX);
    CU_ASSERT(gNombreSommets(a7) == gNombreSommets(g1));
    CU_ASSERT(gEgalite(a7, a1) || gEgalite(a7, a2) || gEgalite(a7, a3) || gEgalite(a7, a4) || gEgalite(a7, a5) == VRAI);
}

int add_testPrim(void)
{
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("Tests Prim", init_suitePrim, clean_suitePrim);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "ftAjouterAretesIncidentes", test_prim_ftAjouterAretesIncidentes) == NULL
        || CU_add_test(pSuite, "gArbreCouvrantMinimum", test_prim_gArbreCouvrantMinimum) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
