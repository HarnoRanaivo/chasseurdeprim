#include "testliste.h"

static char nom1[6] = "abcde\0";
static char nom2[6] = "fghij\0";
static char nom3[6] = "klmno\0";
static char nom4[6] = "pqrst\0";

static ListeArete l1 = NULL;
static ListeArete l2 = NULL;
static ListeArete l3 = NULL;
static ListeArete l4 = NULL;
static ListeArete l5 = NULL;
static ListeArete l6 = NULL;
static ListeArete l7 = NULL;
static ListeArete l8 = NULL;
static ListeArete l9 = NULL;
static ListeArete l10 = NULL;
static ListeArete l11 = NULL;
static ListeArete l12 = NULL;
static ListeArete l13 = NULL;
static ListeArete l14 = NULL;
static ListeArete l15 = NULL;

int init_suiteListe(void)
{
    /* Pour les tests de quelques sélecteurs. */
    l1 = MALLOC(l1);
    l1->s = NULL;
    l1->poids = 10;
    l1->v = copieSommet(nom1);

    l2 = MALLOC(l2);
    l2->s = NULL;
    l2->poids = 5367;
    l2->v = copieSommet(nom2);

    l3 = MALLOC(l3);
    l3->s = l2;
    l3->poids = 42;
    l3->v = copieSommet(nom3);

    l4 = MALLOC(l4);
    l4->s = l3;
    l4->poids = 360;
    l4->v = copieSommet(nom4);

    /* Pour les tests des générateurs et autres sélecteurs. À tester après quelques
     * sélecteurs : on peut utiliser les sélecteurs validés dans les tests. */

    /* Pour tester lajar. */
    l5 = lajar(lajar(listnouv(), "azert", 100), "qsdf", 200);

    /* Pour tester lsupar. */
    l6 = lajar(lajar(listnouv(), "azert", 100), "qsdf", 200);

    /* Pour tester lcopie. */
    l7 = lajar(lajar(lajar(listnouv(), "azer", 1), "qsdf", 2), "wxcv", 3);
    l8 = lcopie(l7);

    /* Pour tester lmod. */
    l9 = lajar(lajar(lajar(listnouv(), "azer", 1), "qsdf", 2), "wxcv", 3);
    l9 = lmod(l9, "qsdf", 42);

    /* Pour tester lega. */
    l10 = lajar(lajar(lajar(listnouv(), "azer", 1), "qsdf", 2), "wxcv", 3);
    l11 = lajar(lajar(lajar(listnouv(), "qsdf", 2), "wxcv", 3), "azer", 1);
    l12 = lajar(lajar(lajar(listnouv(), "azer", 1), "qsdf", 2), "wxcv", 4);
    l13 = lajar(lajar(lajar(listnouv(), "azer", 1), "qsdf", 2), "uiop", 3);
    l14 = lajar(lajar(lajar(lajar(listnouv(), "azer", 1), "qsdf", 2), "wxcv", 3), "uiop", 4);
    l15 = lajar(lajar(listnouv(), "azer", 1), "qsdf", 2);

    return 0;
}

int clean_suiteListe(void)
{
    l1->v = libererSommet(l1->v);
    l2->v = libererSommet(l2->v);
    l3->v = libererSommet(l3->v);
    l4->v = libererSommet(l4->v);
    free(l1);
    free(l2);
    free(l3);
    free(l4);
    l5 = lliberer(l5);
    l6 = lliberer(l6);
    l7 = lliberer(l7);
    l8 = lliberer(l8);
    l9 = lliberer(l9);
    l10 = lliberer(l10);
    l11 = lliberer(l11);
    l12 = lliberer(l12);
    l13 = lliberer(l13);
    l14 = lliberer(l14);
    l15 = lliberer(l15);

    return 0;
}

void test_liste_listnouv(void)
{
    CU_ASSERT(listnouv() == NULL);
}

void test_liste_lest_vide(void)
{
    CU_ASSERT(lest_vide(listnouv()) == VRAI);
    CU_ASSERT(lest_vide(l1) == FAUX);
    CU_ASSERT(lest_vide(l2) == FAUX);
    CU_ASSERT(lest_vide(l3) == FAUX);
    CU_ASSERT(lest_vide(l4) == FAUX);
}

void test_liste_ltaille(void)
{
    CU_ASSERT(ltaille(listnouv()) == 0);
    CU_ASSERT(ltaille(l1) == 1);
    CU_ASSERT(ltaille(l4) == 3);
}

void test_liste_lsommet_tete(void)
{
    CU_ASSERT(egalSom(lsommet_tete(l1), nom1) == VRAI);
    CU_ASSERT(egalSom(lsommet_tete(l2), nom2) == VRAI);
    CU_ASSERT(egalSom(lsommet_tete(l3), nom3) == VRAI);
    CU_ASSERT(egalSom(lsommet_tete(l4), nom4) == VRAI);
}

void test_liste_lpoids_tete(void)
{
    CU_ASSERT(lpoids_tete(l1) == 10);
    CU_ASSERT(lpoids_tete(l2) == 5367);
    CU_ASSERT(lpoids_tete(l3) == 42);
    CU_ASSERT(lpoids_tete(l4) == 360);
}

void test_liste_lsuiv(void)
{
    CU_ASSERT(lsuiv(l1) == NULL);
    CU_ASSERT(lsuiv(l4) == l3);
    CU_ASSERT(lsuiv(l3) == l2);
    CU_ASSERT(lsuiv(l2) == NULL);
}

void test_liste_lexar(void)
{
    CU_ASSERT(lexar(listnouv(), nom1) == FAUX);

    CU_ASSERT(lexar(l1, nom1) == VRAI);
    CU_ASSERT(lexar(l1, nom2) == FAUX);

    CU_ASSERT(lexar(l4, nom1) == FAUX);
    CU_ASSERT(lexar(l4, nom2) == VRAI);
    CU_ASSERT(lexar(l4, nom3) == VRAI);
    CU_ASSERT(lexar(l4, nom4) == VRAI);
}

void test_liste_lpoids(void)
{
    CU_ASSERT(lpoids(l1, nom1) == 10);

    CU_ASSERT(lpoids(l4, nom2) == 5367);
    CU_ASSERT(lpoids(l4, nom3) == 42);
    CU_ASSERT(lpoids(l4, nom4) == 360);
}

void test_liste_lajar(void)
{
    CU_ASSERT(ltaille(l5) == 2);
    CU_ASSERT(lexar(l5, "azert") == VRAI);
    CU_ASSERT(lexar(l5, "qsdf") == VRAI);
    CU_ASSERT(lpoids(l5, "azert") == 100);
    CU_ASSERT(lpoids(l5, "qsdf") == 200);
}

void test_liste_lsupar(void)
{
    l6 = lsupar(l6, "qsdf");
    CU_ASSERT(ltaille(l6) == 1);
    CU_ASSERT(lexar(l6, "azert") == VRAI);
    CU_ASSERT(lexar(l6, "qsdf") == FAUX);
    CU_ASSERT(lpoids(l6, "azert") == 100);

    l6 = lsupar(l6, "qsdf");
    CU_ASSERT(ltaille(l6) == 1);
    CU_ASSERT(lexar(l6, "qsdf") == FAUX);
    CU_ASSERT(lexar(l6, "azert") == VRAI);
    CU_ASSERT(lpoids(l6, "azert") == 100);

    l6 = lsupar(l6, "azert");
    CU_ASSERT(ltaille(l6) == 0);
    CU_ASSERT(lexar(l6, "azert") == FAUX);
}

void test_liste_lcopie(void)
{
    CU_ASSERT(ltaille(l8) == ltaille(l7));
    CU_ASSERT(lexar(l8, "azer") == VRAI);
    CU_ASSERT(lexar(l8, "qsdf") == VRAI);
    CU_ASSERT(lexar(l8, "wxcv") == VRAI);
    CU_ASSERT(lpoids(l8, "azer") == 1);
    CU_ASSERT(lpoids(l8, "qsdf") == 2);
    CU_ASSERT(lpoids(l8, "wxcv") == 3);
}

void test_liste_lmod(void)
{
    CU_ASSERT(ltaille(l9) == 3);
    CU_ASSERT(lexar(l9, "azer") == VRAI);
    CU_ASSERT(lexar(l9, "qsdf") == VRAI);
    CU_ASSERT(lexar(l9, "wxcv") == VRAI);
    CU_ASSERT(lpoids(l9, "azer") == 1);
    CU_ASSERT(lpoids(l9, "qsdf") == 42);
    CU_ASSERT(lpoids(l9, "wxcv") == 3);
}

void test_liste_lega(void)
{
    CU_ASSERT(lega(l10, l11) == VRAI);
    CU_ASSERT(lega(l10, l12) == FAUX);
    CU_ASSERT(lega(l10, l13) == FAUX);
    CU_ASSERT(lega(l10, l14) == FAUX);
    CU_ASSERT(lega(l10, l15) == FAUX);

}

int add_testliste(void)
{
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("Tests Liste", init_suiteListe, clean_suiteListe);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "listnouv", test_liste_listnouv) == NULL
        || CU_add_test(pSuite, "lest_vide", test_liste_lest_vide) == NULL
        || CU_add_test(pSuite, "lsommet_tete", test_liste_lsommet_tete) == NULL
        || CU_add_test(pSuite, "lpoids_tete", test_liste_lpoids_tete) == NULL
        || CU_add_test(pSuite, "lsuiv", test_liste_lsuiv) == NULL
        || CU_add_test(pSuite, "ltaille", test_liste_ltaille) == NULL
        || CU_add_test(pSuite, "lpoids", test_liste_lpoids) == NULL
        || CU_add_test(pSuite, "lexar", test_liste_lexar) == NULL
        || CU_add_test(pSuite, "lajar", test_liste_lajar) == NULL
        || CU_add_test(pSuite, "lsupar", test_liste_lsupar) == NULL
        || CU_add_test(pSuite, "lcopie", test_liste_lcopie) == NULL
        || CU_add_test(pSuite, "lmod", test_liste_lmod) == NULL
        || CU_add_test(pSuite, "lega", test_liste_lega) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
