#pragma once

#ifndef I2C_H
#define I2C_H


#define I2C0	"/dev/i2c-0"
#define I2C1	"/dev/i2c-1"
#define I2C2	"/dev/i2c-2"
#define I2C3	"/dev/i2c-3"
#define I2C4	"/dev/i2c-4"
#define I2C5	"/dev/i2c-5"

#define RED		"\033[22;31m"
#define GREEN	"\033[22;32m"
#define GRAY	"\033[22;37m"
#define WHITE	"\033[01;37m"

//class I2C
//{
//public:
	//I2C(void);
	//~I2C(void);

	void I2C_Open(int *f, unsigned char address);
	void I2C_Send(int *f, unsigned char *buffer, unsigned char num_bytes);
	int I2C_Read(int *f, unsigned char *buffer, unsigned char num_bytes);
	void I2C_Close(int *f);
	void write_to_i2c(int address, int value);
//};



#endif




