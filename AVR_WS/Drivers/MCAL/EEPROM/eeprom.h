#ifndef EEPROM_H_
#define EEPROM_H_

#include "I2C.h"

void eeprom_init(void);
void eeprom_write_byte(unsigned short address, unsigned char data);
unsigned char eeprom_read_byte(unsigned short address);
 
#endif /* EEPROM_H_ */