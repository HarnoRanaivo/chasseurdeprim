#include "testarete.h"

static Arete a0 = NULL;
static Arete a1 = NULL;
static Arete a2 = NULL;
static Arete a3 = NULL;

int init_suiteArete(void)
{
    a0 = MALLOC(a0);
    a0->a = copieSommet("a");
    a0->b = copieSommet("b");
    a0->poids = 1;
    a1 = MALLOC(a1);
    a1->a = copieSommet("b");
    a1->b = copieSommet("a");
    a1->poids = 2;
    a2 = MALLOC(a2);
    a2->a = copieSommet("azer");
    a2->b = copieSommet("qsdf");
    a2->poids = 42;

    a3 = aNouv("a", "b", 1);

    return 0;
}

int clean_suiteArete(void)
{
    a0->a = libererSommet(a0->a);
    a0->b = libererSommet(a0->b);
    a1->a = libererSommet(a1->a);
    a1->b = libererSommet(a1->b);
    a2->a = libererSommet(a2->a);
    a2->b = libererSommet(a2->b);
    free(a0);
    free(a1);
    free(a2);
    a3 = aLiberer(a3);

    return 0;
}

void test_arete_aNouv(void)
{
    CU_ASSERT(egalSom(aA(a3), "a") == VRAI);
    CU_ASSERT(egalSom(aB(a3), "b") == VRAI);
    CU_ASSERT(aPoids(a3) == 1);
}

void test_arete_aA(void)
{
    CU_ASSERT(egalSom(aA(a0), "a") == VRAI);
    CU_ASSERT(egalSom(aA(a1), "b") == VRAI);
    CU_ASSERT(egalSom(aA(a2), "azer") == VRAI);
    CU_ASSERT(egalSom(aA(a0), "b") == FAUX);
    CU_ASSERT(egalSom(aA(a1), "a") == FAUX);
    CU_ASSERT(egalSom(aA(a2), "qsdf") == FAUX);
    CU_ASSERT(egalSom(aA(a0), "z") == FAUX);
    CU_ASSERT(egalSom(aA(a1), "z") == FAUX);
    CU_ASSERT(egalSom(aA(a2), "hjkl") == FAUX);
}

void test_arete_aB(void)
{
    CU_ASSERT(egalSom(aB(a0), "b") == VRAI);
    CU_ASSERT(egalSom(aB(a1), "a") == VRAI);
    CU_ASSERT(egalSom(aB(a2), "qsdf") == VRAI);
    CU_ASSERT(egalSom(aB(a0), "a") == FAUX);
    CU_ASSERT(egalSom(aB(a1), "b") == FAUX);
    CU_ASSERT(egalSom(aB(a2), "azer") == FAUX);
    CU_ASSERT(egalSom(aB(a0), "z") == FAUX);
    CU_ASSERT(egalSom(aB(a1), "z") == FAUX);
    CU_ASSERT(egalSom(aB(a2), "hjkl") == FAUX);
}

void test_arete_aPoids(void)
{
    CU_ASSERT(aPoids(a0) == 1);
    CU_ASSERT(aPoids(a1) == 2);
    CU_ASSERT(aPoids(a2) == 42);
}

int add_testarete(void)
{
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("Tests Arete", init_suiteArete, clean_suiteArete);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "aNouv", test_arete_aNouv) == NULL
        || CU_add_test(pSuite, "aA", test_arete_aA) == NULL
        || CU_add_test(pSuite, "aB", test_arete_aB) == NULL
        || CU_add_test(pSuite, "aPoids", test_arete_aPoids) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
