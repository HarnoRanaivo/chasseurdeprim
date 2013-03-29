#ifndef __TESTGRAPHECONNEXE_H
#define __TESTGRAPHECONNEXE_H

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "sommet.h"
#include "liste.h"
#include "graphe.h"
#include "parcours.h"
#include "grapheconnexe.h"

int init_suiteGrapheConnexe(void);

int clean_suiteGrapheConnexe(void);

void test_grapheconnexe_gcNouv(void);

void test_grapheconnexe_gcAjouterSommet(void);

void test_grapheconnexe_gcAjouterArete(void);

void test_grapheconnexe_gcSupprimerSommet(void);

void test_grapheconnexe_gcSupprimerArete(void);

void test_grapheconnexe_gcModifierArete(void);

int add_testgrapheconnexe(void);

#endif /* __TESTGRAPHECONNEXE_H */
