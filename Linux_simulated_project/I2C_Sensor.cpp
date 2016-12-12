#pragma once
#include "I2C.h"
#include "I2C_Sensor.h"
void somethingA(void) {}
void somethingB(void) {}

void Print_Help(void) {
//	puts("\n\
//Usage:	./MOD-RTC [--debug] [parameter] [argument]\n\n\
//--verbose	- Print debug messages\n\
//--debug		- Same as above\n\
//-r, --read	- Read RTC\n\
//-w, --write	- Set RTC according the system\n\
//-s, --sync	- Syncing system clock with RTC\n\
//--help		- Print this help\n");
//	exit(0);
}


void Read_RTC() {
	
	int fd;
	unsigned char buff[10];
	unsigned char data[10];
	
	buff[0] = 0x00;
	
	
	
	
	/* Open I2C-BUS */	
	I2C_Open(&fd, 0x68);
	
	/* Write register */
	I2C_Send(&fd, buff, 1);
	
	/* Read the RTC */
	I2C_Read(&fd, data, 7);
	
	/* Close I2C-BUS */
	I2C_Close(&fd);
	
	data[0] &= 0x7F;
	data[1] &= 0x7F;
	data[2] &= 0x3F;
	data[3] &= 0x07;
	data[4] &= 0x3F;
	data[5] &= 0x1F;
	data[6] &= 0xFF;	
	
//	printf("Sec: %d\n", BCDtoInt(data[0]));
//	printf("Min: %d\n", BCDtoInt(data[1]));
//	printf("Hour: %d\n", BCDtoInt(data[2]));
//	printf("WDays: %d\n", BCDtoInt(data[3]));
//	printf("MDays: %d\n", BCDtoInt(data[4]));
//	printf("Month: %d\n", BCDtoInt(data[5]));
//	printf("Year: %d\n", BCDtoInt(data[6]));
	
}

