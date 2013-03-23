#include "testgraphe.h"

int init_suiteGraphe(void)
{
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
