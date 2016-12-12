//extern "C" {
#include "I2C_Sensor.h" // UUT
//};

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTestExt/MockSupport.h"


TEST_GROUP(I2C)
{
	void setup() {}
	void teardown() {
		mock().checkExpectations();
		mock().clear();
	}
};

TEST(I2C, Sensorread)
{
	const int value = 10;
	//mock().ignoreOtherCalls();
	mock().expectOneCall("I2C_Read").ignoreOtherParameters()
	    .andReturnValue(value);
	Read_RTC_min();
}