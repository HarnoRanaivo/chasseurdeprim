#ifndef __TESTSOMMET_H
#define __TESTSOMMET_H

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "sommet.h"

int init_suiteSommet(void);

int clean_suiteSommet(void);

void test_sommet_egalSom(void);

int add_testsommets(void);

#endif /* __TESTSOMMET_H */
