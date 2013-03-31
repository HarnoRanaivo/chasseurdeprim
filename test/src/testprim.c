#include "testprim.h"

static Graphe g0 = NULL;
static CouleursGraphe cg0 = NULL;
static CouleursGraphe cg1 = NULL;
static FileTriee ft0 = NULL;
static FileTriee ft1 = NULL;
static FileTriee ft2 = NULL;
static Graphe a0 = NULL;
static Graphe g1 = NULL;
static Graphe a1 = NULL;
static Graphe a2 = NULL;
static Graphe a3 = NULL;
static Graphe a4 = NULL;
static Graphe a5 = NULL;

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

    ft0 = pAjouterAretesIncidentes(ft0, g0, cg0, "a");

    ft1 = pAjouterAretesIncidentes(ft1, g0, cg1, "e");

    ft2 = pAjouterAretesIncidentes(ft2, g0, cg0, "a");
    ft2 = ftSupprimerArete(ft2, "a", "e");
    ft2 = pAjouterAretesIncidentes(ft2, g0, cg1, "e");

    a0 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "a"), "b"), "c");
    a0 = gAjouterSommet(gAjouterSommet(gAjouterSommet(a0, "d"), "e"), "f");
    a0 = gAjouterArete(gAjouterArete(a0, "a", "b", 1), "a", "d", 1);
    a0 = gAjouterArete(gAjouterArete(a0, "a", "b", 1), "b", "c", 2);
    a0 = gAjouterArete(a0, "e", "f", 3);

    g1 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "a"), "b"), "c");
    g1 = gAjouterSommet(gAjouterSommet(gAjouterSommet(g1, "d"), "e"), "f");
    g1 = gAjouterArete(gAjouterArete(g1, "a", "b", 2), "a", "c", 1);
    g1 = gAjouterArete(gAjouterArete(g1, "a", "d", 3), "a", "f", 5);
    g1 = gAjouterArete(gAjouterArete(g1, "b", "c", 2), "b", "d", 1);
    g1 = gAjouterArete(gAjouterArete(g1, "b", "e", 1), "c", "a", 1);
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

    a4 = pArbreCouvrantMinimum(g0, "a");
    a5 = pArbreCouvrantMinimum(g1, "b");

    return 0;
}

int clean_suitePrim(void)
{
    g0 = gLiberer(g0);
    cg0 = cgLiberer(cg0);
    cg1 = cgLiberer(cg1);
    ft0 = ftLiberer(ft0);
    ft1 = ftLiberer(ft1);
    ft2 = ftLiberer(ft2);
    a0 = gLiberer(a0);
    g1 = gLiberer(g1);
    a1 = gLiberer(a1);
    a2 = gLiberer(a2);
    a3 = gLiberer(a3);
    a4 = gLiberer(a4);
    a5 = gLiberer(a5);

    return 0;
}

void test_prim_pAjouterAretesIncidentes(void)
{
    CU_ASSERT(ftEstVide(ft0) == FAUX);
    CU_ASSERT(ftNombreAretes(ft0) == 4);
    CU_ASSERT(ftExisteArete(ft0, "a", "b") == VRAI);
    CU_ASSERT(ftExisteArete(ft0, "a", "c") == VRAI);
    CU_ASSERT(ftExisteArete(ft0, "a", "d") == VRAI);
    CU_ASSERT(ftExisteArete(ft0, "a", "e") == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ftSuivante(ftSuivante(ft0)))), "a", "c", 3) == VRAI);

    CU_ASSERT(ftEstVide(ft1) == FAUX);
    CU_ASSERT(ftNombreAretes(ft1) == 3);
    CU_ASSERT(ftExisteArete(ft1, "e", "a") == FAUX);
    CU_ASSERT(ftExisteArete(ft1, "e", "c") == VRAI);
    CU_ASSERT(ftExisteArete(ft1, "e", "d") == VRAI);
    CU_ASSERT(ftExisteArete(ft1, "e", "f") == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ft1), "e", "d", 2) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ft1)), "e", "f", 3) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ftSuivante(ft1))), "e", "c", 5) == VRAI);

    CU_ASSERT(ftEstVide(ft2) == FAUX);
    CU_ASSERT(ftNombreAretes(ft2) == 6);
    CU_ASSERT(ftExisteArete(ft2, "e", "a") == FAUX);
    CU_ASSERT(ftExisteArete(ft2, "a", "b") == VRAI);
    CU_ASSERT(ftExisteArete(ft2, "a", "c") == VRAI);
    CU_ASSERT(ftExisteArete(ft2, "a", "d") == VRAI);
    CU_ASSERT(ftExisteArete(ft2, "e", "c") == VRAI);
    CU_ASSERT(ftExisteArete(ft2, "e", "d") == VRAI);
    CU_ASSERT(ftExisteArete(ft2, "e", "f") == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ftSuivante(ft2))), "e", "d", 2) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ftSuivante(ftSuivante(ftSuivante(ftSuivante(ft2)))))), "e", "c", 5) == VRAI);
}

void test_prim_pArbreCouvrantMinimum(void)
{
    CU_ASSERT(gEstVide(a4) == FAUX);
    CU_ASSERT(gNombreSommets(a4) == gNombreSommets(g0));
    CU_ASSERT(gNombreAretes(a4) == gNombreSommets(a4) - 1);
    CU_ASSERT(gEstConnexe(a4) == VRAI);
    CU_ASSERT(gACycle(a4) == FAUX);
    CU_ASSERT(gEgalite(a0, a4) == VRAI);

    CU_ASSERT(gEstVide(a5) == FAUX);
    CU_ASSERT(gNombreSommets(a5) == gNombreSommets(g1));
    CU_ASSERT(gNombreAretes(a5) == gNombreSommets(a5) - 1);
    CU_ASSERT(gEstConnexe(a5) == VRAI);
    CU_ASSERT(gACycle(a5) == FAUX);
    CU_ASSERT(gNombreSommets(a5) == gNombreSommets(g1));
    CU_ASSERT(gEgalite(a5, a1) || gEgalite(a5, a2) || gEgalite(a5, a3) == VRAI);
}

int add_testprim(void)
{
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("Tests Prim", init_suitePrim, clean_suitePrim);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "pAjouterAretesIncidentes", test_prim_pAjouterAretesIncidentes) == NULL
        || CU_add_test(pSuite, "pArbreCouvrantMinimum", test_prim_pArbreCouvrantMinimum) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
