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

void validerTH_1_test( void ) {
	CU_ASSERT_EQUAL( validerTH_1 ( 
bool validerTH_1(int);
bool validerTH_2(char);
bool validerTH_3(short);

bool validerTA_1(int);
bool validerTA_2(char);
bool validerTA_3(short);

bool validerPulsation_1(int);
bool validerPulsation_2(char);
bool validerPulsation_3(short);

bool validerSignal_1(int);
bool validerSignal_2(char);
bool validerSignal_3(short);


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
   if ( (NULL == CU_add_test(pSuite, "tp1_1", tp1_un)) ||
        (NULL == CU_add_test(pSuite, "tp1_2", tp1_deux)) ||
        (NULL == CU_add_test(pSuite, "tp1_3", tp1_trois))
      )
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
