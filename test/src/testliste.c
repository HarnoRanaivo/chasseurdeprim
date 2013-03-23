#include "testliste.h"

char nom1[6] = "abcde\0";
char nom12[6] = "abcdf\0";
char nom2[6] = "fghij\0";
char nom3[6] = "klmno\0";
char nom4[6] = "pqrst\0";

ListeArete l1 = NULL;
ListeArete l2 = NULL;
ListeArete l3 = NULL;
ListeArete l4 = NULL;
ListeArete l5 = NULL;

int init_suiteListe(void)
{
    l1 = MALLOC(l1);
    l1->s = NULL;
    l1->poids = 10;
    l1->v = nom1;

    l2 = MALLOC(l2);
    l2->s = NULL;
    l2->poids = 5367;
    l2->v = nom2;

    l3 = MALLOC(l3);
    l3->s = l2;
    l3->poids = 42;
    l3->v = nom3;

    l4 = MALLOC(l4);
    l4->s = l3;
    l4->poids = 360;
    l4->v = nom4;

    return 0;
}

int clean_suiteListe(void)
{
    free(l1);
    free(l2);
    free(l3);
    free(l4);
    free(l5);

    return 0;
}

void test_liste_listnouv(void)
{
    CU_ASSERT(listnouv() == NULL);
}

void test_liste_ltaille(void)
{
    CU_ASSERT(ltaille(listnouv()) == 0);
    CU_ASSERT(ltaille(l1) == 1);
    CU_ASSERT(ltaille(l4) == 3);
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
    l5 = lajar(lajar(listnouv(), "azert", 100), "qsdf", 200);
    CU_ASSERT(ltaille(l5) == 2);
    CU_ASSERT(lexar(l5, "azert") == VRAI);
    CU_ASSERT(lexar(l5, "qsdf") == VRAI);
    CU_ASSERT(lpoids(l5, "azert") == 100);
    CU_ASSERT(lpoids(l5, "qsdf") == 200);
}

void test_liste_lsupar(void)
{
    l5 = lsupar(l5, "qsdf");
    CU_ASSERT(ltaille(l5) == 1);
    CU_ASSERT(lexar(l5, "azert") == VRAI);
    CU_ASSERT(lexar(l5, "qsdf") == FAUX);
    CU_ASSERT(lpoids(l5, "azert") == 100);

    l5 = lsupar(l5, "qsdf");
    CU_ASSERT(ltaille(l5) == 1);
    CU_ASSERT(lexar(l5, "qsdf") == FAUX);
    CU_ASSERT(lexar(l5, "azert") == VRAI);
    CU_ASSERT(lpoids(l5, "azert") == 100);

    l5 = lsupar(l5, "azert");
    CU_ASSERT(ltaille(l5) == 0);
    CU_ASSERT(lexar(l5, "azert") == FAUX);
}

void test_liste_lliberer(void)
{
    ListeArete l6 = lajar(lajar(lajar(listnouv(), "azer", 1), "qsdf", 2), "wxcv", 3);
    l6 = lliberer(l6);

    CU_ASSERT(ltaille(l6) == 0);
}

void test_liste_lcopie(void)
{
    ListeArete l7 = lajar(lajar(lajar(listnouv(), "azer", 1), "qsdf", 2), "wxcv", 3);
    ListeArete l8 = lcopie(l7);

    CU_ASSERT(ltaille(l8) == ltaille(l7));
    CU_ASSERT(lexar(l8, "azer") == VRAI);
    CU_ASSERT(lexar(l8, "qsdf") == VRAI);
    CU_ASSERT(lexar(l8, "wxcv") == VRAI);
    CU_ASSERT(lpoids(l8, "azer") == 1);
    CU_ASSERT(lpoids(l8, "qsdf") == 2);
    CU_ASSERT(lpoids(l8, "wxcv") == 3);

    l7 = lliberer(l7);
    l8 = lliberer(l8);
}

void test_liste_lmod(void)
{
    ListeArete l9 = lajar(lajar(lajar(listnouv(), "azer", 1), "qsdf", 2), "wxcv", 3);
    l9 = lmod(l9, "qsdf", 42);

    CU_ASSERT(ltaille(l9) == 3);
    CU_ASSERT(lexar(l9, "azer") == VRAI);
    CU_ASSERT(lexar(l9, "qsdf") == VRAI);
    CU_ASSERT(lexar(l9, "wxcv") == VRAI);
    CU_ASSERT(lpoids(l9, "azer") == 1);
    CU_ASSERT(lpoids(l9, "qsdf") == 42);
    CU_ASSERT(lpoids(l9, "wxcv") == 3);

    l9 = lliberer(l9);
}

void test_liste_lega(void)
{
    ListeArete l10 = lajar(lajar(lajar(listnouv(), "azer", 1), "qsdf", 2), "wxcv", 3);
    ListeArete l11 = lajar(lajar(lajar(listnouv(), "qsdf", 2), "wxcv", 3), "azer", 1);
    ListeArete l12 = lajar(lajar(lajar(listnouv(), "azer", 1), "qsdf", 2), "wxcv", 4);
    ListeArete l13 = lajar(lajar(lajar(listnouv(), "azer", 1), "qsdf", 2), "uiop", 3);
    ListeArete l14 = lajar(lajar(lajar(lajar(listnouv(), "azer", 1), "qsdf", 2), "wxcv", 3), "uiop", 4);
    ListeArete l15 = lajar(lajar(listnouv(), "azer", 1), "qsdf", 2);

    CU_ASSERT(lega(l10, l11) == VRAI);
    CU_ASSERT(lega(l10, l12) == FAUX);
    CU_ASSERT(lega(l10, l13) == FAUX);
    CU_ASSERT(lega(l10, l14) == FAUX);
    CU_ASSERT(lega(l10, l15) == FAUX);

    l10 = lliberer(l10);
    l11 = lliberer(l11);
    l12 = lliberer(l12);
    l13 = lliberer(l13);
    l14 = lliberer(l14);
    l15 = lliberer(l15);
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

    if (CU_add_test(pSuite, "Test listnouv", test_liste_listnouv) == NULL
        || CU_add_test(pSuite, "Test ltaille", test_liste_ltaille) == NULL
        || CU_add_test(pSuite, "Test lpoids", test_liste_lpoids) == NULL
        || CU_add_test(pSuite, "Test lexar", test_liste_lexar) == NULL
        || CU_add_test(pSuite, "Test lajar", test_liste_lajar) == NULL
        || CU_add_test(pSuite, "Test lsupar", test_liste_lsupar) == NULL
        || CU_add_test(pSuite, "Test lliberer", test_liste_lliberer) == NULL
        || CU_add_test(pSuite, "Test lcopie", test_liste_lcopie) == NULL
        || CU_add_test(pSuite, "Test lmod", test_liste_lmod) == NULL
        || CU_add_test(pSuite, "Test lega", test_liste_lega) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
