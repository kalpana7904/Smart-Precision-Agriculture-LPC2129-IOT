
#include<lpc21xx.h>
#include"header.h"

#define GREEN   1<<17
#define YELLOW  1<<18
#define RED     1<<19

#define BUZZER  (1<<21)
#define flame_sens ((IOPIN0 >> 22 ) & 1)

void Flame_Sensor(void)
{
   if(flame_sens == 1) // NO FIRE
	 {
	    uart0_tx_string("Flame Status : SAFE \r\n");
	    uart0_tx_string("Alarm : OFF\r\n");
			
			IOCLR0 = GREEN;
			IOSET0 = YELLOW | RED;
			
			IOCLR0 = BUZZER;
			
			lcd_cmd(0x01);
			lcd_cmd(0x80);
			lcd_string("Flame :SAFE");
			lcd_cmd(0xC0);
			lcd_string("Status : NORMAL");
	 }
	 else  //FIRE
	 {
	    uart0_tx_string("Flame Status : DETECTED \r\n");
			uart0_tx_string("Alarm : ON\r\n");
			
			IOCLR0 = RED;
			IOSET0 = GREEN | YELLOW;
			
			IOSET0 = BUZZER;
			
			lcd_cmd(0x01);
			lcd_cmd(0x80);
			lcd_string("FIRE ALERT!!");
			lcd_cmd(0xC0);
			lcd_string("Check Field");
	 }
	 uart0_tx_string("-----------------------------------\r\n");
	
	 //delay_ms(100);
}
