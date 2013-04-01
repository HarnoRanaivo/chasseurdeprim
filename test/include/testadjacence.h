#ifndef __TESTADJACENCE_H
#define __TESTADJACENCE_H

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "sommet.h"
#include "adjacence.h"

int init_suiteAdjacence(void);

int clean_suiteAdjacence(void);

void test_adjacence_listnouv(void);

void test_adjacence_lest_vide(void);

void test_adjacence_lsommet_tete(void);

void test_adjacence_lpoids_tete(void);

void test_adjacence_lsuiv(void);

void test_adjacence_ltaille(void);

void test_adjacence_lexar(void);

void test_adjacence_lpoids(void);

void test_adjacence_lajar(void);

void test_adjacence_lliberer(void);

void test_adjacence_lcopie(void);

void test_adjacence_lmod(void);

void test_adjacence_lega(void);

int add_testAdjacence(void);

#endif /* __TESTADJACENCE_H */
