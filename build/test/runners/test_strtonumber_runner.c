/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      setUp(); \
      TestFunc(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  if (TEST_PROTECT()) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_open_Hex_file_with_not_existing_file_adderss_result_should_return_0(void);
extern void test_open_Hex_file_with_existing_file_adderss_result_should_return_1(void);
extern void test_read_line_Hex_file_data_CheckSum_should_return_1(void);
extern void test_verify_Hex_line_data_should_return_data(void);


/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_strtonumber.c");
  RUN_TEST(test_open_Hex_file_with_not_existing_file_adderss_result_should_return_0, 11);
  RUN_TEST(test_open_Hex_file_with_existing_file_adderss_result_should_return_1, 18);
  RUN_TEST(test_read_line_Hex_file_data_CheckSum_should_return_1, 25);
  RUN_TEST(test_verify_Hex_line_data_should_return_data, 34);

  return (UnityEnd());
}
