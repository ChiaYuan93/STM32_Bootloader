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
extern void test_openHexfile_with_not_existing_file_adderss_result_should_return_0(void);
extern void test_readLine_Hex_file_should_read_1_line_of_data(void);
extern void test_verifyHexLine_with_correct_check_sum_should_return_1(void);
extern void test_verifyHexLine_with_wrong_check_sum_should_return_0(void);
extern void test_verifyHexLine_with_wrong_Checksum_should_return_0(void);
extern void test_verifyHexLine_with_invalid_checksum_should_return_0(void);
extern void test_convert_ascii_digits_to_string_of_number_should_retrun_data(void);
extern void test_convertHexLineToStrOfNum_with_full_ascii_data_should_return_string_of_number(void);
extern void test_getHexLineLength_should_return_first_byte_of_data_from_strOfNum(void);
extern void test_getHexLineAddress_should_return_16_bits_of_address_from_strOfNum(void);


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
  RUN_TEST(test_openHexfile_with_not_existing_file_adderss_result_should_return_0, 11);
  RUN_TEST(test_readLine_Hex_file_should_read_1_line_of_data, 18);
  RUN_TEST(test_verifyHexLine_with_correct_check_sum_should_return_1, 27);
  RUN_TEST(test_verifyHexLine_with_wrong_check_sum_should_return_0, 34);
  RUN_TEST(test_verifyHexLine_with_wrong_Checksum_should_return_0, 41);
  RUN_TEST(test_verifyHexLine_with_invalid_checksum_should_return_0, 48);
  RUN_TEST(test_convert_ascii_digits_to_string_of_number_should_retrun_data, 55);
  RUN_TEST(test_convertHexLineToStrOfNum_with_full_ascii_data_should_return_string_of_number, 64);
  RUN_TEST(test_getHexLineLength_should_return_first_byte_of_data_from_strOfNum, 82);
  RUN_TEST(test_getHexLineAddress_should_return_16_bits_of_address_from_strOfNum, 91);

  return (UnityEnd());
}
