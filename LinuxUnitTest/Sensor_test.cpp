#include "CppUTest/TestHarness.h"
#include "i2c_comm.h"
#include "I2C_Sensor.h"
#include "MockI2cComm.h"

TEST_GROUP(I2C_Sensor)
{
	I2C_Sensor* i2c_sensor;
	Mocki2cComm* mocki2c_o;

	void setup()
	{
		mocki2c_o = new Mocki2cComm();
		i2c_sensor = new I2C_Sensor(mocki2c_o);
	}
	void teardown()
	{
		delete i2c_sensor;
	}
}
;
TEST(I2C_Sensor, checkSimpleRead)
{
	mock().expectOneCall("I2C_Open").ignoreOtherParameters();
	mock().expectOneCall("I2C_Send").ignoreOtherParameters();
	mock().expectOneCall("I2C_Read").ignoreOtherParameters();
	i2c_sensor->Read_RTC_min();
}
//int fd;
//mock().expectNCalls(2, "I2C_Open").ignoreOtherParameters();
////printer->Print("hello\n");
//i2c_o->I2C_Open(&fd, 0x68);
//i2c_o->I2C_Close(&fd);
//CHECK_EQUAL(expected, mocki2c_o->I2C_Open(&fd, 0x68));