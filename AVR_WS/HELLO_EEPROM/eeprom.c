#include "eeprom.h"

void eeprom_init(void)
{
	i2c_init_master();
}

void eeprom_write_byte(unsigned short address, unsigned char data)
{
    i2c_start();
	i2c_send_slave_address_with_write_req( 0x50 | ((address & 0x0700)>>8) );
	i2c_write_byte((unsigned char)address);
	i2c_write_byte(data);
	i2c_stop();
    return;
}

unsigned char eeprom_read_byte(unsigned short address)
{
	unsigned char data;
	i2c_start();
	i2c_send_slave_address_with_write_req( 0x50 | ((address & 0x0700)>>8) );
    i2c_write_byte((unsigned char)address);
	i2c_repeated_start();
	i2c_send_slave_address_with_read_req( 0x50 | ((address & 0x0700)>>8) );
	data = i2c_read_byte();
	i2c_stop();
    return data;
}
