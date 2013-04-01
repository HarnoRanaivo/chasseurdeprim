#include "testfilearetetriee.h"

static FileAreteTriee * ft0 = NULL;

int init_suiteFileAreteTriee(void)
{
    ft0 = ftAjouterArete(ftAjouterArete(ftNouv(), "a", "b", 3), "c", "d", 1);
    ft0 = ftAjouterArete(ftAjouterArete(ft0, "e", "f", 5), "g", "h", 2);

    return 0;
}

int clean_suiteFileAreteTriee(void)
{
    ft0 = larLiberer(ft0);

    return 0;
}

void test_filearetetriee_ftNouv(void)
{
    CU_ASSERT(larEstVide(ftNouv()) == VRAI);
    CU_ASSERT(larNombreAretes(ftNouv()) == 0);
}

void test_filearetetriee_ftAjouterArete(void)
{
    CU_ASSERT(larEstVide(ft0) == FAUX);
    CU_ASSERT(larNombreAretes(ft0) == 4);
    CU_ASSERT(larExisteArete(ft0, "a", "b") == VRAI);
    CU_ASSERT(larExisteArete(ft0, "c", "d") == VRAI);
    CU_ASSERT(larExisteArete(ft0, "e", "f") == VRAI);
    CU_ASSERT(larExisteArete(ft0, "g", "h") == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(ft0), "c", "d", 1) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(ft0)), "g", "h", 2) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(larSuivante(ft0))), "a", "b", 3) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(larSuivante(larSuivante(ft0)))), "e", "f", 5) == VRAI);
}

int add_testFileAreteTriee(void)
{
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("Tests Files d'Arêtes Triées", init_suiteFileAreteTriee, clean_suiteFileAreteTriee);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "ftNouv", test_filearetetriee_ftNouv) == NULL
        || CU_add_test(pSuite, "ftAjouterArete", test_filearetetriee_ftAjouterArete) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
