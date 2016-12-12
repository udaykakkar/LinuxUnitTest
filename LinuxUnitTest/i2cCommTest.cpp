#include "CppUTest/TestHarness.h"
#include "i2c_comm.h"
#include "MockI2cComm.h"

TEST_GROUP(i2c_comm)
{
	i2c_comm* i2c_o;
	Mocki2cComm* mocki2c_o;

	void setup()
	{
		mocki2c_o = new Mocki2cComm();
		i2c_o = mocki2c_o;
	}
	void teardown()
	{
		delete i2c_o;
	}
}
;

TEST(i2c_comm, checkOpenClose)
{
	int fd;
	mock().expectNCalls(2,"I2C_Open").ignoreOtherParameters();
	mock().expectNCalls(2, "I2C_Close").ignoreOtherParameters();
	//printer->Print("hello\n");
	i2c_o->I2C_Open(&fd, 0x68);
	i2c_o->I2C_Close(&fd);
	//CHECK_EQUAL(expected, mocki2c_o->I2C_Open(&fd, 0x68));
}

