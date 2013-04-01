#include "testlistearete.h"

static ListeArete * lar0 = NULL;
static ListeArete * lar1 = NULL;
static ListeArete * lar2 = NULL;
static ListeArete * lar3 = NULL;
static ListeArete * lar4 = NULL;
static ListeArete * lar5 = NULL;
static ListeArete * lar6 = NULL;
static ListeArete * lar7 = NULL;
static ListeArete * lar8 = NULL;
static ListeArete * lar9 = NULL;

int init_suiteListeArete(void)
{
    lar0 = NULL;

    lar1 = MALLOC(lar1);
    lar1->arete = aNouv("a", "b", 1);
    lar1->suivante = NULL;

    lar2 = MALLOC(lar2);
    lar2->arete = aNouv("e", "f", 8);
    lar2->suivante = NULL;

    lar3 = MALLOC(lar3);
    lar3->arete = aNouv("c", "d", 4);
    lar3->suivante = lar2;

    lar4 = MALLOC(lar4);
    lar4->arete = aNouv("a", "b", 1);
    lar4->suivante = lar3;

    lar5 = larAjouterAreteTete(larAjouterAreteTete(larNouv(), "a", "b", 3), "c", "d", 1);
    lar5 = larAjouterAreteTete(larAjouterAreteTete(lar5, "e", "f", 5), "g", "h", 2);

    lar6 = larAjouterAreteTete(larAjouterAreteTete(larNouv(), "a", "b", 3), "c", "d", 1);
    lar6 = larAjouterAreteTete(larAjouterAreteTete(lar6, "e", "f", 5), "g", "h", 2);
    lar6 = larSupprimerTete(lar6);

    lar7 = larAjouterAreteTete(larAjouterAreteTete(larNouv(), "a", "b", 3), "c", "d", 1);
    lar7 = larAjouterAreteTete(larAjouterAreteTete(lar7, "e", "f", 5), "g", "h", 2);
    lar7 = larSupprimerArete(lar7, "e", "f");


    lar8 = larAjouterAreteTete(larAjouterAreteTete(larNouv(), "a", "b", 3), "c", "d", 1);
    lar8 = larAjouterAreteTete(larAjouterAreteTete(lar8, "e", "f", 5), "g", "h", 2);
    lar8 = larSupprimerArete(lar8, "a", "b");

    lar9 = larAjouterAreteTete(larAjouterAreteTete(larNouv(), "a", "b", 3), "c", "d", 1);
    lar9 = larAjouterAreteTete(larAjouterAreteTete(lar9, "e", "f", 5), "g", "h", 2);
    lar9 = larSupprimerArete(lar9, "i", "j");

    return 0;
}

int clean_suiteListeArete(void)
{
    lar1->arete = aLiberer(lar1->arete);
    free(lar1);
    lar2->arete = aLiberer(lar2->arete);
    free(lar2);
    lar3->arete = aLiberer(lar3->arete);
    free(lar3);
    lar4->arete = aLiberer(lar4->arete);
    free(lar4);

    lar5 = larLiberer(lar5);
    lar6 = larLiberer(lar6);
    lar7 = larLiberer(lar7);
    lar8 = larLiberer(lar8);
    lar9 = larLiberer(lar9);

    return 0;
}

void test_listearete_larNouv(void)
{
    CU_ASSERT(larEstVide(larNouv()) == VRAI);
    CU_ASSERT(larNombreAretes(larNouv()) == 0);
}

void test_listearete_larAjouterAreteTete(void)
{
    CU_ASSERT(larEstVide(lar5) == FAUX);
    CU_ASSERT(larNombreAretes(lar5) == 4);
    CU_ASSERT(larExisteArete(lar5, "a", "b") == VRAI);
    CU_ASSERT(larExisteArete(lar5, "c", "d") == VRAI);
    CU_ASSERT(larExisteArete(lar5, "e", "f") == VRAI);
    CU_ASSERT(larExisteArete(lar5, "g", "h") == VRAI);
    CU_ASSERT(aPoids(larAreteTete(larPArete(lar5, "a", "b"))) == 3);
    CU_ASSERT(aPoids(larAreteTete(larPArete(lar5, "c", "d"))) == 1);
    CU_ASSERT(aPoids(larAreteTete(larPArete(lar5, "e", "f"))) == 5);
    CU_ASSERT(aPoids(larAreteTete(larPArete(lar5, "g", "h"))) == 2);
    CU_ASSERT(aAreteEgaleP(larAreteTete(lar5), "g", "h", 2) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(lar5)), "e", "f", 5) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(larSuivante(lar5))), "c", "d", 1) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(larSuivante(larSuivante(lar5)))), "a", "b", 3) == VRAI);
}

void test_listearete_larSupprimerTete(void)
{
    CU_ASSERT(larEstVide(lar6) == FAUX);
    CU_ASSERT(larNombreAretes(lar6) == 3);
    CU_ASSERT(larExisteArete(lar6, "a", "b") == VRAI);
    CU_ASSERT(larExisteArete(lar6, "c", "d") == VRAI);
    CU_ASSERT(larExisteArete(lar6, "e", "f") == VRAI);
    CU_ASSERT(larExisteArete(lar6, "g", "h") == FAUX);
    CU_ASSERT(aAreteEgaleP(larAreteTete(lar6), "g", "h", 2) == FAUX);
    CU_ASSERT(aAreteEgaleP(larAreteTete(lar6), "e", "f", 5) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(lar6)), "c", "d", 1) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(larSuivante(lar6))), "a", "b", 3) == VRAI);
}

void test_listearete_larSupprimerArete(void)
{
    CU_ASSERT(larEstVide(lar7) == FAUX);
    CU_ASSERT(larNombreAretes(lar7) == 3);
    CU_ASSERT(larExisteArete(lar7, "a", "b") == VRAI);
    CU_ASSERT(larExisteArete(lar7, "c", "d") == VRAI);
    CU_ASSERT(larExisteArete(lar7, "e", "f") == FAUX);
    CU_ASSERT(larExisteArete(lar7, "g", "h") == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(lar7), "g", "h", 2) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(lar7)), "e", "f", 5) == FAUX);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(lar7)), "c", "d", 1) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(larSuivante(lar7))), "a", "b", 3) == VRAI);

    CU_ASSERT(larEstVide(lar8) == FAUX);
    CU_ASSERT(larNombreAretes(lar8) == 3);
    CU_ASSERT(larExisteArete(lar8, "a", "b") == FAUX);
    CU_ASSERT(larExisteArete(lar8, "c", "d") == VRAI);
    CU_ASSERT(larExisteArete(lar8, "e", "f") == VRAI);
    CU_ASSERT(larExisteArete(lar8, "g", "h") == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(lar8), "g", "h", 2) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(lar8)), "e", "f", 5) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(larSuivante(lar8))), "c", "d", 1) == VRAI);

    CU_ASSERT(larEstVide(lar9) == FAUX);
    CU_ASSERT(larNombreAretes(lar9) == 4);
    CU_ASSERT(larExisteArete(lar9, "a", "b") == VRAI);
    CU_ASSERT(larExisteArete(lar9, "c", "d") == VRAI);
    CU_ASSERT(larExisteArete(lar9, "e", "f") == VRAI);
    CU_ASSERT(larExisteArete(lar9, "g", "h") == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(lar9), "g", "h", 2) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(lar9)), "e", "f", 5) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(larSuivante(lar9))), "c", "d", 1) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(larSuivante(larSuivante(larSuivante(lar9)))), "a", "b", 3) == VRAI);
}

void test_listearete_larEstVide(void)
{
    CU_ASSERT(larEstVide(lar0) == VRAI);
    CU_ASSERT(larEstVide(lar1) == FAUX);
    CU_ASSERT(larEstVide(lar2) == FAUX);
    CU_ASSERT(larEstVide(lar3) == FAUX);
    CU_ASSERT(larEstVide(lar4) == FAUX);
}

void test_listearete_larExisteArete(void)
{
    CU_ASSERT(larExisteArete(lar0, "a", "b") == FAUX);
    CU_ASSERT(larExisteArete(lar1, "a", "b") == VRAI);
    CU_ASSERT(larExisteArete(lar4, "a", "b") == VRAI);
    CU_ASSERT(larExisteArete(lar4, "c", "d") == VRAI);
    CU_ASSERT(larExisteArete(lar4, "e", "f") == VRAI);
    CU_ASSERT(larExisteArete(lar3, "a", "b") == FAUX);
    CU_ASSERT(larExisteArete(lar3, "c", "d") == VRAI);
    CU_ASSERT(larExisteArete(lar3, "e", "f") == VRAI);
    CU_ASSERT(larExisteArete(lar2, "a", "b") == FAUX);
    CU_ASSERT(larExisteArete(lar2, "c", "d") == FAUX);
    CU_ASSERT(larExisteArete(lar2, "e", "f") == VRAI);

    CU_ASSERT(larExisteArete(lar0, "b", "a") == FAUX);
    CU_ASSERT(larExisteArete(lar1, "b", "a") == VRAI);
    CU_ASSERT(larExisteArete(lar4, "b", "a") == VRAI);
    CU_ASSERT(larExisteArete(lar4, "d", "c") == VRAI);
    CU_ASSERT(larExisteArete(lar4, "f", "e") == VRAI);
    CU_ASSERT(larExisteArete(lar3, "b", "a") == FAUX);
    CU_ASSERT(larExisteArete(lar3, "d", "c") == VRAI);
    CU_ASSERT(larExisteArete(lar3, "f", "e") == VRAI);
    CU_ASSERT(larExisteArete(lar2, "b", "a") == FAUX);
    CU_ASSERT(larExisteArete(lar2, "d", "c") == FAUX);
    CU_ASSERT(larExisteArete(lar2, "f", "e") == VRAI);
}

void test_listearete_larNombreAretes(void)
{
    CU_ASSERT(larNombreAretes(lar0) == 0);
    CU_ASSERT(larNombreAretes(lar1) == 1);
    CU_ASSERT(larNombreAretes(lar2) == 1);
    CU_ASSERT(larNombreAretes(lar3) == 2);
    CU_ASSERT(larNombreAretes(lar4) == 3);
}

void test_listearete_larAreteTete(void)
{
    CU_ASSERT(aAreteEgaleP(larAreteTete(lar1), "a", "b", 1) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(lar2), "e", "f", 8) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(lar3), "c", "d", 4) == VRAI);
    CU_ASSERT(aAreteEgaleP(larAreteTete(lar4), "a", "b", 1) == VRAI);
    CU_ASSERT(aAreteEgaleS(larAreteTete(lar4), "c", "d") == FAUX);
    CU_ASSERT(aAreteEgaleS(larAreteTete(lar4), "e", "f") == FAUX);
    CU_ASSERT(aAreteEgaleS(larAreteTete(lar3), "e", "f") == FAUX);
    CU_ASSERT(aAreteEgaleS(larAreteTete(lar3), "a", "b") == FAUX);
    CU_ASSERT(aAreteEgaleS(larAreteTete(lar2), "c", "d") == FAUX);
    CU_ASSERT(aAreteEgaleS(larAreteTete(lar2), "a", "b") == FAUX);
}

void test_listearete_larSuivante(void)
{
    CU_ASSERT(larSuivante(lar0) == NULL);
    CU_ASSERT(larSuivante(lar1) == NULL);
    CU_ASSERT(larSuivante(lar2) == NULL);
    CU_ASSERT(larSuivante(lar3) == lar2);
    CU_ASSERT(larSuivante(lar4) == lar3);
}

void test_listearete_larPArete(void)
{
    CU_ASSERT(larPArete(lar0, "a", "b") == NULL);
    CU_ASSERT(larPArete(lar1, "a", "b") == lar1);
    CU_ASSERT(larPArete(lar1, "b", "a") == lar1);
    CU_ASSERT(larPArete(lar1, "e", "a") == NULL);
    CU_ASSERT(larPArete(lar1, "a", "e") == NULL);
    CU_ASSERT(larPArete(lar1, "e", "c") == NULL);
    CU_ASSERT(larPArete(lar1, "c", "e") == NULL);

    CU_ASSERT(larPArete(lar4, "e", "f") == lar2);
    CU_ASSERT(larPArete(lar4, "c", "d") == lar3);
    CU_ASSERT(larPArete(lar4, "a", "b") == lar4);
    CU_ASSERT(larPArete(lar3, "e", "f") == lar2);
    CU_ASSERT(larPArete(lar3, "c", "d") == lar3);
    CU_ASSERT(larPArete(lar3, "a", "b") == NULL);
    CU_ASSERT(larPArete(lar2, "e", "f") == lar2);
    CU_ASSERT(larPArete(lar2, "c", "d") == NULL);
    CU_ASSERT(larPArete(lar2, "a", "b") == NULL);
}

int add_testListeArete(void)
{
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("Tests Listes d'Arêtes", init_suiteListeArete, clean_suiteListeArete);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "larNouv", test_listearete_larNouv) == NULL
        || CU_add_test(pSuite, "larEstVide", test_listearete_larEstVide) == NULL
        || CU_add_test(pSuite, "larExisteArete", test_listearete_larExisteArete) == NULL
        || CU_add_test(pSuite, "larNombreAretes", test_listearete_larNombreAretes) == NULL
        || CU_add_test(pSuite, "larAreteTete", test_listearete_larAreteTete) == NULL
        || CU_add_test(pSuite, "larSuivante", test_listearete_larSuivante) == NULL
        || CU_add_test(pSuite, "larAjouterAreteTete", test_listearete_larAjouterAreteTete) == NULL
        || CU_add_test(pSuite, "larSupprimerTete", test_listearete_larSupprimerTete) == NULL
        || CU_add_test(pSuite, "larSupprimerArete", test_listearete_larSupprimerArete) == NULL
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return CU_get_error();
}
