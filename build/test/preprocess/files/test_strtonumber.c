#include "build/temp/_test_strtonumber.c"
#include "CException.h"
#include "strtonumber.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_openHexfile_with_not_existing_file_adderss_result_should_return_0(void){

  FILE *result;

  result = openHexFile("data");



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((result)), (

 ((void *)0)

 ), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_INT);

}



void test_openHexfile_with_existing_file_adderss_result_should_return_exactAddress(void){

  FILE *fileHandler;

  fileHandler = fopen("Data/STM32_Bootloader.hex", "r");



  FILE *result;

  result = openHexFile("Data/STM32_Bootloader.hex");



  UnityAssertEqualNumber((UNITY_INT)((fileHandler)), (UNITY_INT)((result)), (

 ((void *)0)

 ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);

}



void test_read_line_Hex_file_should_read_1_line_of_data(void){

  FILE *fileHandler;

  fileHandler = openHexFile("Data/STM32_Bootloader.hex");



  char *data = readLine(fileHandler);



  UnityAssertEqualString((const char*)((":020000040800F2\n")), (const char*)((data)), (

 ((void *)0)

 ), (UNITY_UINT)(34));

}



void test_verify_Hex_line_with_correct_check_sum_should_return_1(void){

  char *data = (":020000040800F2\n");

  int SumOfLine = verifyHexLine(data);



  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((SumOfLine)), (

 ((void *)0)

 ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

}



void test_verify_Hex_line_with_wrong_check_sum_should_return_0(void){

  char *data = (":020000040800F3\n");

  int SumOfLine = verifyHexLine(data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((SumOfLine)), (

 ((void *)0)

 ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

}



void test_verify_Hex_line_with_wrong_Checksum_should_return_0(void){

  char *data = (":021E\n");

  int SumOfLine = verifyHexLine(data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((SumOfLine)), (

 ((void *)0)

 ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);

}



void test_verify_Hex_line_with_invalid_checksum_should_return_0(void){

  char *data = (":10F040\n");

  int SumOfLine = verifyHexLine(data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((SumOfLine)), (

 ((void *)0)

 ), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT);

}



void xtest_convert_ascii_digits_to_string_of_number_should_retrun_data(void){

  FILE *fileHandler;

  fileHandler = fopen("Data/STM32_Bootloader.hex", "r");

  char *data = readLine(fileHandler);



  uint8_t *StrOfNum = convertHexLineToStrOfNum(data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((StrOfNum)), (

 ((void *)0)

 ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_INT);

}
