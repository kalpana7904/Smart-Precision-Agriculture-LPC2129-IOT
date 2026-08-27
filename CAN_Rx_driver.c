/*can1_driver.c*/
#include <LPC21xx.H>
#include<lpc21xx.h>
#include "header.h"

extern u8 flag;
extern CAN1 r1;


/*void config_vic_for_can1(void){
	VICVectCntl5=26|(1<<5);
	VICVectAddr5=(u32)CAN1_Rx_Handler;
	VICIntEnable=(1<<26);//En CAN1 Rx intr in VIC peri
	C1IER=1;//En CAN1 Rx intr only
} */


void can1_init(void){
	VPBDIV=1;//PCLK=60MHz
	PINSEL1|=0x40000;//P0.25-->RD1
	C1MOD=1;//Select reset mode
	C1BTR=0x001C001D;//125Kbps baudrate
	AFMR=2;//accept all receiving msgs
	C1MOD=0;//release reset mode	
}

#define RBS (C1GSR&1)
void can1_rx(CAN1 *ptr){
	while(RBS==0);//waiting for data-frame to receive
	ptr->id=C1RID;	
	ptr->dlc=(C1RFS>>16)&0xF;//extract dlc
	ptr->rtr=(C1RFS>>30)&1;//extract rtr
	ptr->ff=(C1RFS>>31)&1;//extract frame format
	if(ptr->rtr==0){//if data-frame
		ptr->byteA=C1RDA;
		ptr->byteB=C1RDB;
	}
	C1CMR=(1<<2);//*release rxbuf
}


#define TCS ((C1GSR>>3)&1)
void can1_tx(CAN1 v){
	C1TID1=v.id;
	C1TFI1=v.dlc<<16;//set dlc,rtr=0,ff=0(std version)
	if(v.rtr==0){//if data-frame
		C1TDA1=v.byteA;
		C1TDB1=v.byteB;
	}
	else
		C1TFI1|=(1<<30);//rtr=1
	
	C1CMR=1|(1<<5);//Select Txbuf1 & start Xmission
	while(TCS==0);
}
