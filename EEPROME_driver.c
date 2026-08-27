#include<lpc21xx.h>
#include"header.h"
#define GREEN 0x01
#define YELLOW 0x02
#define RED  0x04
extern char EEPROM_status[20]="DATA SAVED";


void EEPROM_data(void)
{
unsigned char temp;
//i2c_write
i2c_write(0xA0,0x02,'A');
delay_ms(30);


//read data
temp=i2c_read(0xA1,0x02);
if(temp=='A')
{
//strcpy(EEPROM_status,"DATA SAVED");
uart0_tx_string("EEPROM_status: DATA SAVED\r\n");
uart0_tx_string("\n\r");
IOCLR0=GREEN;
IOSET0=YELLOW| RED;
}
else
{
 //strcpy(EEPROM_status,"WRITE FAIL");
 uart0_tx_string("EEPROM_status: WRITE FAIL\r\n");
 uart0_tx_string("\n\r");
		 IOCLR0=RED;
IOSET0=YELLOW|GREEN;

}
}
