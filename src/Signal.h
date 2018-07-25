#ifndef Signal_H
#define Signal_H

void flash_unlock(void);
void flash_lock(void);
void flash_program_word(uint32_t address, uint32_t data);
void flash_program_halfword(uint32_t address, uint16_t data);
void flash_program_byteword(uint32_t address, uint8_t data);
void flash_pageErase(uint32_t address);
void flash_massErase(void);
int getTransmitData (uint32_t *address, uint8_t *dataByte, int *length);
int getReceiveStatus(int status);
#endif // Signal_H