#include "SerialCom.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CException.h"
#include "Serial.h"
#include "Signal.h"

uint8_t serialComm(int status, int writeMethod, uint32_t address, uint8_t *dataByte, int *length){
  uint8_t FlashMemory[0x0801FFFF];
  if(status){
	flash_unlock();
	flash_pageErase(address);
	
	if(writeMethod == 1){
	  //flash_program_word(address, dataByte);
	}
	else if(writeMethod == 2){
	  //flash_program_halfword(address, dataByte);	
	}
	else if(writeMethod == 3){
	  for(int i = 0; i != *length; i++){
	    address = address+0x2;
        FlashMemory[address] = dataByte[i+4];
    }
      return 1;	
	}
	else{
	  return 0;
	}
	
	flash_lock();
  }
  else{
	return 0;
  }
}