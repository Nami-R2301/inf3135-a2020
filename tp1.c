#include "Basic.h"
#include "tcv.h"         // declarations des fonctions tests
#include <stdio.h>

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/********************* NOS fonctions de tests *********************/
/*
void test_case_exemple(void)
{
   // Les types d'assertions disponibles
   CU_ASSERT(CU_TRUE);
   CU_ASSERT_NOT_EQUAL(2, -1);
   CU_ASSERT_STRING_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #2");

   CU_ASSERT(CU_FALSE);
   CU_ASSERT_EQUAL(2, 3);
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_EQUAL("string #1", "string #2");
}
*/

void validerTH_Un(void) {

//  CU_ASSERT_TRUE( validerTH_1( 17 ) && validerTH_1( 18 ) && validerTH_1( 19 ) && validerTH_1( 20 ) && validerTH_1( 21 ) && validerTH_1( 22 ) &&
//  validerTH_1( 23 ) && validerTH_1( 24 ) && validerTH_1( 25 ) && validerTH_1( 26 ) && validerTH_1( 27 ) && validerTH_1( 28 ) && validerTH_1( 29 ) &&
//  validerTH_1( 30 ) && validerTH_1( 31 ) && validerTH_1( 32 ) && validerTH_1( 33 ) && validerTH_1( 34 ) && validerTH_1( 35 ) && validerTH_1( 36 ) &&
//  validerTH_1( 37 ) && validerTH_1( 38 ) && validerTH_1( 39 ) && validerTH_1( 40 ) );

  CU_ASSERT_FALSE( validerTH_1( 0 ) && validerTH_1( -17 ) && validerTH_1( -40 ) );
}

void validerTH_Deux(void) {

  CU_ASSERT_FALSE( validerTH_1( 0 ) && validerTH_1( -17 ) && validerTH_1( -40 ) );
}

int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite( "tp1_suite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ( (NULL == CU_add_test(pSuite, "validerTH_1", validerTH_Un ) ) ||
	(NULL == CU_add_test(pSuite, "validerTH_2", validerTH_Deux ) ) )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   // Run all tests using the basic interface
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests(); 
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");


   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}
