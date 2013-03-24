#include "testgraphe.h"

/* Variables globales. */
static Graphe g0 = NULL;
static Graphe g1 = NULL;
static Graphe g2 = NULL;
static Graphe g3 = NULL;
static Graphe g4 = NULL;
static Graphe g5 = NULL;
static ListeArete l2 = NULL;
static ListeArete l3 = NULL;
static ListeArete l4 = NULL;
static ListeArete l5 = NULL;
static Graphe g6 = NULL;

int init_suiteGraphe(void)
{
    /* Pour tester gEstVide. */
    g1 = MALLOC(g1);
    g1->sommet = copieSommet("azer");
    g1->listeadjacence = listnouv();
    g1->suivant = NULL;

    /* Pour tester les sélecteurs. */
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

    /* Pour tester les générateurs. */
    g6 = gAjoutSommet(gAjoutSommet(gNouv(), "azer"), "qsdf");
    g7 = gAjoutSommet(gAjoutSommet(gAjoutSommet(gAjoutSommet(gNouv(), "azer"), "qsdf"), "wxcv"), "uiop");
    g7 = gAjoutArete(gAjoutArete(gAjoutArete(g6, "azer", "wxcv"), "azer", "azer"), "qsdf", "azer");


    return 0;
}

int clean_suiteGraphe(void)
{
    g1->sommet = libererSommet(g1->sommet);
    g2->sommet = libererSommet(g2->sommet);
    g3->sommet = libererSommet(g3->sommet);
    g4->sommet = libererSommet(g4->sommet);
    g5->sommet = libererSommet(g5->sommet);
    l2 = lliberer(l2);
    l3 = lliberer(l3);
    l4 = lliberer(l4);
    l5 = lliberer(l5);
    free(g1);
    free(g2);
    free(g3);
    free(g4);
    free(g5);
    g6 = gLiberer(g6);

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
    CU_ASSERT(gAArete(g5, "azer") == VRAI);
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
    CU_ASSERT(lega(gAdjacenceSommet(g5, "qsdf"), l3) == VRAI);
    CU_ASSERT(lega(gAdjacenceSommet(g5, "wxcv"), l4) == VRAI);
    CU_ASSERT(lega(gAdjacenceSommet(g5, "uiop"), l5) == VRAI);
    CU_ASSERT(lega(gAdjacenceSommet(g5, "azer"), l3) == FAUX);
    CU_ASSERT(lega(gAdjacenceSommet(g5, "hjkl"), l2) == FAUX);
}

void test_graphe_gNombreSommets(void)
{
    CU_ASSERT(gNombreSommets(g0) == 0);
    CU_ASSERT(gNombreSommets(g1) == 1);
    CU_ASSERT(gNombreSommets(g2) == 1);
    CU_ASSERT(gNombreSommets(g3) == 2);
    CU_ASSERT(gNombreSommets(g4) == 3);
    CU_ASSERT(gNombreSommets(g5) == 4);
}

void test_graphe_gNombreAretes(void)
{
    CU_ASSERT(gNombreAretes(g0) == 0);
    CU_ASSERT(gNombreAretes(g1) == 0);
    CU_ASSERT(gNombreAretes(g5) == 2);
}

void test_graphe_gNombreVoisins(void)
{
    CU_ASSERT(gNombreVoisins(g5, "azer") == 1);
    CU_ASSERT(gNombreVoisins(g5, "qsdf") == 2);
    CU_ASSERT(gNombreVoisins(g5, "wxcv") == 1);
    CU_ASSERT(gNombreVoisins(g5, "uiop") == 0);
}

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

void test_graphe_gAjoutSommet(void)
{
    CU_ASSERT(gNombreSommets(g6) == 2);
    CU_ASSERT(gNombreAretes(g6) == 0);
    CU_ASSERT(gExisteSommet(g6, "azer") == VRAI);
    CU_ASSERT(gExisteSommet(g6, "qsdf") == VRAI);
    CU_ASSERT(gExisteSommet(g6, "wxcv") == VRAI);
    CU_ASSERT(gAArete(g6, "azer") == FAUX);
    CU_ASSERT(gAArete(g6, "qsdf") == FAUX);
}

void test_graphe_gAjoutArete(void)
{
    CU_ASSERT(gNombreSommets(g7) == 4);
    CU_ASSERT(gNombreAretes(g7) == 3);
    CU_ASSERT(gExisteSommet(g7, "azer") == VRAI);
    CU_ASSERT(gExisteSommet(g7, "qsdf") == VRAI);
    CU_ASSERT(gExisteSommet(g7, "wxcv") == VRAI);
    CU_ASSERT(gExisteSommet(g7, "uiop") == VRAI);
    CU_ASSERT(gAArete(g7, "azer") == VRAI);
    CU_ASSERT(gAArete(g7, "qsdf") == VRAI);
    CU_ASSERT(gAArete(g7, "wxcv") == VRAI);
    CU_ASSERT(gAArete(g7, "uiop") == FAUX);
    CU_ASSERT(gNombreVoisins(g7, "azer") == 3);
    CU_ASSERT(gNombreVoisins(g7, "wxcv") == 1);
    CU_ASSERT(gNombreVoisins(g7, "qsdf") == 1);
    CU_ASSERT(gNombreVoisins(g7, "uiop") == 1);
}

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

    /* gPSommet est utilisé par gAdjacenceSommet qui est utilisé par gAArete,
     * gExisteArete et gNombreVoisins. À tester dans cet ordre !
     */
    if (CU_add_test(pSuite, "Test gNouv", test_graphe_gNouv) == NULL
        || CU_add_test(pSuite, "Test gEstVide", test_graphe_gEstVide) == NULL
        || CU_add_test(pSuite, "Test gExisteSommet", test_graphe_gExisteSommet) == NULL
        || CU_add_test(pSuite, "Test gPSommet", test_graphe_gPSommet) == NULL
        || CU_add_test(pSuite, "Test gAdjacenceSommet", test_graphe_gAdjacenceSommet) == NULL
        || CU_add_test(pSuite, "Test gAArete", test_graphe_gAArete) == NULL
        || CU_add_test(pSuite, "Test gExisteArete", test_graphe_gExisteArete) == NULL
        || CU_add_test(pSuite, "Test gNombreVoisins", test_graphe_gNombreVoisins) == NULL
        || CU_add_test(pSuite, "Test gNombreSommets", test_graphe_gNombreSommets) == NULL
        || CU_add_test(pSuite, "Test gNombreAretes", test_graphe_gNombreAretes) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
