#include<lpc21xx.h>
#include"header.h"
#define Pump (1 << 15) 
#define GREEN 1<<17
#define YELLOW	1<<18
#define RED	 1<<19	 
//char EEPROM_status[20];
int soil,ldr,temp,water;

CAN1 m1;
int main()
{
//int flag=0;
//unsigned int adcout, temp;
//unsigned int adcout;
//float temp_out1,centi;
//IODIR0=GREEN|RED|YELLOW|Pump;
//IOSET0=GREEN|RED|YELLOW|Pump;
//lcd_init();
adc_init();
i2c_init();
//can1_init();
uart0_init(9600);
uart0_tx_string("*****************************************\n\r");
uart0_tx_string("SMART PRECISION AGRICULTURE SYSTEM       \n\r");
uart0_tx_string("****************************************\n\r");
uart0_tx_string("Controller    :  OK\n\r");
uart0_tx_string("ADC           :  OK\n\r");
uart0_tx_string("UART          :  OK\n\r");
uart0_tx_string("I2C           :  OK\n\r");
uart0_tx_string("SPI           :  OK\n\r");
uart0_tx_string("CAN           :  OK\n\r");
uart0_tx_string("controller    : active\n\r");
uart0_tx_string("initliazation : success\n\r");
uart0_tx_string("*******************************\n\r");
lcd_cmd(0x80);
lcd_string("system ready");
lcd_cmd(0xc0);
lcd_string("LPC2129 active");
	m1.id=0x123;

	m1.rtr=0;//data frame

	m1.dlc=1;
	m1.byteB=0;
while(1)
{
  /*if(flag==0)
  {
  uart0_tx_string("controller     : LPC2119\n\r");
  uart0_tx_string("system status  : running\n\r");
  uart0_tx_string("sensor status  : monotoring\n\r");
  uart0_tx_string("decision Engine: active\n\r");
  uart0_tx_string("decision Engine: active\n\r");
  uart0_tx_string("Pump COntrol   : active\n\r");
  uart0_tx_string("cloud status   : active\n\r");
  lcd_cmd(0x80);
  lcd_string("system running");
  lcd_cmd(0xc0);
  lcd_string("monitoring");
  flag=1;
  
  }	
 // *///EEPROM_data();
	//ldr_sensor();
	/*uart0_tx_string("**************************************************\n\r");
	uart0_tx_string("SMART PRECISION AGRICULTURE MONOTORING SYSTEM\n\r");
	uart0_tx_string("**************************************************\n\r");		
	uart0_tx_string("controller         : LPC2129 ARM\n\r");
	uart0_tx_string("project status     : RUNNING                        \n\r");*/    
 	soil=soil_moisture_sensor();
	delay_ms(100);
	water=water_sensor();
	delay_ms(100);
	temp=LM35_temp_sensor();
	uart0_tx_string("\n\r");
    delay_ms(100);
    rain_sensor();
	delay_ms(100);
    ldr=ldr_sensor();
	delay_ms(100);
	Flame_Sensor();
	delay_ms(100);
	PIR_Sensor();
	delay_ms(100);
	 rtc_data();
	 delay_sec(1);
	EEPROM_data(); 
	uart0_tx_string("\r\n");
	wifi();
	uart0_tx_string("\r\n");



	 uart0_tx_string("CAN transmiting \r\n");

	m1.byteA=soil | (water<<8) | (temp<<16);
//EEPROM_data();
//	rtc_data();

//	can1_tx(m1);
	 //wifi();
	 uart0_tx_string("-----------------------\r\n");
	   
	delay_ms(100);
	
}
 }
