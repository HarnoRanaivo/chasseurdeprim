#ifndef __TESTFILEARETETREEe_H
#define __TESTlistearete_H

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "sommet.h"
#include "arete.h"
#include "listearete.h"

int init_suiteListeArete(void);

int clean_suiteListeArete(void);

void test_listearete_larNouv(void);

void test_listearete_larAjouterArete(void);

void test_listearete_larSupprimerTete(void);

void test_listearete_larSupprimerArete(void);

void test_listearete_larEstVide(void);

void test_listearete_larExisteArete(void);

void test_listearete_larNombreAretes(void);

void test_listearete_larAreteTete(void);

void test_listearete_larSuivante(void);

void test_listearete_larPArete(void);

int add_testListeArete(void);

#endif /* __TESTlistearete_H */
