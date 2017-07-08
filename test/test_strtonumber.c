#include <stdint.h>
#include <stdio.h>
#include "unity.h"
#include "strtonumber.h"
#include "CException.h"

void setUp(void){}

void tearDown(void){}

void test_openHexfile_with_not_existing_file_adderss_result_should_return_0(void){
  FILE *result;
  result = openHexFile("data");
  
  TEST_ASSERT_EQUAL(0, result);
}

void test_openHexfile_with_existing_file_adderss_result_should_return_exactAddress(void){
  FILE *fileHandler;
  fileHandler = fopen("Data/STM32_Bootloader.hex", "r");
  
  FILE *result;
  result = openHexFile("Data/STM32_Bootloader.hex");
  
  TEST_ASSERT_EQUAL(fileHandler, result);
}

void test_read_line_Hex_file_should_read_1_line_of_data(void){
  FILE *fileHandler;
  fileHandler = openHexFile("Data/STM32_Bootloader.hex");
  
  char *data = readLine(fileHandler);
  
  TEST_ASSERT_EQUAL_STRING(":020000040800F2\n", data);
}

void test_verify_Hex_line_with_correct_check_sum_should_return_1(void){
  char *data = (":020000040800F2\n");  
  int SumOfLine = verifyHexLine(data);
  
  TEST_ASSERT_EQUAL(1, SumOfLine);
}

void test_verify_Hex_line_with_wrong_check_sum_should_return_0(void){
  char *data = (":020000040800F3\n");
  int SumOfLine = verifyHexLine(data);
  
  TEST_ASSERT_EQUAL(0, SumOfLine);
}

void test_verify_Hex_line_with_wrong_Checksum_should_return_0(void){
  char *data = (":021E\n");  
  int SumOfLine = verifyHexLine(data);
  
  TEST_ASSERT_EQUAL(0, SumOfLine);
}

void test_verify_Hex_line_with_invalid_checksum_should_return_0(void){
  char *data = (":10F040\n");  
  int SumOfLine = verifyHexLine(data);
  
  TEST_ASSERT_EQUAL(0, SumOfLine);
}

void xtest_convert_ascii_digits_to_string_of_number_should_retrun_data(void){
  FILE *fileHandler;
  fileHandler = fopen("Data/STM32_Bootloader.hex", "r");
  char *data = readLine(fileHandler);
  
  uint8_t *StrOfNum = convertHexLineToStrOfNum(data);
  
  TEST_ASSERT_EQUAL(0, StrOfNum);
}











