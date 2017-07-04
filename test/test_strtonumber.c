#include <stdint.h>
#include <stdio.h>
#include "unity.h"
#include "strtonumber.h"
#include "CException.h"

void setUp(void){}

void tearDown(void){}

void test_open_Hex_file_with_not_existing_file_adderss_result_should_return_0(void){
  int result;
  result = openHexFile("data");
  
  TEST_ASSERT_EQUAL(0, result);
}

void test_open_Hex_file_with_existing_file_adderss_result_should_return_1(void){
  int result;
  result = openHexFile("Data/STM32_Bootloader.hex");
  
  TEST_ASSERT_EQUAL(1, result);
}

void test_read_line_Hex_file_data_CheckSum_should_return_1(void){
  FILE *fileHandler;
  fileHandler = fopen("Data/STM32_Bootloader.hex", "r");
  
  char *data = readLine(fileHandler);
  
  TEST_ASSERT_EQUAL_STRING(":020000040800F2\n", data);
}

void test_verify_Hex_line_data_should_return_data(void){
  FILE *fileHandler;
  fileHandler = fopen("Data/STM32_Bootloader.hex", "r");
  char *data = readLine(fileHandler);
  
  int SumOfLine = verifyHexLine(data);
  
  TEST_ASSERT_EQUAL(1, SumOfLine);
}











