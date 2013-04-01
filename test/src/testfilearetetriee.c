#include "testfilearetetriee.h"

static FileAreteTriee * ft0 = NULL;
static FileAreteTriee * ft1 = NULL;
static FileAreteTriee * ft2 = NULL;
static FileAreteTriee * ft3 = NULL;
static FileAreteTriee * ft4 = NULL;
static FileAreteTriee * ft5 = NULL;
static FileAreteTriee * ft6 = NULL;
static FileAreteTriee * ft7 = NULL;
static FileAreteTriee * ft8 = NULL;
static FileAreteTriee * ft9 = NULL;

int init_suiteFileAreteTriee(void)
{
    ft0 = NULL;

    ft1 = MALLOC(ft1);
    ft1->arete = aNouv("a", "b", 1);
    ft1->suivante = NULL;

    ft2 = MALLOC(ft2);
    ft2->arete = aNouv("e", "f", 8);
    ft2->suivante = NULL;

    ft3 = MALLOC(ft3);
    ft3->arete = aNouv("c", "d", 4);
    ft3->suivante = ft2;

    ft4 = MALLOC(ft4);
    ft4->arete = aNouv("a", "b", 1);
    ft4->suivante = ft3;

    ft5 = ftAjouterArete(ftAjouterArete(ftNouv(), "a", "b", 3), "c", "d", 1);
    ft5 = ftAjouterArete(ftAjouterArete(ft5, "e", "f", 5), "g", "h", 2);

    ft6 = ftAjouterArete(ftAjouterArete(ftNouv(), "a", "b", 3), "c", "d", 1);
    ft6 = ftAjouterArete(ftAjouterArete(ft6, "e", "f", 5), "g", "h", 2);
    ft6 = ftSupprimerTete(ft6);

    ft7 = ftNouv();

    ft8 = ftAjouterArete(ftAjouterArete(ftNouv(), "a", "b", 3), "c", "d", 1);
    ft8 = ftAjouterArete(ftAjouterArete(ft8, "e", "f", 5), "g", "h", 2);
    ft8 = ftSupprimerArete(ft8, "a", "b");

    ft9 = ftAjouterArete(ftAjouterArete(ftNouv(), "a", "b", 3), "c", "d", 1);
    ft9 = ftAjouterArete(ftAjouterArete(ft9, "e", "f", 5), "g", "h", 2);
    ft9 = ftSupprimerArete(ft9, "i", "j");

    return 0;
}

int clean_suiteFileAreteTriee(void)
{
    ft1->arete = aLiberer(ft1->arete);
    free(ft1);
    ft2->arete = aLiberer(ft2->arete);
    free(ft2);
    ft3->arete = aLiberer(ft3->arete);
    free(ft3);
    ft4->arete = aLiberer(ft4->arete);
    free(ft4);

    ft5 = ftLiberer(ft5);
    ft6 = ftLiberer(ft6);
    ft7 = ftLiberer(ft7);
    ft8 = ftLiberer(ft8);
    ft9 = ftLiberer(ft9);

    return 0;
}

void test_filearetetriee_ftNouv(void)
{
    CU_ASSERT(ftEstVide(ftNouv()) == VRAI);
    CU_ASSERT(ftNombreAretes(ftNouv()) == 0);
}

void test_filearetetriee_ftAjouterArete(void)
{
    CU_ASSERT(ftEstVide(ft5) == FAUX);
    CU_ASSERT(ftNombreAretes(ft5) == 4);
    CU_ASSERT(ftExisteArete(ft5, "a", "b") == VRAI);
    CU_ASSERT(ftExisteArete(ft5, "c", "d") == VRAI);
    CU_ASSERT(ftExisteArete(ft5, "e", "f") == VRAI);
    CU_ASSERT(ftExisteArete(ft5, "g", "h") == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ft5), "c", "d", 1) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ft5)), "g", "h", 2) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ftSuivante(ft5))), "a", "b", 3) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ftSuivante(ftSuivante(ft5)))), "e", "f", 5) == VRAI);
}

void test_filearetetriee_ftSupprimerTete(void)
{
    CU_ASSERT(ftEstVide(ft6) == FAUX);
    CU_ASSERT(ftNombreAretes(ft6) == 3);
    CU_ASSERT(ftExisteArete(ft6, "a", "b") == VRAI);
    CU_ASSERT(ftExisteArete(ft6, "c", "d") == FAUX);
    CU_ASSERT(ftExisteArete(ft6, "e", "f") == VRAI);
    CU_ASSERT(ftExisteArete(ft6, "g", "h") == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ft6), "c", "d", 1) == FAUX);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ft6), "g", "h", 2) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ft6)), "a", "b", 3) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ftSuivante(ft6))), "e", "f", 5) == VRAI);

    CU_ASSERT(ftEstVide(ft7) == VRAI);
}

void test_filearetetriee_ftSupprimerArete(void)
{
    CU_ASSERT(ftEstVide(ft8) == FAUX);
    CU_ASSERT(ftNombreAretes(ft8) == 3);
    CU_ASSERT(ftExisteArete(ft8, "a", "b") == FAUX);
    CU_ASSERT(ftExisteArete(ft8, "c", "d") == VRAI);
    CU_ASSERT(ftExisteArete(ft8, "e", "f") == VRAI);
    CU_ASSERT(ftExisteArete(ft8, "g", "h") == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ft8), "c", "d", 1) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ft8)), "g", "h", 2) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ftSuivante(ft8))), "a", "b", 3) == FAUX);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ftSuivante(ft8))), "e", "f", 5) == VRAI);

    CU_ASSERT(ftEstVide(ft9) == FAUX);
    CU_ASSERT(ftNombreAretes(ft9) == 4);
    CU_ASSERT(ftExisteArete(ft9, "a", "b") == VRAI);
    CU_ASSERT(ftExisteArete(ft9, "c", "d") == VRAI);
    CU_ASSERT(ftExisteArete(ft9, "e", "f") == VRAI);
    CU_ASSERT(ftExisteArete(ft9, "g", "h") == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ft9), "c", "d", 1) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ft9)), "g", "h", 2) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ftSuivante(ft9))), "a", "b", 3) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ftSuivante(ftSuivante(ftSuivante(ft9)))), "e", "f", 5) == VRAI);
}

void test_filearetetriee_ftEstVide(void)
{
    CU_ASSERT(ftEstVide(ft0) == VRAI);
    CU_ASSERT(ftEstVide(ft1) == FAUX);
    CU_ASSERT(ftEstVide(ft2) == FAUX);
    CU_ASSERT(ftEstVide(ft3) == FAUX);
    CU_ASSERT(ftEstVide(ft4) == FAUX);
}

void test_filearetetriee_ftExisteArete(void)
{
    CU_ASSERT(ftExisteArete(ft0, "a", "b") == FAUX);
    CU_ASSERT(ftExisteArete(ft1, "a", "b") == VRAI);
    CU_ASSERT(ftExisteArete(ft4, "a", "b") == VRAI);
    CU_ASSERT(ftExisteArete(ft4, "c", "d") == VRAI);
    CU_ASSERT(ftExisteArete(ft4, "e", "f") == VRAI);
    CU_ASSERT(ftExisteArete(ft3, "a", "b") == FAUX);
    CU_ASSERT(ftExisteArete(ft3, "c", "d") == VRAI);
    CU_ASSERT(ftExisteArete(ft3, "e", "f") == VRAI);
    CU_ASSERT(ftExisteArete(ft2, "a", "b") == FAUX);
    CU_ASSERT(ftExisteArete(ft2, "c", "d") == FAUX);
    CU_ASSERT(ftExisteArete(ft2, "e", "f") == VRAI);

    CU_ASSERT(ftExisteArete(ft0, "b", "a") == FAUX);
    CU_ASSERT(ftExisteArete(ft1, "b", "a") == VRAI);
    CU_ASSERT(ftExisteArete(ft4, "b", "a") == VRAI);
    CU_ASSERT(ftExisteArete(ft4, "d", "c") == VRAI);
    CU_ASSERT(ftExisteArete(ft4, "f", "e") == VRAI);
    CU_ASSERT(ftExisteArete(ft3, "b", "a") == FAUX);
    CU_ASSERT(ftExisteArete(ft3, "d", "c") == VRAI);
    CU_ASSERT(ftExisteArete(ft3, "f", "e") == VRAI);
    CU_ASSERT(ftExisteArete(ft2, "b", "a") == FAUX);
    CU_ASSERT(ftExisteArete(ft2, "d", "c") == FAUX);
    CU_ASSERT(ftExisteArete(ft2, "f", "e") == VRAI);
}

void test_filearetetriee_ftNombreAretes(void)
{
    CU_ASSERT(ftNombreAretes(ft0) == 0);
    CU_ASSERT(ftNombreAretes(ft1) == 1);
    CU_ASSERT(ftNombreAretes(ft2) == 1);
    CU_ASSERT(ftNombreAretes(ft3) == 2);
    CU_ASSERT(ftNombreAretes(ft4) == 3);
}

void test_filearetetriee_ftAreteTete(void)
{
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ft1), "a", "b", 1) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ft2), "e", "f", 8) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ft3), "c", "d", 4) == VRAI);
    CU_ASSERT(aAreteEgaleP(ftAreteTete(ft4), "a", "b", 1) == VRAI);
    CU_ASSERT(aAreteEgaleS(ftAreteTete(ft4), "c", "d") == FAUX);
    CU_ASSERT(aAreteEgaleS(ftAreteTete(ft4), "e", "f") == FAUX);
    CU_ASSERT(aAreteEgaleS(ftAreteTete(ft3), "e", "f") == FAUX);
    CU_ASSERT(aAreteEgaleS(ftAreteTete(ft3), "a", "b") == FAUX);
    CU_ASSERT(aAreteEgaleS(ftAreteTete(ft2), "c", "d") == FAUX);
    CU_ASSERT(aAreteEgaleS(ftAreteTete(ft2), "a", "b") == FAUX);
}

void test_filearetetriee_ftSuivante(void)
{
    CU_ASSERT(ftSuivante(ft0) == NULL);
    CU_ASSERT(ftSuivante(ft1) == NULL);
    CU_ASSERT(ftSuivante(ft2) == NULL);
    CU_ASSERT(ftSuivante(ft3) == ft2);
    CU_ASSERT(ftSuivante(ft4) == ft3);
}

int add_testFileAreteTriee(void)
{
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("Tests Files Triées", init_suiteFileAreteTriee, clean_suiteFileAreteTriee);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "ftNouv", test_filearetetriee_ftNouv) == NULL
        || CU_add_test(pSuite, "ftEstVide", test_filearetetriee_ftEstVide) == NULL
        || CU_add_test(pSuite, "ftExisteArete", test_filearetetriee_ftExisteArete) == NULL
        || CU_add_test(pSuite, "ftNombreAretes", test_filearetetriee_ftNombreAretes) == NULL
        || CU_add_test(pSuite, "ftAreteTete", test_filearetetriee_ftAreteTete) == NULL
        || CU_add_test(pSuite, "ftSuivante", test_filearetetriee_ftSuivante) == NULL
        || CU_add_test(pSuite, "ftAjouterArete", test_filearetetriee_ftAjouterArete) == NULL
        || CU_add_test(pSuite, "ftSupprimerTete", test_filearetetriee_ftSupprimerTete) == NULL
        || CU_add_test(pSuite, "ftSupprimerArete", test_filearetetriee_ftSupprimerArete) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
