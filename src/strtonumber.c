#include "strtonumber.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int openHexFile(const char *path){
  //unit32_t address;
  //Static unit32_t upperAddress
  
  unsigned char hexData[1208];
  FILE *fp = fopen(path, "r");
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
