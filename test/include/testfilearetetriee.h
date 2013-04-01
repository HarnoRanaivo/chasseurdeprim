#ifndef __TESTFILEARETETREEe_H
#define __TESTFILEARETETRIEE_H

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "sommet.h"
#include "arete.h"
#include "filearetetriee.h"

int init_suiteFileAreteTriee(void);

int clean_suiteFileAreteTriee(void);

void test_filearetetriee_ftNouv(void);

void test_filearetetriee_ftAjouterArete(void);

void test_filearetetriee_ftSupprimerTete(void);

void test_filearetetriee_ftSupprimerArete(void);

void test_filearetetriee_ftEstVide(void);

void test_filearetetriee_ftExisteArete(void);

void test_filearetetriee_ftNombreAretes(void);

void test_filearetetriee_ftAreteTete(void);

void test_filearetetriee_ftSuivante(void);

int add_testFileAreteTriee(void);

#endif /* __TESTFILEARETETRIEE_H */
