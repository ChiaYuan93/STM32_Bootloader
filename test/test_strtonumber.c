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

void test_readLine_Hex_file_should_read_1_line_of_data(void){
  FILE *fileHandler;
  fileHandler = openHexFile("Data/STM32_Bootloader.hex");
  
  char *data = readLine(fileHandler);
  
  TEST_ASSERT_EQUAL_STRING(":020000040800F2\n", data);
}

void test_verifyHexLine_with_correct_check_sum_should_return_1(void){
  char *data = (":020000040800F2\n");  
  int SumOfLine = verifyHexLine(data);
  
  TEST_ASSERT_EQUAL(1, SumOfLine);
}

void test_verifyHexLine_with_wrong_check_sum_should_return_0(void){
  char *data = (":020000040800F3\n");
  int SumOfLine = verifyHexLine(data);
  
  TEST_ASSERT_EQUAL(0, SumOfLine);
}

void test_verifyHexLine_with_wrong_Checksum_should_return_0(void){
  char *data = (":021E\n");  
  int SumOfLine = verifyHexLine(data);
  
  TEST_ASSERT_EQUAL(0, SumOfLine);
}

void test_verifyHexLine_with_invalid_checksum_should_return_0(void){
  char *data = (":10F040\n");  
  int SumOfLine = verifyHexLine(data);
  
  TEST_ASSERT_EQUAL(0, SumOfLine);
}

void test_convert_ascii_digits_to_string_of_number_should_retrun_data(void){
  char *data = (":1030C0\n");
  uint8_t expectedArray[3] = {0x10, 0x30, 0xC0}; 
  
  uint8_t *StrOfNum = convertHexLineToStrOfNum(data);
  
  TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedArray, StrOfNum, 3);
}

void test_convertHexLineToStrOfNum_with_full_ascii_data_should_return_string_of_number(void){
  char *data = (":100000000050002069010008A9030008AD030008A2\n");
  uint8_t expectedArray[] = {0x10,0x00,0x00,0x00,0x00,0x50,0x00,0x20,0x69,0x01,0x00,0x08,0xA9,0x03,0x00,0x08,0xAD,0x03,0x00,0x08,0xA2}; 
  
  uint8_t *StrOfNum = convertHexLineToStrOfNum(data);
  
  TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedArray, StrOfNum, 21);
}

void xtest_wrong_converting_ascii_digits_to_string_of_number_should_throw_exception(void){
  char *data = (":1030C0\n");
  uint8_t expectedArray[3] = {0x20, 0x30, 0xC0}; 
  
  uint8_t *StrOfNum = convertHexLineToStrOfNum(data);
  
  TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedArray, StrOfNum, 3);
}

void test_getHexLineLength_should_return_first_byte_of_data_from_strOfNum(void){
  char *data = (":0C12E2\n");
  uint8_t *StrOfNum = convertHexLineToStrOfNum(data);
  
  int LineLength = getHexLineLength(StrOfNum);
  
  TEST_ASSERT_EQUAL(0x0C, LineLength);
}

void test_getHexLineAddress_should_return_16_bits_of_address_from_strOfNum(void){
  char *data = (":0224620408006C\n");
  uint8_t *StrOfNum = convertHexLineToStrOfNum(data);
  
  int LineAddress = getHexLineAddress(StrOfNum);
  
  TEST_ASSERT_EQUAL(0x2462, LineAddress);
}








