#include "testarete.h"

static Arete * a0 = NULL;
static Arete * a1 = NULL;
static Arete * a2 = NULL;
static Arete * a3 = NULL;

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

void test_arete_aAreteEgaleS(void)
{
    CU_ASSERT(aAreteEgaleS(a0, "a", "b") == VRAI);
    CU_ASSERT(aAreteEgaleS(a0, "b", "a") == VRAI);
    CU_ASSERT(aAreteEgaleS(a0, "e", "g") == FAUX);
    CU_ASSERT(aAreteEgaleS(a0, "g", "e") == FAUX);
    CU_ASSERT(aAreteEgaleS(a0, "a", "g") == FAUX);
    CU_ASSERT(aAreteEgaleS(a0, "g", "a") == FAUX);

    CU_ASSERT(aAreteEgaleS(a1, "a", "b") == VRAI);
    CU_ASSERT(aAreteEgaleS(a1, "b", "a") == VRAI);
    CU_ASSERT(aAreteEgaleS(a1, "e", "g") == FAUX);
    CU_ASSERT(aAreteEgaleS(a1, "g", "e") == FAUX);
    CU_ASSERT(aAreteEgaleS(a1, "a", "g") == FAUX);
    CU_ASSERT(aAreteEgaleS(a1, "g", "a") == FAUX);

    CU_ASSERT(aAreteEgaleS(a2, "azer", "qsdf") == VRAI);
    CU_ASSERT(aAreteEgaleS(a2, "qsdf", "azer") == VRAI);
    CU_ASSERT(aAreteEgaleS(a2, "hjkl", "qsdf") == FAUX);
    CU_ASSERT(aAreteEgaleS(a2, "qsdf", "hjkl") == FAUX);
    CU_ASSERT(aAreteEgaleS(a2, "hjkl", "wxcv") == FAUX);
    CU_ASSERT(aAreteEgaleS(a2, "wxcv", "hjkl") == FAUX);
}

void test_arete_aAreteEgaleS2(void)
{
    CU_ASSERT(aAreteEgaleS2(a0, a0) == VRAI);
    CU_ASSERT(aAreteEgaleS2(a0, a1) == VRAI);
    CU_ASSERT(aAreteEgaleS2(a0, a2) == FAUX);

    CU_ASSERT(aAreteEgaleS2(a1, a1) == VRAI);
    CU_ASSERT(aAreteEgaleS2(a1, a0) == VRAI);
    CU_ASSERT(aAreteEgaleS2(a1, a2) == FAUX);

    CU_ASSERT(aAreteEgaleS2(a2, a2) == VRAI);
    CU_ASSERT(aAreteEgaleS2(a2, a0) == FAUX);
    CU_ASSERT(aAreteEgaleS2(a2, a1) == FAUX);
}

void test_arete_aAreteEgaleP(void)
{
    CU_ASSERT(aAreteEgaleP(a0, "a", "b", 1) == VRAI);
    CU_ASSERT(aAreteEgaleP(a0, "a", "b", 2) == FAUX);
    CU_ASSERT(aAreteEgaleP(a0, "a", "c", 1) == FAUX);
    CU_ASSERT(aAreteEgaleP(a0, "c", "c", 1) == FAUX);

    CU_ASSERT(aAreteEgaleP(a1, "a", "b", 2) == VRAI);
    CU_ASSERT(aAreteEgaleP(a1, "a", "b", 1) == FAUX);
    CU_ASSERT(aAreteEgaleP(a1, "a", "c", 2) == FAUX);
    CU_ASSERT(aAreteEgaleP(a1, "c", "b", 2) == FAUX);

    CU_ASSERT(aAreteEgaleP(a2, "azer", "qsdf", 42) == VRAI);
    CU_ASSERT(aAreteEgaleP(a2, "azer", "qsdf", 1) == FAUX);
    CU_ASSERT(aAreteEgaleP(a2, "hjkl", "qsdf", 42) == FAUX);
    CU_ASSERT(aAreteEgaleP(a2, "azer", "hjkl", 42) == FAUX);
}

void test_arete_aAreteEgaleP2(void)
{
    CU_ASSERT(aAreteEgaleP2(a0, a0) == VRAI);
    CU_ASSERT(aAreteEgaleP2(a0, a1) == FAUX);
    CU_ASSERT(aAreteEgaleP2(a0, a2) == FAUX);

    CU_ASSERT(aAreteEgaleP2(a1, a1) == VRAI);
    CU_ASSERT(aAreteEgaleP2(a1, a0) == FAUX);
    CU_ASSERT(aAreteEgaleP2(a1, a2) == FAUX);

    CU_ASSERT(aAreteEgaleP2(a2, a2) == VRAI);
    CU_ASSERT(aAreteEgaleP2(a2, a0) == FAUX);
    CU_ASSERT(aAreteEgaleP2(a2, a1) == FAUX);
}

int add_testArete(void)
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
        || CU_add_test(pSuite, "aAreteEgaleS", test_arete_aAreteEgaleS) == NULL
        || CU_add_test(pSuite, "aAreteEgaleS2", test_arete_aAreteEgaleS2) == NULL
        || CU_add_test(pSuite, "aAreteEgaleP", test_arete_aAreteEgaleP) == NULL
        || CU_add_test(pSuite, "aAreteEgaleP2", test_arete_aAreteEgaleP2) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
