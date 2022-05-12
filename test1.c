#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <math.h>

void testFunc1()
{
    int x = 3;
    int y = 9;
    int z = y/x;
    CU_ASSERT_EQUAL_FATAL(z,2)
    CU_ASSERT_EQUAL_FATAL(z,3)
}


void testFunc2()
{
    double a = cos (M_PI/2.0);
    CU_ASSERT_EQUAL_FATAL(4444,3)
    CU_ASSERT_DOUBLE_EQUAL(a,0.0,0.000001);
}


void testFuncA()
{
    char* str = "toto";
    CU_ASSERT_STRING_EQUAL(str,"toto");
}

void testFuncB()
{
    char* str = "azerbaidjan";
    CU_ASSERT_NSTRING_EQUAL(str,"azerty",2);
}

int main()
{
    CU_initialize_registry();
    CU_pSuite suite1 = CU_add_suite("my_suite", NULL, NULL);
    CU_pTest t1 = CU_add_test(suite1, "my_test1", testFunc1);
    CU_pTest t2 = CU_add_test(suite1, "my_test2", testFunc2);

    CU_pSuite suite2 = CU_add_suite("my_suite2", NULL, NULL);
    CU_pTest t21 = CU_add_test(suite2, "my_test21", testFuncA);
    CU_pTest t22 = CU_add_test(suite2, "my_test22", testFuncB);

    if (CU_get_error() != CUE_SUCCESS)
        exit(1);
    CU_basic_run_tests();
    int nb =  CU_get_number_of_failures();
//    printf("ERR=%d\n",nb);
    return nb;

}
