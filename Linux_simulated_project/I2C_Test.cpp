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
	mock().ignoreOtherCalls();
	mock().expectOneCall("I2C_Send").ignoreOtherParameters();
	    //.andReturnValue();
	Read_RTC();
}