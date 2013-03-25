#ifndef __TESTLISTE_H
#define __TESTLISTE_H

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "sommet.h"
#include "liste.h"

int init_suiteListe(void);

int clean_suiteListe(void);

void test_liste_listnouv(void);

void test_liste_lsommet_tete(void);

void test_liste_lpoids_tete(void);

void test_liste_lsuiv(void);

void test_liste_ltaille(void);

void test_liste_lexar(void);

void test_liste_lpoids(void);

void test_liste_lajar(void);

void test_liste_lliberer(void);

void test_liste_lcopie(void);

void test_liste_lmod(void);

void test_liste_lega(void);

int add_testliste(void);

#endif /* __TESTLISTE_H */
