#ifndef D_Mocki2cComm_H
#define D_Mocki2cComm_H

#include "i2c_comm.h"
#include "CppUTest/SimpleString.h"
#include <stdlib.h>
#include <string>
#include "CppUTestExt/MockSupport.h"

//#pragma once
///////////////////////////////////////////////////////////////////////////////
//
//  MockPrinter.h
//
//  MockPrinter is responsible for providing a test stub for Printer
//
///////////////////////////////////////////////////////////////////////////////


class Mocki2cComm : public i2c_comm
{
public:
	explicit Mocki2cComm()
	{
	}
	virtual ~Mocki2cComm()
	{
	}
	/*virtual void write_to_i2c(int address, int value) {
		mock().actualCall(__FUNCTION__)
			.withParameter("address", address)
			.withParameter("value", value);
	}
	virtual uint8_t read_from_i2c(uint8_t address) {
		mock().actualCall(__FUNCTION__)
			.withParameter("address", address);
		uint8_t ret = mock().returnIntValueOrDefault(0);
		return ret;
	}*/


	virtual int I2C_Read(int *fd, unsigned char *buffer, unsigned char num_bytes) {
		mock().actualCall(__FUNCTION__)
			.withParameter("fd", fd)
			.withParameter("buffer", buffer)
			.withParameter("num_bytes", num_bytes);
		int ret = mock().returnIntValueOrDefault(0);
		return ret;
	}
	virtual void I2C_Send(int *fd, unsigned char *buffer, unsigned char num_bytes) {
		mock().actualCall(__FUNCTION__)
			.withParameter("fd", fd)
			.withParameter("buffer", buffer)
			.withParameter("num_bytes", num_bytes);
	}
	virtual void I2C_Close(int *fd) {
		mock().actualCall(__FUNCTION__)
			.withParameter("fd", fd);
	}

	virtual int I2C_Open(int *fd, unsigned char address) {
		mock().actualCall(__FUNCTION__)
			.withParameter("fd", fd)
			.withParameter("address", address);
		int ret = mock().returnIntValueOrDefault(0);
		return ret;
	}

};

#endif 