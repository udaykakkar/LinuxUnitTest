
#ifndef D_i2cComm_H
#define D_i2cComm_H

#include <stdint.h>



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

class i2c_comm
{
public:
	explicit i2c_comm();
	virtual ~i2c_comm();
	//virtual void write_to_i2c(uint8_t address, uint8_t value);
	//virtual uint8_t read_from_i2c(uint8_t address);
	virtual int I2C_Open(int *f, unsigned char address);
	virtual void I2C_Send(int *f, unsigned char *buffer, unsigned char num_bytes);
	virtual int I2C_Read(int *f, unsigned char *buffer, unsigned char num_bytes);
	virtual void I2C_Close(int *f);
};

#endif