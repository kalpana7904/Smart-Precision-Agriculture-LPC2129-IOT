#include<lpc21xx.h>
#include"header.h"

#define GREEN  1<<17
#define YELLOW 1<<18
#define RED    1<<19

int ldr_sensor(void)
{
  unsigned int adcout , temp;
	
	adcout = adc_read(3);
	
	temp = (adcout * 100) / 1023;
	
	uart0_tx_string("Light Level : ");
	
	if(temp >= 70)
	{
	  uart0_tx_string("HIGH\r\n");
		uart0_tx_string("Status : SUNNY\r\n");
		
		IOCLR0 = GREEN;
		IOSET0 = YELLOW | RED;
		
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("Light : HIGH");
		lcd_cmd(0xC0);
		lcd_string("Sunny Field");
	}
	else if(temp > 50)
	{
	  uart0_tx_string("MEDIUM\r\n");
		uart0_tx_string("Status : NORMAL\r\n");
		
		IOCLR0 = GREEN;
		IOSET0 = YELLOW | RED;
		
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("Light : MED");
		lcd_cmd(0xC0);
		lcd_string("Normal Day");
	}
	else
	{
	  uart0_tx_string("LOW \r\n");
		uart0_tx_string("Status : CLOUDY\r\n");
		
		IOCLR0 = YELLOW;
		IOSET0 = GREEN | RED;
		
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("Light : LOW");
		lcd_cmd(0xC0);
		lcd_string("Cloudy Sky");
	}
	
	uart0_tx_string("-----------------------------------\r\n");
	delay_ms(100);
	return temp;
}
