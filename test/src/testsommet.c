#include "testsommet.h"

Sommet a;
Sommet b;

int init_suiteSommet(void)
{
    Sommet c;

    /* Pour tester copieSommet. */
    a = copieSommet("abcde");

    /* Pour tester modSommet. */
    b = copieSommet("abcde");
    c = modSommet(b, "fghijkl");
    if (c != NULL) b = c;

    return 0;
}

int clean_suiteSommet(void)
{
    free(a);
    free(b);

    return 0;
}

void test_sommet_egalSom(void)
{
    CU_ASSERT(egalSom("abcde", "abcde") == VRAI);
    CU_ASSERT(egalSom("abcde", "abcd") == FAUX);
    CU_ASSERT(egalSom("abcde", "abcdr") == FAUX);
    CU_ASSERT(egalSom("abcde", "azert") == FAUX);
}

void test_sommet_copieSommet(void)
{
    CU_ASSERT(egalSom(a, "abcde") == VRAI);
    CU_ASSERT(egalSom(a, "abcdf") == FAUX);
}

void test_sommet_modSommet(void)
{
    CU_ASSERT(egalSom(b, "abcde") == FAUX);
    CU_ASSERT(egalSom(b, "fghijkl") == VRAI);
}

int add_testsommets(void)
{
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("Tests Sommet", init_suiteSommet, clean_suiteSommet);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "test_egalSom", test_sommet_egalSom) == NULL
        || CU_add_test(pSuite, "Test copieSommet", test_sommet_copieSommet) == NULL
        || CU_add_test(pSuite, "Test modSommet", test_sommet_modSommet) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
