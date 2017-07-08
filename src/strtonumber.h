#ifndef _STRTONUMBER_H
#define _STRTONUMBER_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

FILE *openHexFile(char *fileHandler);
char *readLine(FILE *fileHandler);
int verifyHexLine(char *line);
uint8_t *convertHexLineToStrOfNum(char *line);

#endif // _STRTONUMBER_H
