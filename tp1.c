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

  CU_ASSERT_TRUE( validerTH_1( (unsigned) 170 ) && validerTH_1( (unsigned) 400 ) );
}

void validerTH_Deux(void) {

  CU_ASSERT_TRUE( validerTH_2( (unsigned char) 17 ) && validerTH_2( (unsigned char) 40 ) );
  CU_ASSERT_TRUE( validerTH_2( '(' ) );
  CU_ASSERT_FALSE( validerTH_2( 0 ) );
  CU_ASSERT_FALSE( validerTH_2( -17 ) );
  CU_ASSERT_FALSE( validerTH_2( -40 ) );
}

void validerTH_Trois(void) { 

  CU_ASSERT_TRUE( validerTH_3( 170 ) );
  CU_ASSERT_TRUE( validerTH_3( 400 ) );
  CU_ASSERT_TRUE( validerTH_3( 171 ) && validerTH_3( 399 ) );
  CU_ASSERT_FALSE( validerTH_3( (short) 17 ) && validerTH_3( (short) 40 ) );
  CU_ASSERT_FALSE( validerTH_3( 0 ) );
  CU_ASSERT_FALSE( validerTH_3( -171 ) );
  CU_ASSERT_FALSE( validerTH_3( -401 ) );
}

void validerTA_Un(void) {

  CU_ASSERT_TRUE( validerTA_1( (signed int) -40 ) && validerTA_1( (signed int) 40 ) );
  CU_ASSERT_FALSE( validerTA_1( -41 ) && validerTA_1( 41 ) );
}  

void validerTA_Deux(void) {

  CU_ASSERT_TRUE( validerTA_2( '(' ) && validerTA_2( '(' ) );
  CU_ASSERT_TRUE( validerTA_2( '!' ) && validerTA_2( '!' ) );
  CU_ASSERT_FALSE( validerTA_2( 127 ) );
}

void validerTA_Trois(void) {

  CU_ASSERT_TRUE( validerTA_3( -400 ) && validerTA_3( 400 ) );
  CU_ASSERT_FALSE( validerTA_3( -408 ) && validerTA_3( 401 ) );
}

void validerPU_Un(void) {

  CU_ASSERT_TRUE( validerPulsation_1( (unsigned)50 ) && validerPulsation_1( (unsigned) 200 ) );
  CU_ASSERT_FALSE( validerPulsation_1( (unsigned)49 ) && validerPulsation_1( (unsigned) 201 ) );
}

void validerPU_Deux(void) {

  CU_ASSERT_TRUE( validerPulsation_2( (unsigned) 50 ) && validerPulsation_2( (unsigned char) 200 ) );
  CU_ASSERT_FALSE( validerPulsation_2( (unsigned) 49 ) && validerPulsation_2( (unsigned char) 201 ) );
  CU_ASSERT_TRUE( validerPulsation_2( '2' ) && validerPulsation_2( (unsigned char) 200 ) );
}

void validerPU_Trois(void) {

  CU_ASSERT_TRUE( validerPulsation_3( 50 ) && validerPulsation_3( 200 ) );
  CU_ASSERT_FALSE( validerPulsation_3( 49 ) && validerPulsation_3( 201 ) );
}

void validerSign_Un(void) {

  CU_ASSERT_TRUE( validerSignal_1(-85 ) && validerSignal_1( -25 ) );
  CU_ASSERT_FALSE( validerSignal_1( (signed)-86 ) && validerSignal_1( (signed)-24 ) );
}

void validerSign_Deux(void) {

  CU_ASSERT_TRUE( validerSignal_2( (signed) -85 ) && validerSignal_2( (signed) -25 ) );
  CU_ASSERT_FALSE( validerSignal_2( (signed) -86 ) && validerSignal_2( (signed) -24 ) );
}

void validerSign_Trois(void) {

  CU_ASSERT_TRUE( validerSignal_3( -850 ) && validerSignal_3( -250 ) );
  CU_ASSERT_TRUE( validerSignal_3( -85 ) && validerSignal_3( -25 ) );
  CU_ASSERT_FALSE( validerSignal_3( -860 ) && validerSignal_3( -240 ) );
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
	(NULL == CU_add_test(pSuite, "validerTH_2", validerTH_Deux ) ) ||
	(NULL == CU_add_test(pSuite, "validerTH_3", validerTH_Trois ) ) ||
	(NULL == CU_add_test(pSuite, "validerTA_1", validerTA_Un ) ) ||
	(NULL == CU_add_test(pSuite, "validerTA_2", validerTA_Deux ) ) ||
	(NULL == CU_add_test(pSuite, "validerTA_3", validerTA_Trois ) ) ||
	(NULL == CU_add_test(pSuite, "validerPulsation_1", validerPU_Un ) ) ||
	(NULL == CU_add_test(pSuite, "validerPulsation_2", validerPU_Deux ) ) ||
	(NULL == CU_add_test(pSuite, "validerPulsation_3", validerPU_Trois ) ) ||
	(NULL == CU_add_test(pSuite, "validerSignal_1", validerSign_Un ) ) ||
	(NULL == CU_add_test(pSuite, "validerSignal_2", validerSign_Deux ) ) ||
	(NULL == CU_add_test(pSuite, "validerSignal_3", validerSign_Trois ) ) )
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
