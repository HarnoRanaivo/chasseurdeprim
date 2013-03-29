#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "base.h"
#include "testsommet.h"
#include "testliste.h"
#include "testgraphe.h"
#include "testcoloration.h"
#include "testparcours.h"

int main(int argc, char ** argv)
{
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    add_testsommets();
    add_testliste();
    add_testgraphe();
    add_testcoloration();
    add_testparcours();

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
