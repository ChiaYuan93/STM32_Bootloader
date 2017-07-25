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

  char *data = ":020000040800F2\n";

  int sumOfLine = verifyHexLine(data);



  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((sumOfLine)), (

 ((void *)0)

 ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

}



void test_verifyHexLine_with_wrong_check_sum_should_return_0(void){

  char *data = ":020000040800F3\n";

  int sumOfLine = verifyHexLine(data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sumOfLine)), (

 ((void *)0)

 ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

}



void test_verifyHexLine_with_wrong_Checksum_should_return_0(void){

  char *data = ":021E\n";

  int sumOfLine = verifyHexLine(data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sumOfLine)), (

 ((void *)0)

 ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);

}



void test_verifyHexLine_with_invalid_checksum_should_return_0(void){

  char *data = ":10F040\n";

  int sumOfLine = verifyHexLine(data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((sumOfLine)), (

 ((void *)0)

 ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);

}



void test_convert_ascii_digits_to_string_of_number_should_retrun_data(void){

  char *data = ":1030C0\n";

  uint8_t expectedArray[3] = {0x10, 0x30, 0xC0};



  uint8_t *strOfNum = convertHexLineToStrOfNum(data);



  UnityAssertEqualIntArray(( const void*)((expectedArray)), ( const void*)((strOfNum)), (UNITY_UINT32)((3)), (

 ((void *)0)

 ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

  free (strOfNum);

}



void test_convertHexLineToStrOfNum_with_full_ascii_data_should_return_string_of_number(void){

  char *data = ":100000000050002069010008A9030008AD030008A2\n";

  uint8_t expectedArray[] = {

    0x10,0x00,0x00,0x00,0x00,0x50,0x00,0x20,0x69,0x01,

    0x00,0x08,0xA9,0x03,0x00,0x08,0xAD,0x03,0x00,0x08,

    0xA2};



  uint8_t *strOfNum = convertHexLineToStrOfNum(data);



  UnityAssertEqualIntArray(( const void*)((expectedArray)), ( const void*)((strOfNum)), (UNITY_UINT32)((21)), (

 ((void *)0)

 ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

  free (strOfNum);

}



void xtest_wrong_converting_ascii_digits_to_string_of_number_should_throw_exception(void){

  char *data = ":1030C0\n";

  uint8_t expectedArray[3] = {0x20, 0x30, 0xC0};



  uint8_t *strOfNum = convertHexLineToStrOfNum(data);



  UnityAssertEqualIntArray(( const void*)((expectedArray)), ( const void*)((strOfNum)), (UNITY_UINT32)((3)), (

 ((void *)0)

 ), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_getHexLineLength_should_return_first_byte_of_data_from_strOfNum(void){

  char *data = ":0C12E2\n";

  uint8_t *strOfNum = convertHexLineToStrOfNum(data);



  int lineLength = getHexLineLength(strOfNum);



  UnityAssertEqualNumber((UNITY_INT)((0x0C)), (UNITY_INT)((lineLength)), (

 ((void *)0)

 ), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_INT);

}



void test_getHexLineAddress_should_return_16_bits_of_address_from_strOfNum(void){

  char *data = ":0224620408006C\n";

  uint8_t *strOfNum = convertHexLineToStrOfNum(data);



  int lineAddress = getHexLineAddress(strOfNum);



  UnityAssertEqualNumber((UNITY_INT)((0x2462)), (UNITY_INT)((lineAddress)), (

 ((void *)0)

 ), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_INT);

}



void test_getHexLineCode_should_return_thrid_byte_of_data_type_from_strOfNum(void){

  char *data = ":04130C006E2E6300DE\n";

  uint8_t *strOfNum = convertHexLineToStrOfNum(data);



  int dataType = getHexLineCode(strOfNum);



  UnityAssertEqualNumber((UNITY_INT)((0x00)), (UNITY_INT)((dataType)), (

 ((void *)0)

 ), (UNITY_UINT)(111), UNITY_DISPLAY_STYLE_INT);

}



void test_getHexLineCode_should_return_data_type_from_3rd_byte_of_strOfNum(void){

  char *data = ":0224620408006C\n";

  uint8_t *strOfNum = convertHexLineToStrOfNum(data);



  int dataType = getHexLineCode(strOfNum);



  UnityAssertEqualNumber((UNITY_INT)((0x04)), (UNITY_INT)((dataType)), (

 ((void *)0)

 ), (UNITY_UINT)(120), UNITY_DISPLAY_STYLE_INT);

}



void test_getHexLineDataByte_should_return_dataByte_from_strOfNum(void){

  char *data = ":0224620408006C\n";

  uint8_t *strOfNum = convertHexLineToStrOfNum(data);

  int length;

  uint8_t expectedArray[] = {0x08,0x00};



  uint8_t *dataByte = getHexLineDataByte(strOfNum, &length);



  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((length)), (

 ((void *)0)

 ), (UNITY_UINT)(131), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualIntArray(( const void*)((expectedArray)), ( const void*)((dataByte)), (UNITY_UINT32)((length)), (

 ((void *)0)

 ), (UNITY_UINT)(132), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

  freeMemory(dataByte);

}



void test_getHexLineDataByte_should_return_correct_dataByte_from_strOfNum(void){

  char *data = ":100000000050002069010008A9030008AD030008A2\n";

  uint8_t *strOfNum = convertHexLineToStrOfNum(data);

  int length;

  uint8_t expectedArray[] = {

    0x00,0x50,0x00,0x20,0x69,0x01,0x00,0x08,

    0xA9,0x03,0x00,0x08,0xAD,0x03,0x00,0x08};



  uint8_t *dataByte = getHexLineDataByte(strOfNum, &length);



  UnityAssertEqualNumber((UNITY_INT)((16)), (UNITY_INT)((length)), (

 ((void *)0)

 ), (UNITY_UINT)(146), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualIntArray(( const void*)((expectedArray)), ( const void*)((dataByte)), (UNITY_UINT32)((length)), (

 ((void *)0)

 ), (UNITY_UINT)(147), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

  freeMemory(dataByte);

}



void test_getHexLineDataByte_with_0_length_should_return_NULL(void){

  char *data = ":00000001FF";

  uint8_t *strOfNum = convertHexLineToStrOfNum(data);

  int length;



  uint8_t *dataByte = getHexLineDataByte(strOfNum, &length);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((length)), (

 ((void *)0)

 ), (UNITY_UINT)(158), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((

 ((void *)0)

 )), (UNITY_INT)((dataByte)), (

 ((void *)0)

 ), (UNITY_UINT)(159), UNITY_DISPLAY_STYLE_INT);

  freeMemory(dataByte);

}
