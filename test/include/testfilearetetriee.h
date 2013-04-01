#ifndef __TESTFILEARETETREEe_H
#define __TESTFILEARETETRIEE_H

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "sommet.h"
#include "arete.h"
#include "listearete.h"
#include "filearetetriee.h"

int init_suiteFileAreteTriee(void);

int clean_suiteFileAreteTriee(void);

void test_filearetetriee_ftNouv(void);

void test_filearetetriee_ftAjouterArete(void);

int add_testFileAreteTriee(void);

#endif /* __TESTFILEARETETRIEE_H */
