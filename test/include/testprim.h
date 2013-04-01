#ifndef __TESTPRIM_H
#define __TESTPRIM_H

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "sommet.h"
#include "graphe.h"
#include "coloration.h"
#include "filearetetriee.h"
#include "arete.h"
#include "prim.h"
#include "parcours.h"

int init_suitePrim(void);

int clean_suitePrim(void);

void test_prim_pAjouterAretesIncidentes(void);

void test_prim_pArbreCouvrantMinimum(void);

int add_testPrim(void);

#endif /* __TESTPRIM_H */
