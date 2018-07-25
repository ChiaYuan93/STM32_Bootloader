#include "unity.h"
#include "SerialCom.h"
#include <stdint.h>
#include <stdio.h>
#include "CException.h"
#include "strtonumber.h"
#include "mock_Signal.h"

void setUp(void){}

void tearDown(void){}

void test_serial_communication_given_success_should_transmit_data(void){
  int PROGRAM_WORD = 1;
  int PROGRAM_HALFWORD = 2;
  int PROGRAM_BYTEWORD = 3;
  int FAIL = 0;
  int SUCCESS = 1;
  
  char *HexLine = ":100000000050002069010008A9030008AD030008A2\n";
  int length;
  uint32_t startAddress = 0x08040000;
  uint8_t FlashMemory[0x0801FFFF];	
  uint8_t *strOfNum = convertHexLineToStrOfNum(HexLine);
  uint8_t *dataByte = getHexLineDataByte(strOfNum, &length);
  //int status = getReceiveStatus_Expect(SUCCESS);
  // getTransmitData_Expect (startAddress, dataByte, &length);
  serialComm(SUCCESS, PROGRAM_BYTEWORD, startAddress, dataByte, &length);
  
  
  TEST_ASSERT_EQUAL(0x05, FlashMemory[startAddress]);
  TEST_ASSERT_EQUAL(0x00, FlashMemory[startAddress+2]);
  TEST_ASSERT_EQUAL(0x02, FlashMemory[startAddress+4]);
  TEST_ASSERT_EQUAL(0x06, FlashMemory[startAddress+6]);
  TEST_ASSERT_EQUAL(0x90, FlashMemory[startAddress+8]);
  TEST_ASSERT_EQUAL(0x10, FlashMemory[startAddress+10]);
  TEST_ASSERT_EQUAL(0x00, FlashMemory[startAddress+12]);
  TEST_ASSERT_EQUAL(0x08, FlashMemory[startAddress+14]);  
  TEST_ASSERT_EQUAL(0xA9, FlashMemory[startAddress+16]);  
  TEST_ASSERT_EQUAL(0x03, FlashMemory[startAddress+18]);  
  TEST_ASSERT_EQUAL(0x00, FlashMemory[startAddress+20]);  
  TEST_ASSERT_EQUAL(0x08, FlashMemory[startAddress+22]);  
  TEST_ASSERT_EQUAL(0xAD, FlashMemory[startAddress+24]);  
  TEST_ASSERT_EQUAL(0x03, FlashMemory[startAddress+26]);  
  TEST_ASSERT_EQUAL(0x00, FlashMemory[startAddress+28]);  
  TEST_ASSERT_EQUAL(0x08, FlashMemory[startAddress+30]);    	
}

void xtest_serial_communication_given_success_expect_transmit_data(void){
  int PROGRAM_WORD = 1;
  int PROGRAM_HALFWORD = 2;
  int PROGRAM_BYTEWORD = 3;
  int FAIL = 0;
  int SUCCESS = 1;
  
  char *HexLine = "::0224620408006C\n\n";
  int length;
  uint32_t startAddress = 0x08040000;
  uint8_t FlashMemory[0x0801FFFF];	
  uint8_t *strOfNum = convertHexLineToStrOfNum(HexLine);
  uint8_t *dataByte = getHexLineDataByte(strOfNum, &length);
  //int status = getReceiveStatus_Expect(SUCCESS);
  // getTransmitData_Expect (startAddress, dataByte, &length);
  serialComm(SUCCESS, PROGRAM_BYTEWORD, startAddress, dataByte, &length);
  
  
  TEST_ASSERT_EQUAL(0x08, FlashMemory[startAddress]);
  TEST_ASSERT_EQUAL(0x00, FlashMemory[startAddress+2]);
}

void xtest_serial_communication_given_FAIL_should_not_transmit_data(void){
  int PROGRAM_WORD = 1;
  int PROGRAM_HALFWORD = 2;
  int PROGRAM_BYTEWORD = 3;
  int FAIL = 0;
  int SUCCESS = 1;
  
  char *HexLine = ":100000000050002069010008A9030008AD030008A2\n";
  int length;
  uint32_t startAddress = 0x08040000;
  uint8_t FlashMemory[0x0801FFFF];	
  uint8_t *strOfNum = convertHexLineToStrOfNum(HexLine);
  uint8_t *dataByte = getHexLineDataByte(strOfNum, &length);
  //int status = getReceiveStatus_Expect(FAIL);
  //getTransmitData_Expect (startAddress, dataByte, &length);
  serialComm(SUCCESS, PROGRAM_BYTEWORD, startAddress, dataByte, &length);
  	
}