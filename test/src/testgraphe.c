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
static Graphe g7 = NULL;
static Graphe g8 = NULL;
static Graphe g9 = NULL;
static Graphe g10 = NULL;
static Graphe g11 = NULL;
static Graphe g12 = NULL;
static Graphe g13 = NULL;
static Graphe g14 = NULL;
static Graphe g15 = NULL;
static Graphe g16 = NULL;
static Graphe g17 = NULL;
static Graphe g18 = NULL;
static Graphe g19 = NULL;
static Graphe g20 = NULL;

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

    /* gAjouterSommet. */
    g6 = gAjouterSommet(gAjouterSommet(gNouv(), "azer"), "qsdf");

    /* gAjouterArete. */
    g7 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "azer"), "qsdf"), "wxcv"), "uiop");
    g7 = gAjouterArete(gAjouterArete(gAjouterArete(g7, "azer", "wxcv", 1), "azer", "azer", 2), "qsdf", "azer", 3);

    /* gSupprimerSommet. */
    g8 = gAjouterSommet(gAjouterSommet(gNouv(), "azer"), "qsdf");
    g8 = gSupprimerSommet(g8, "wxcv");

    g9 = gAjouterSommet(gAjouterSommet(gNouv(), "azer"), "qsdf");
    g9 = gSupprimerSommet(g9, "azer");

    g10 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "azer"), "qsdf"), "wxcv"), "uiop");
    g10 = gAjouterArete(gAjouterArete(gAjouterArete(g10, "azer", "wxcv", 1), "azer", "azer", 2), "qsdf", "wxcv", 3);
    g10 = gSupprimerSommet(g10, "azer");

    /* gSupprimerArete. */
    g11 = gAjouterSommet(gAjouterSommet(gNouv(), "azer"), "qsdf");
    g11 = gSupprimerArete(g11, "azer", "qsdf");

    g12 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "azer"), "qsdf"), "wxcv"), "uiop");
    g12 = gAjouterArete(gAjouterArete(gAjouterArete(g12, "azer", "wxcv", 1), "azer", "azer", 2), "qsdf", "azer", 3);
    g12 = gSupprimerArete(g12, "azer", "qsdf");


    /* gEgalite. */
    g13 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "azer"), "qsdf"), "wxcv"), "uiop");
    g13 = gAjouterArete(gAjouterArete(gAjouterArete(g13, "azer", "wxcv", 1), "azer", "azer", 2), "qsdf", "azer", 3);
    g14 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "uiop"), "qsdf"), "azer"), "wxcv");
    g14 = gAjouterArete(gAjouterArete(gAjouterArete(g14, "azer", "azer", 2), "azer", "wxcv", 1), "qsdf", "azer", 3);
    g15 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "hjkl"), "qsdf"), "azer");
    g15 = gAjouterArete(gAjouterArete(gAjouterArete(g15, "azer", "azer", 2), "azer", "hjkl", 1), "qsdf", "azer", 3);

    /* gModifierArete. */
    g16 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "azer"), "qsdf"), "wxcv"), "uiop");
    g16 = gAjouterArete(gAjouterArete(gAjouterArete(g16, "azer", "wxcv", 1), "azer", "azer", 2), "qsdf", "azer", 3);
    g16 = gModifierArete(g16, "azer", "qsdf", 42);

    g17 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "azer"), "qsdf"), "wxcv"), "uiop");
    g17 = gAjouterArete(gAjouterArete(gAjouterArete(g17, "azer", "wxcv", 1), "azer", "azer", 2), "qsdf", "azer", 3);
    g17 = gModifierArete(g17, "uiop", "azer", 67);

    g18 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "azer"), "qsdf"), "wxcv"), "uiop");
    g18 = gAjouterArete(gAjouterArete(gAjouterArete(g18, "azer", "wxcv", 1), "azer", "azer", 2), "qsdf", "azer", 3);
    g18 = gModifierArete(g18, "hjkl", "uiop", 123);


    /* gCopier. */
    g19 = gAjouterSommet(gAjouterSommet(gAjouterSommet(gAjouterSommet(gNouv(), "azer"), "qsdf"), "wxcv"), "uiop");
    g19 = gAjouterArete(gAjouterArete(gAjouterArete(g19, "azer", "wxcv", 1), "azer", "azer", 2), "qsdf", "azer", 3);
    g20 = gCopier(g19);

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
    g7 = gLiberer(g7);
    g8 = gLiberer(g8);
    g9 = gLiberer(g9);
    g10 = gLiberer(g10);
    g11 = gLiberer(g11);
    g12 = gLiberer(g12);
    g13 = gLiberer(g13);
    g14 = gLiberer(g14);
    g15 = gLiberer(g15);
    g16 = gLiberer(g16);
    g17 = gLiberer(g17);
    g18 = gLiberer(g18);
    g19 = gLiberer(g19);
    g20 = gLiberer(g20);

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

void test_graphe_gSuivant(void)
{
    CU_ASSERT(gSuivant(g1) == NULL);
    CU_ASSERT(gSuivant(g5) == g4);
    CU_ASSERT(gSuivant(g4) == g3);
    CU_ASSERT(gSuivant(g3) == g2);
    CU_ASSERT(gSuivant(g2) == NULL);
}

void test_graphe_gSommetTete(void)
{
    CU_ASSERT(egalSom(gSommetTete(g1), "azer") == VRAI);
    CU_ASSERT(egalSom(gSommetTete(g5), "uiop") == VRAI);
    CU_ASSERT(egalSom(gSommetTete(g4), "wxcv") == VRAI);
    CU_ASSERT(egalSom(gSommetTete(g3), "qsdf") == VRAI);
    CU_ASSERT(egalSom(gSommetTete(g2), "azer") == VRAI);
}

void test_graphe_gAdjacenceTete(void)
{
    CU_ASSERT(gAdjacenceTete(g1) == NULL);
    CU_ASSERT(gAdjacenceTete(g2) == l2);
    CU_ASSERT(gAdjacenceTete(g3) == l3);
    CU_ASSERT(gAdjacenceTete(g4) == l4);
    CU_ASSERT(gAdjacenceTete(g5) == l5);
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

void test_graphe_gPoidsArete(void)
{
    CU_ASSERT(gPoidsArete(g5, "qsdf", "azer") == 3);
    CU_ASSERT(gPoidsArete(g5, "azer", "qsdf") == gPoidsArete(g5, "qsdf", "azer"));
    CU_ASSERT(gPoidsArete(g5, "qsdf", "wxcv") == 2);
    CU_ASSERT(gPoidsArete(g5, "wxcv", "qsdf") == gPoidsArete(g5, "qsdf", "wxcv"));
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

void test_graphe_gAjouterSommet(void)
{
    CU_ASSERT(gNombreSommets(g6) == 2);
    CU_ASSERT(gNombreAretes(g6) == 0);
    CU_ASSERT(gExisteSommet(g6, "azer") == VRAI);
    CU_ASSERT(gExisteSommet(g6, "qsdf") == VRAI);
    CU_ASSERT(gExisteSommet(g6, "wxcv") == FAUX);
    CU_ASSERT(gAArete(g6, "azer") == FAUX);
    CU_ASSERT(gAArete(g6, "qsdf") == FAUX);
}

void test_graphe_gAjouterArete(void)
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
    CU_ASSERT(gNombreVoisins(g7, "uiop") == 0);
}

void test_graphe_gSupprimerSommet(void)
{
    CU_ASSERT(gNombreSommets(g8) == 2);
    CU_ASSERT(gExisteSommet(g8, "azer") == VRAI);
    CU_ASSERT(gExisteSommet(g8, "qsdf") == VRAI);
    CU_ASSERT(gNombreSommets(g9) == 1);
    CU_ASSERT(gExisteSommet(g9, "azer") == FAUX);
    CU_ASSERT(gExisteSommet(g9, "qsdf") == VRAI);
    CU_ASSERT(gNombreSommets(g10) == 3);
    CU_ASSERT(gNombreAretes(g10) == 1);
    CU_ASSERT(gExisteSommet(g10, "azer") == FAUX);
    CU_ASSERT(gExisteSommet(g10, "qsdf") == VRAI);
    CU_ASSERT(gExisteSommet(g10, "wxcv") == VRAI);
    CU_ASSERT(gExisteSommet(g10, "uiop") == VRAI);
}

void test_graphe_gSupprimerArete(void)
{
    CU_ASSERT(gNombreSommets(g11) == 2);
    CU_ASSERT(gNombreAretes(g11) == 0);
    CU_ASSERT(gNombreSommets(g12) == 4);
    CU_ASSERT(gNombreAretes(g12) == 2);
    CU_ASSERT(gNombreVoisins(g12, "azer") == 2);
}

void test_graphe_gModifierArete(void)
{
    CU_ASSERT(gNombreSommets(g16) == 4);
    CU_ASSERT(gNombreAretes(g16) == 3);
    CU_ASSERT(gPoidsArete(g16, "azer", "wxcv") == 1);
    CU_ASSERT(gPoidsArete(g16, "azer", "azer") == 2);
    CU_ASSERT(gPoidsArete(g16, "azer", "qsdf") == 42);

    CU_ASSERT(gNombreSommets(g17) == 4);
    CU_ASSERT(gNombreAretes(g17) == 3);
    CU_ASSERT(gPoidsArete(g17, "azer", "wxcv") == 1);
    CU_ASSERT(gPoidsArete(g17, "azer", "azer") == 2);
    CU_ASSERT(gPoidsArete(g17, "azer", "qsdf") == 3);
    CU_ASSERT(gExisteArete(g17, "uiop", "azer") == FAUX);

    CU_ASSERT(gNombreSommets(g18) == 4);
    CU_ASSERT(gNombreAretes(g18) == 3);
    CU_ASSERT(gPoidsArete(g18, "azer", "wxcv") == 1);
    CU_ASSERT(gPoidsArete(g18, "azer", "azer") == 2);
    CU_ASSERT(gPoidsArete(g18, "azer", "qsdf") == 3);
    CU_ASSERT(gExisteSommet(g18, "hjkl") == FAUX);
    CU_ASSERT(gExisteArete(g18, "hjkl", "uiop") == FAUX);
}

void test_graphe_gEgalite(void)
{
    CU_ASSERT(gEgalite(gNouv(), gNouv()) == VRAI);
    CU_ASSERT(gEgalite(g13, g14) == VRAI);
    CU_ASSERT(gEgalite(g13, gNouv()) == FAUX);
    CU_ASSERT(gEgalite(g13, g15) == FAUX);
}

void test_graphe_gCopier(void)
{
    CU_ASSERT(gEgalite(g19, g20) == VRAI);
}

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
        || CU_add_test(pSuite, "Test gSuivant", test_graphe_gSuivant) == NULL
        || CU_add_test(pSuite, "Test gSommetTete", test_graphe_gSommetTete) == NULL
        || CU_add_test(pSuite, "Test gAdjacenceTete", test_graphe_gAdjacenceTete) == NULL
        || CU_add_test(pSuite, "Test gExisteSommet", test_graphe_gExisteSommet) == NULL
        || CU_add_test(pSuite, "Test gPSommet", test_graphe_gPSommet) == NULL
        || CU_add_test(pSuite, "Test gAdjacenceSommet", test_graphe_gAdjacenceSommet) == NULL
        || CU_add_test(pSuite, "Test gPoidsArete", test_graphe_gPoidsArete) == NULL
        || CU_add_test(pSuite, "Test gAArete", test_graphe_gAArete) == NULL
        || CU_add_test(pSuite, "Test gExisteArete", test_graphe_gExisteArete) == NULL
        || CU_add_test(pSuite, "Test gNombreVoisins", test_graphe_gNombreVoisins) == NULL
        || CU_add_test(pSuite, "Test gNombreSommets", test_graphe_gNombreSommets) == NULL
        || CU_add_test(pSuite, "Test gNombreAretes", test_graphe_gNombreAretes) == NULL
        || CU_add_test(pSuite, "Test gAjouterSommet", test_graphe_gAjouterSommet) == NULL
        || CU_add_test(pSuite, "Test gAjouterArete", test_graphe_gAjouterArete) == NULL
        || CU_add_test(pSuite, "Test gSupprimerSommet", test_graphe_gSupprimerSommet) == NULL
        || CU_add_test(pSuite, "Test gSupprimerArete", test_graphe_gSupprimerArete) == NULL
        || CU_add_test(pSuite, "Test gModifierArete", test_graphe_gModifierArete) == NULL
        || CU_add_test(pSuite, "Test gEgalite", test_graphe_gEgalite) == NULL
        || CU_add_test(pSuite, "Test gCopier", test_graphe_gCopier) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
