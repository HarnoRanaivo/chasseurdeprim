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
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
