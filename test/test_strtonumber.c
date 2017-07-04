#include <stdint.h>
#include <stdio.h>
#include "unity.h"
#include "strtonumber.h"
#include "CException.h"

void setUp(void){}

void tearDown(void){}

void test_open_Hex_file(void){
  openHexFile("../data/STM32_Bootloader.hex");
}
