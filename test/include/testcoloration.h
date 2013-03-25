#ifndef __TESTCOLORATION_H
#define __TESTCOLORATION_H

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "sommet.h"
#include "graphe.h"
#include "coloration.h"

int init_suiteColoration(void);

int clean_suiteColoration(void);

void test_couleursgraphe_cgNouv(void);

void test_couleursgraphe_cgAjouterSommet(void);

void test_couleursgraphe_cgSupprimerTete(void);

void test_couleursgraphe_cgSupprimerSommet(void);

void test_couleursgraphe_cgModifierSommet(void);

void test_couleursgraphe_cgInit(void);

void test_couleursgraphe_cgEstVide(void);

void test_couleursgraphe_cgSuivant(void);

void test_couleursgraphe_cgSommetTete(void);

void test_couleursgraphe_cgCouleurTete(void);

void test_couleursgraphe_cgCouleurSommet(void);

void test_couleursgraphe_cgPremierSommetNoir(void);

void test_couleursgraphe_cgPremierSommetGris(void);

void test_couleursgraphe_cgPremierSommetBlanc(void);

void test_couleursgraphe_cgNombreSommetsNoirs(void);

void test_couleursgraphe_cgNombreSommetsGris(void);

void test_couleursgraphe_cgNombreSommetsBlancs(void);

void test_couleursgraphe_cgPSommet(void);

int add_testcoloration(void);

#endif /* __TESTCOLORATION_H */
