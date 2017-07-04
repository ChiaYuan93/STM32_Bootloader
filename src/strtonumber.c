#include "strtonumber.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CException.h"

char buffer[1028];

char *readLine(FILE *fileHandler) {
  return fgets(buffer, 1028, fileHandler);
}

int verifyHexLine(char *line) {
  // sscanf each byte and sum them up.
  // it should be zero.
  // Return 1 if zero; otherwise 0
  return -1;
}

uint8_t *convertHexLineToStrOfNum(char *line) {
  // sscanf to convert ascii digits to numbers
  // and return the buffer containing the result
}

int getHexLineLength(uint8_t *strOfNum) {
  // return the first byte of data from strOfNum
}

int getHexLineAddress(uint8_t *strOfNum) {
  // return the 16-bit data at byte 1 and 2
}

int getHexLineCode(uint8_t *strOfNum) {
  // return the 8-bit data at byte 3
}

uint8_t *getHexLineDataByte(uint8_t *strOfNum) {
  // return the data bytes
}

int openHexFile(const char *path){
  // unit32_t address;
  // Static unit32_t upperAddress;

  unsigned char hexData[1208];
  FILE *fp = fopen(path, "r");
  // check if data file is there (fp != NULL)

  while (fgets(hexData, 1208, fp) != NULL) {
    unsigned char a[1208];
    int i = 0;
    while (hexData[i] != '\n') {
        int b;
        sscanf(&hexData[i], "%2x", &b);
        printf("%x\n", hexData);
        a[i] = b;
        i += 2;
    }
  }
  fclose (fp);
  return 0;
}

