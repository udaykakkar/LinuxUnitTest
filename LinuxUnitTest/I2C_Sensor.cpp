#pragma once
#include "I2C_Sensor.h"
#include <stdio.h>


I2C_Sensor::I2C_Sensor(i2c_comm* i2c_ob)
{
	this->i2c_ob = i2c_ob;
}
I2C_Sensor::~I2C_Sensor()
{
}



void I2C_Sensor::Print_Help(void) {
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
unsigned char I2C_Sensor::BCDtoInt(unsigned char BCD) {

	unsigned char a;
	unsigned char b;

	a = BCD & 0x0F;
	b = BCD >> 4;

	return b * 10 + a;
}
unsigned char I2C_Sensor::InttoBCD(unsigned char Int) {

	unsigned char a;
	unsigned char b;

	a = Int % 10;
	b = Int / 10;

	return (b << 4) + a;
}


unsigned char I2C_Sensor::Read_RTC_min() {
	printf("reading RTC Minute \n");
	int fd;
	unsigned char buff[10];
	unsigned char data[10];

	buff[0] = 0x00;




	/* Open I2C-BUS */
	i2c_ob->I2C_Open(&fd, 0x68);

	/* Write register */
	i2c_ob->I2C_Send(&fd, buff, 1);

	/* Read the RTC */
	i2c_ob->I2C_Read(&fd, data, 7);

	/* Close I2C-BUS */
	//i2c_ob->I2C_Close(&fd);

	data[0] &= 0x7F;
	data[1] &= 0x7F;
	data[2] &= 0x3F;
	data[3] &= 0x07;
	data[4] &= 0x3F;
	data[5] &= 0x1F;
	data[6] &= 0xFF;

		printf("Sec: %d\n", BCDtoInt(data[0]));
		printf("Min: %d\n", BCDtoInt(data[1]));
		printf("Hour: %d\n", BCDtoInt(data[2]));
		printf("WDays: %d\n", BCDtoInt(data[3]));
		printf("MDays: %d\n", BCDtoInt(data[4]));
		printf("Month: %d\n", BCDtoInt(data[5]));
		printf("Year: %d\n", BCDtoInt(data[6]));
	return BCDtoInt(data[1]);
}

unsigned char I2C_Sensor::Read_RTC_sec() {

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

	

	data[0] &= 0x7F;
	data[1] &= 0x7F;
	data[2] &= 0x3F;
	data[3] &= 0x07;
	data[4] &= 0x3F;
	data[5] &= 0x1F;
	data[6] &= 0xFF;
	/* Close I2C-BUS */
	//I2C_Close(&fd);
	//	printf("Sec: %d\n", BCDtoInt(data[0]));
	//	printf("Min: %d\n", BCDtoInt(data[1]));
	//	printf("Hour: %d\n", BCDtoInt(data[2]));
	//	printf("WDays: %d\n", BCDtoInt(data[3]));
	//	printf("MDays: %d\n", BCDtoInt(data[4]));
	//	printf("Month: %d\n", BCDtoInt(data[5]));
	//	printf("Year: %d\n", BCDtoInt(data[6]));
	return BCDtoInt(data[0]);

}


unsigned char I2C_Sensor::Read_RTC_day() {
	
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
	return BCDtoInt(data[3]);
	
}

unsigned char I2C_Sensor::Read_RTC_date() {

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
	return BCDtoInt(data[4]);

}

unsigned char I2C_Sensor::Read_RTC_month() {

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
	return BCDtoInt(data[5]);

}


unsigned char I2C_Sensor::Read_RTC_year() {

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
	return BCDtoInt(data[6]);
}
