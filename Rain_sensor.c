#include<lpc21xx.h>
#include"header.h"

#define GREEN  1<<17
#define YELLOW 1<<18
#define RED    1<<19
#define Pump  (1<<15)

#define Rain_sens ((IOPIN0 >> 21) & 1) //Lpc2129 p0.14

void rain_sensor(void)
{
  if(Rain_sens == 1) //No RAin
	{
	  uart0_tx_string("Rain Status : NO RAIN\r\n");
		uart0_tx_string("Pump Status : READY\r\n");
		
		IOCLR0 = GREEN;
		IOSET0 = YELLOW | RED;
		
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("Rain : NO");
		lcd_cmd(0xC0);
		lcd_string("Pump : READY");
	}
	else  // RAin
	{
    	uart0_tx_string("Rain Status : DETECTED\r\n");
		uart0_tx_string("Pump Status : OFF\r\n");
			
			IOCLR0 = YELLOW;
			IOSET0 = GREEN | RED;
			
			IOCLR0 = Pump;
			
			lcd_cmd(0x01);
			lcd_cmd(0x80);
			lcd_string("Rain : YES");
			lcd_cmd(0xC0);
			lcd_string("Pump : OFF");
	}
	uart0_tx_string("-----------------------------------\r\n");
	delay_ms(100);
}
