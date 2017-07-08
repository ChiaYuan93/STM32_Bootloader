#include "strtonumber.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "CException.h"

char buffer[1028];

int openHexFile(char *path){
  FILE *fileHandler ;
  fileHandler = fopen(path, "r");
    if(fileHandler == NULL){
      return 0;
    }
    if(fileHandler != NULL){
      return 1;
    }
}

char *readLine(FILE *fileHandler){  
  return fgets(buffer, 1028, fileHandler);
}

 // sscanf each byte and sum them up.
 // it should be zero.
 // Return 1 if zero; otherwise 0
int verifyHexLine(char *line){
  int hex;
  int storeHex = 0;
  int i = 0;
  char temp;

  while(1){
    sscanf(&line[i+1], "%2c", &temp);
    
    if(temp != '\n'){
      sscanf(&line[i+1], "%2x", &hex);
      i = i + 2;
      storeHex = storeHex + hex;
    }
    else{
      if((storeHex % 0x10) == 0){
        return 1;
        break;
      }
      else{
        return 0;
        break;
      }
    }
  }
}

  // sscanf to convert ascii digits to numbers
  // and return the buffer containing the result
uint8_t *convertHexLineToStrOfNum(char *line){
  
}

// int getHexLineLength(uint8_t *strOfNum) {
  // // return the first byte of data from strOfNum
// }

// int getHexLineAddress(uint8_t *strOfNum) {
  // // return the 16-bit data at byte 1 and 2
// }

// int getHexLineCode(uint8_t *strOfNum) {
  // // return the 8-bit data at byte 3
// }

// uint8_t *getHexLineDataByte(uint8_t *strOfNum) {
  // // return the data bytes
// }



