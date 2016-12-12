#pragma once
extern "C" {
#include "I2C.h"
};

#include "CppUTest/SimpleString.h"
#include <stdlib.h>
#include <string>
#include "CppUTestExt/MockSupport.h"

//class MockI2C : public I2C
//{
//public:
//	explicit MockPrinter()
//	{
//	}
//	virtual ~MockPrinter()
//	{
//	}

void write_to_i2c(int address, int value) {
	mock().actualCall(__FUNCTION__)
	    .withParameter("address", address)
	    .withParameter("value", value);
}


int I2C_Read(int *fd, unsigned char *buffer, unsigned char num_bytes) {
	mock().actualCall(__FUNCTION__)
	    .withParameter("fd", fd)
	    .withParameter("buffer", buffer)
	  .withParameter("num_bytes", num_bytes);
	int ret = mock().returnIntValueOrDefault(0);
	return ret;
}

	
void I2C_Send(int *fd, unsigned char *buffer, unsigned char num_bytes) {
	mock().actualCall(__FUNCTION__)
	    .withParameter("fd", fd)
	    .withParameter("buffer", buffer)
	  .withParameter("num_bytes", num_bytes);
}

	
void I2C_Close(int *fd) {
	mock().actualCall(__FUNCTION__)
	    .withParameter("fd", fd);
}

void I2C_Open(int *fd, unsigned char address) {
	mock().actualCall(__FUNCTION__)
	    .withParameter("fd", fd)
	    .withParameter("address", address);
}


//};

