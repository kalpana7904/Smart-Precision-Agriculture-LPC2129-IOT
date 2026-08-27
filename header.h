#include<lpc21xx.h>
extern void wifi_print(void);
   extern intlen(char *p);
   extern int str_str(char *p,char *q);
 extern void delay_sec(unsigned int sec);
extern void delay_ms(unsigned int ms);

//uart0_
typedef unsigned char u8;
typedef unsigned int u32;
							   //i2c
	extern void i2c_init(void);
	 extern void i2c_write(u8 sa, u8 mr, u8 data);
	 extern u8 i2c_read(u8 sa,u8 mr);
extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *ptr);
extern void uart0_tx_integer(int num);
extern void uart0_float(float f);


//wifi
extern void wifi_cmd(char *cmd);
extern void wifi_init(void);
extern void wifi_send(char *data);
extern void wifi_connect_server(void);
extern void wifi_close(void);


//RTC
extern void rtc_data(void);

  extern void wifi(void);
extern	void Display_data(void);
typedef struct CAN1_MSG{

	u32 id;

	u32 byteA;

	u32 byteB;

	u8 rtr;

	u8 dlc;

	u8 ff;

}CAN1;


extern void can1_tx(CAN1 v);

extern void can1_init(void);



 //char EEPROM_status[20]="DATA SAVED";


//ADC
extern void adc_init(void);
extern unsigned int adc_read(unsigned char ch_num);


//delay
extern void delay_sec(unsigned int sec);
extern void delay_ms(unsigned int ms);

//LCD
extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void);
extern void lcd_string(char *ptr);
extern void lcd_integer(int num);
extern void lcd_float(double f);

extern void EEPROM_data(void);

//sensors
extern int LM35_temp_sensor(void);
extern int soil_moisture_sensor(void);
extern int water_sensor(void);
extern void rain_sensor(void);
extern void Flame_Sensor(void);
extern int ldr_sensor(void);
extern void PIR_Sensor(void);

//I2c
extern void i2c_init(void);
extern void i2c_write(u8 sa, u8 mr, u8 data);
extern u8 i2c_read(u8 sa,u8 mr);
//uart1
extern void UART1_SendChar(char ch);
extern void UART1_Init(void);
//extern void UART1_SendString(char *str);
void UART1_SendString(char *str);
extern void UART1_ReadResponse(unsigned int timeout_ms);
extern void ESP_SendCommand(char *cmd, unsigned int wait_ms);
extern void ESP8266_Init(void);
extern void ESP8266_UploadData(int soilMoisture, int waterLevel, int temperature,
                         int humidity, int rainStatus, int lightLevel,
                         int flameStatus, int pumpStatus);
