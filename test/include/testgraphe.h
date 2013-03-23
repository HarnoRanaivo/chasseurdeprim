#ifndef __TESTGRAPHE_H
#define __TESTGRAPHE_H

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "graphe.h"

int init_suiteGraphe(void);

int clean_suiteGraphe(void);

void test_graphe_gNouv(void);

void test_graphegEstVide(void);

void test_graphe_gExisteSommet(void);

void test_graphe_gAArete(void);

void test_graphe_gExisteArete(void);

void test_graphe_gAdjacenceSommet(void);

void test_graphe_gNombreSommets(void);

void test_graphe_gNombreAretes(void);

void test_graphe_gNombreVoisins(void);

void test_graphe_gPSommet(void);

void test_graphe_gAjoutSommet(void);

void test_graphe_gAjoutArete(void);

void test_graphe_gSupprimerSommet(void);

void test_graphe_gSupprimerArete(void);

void test_graphe_gModifierArete(void);

void test_graphe_gCopie(void);

void test_graphe_gLiberer(void);

int add_testgraphe(void);

#endif /* __TESTGRAPHE_H */
