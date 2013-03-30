#ifndef __TESTFILETRIEE_H
#define __TESTFILETRIEE_H

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "sommet.h"
#include "arete.h"
#include "filetriee.h"

int init_suiteFileTriee(void);

int clean_suiteFileTriee(void);

void test_filetriee_ftNouv(void);

void test_filetriee_ftAjouterArete(void);

void test_filetriee_ftSupprimerTete(void);

void test_filetriee_ftSupprimerArete(void);

void test_filetriee_ftEstVide(void);

void test_filetriee_ftExisteArete(void);

void test_filetriee_ftNombreAretes(void);

void test_filetriee_ftAreteTete(void);

void test_filetriee_ftSuivante(void);

int add_testfiletriee(void);

#endif /* __TESTFILETRIEE_H */
