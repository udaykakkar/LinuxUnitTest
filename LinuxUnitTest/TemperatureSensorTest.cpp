
//extern "C" {
#include "temperature.h" // UUT
//};

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(Temperature)
{
	void setup() {}
	void teardown() {
		mock().checkExpectations();
		mock().clear();
	}
};

TEST(Temperature, somethingA)
{
	const uint8_t value = 10;
	//mock().ignoreOtherCalls();
	mock().expectOneCall("read_from_i2c").ignoreOtherParameters();

	temperature_do(10, value);
}
TEST(Temperature, somethingB)
{
	const uint8_t value = 10;
	mock().ignoreOtherCalls();
	mock().expectOneCall("read_from_i2c").ignoreOtherParameters()
		.andReturnValue(value + 1);
	temperature_do(10, value);
}