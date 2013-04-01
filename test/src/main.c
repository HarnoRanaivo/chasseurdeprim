#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "testsommet.h"
#include "testarete.h"
#include "testadjacence.h"
#include "testgraphe.h"
#include "testcoloration.h"
#include "testparcours.h"
#include "testgrapheconnexe.h"
#include "testfilearetetriee.h"
#include "testprim.h"

int main(int argc, char ** argv)
{
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    add_testSommet();
    add_testArete();
    add_testFileAreteTriee();
    add_testAdjacence();
    add_testGraphe();
    add_testColoration();
    add_testParcours();
    add_testGrapheConnexe();
    add_testPrim();

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
