#include "build/temp/_test_strtonumber.c"
#include "CException.h"
#include "strtonumber.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_open_Hex_file_with_not_existing_file_adderss_result_should_return_0(void){

  int result;

  result = openHexFile("data");



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((result)), (

 ((void *)0)

 ), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_INT);

}



void test_open_Hex_file_with_existing_file_adderss_result_should_return_1(void){

  int result;

  result = openHexFile("Data/STM32_Bootloader.hex");



  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((result)), (

 ((void *)0)

 ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);

}



void test_read_line_Hex_file_data_CheckSum_should_return_1(void){

  FILE *fileHandler;

  fileHandler = fopen("Data/STM32_Bootloader.hex", "r");



  char *data = readLine(fileHandler);



  UnityAssertEqualString((const char*)((":020000040800F2\n")), (const char*)((data)), (

 ((void *)0)

 ), (UNITY_UINT)(31));

}



void test_verify_Hex_line_data_should_return_data(void){

  FILE *fileHandler;

  fileHandler = fopen("Data/STM32_Bootloader.hex", "r");

  char *data = readLine(fileHandler);



  int SumOfLine = verifyHexLine(data);



  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((SumOfLine)), (

 ((void *)0)

 ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

}
