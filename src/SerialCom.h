#ifndef SerialCom_H
#define SerialCom_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint8_t serialComm(int status, int writeMethod, uint32_t address, uint8_t *dataByte, int *length);

#endif // SerialCom_H
