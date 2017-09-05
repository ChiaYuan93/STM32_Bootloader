#include "CException.h"
#include "SerialCom.h"
#include "unity.h"




void setUp(void){}



void tearDown(void){}



void test_flashErasePage_to_combine_in_specific_pattern(){

  uint8_t eraseAddress = 0x01;

  int addressLength = 5;

  uint8_t address = 0x1234567890;

  int numberOfPages = 1;



  flashErasePage(eraseAddress);



  UnityAssertEqualString((const char*)("015123456789001"), (const char*)(data), (((void *)0)), (_U_UINT)18);

}
