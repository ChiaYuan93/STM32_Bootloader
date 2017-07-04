#include "build/temp/_test_strtonumber.c"
#include "CException.h"
#include "strtonumber.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_fopen_non_existent_data_file_expect_to_fail() {

  FILE *hexFile = fopen("data", "r");



  if ((((hexFile)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(14))));};

}



void test_fopen_test_hex_data_file() {

  FILE *hexFile = fopen("data/STM32_Bootloader.hex", "r");



  if ((((hexFile)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(20))));};

}



void test_fgets_read_a_line() {

  FILE *hexFile = fopen("data/STM32_Bootloader.hex", "r");

  char *buf = readLine(hexFile);



  if ((((buf)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(27))));};

  UnityAssertEqualString((const char*)((":020000040800F2\n")), (const char*)((buf)), (

 ((void *)0)

 ), (UNITY_UINT)(28));

}



void test_verifyHexLine_given_HexWithWrongChecksum_hex_file_expect_0(void) {

  FILE *hexFile = fopen("data/HexWithWrongChecksum.hex", "r");

  char *line = readLine(hexFile);

  int result = verifyHexLine(line);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((result)), (

 ((void *)0)

 ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

}



void test_verifyHexLine_given_HexWithCorrectChecksum_hex_file_expect_0(void) {

  FILE *hexFile = fopen("data/HexWithCorrectChecksum.hex", "r");

  char *line = readLine(hexFile);

  int result = verifyHexLine(line);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((result)), (

 ((void *)0)

 ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_INT);

}





void test_cexception() {

  unsigned int ex;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp3((

 NewFrame

 ), ((void *)0)) 

 == 0) { if (1) {

    Throw(1);

  } else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)) {

    printf("Exception thrown!\n");

  }



}



void test_open_Hex_file(void){

  openHexFile("../data/STM32_Bootloader.hex");

}
