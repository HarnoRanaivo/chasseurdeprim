#include "testgraphe.h"

/* Variables globales. */
Graphe g0 = NULL;
Graphe g1 = NULL;
Graphe g2 = NULL;
Graphe g3 = NULL;
Graphe g4 = NULL;
Graphe g5 = NULL;
ListeArete l2 = NULL;
ListeArete l3 = NULL;
ListeArete l4 = NULL;
ListeArete l5 = NULL;

int init_suiteGraphe(void)
{
    /* Pour tester gEstVide. */
    g1 = MALLOC(g1);
    g1->sommet = copieSommet("azer");
    g1->listeadjacence = listnouv();
    g1->suivant = NULL;

    /* Pour tester gExisteSommet. */
    g2 = MALLOC(g2);
    g3 = MALLOC(g3);
    g4 = MALLOC(g4);
    g5 = MALLOC(g5);
    g2->sommet = copieSommet("azer");
    g3->sommet = copieSommet("qsdf");
    g4->sommet = copieSommet("wxcv");
    g5->sommet = copieSommet("uiop");
    g5->suivant = g4;
    g4->suivant = g3;
    g3->suivant = g2;
    g2->suivant = NULL;
    l5 = listnouv();
    l4 = lajar(listnouv(), "qsdf", 2);
    l3 = lajar(lajar(listnouv(), "azer", 3), "wxcv", 2);
    l2 = lajar(listnouv(), "qsdf", 3);
    g5->listeadjacence = l5;
    g4->listeadjacence = l4;
    g3->listeadjacence = l3;
    g2->listeadjacence = l2;

    return 0;
}

int clean_suiteGraphe(void)
{
    return 0;
}

void test_graphe_gNouv(void)
{
    CU_ASSERT(gNouv() == NULL);
}

void test_graphe_gEstVide(void)
{
    CU_ASSERT(gEstVide(gNouv()) == VRAI);
    CU_ASSERT(gEstVide(g0) == VRAI);
    CU_ASSERT(gEstVide(g1) == FAUX);
}

void test_graphe_gExisteSommet(void)
{
    CU_ASSERT(gExisteSommet(g5, "uiop") == VRAI);
    CU_ASSERT(gExisteSommet(g5, "azer") == VRAI);
    CU_ASSERT(gExisteSommet(g5, "qsdf") == VRAI);
    CU_ASSERT(gExisteSommet(g5, "wxcv") == VRAI);
    CU_ASSERT(gExisteSommet(g5, "uioy") == FAUX);

    CU_ASSERT(gExisteSommet(g4, "uiop") == FAUX);
    CU_ASSERT(gExisteSommet(g4, "azer") == VRAI);
    CU_ASSERT(gExisteSommet(g4, "qsdf") == VRAI);
    CU_ASSERT(gExisteSommet(g4, "wxcv") == VRAI);
    CU_ASSERT(gExisteSommet(g4, "wxcb") == FAUX);

    CU_ASSERT(gExisteSommet(g3, "uiop") == FAUX);
    CU_ASSERT(gExisteSommet(g3, "azer") == VRAI);
    CU_ASSERT(gExisteSommet(g3, "qsdf") == VRAI);
    CU_ASSERT(gExisteSommet(g3, "wxcv") == FAUX);
    CU_ASSERT(gExisteSommet(g3, "qsdg") == FAUX);

    CU_ASSERT(gExisteSommet(g2, "uiop") == FAUX);
    CU_ASSERT(gExisteSommet(g2, "azer") == VRAI);
    CU_ASSERT(gExisteSommet(g2, "qsdf") == FAUX);
    CU_ASSERT(gExisteSommet(g2, "wxcv") == FAUX);
    CU_ASSERT(gExisteSommet(g2, "azet") == FAUX);
}

void test_graphe_gAArete(void)
{
    CU_ASSERT(gAArete(g5 "azer") == VRAI);
    CU_ASSERT(gAArete(g5, "wxcv") == VRAI);
    CU_ASSERT(gAArete(g5, "qsdf") == VRAI);
    CU_ASSERT(gAArete(g5, "uiop") == FAUX);
    CU_ASSERT(gAArete(g5, "hjkl") == FAUX);
}

void test_graphe_gExisteArete(void)
{
    CU_ASSERT(gExisteArete(g4, "azer", "qsdf") == VRAI);
    CU_ASSERT(gExisteArete(g4, "wxcv", "qsdf") == VRAI);
    CU_ASSERT(gExisteArete(g4, "qsdf", "azer") == VRAI);
    CU_ASSERT(gExisteArete(g4, "qsdf", "wxcv") == VRAI);

    CU_ASSERT(gExisteArete(g4, "azer", "wxcv") == FAUX);
    CU_ASSERT(gExisteArete(g4, "wxcv", "azer") == FAUX);
}

void test_graphe_gAdjacenceSommet(void)
{
    CU_ASSERT(lega(gAdjacenceSommet(g5, "azer"), l2) == VRAI);
    CU_ASSERT(lega(gAdjacenceSommet(g5, "qsfd"), l3) == VRAI);
    CU_ASSERT(lega(gAdjacenceSommet(g5, "wxcv"), l4) == VRAI);
    CU_ASSERT(lega(gAdjacenceSommet(g5, "uiop"), l5) == VRAI);
    CU_ASSERT(lega(gAdjacenceSommet(g5, "azer"), l3) == FAUX);
    CU_ASSERT(lega(gAdjacenceSommet(g5, "hjkl"), l2) == FAUX);
}

void test_graphe_gNombreSommets(void);

void test_graphe_gNombreAretes(void);

void test_graphe_gNombreVoisins(void);

void test_graphe_gPSommet(void)
{
    CU_ASSERT(gPSommet(g5, "azer") == g2);
    CU_ASSERT(gPSommet(g5, "qsdf") == g3);
    CU_ASSERT(gPSommet(g5, "wxcv") == g4);
    CU_ASSERT(gPSommet(g5, "uiop") == g5);
    CU_ASSERT(gPSommet(g5, "hjkl") == NULL);

    CU_ASSERT(gPSommet(g4, "azer") == g2);
    CU_ASSERT(gPSommet(g4, "qsdf") == g3);
    CU_ASSERT(gPSommet(g4, "wxcv") == g4);
    CU_ASSERT(gPSommet(g4, "uiop") == NULL);
    CU_ASSERT(gPSommet(g4, "hjkl") == NULL);

    CU_ASSERT(gPSommet(g3, "azer") == g2);
    CU_ASSERT(gPSommet(g3, "qsdf") == g3);
    CU_ASSERT(gPSommet(g3, "wxcv") == NULL);
    CU_ASSERT(gPSommet(g3, "uiop") == NULL);
    CU_ASSERT(gPSommet(g3, "hjkl") == NULL);

    CU_ASSERT(gPSommet(g2, "azer") == g2);
    CU_ASSERT(gPSommet(g2, "qsdf") == NULL);
    CU_ASSERT(gPSommet(g2, "wxcv") == NULL);
    CU_ASSERT(gPSommet(g2, "uiop") == NULL);
    CU_ASSERT(gPSommet(g2, "hjkl") == NULL);

    CU_ASSERT(gPSommet(g0, "azer") == NULL);
    CU_ASSERT(gPSommet(g0, "qsdf") == NULL);
    CU_ASSERT(gPSommet(g0, "wxcv") == NULL);
    CU_ASSERT(gPSommet(g0, "uiop") == NULL);
    CU_ASSERT(gPSommet(g0, "hjkl") == NULL);
}

void test_graphe_gAjoutSommet(void);

void test_graphe_gAjoutArete(void);

void test_graphe_gSupprimerSommet(void);

void test_graphe_gSupprimerArete(void);

void test_graphe_gModifierArete(void);

void test_graphe_gEgalite(void);

void test_graphe_gCopie(void);




int add_testgraphe(void)
{
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("Tests Graphes", init_suiteGraphe, clean_suiteGraphe);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "Test gNouv", test_graphe_gNouv) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
