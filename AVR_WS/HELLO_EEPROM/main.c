#include "eeprom.h"
#include <util/delay.h>

int main(void)
{
	DDRD = 0xff;
	DDRB = 0xff;
	eeprom_init();
	eeprom_write_byte(0,0x55);
	_delay_ms(10);
	PORTD = eeprom_read_byte(0);
	
    while(1)
    {
        
    }
}