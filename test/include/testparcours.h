#ifndef __TESTPARCOURS_H
#define __TESTPARCOURS_H

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "sommet.h"
#include "graphe.h"
#include "coloration.h"
#include "parcours.h"

int init_suiteParcours(void);

int clean_suiteParcours(void);

int add_testparcours(void);

#endif /* __TEST_PARCOURS_H */
