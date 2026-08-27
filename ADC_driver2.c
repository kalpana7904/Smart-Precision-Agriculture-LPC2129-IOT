#include <LPC21xx.H>
#include "header.h"

void adc_init(void){
	const int a[]={4,19,9,4,4};
	unsigned int clkdiv=0;
	clkdiv=a[VPBDIV];
	PINSEL1|=0x15400000;
	ADCR=0x00200000|(clkdiv<<8);
}

#define DONE ((ADDR>>31)&1)
//u32 adc_read(u8 ch_num)
unsigned int adc_read(unsigned char ch_num)
	{
	unsigned int result=0;
	
	/*step1: select channel*/
	ADCR|=(1<<ch_num);
	
	/*step2: start adc*/
	ADCR|=(1<<24);
	
	/*step3: wait for adc conv to complete*/
	while(DONE==0);
	
	/*step4: stop adc*/
	ADCR^=(1<<24);
	
	/*step5: deselect adc channel*/
	ADCR^=(1<<ch_num);
	
	/*extract the result*/
	result=(ADDR>>6)&0x3FF;
	
	return result;	
}

