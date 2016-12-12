#pragma once
extern "C" {
#include "i2c_comm.h"
}
#include <string>
class I2C_Sensor : public i2c_comm
{
public:
	explicit I2C_Sensor(i2c_comm* i2c_ob);
	virtual ~I2C_Sensor();
	void Print_Help(void);
	unsigned char Read_RTC_min();
	unsigned char Read_RTC_sec();
	unsigned char Read_RTC_day();
	unsigned char Read_RTC_date();
	unsigned char Read_RTC_month();
	unsigned char Read_RTC_year();
	void Write_RTC();
	void Sync_RTC();
	unsigned char BCDtoInt(unsigned char BCD);
	unsigned char InttoBCD(unsigned char Int);
	i2c_comm* i2c_ob;
};