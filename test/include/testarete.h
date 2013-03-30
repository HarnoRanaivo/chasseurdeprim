#ifndef __TESTARETE_H
#define __TESTARETE_H

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "sommet.h"
#include "arete.h"

int init_suiteArete(void);

int clean_suiteArete(void);

void test_arete_aNouv(void);

void test_arete_aA(void);

void test_arete_aB(void);

void test_arete_aPoids(void);

void test_arete_aAreteEgaleS(void);

void test_arete_aAreteEgaleS2(void);

void test_arete_aAreteEgaleP(void);

void test_arete_aAreteEgaleP2(void);

int add_testarete(void);

#endif /* __TESTARETE_H */
