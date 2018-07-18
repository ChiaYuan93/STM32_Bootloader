#include "unity.h"
#include "SerialCom.h"
#include <stdint.h>
#include <stdio.h>
#include "CException.h"
#include "strtonumber.h"
#include "mock_Signal.h"

void setUp(void){}

void tearDown(void){}

void test_when_button_is_pressed_should_send_Hex_data_into_FLASH(void){
	char *HexLine = ":100000000050002069010008A9030008AD030008A2\n";
	
	getSignal_ExpectAndReturn(BUTTON_PRESSED);
	
	uint8_t *strOfNum = convertHexLineToStrOfNum(HexLine);
	int lineLength = getHexLineLength(strOfNum);
	int lineAddress = getHexLineAddress(strOfNum);
	int dataType = getHexLineCode(strOfNum);
	uint8_t *dataByte = getHexLineDataByte(strOfNum, &length);
	
	
}

