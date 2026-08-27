#include<lpc21xx.h>
#include"header.h"

			  
#define GREEN  1<<17
#define YELLOW 1<<18
#define RED    1<<19

#define BUZZER  (1<<21)
#define Pir_sens ((IOPIN0 >> 23 ) & 1)

void PIR_Sensor(void)
{
  if(Pir_sens == 1) // NO Motion
	{
	   uart0_tx_string("Motion Status : CLEAR \r\n");
		 uart0_tx_string("Security : NORMAL \r\n");
		 
		 IOCLR0 = GREEN;
		 IOSET0 = YELLOW | RED;
		 
		 IOCLR0 = BUZZER;
		 
		 lcd_cmd(0x01);
		 lcd_cmd(0x80);
		 lcd_string("Field :SAFE");
		 lcd_cmd(0xC0);
		 lcd_string("No Motion");
	}
	else
	{
	   uart0_tx_string("Motion Status : DETECTED\r\n");
		 uart0_tx_string("Security : ALERT\r\n");
		 
		 IOCLR0 = YELLOW;
		 IOSET0 = GREEN | RED;
		 
		 IOSET0 = BUZZER;
		 
		 lcd_cmd(0x01);
		 lcd_cmd(0x80);
		 lcd_string("Motion Found");
		 lcd_cmd(0xC0);
		 lcd_string("Check Field");
	}
	
	uart0_tx_string("-----------------------------------\r\n");
	
//	delay_ms(100);
}
