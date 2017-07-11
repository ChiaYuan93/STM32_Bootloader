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



void test_readLine_Hex_file_should_read_1_line_of_data(void){

  FILE *fileHandler;

  fileHandler = openHexFile("Data/STM32_Bootloader.hex");



  char *data = readLine(fileHandler);



  UnityAssertEqualString((const char*)((":020000040800F2\n")), (const char*)((data)), (

 ((void *)0)

 ), (UNITY_UINT)(24));

}



void test_verifyHexLine_with_correct_check_sum_should_return_1(void){

  char *data = (":020000040800F2\n");

  int SumOfLine = verifyHexLine(data);



  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((SumOfLine)), (

 ((void *)0)

 ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

}



void test_verifyHexLine_with_wrong_check_sum_should_return_0(void){

  char *data = (":020000040800F3\n");

  int SumOfLine = verifyHexLine(data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((SumOfLine)), (

 ((void *)0)

 ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

}



void test_verifyHexLine_with_wrong_Checksum_should_return_0(void){

  char *data = (":021E\n");

  int SumOfLine = verifyHexLine(data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((SumOfLine)), (

 ((void *)0)

 ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);

}



void test_verifyHexLine_with_invalid_checksum_should_return_0(void){

  char *data = (":10F040\n");

  int SumOfLine = verifyHexLine(data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((SumOfLine)), (

 ((void *)0)

 ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);

}



void test_convert_ascii_digits_to_string_of_number_should_retrun_data(void){

  char *data = (":1030C0\n");

  uint8_t expectedArray[3] = {0x10, 0x30, 0xC0};



  uint8_t *StrOfNum = convertHexLineToStrOfNum(data);



  UnityAssertEqualIntArray(( const void*)((expectedArray)), ( const void*)((StrOfNum)), (UNITY_UINT32)((3)), (

 ((void *)0)

 ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_convertHexLineToStrOfNum_with_full_ascii_data_should_return_string_of_number(void){

  char *data = (":100000000050002069010008A9030008AD030008A2\n");

  uint8_t expectedArray[] = {0x10,0x00,0x00,0x00,0x00,0x50,0x00,0x20,0x69,0x01,0x00,0x08,0xA9,0x03,0x00,0x08,0xAD,0x03,0x00,0x08,0xA2};



  uint8_t *StrOfNum = convertHexLineToStrOfNum(data);



  UnityAssertEqualIntArray(( const void*)((expectedArray)), ( const void*)((StrOfNum)), (UNITY_UINT32)((21)), (

 ((void *)0)

 ), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void xtest_wrong_converting_ascii_digits_to_string_of_number_should_throw_exception(void){

  char *data = (":1030C0\n");

  uint8_t expectedArray[3] = {0x20, 0x30, 0xC0};



  uint8_t *StrOfNum = convertHexLineToStrOfNum(data);



  UnityAssertEqualIntArray(( const void*)((expectedArray)), ( const void*)((StrOfNum)), (UNITY_UINT32)((3)), (

 ((void *)0)

 ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_getHexLineLength_should_return_first_byte_of_data_from_strOfNum(void){

  char *data = (":0C12E2\n");

  uint8_t *StrOfNum = convertHexLineToStrOfNum(data);



  int LineLength = getHexLineLength(StrOfNum);



  UnityAssertEqualNumber((UNITY_INT)((0x0C)), (UNITY_INT)((LineLength)), (

 ((void *)0)

 ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);

}



void test_getHexLineAddress_should_return_16_bits_of_address_from_strOfNum(void){

  char *data = (":0224620408006C\n");

  uint8_t *StrOfNum = convertHexLineToStrOfNum(data);



  int LineAddress = getHexLineAddress(StrOfNum);



  UnityAssertEqualNumber((UNITY_INT)((0x2462)), (UNITY_INT)((LineAddress)), (

 ((void *)0)

 ), (UNITY_UINT)(97), UNITY_DISPLAY_STYLE_INT);

}
