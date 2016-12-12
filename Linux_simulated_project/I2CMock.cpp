extern "C" {
#include "i2C.h"
}
;

#include "CppUTestExt/MockSupport.h"

void write_to_i2c(uint8_t address, uint8_t value) {
	mock().actualCall(__FUNCTION__)
	    .withParameter("address", address)
	    .withParameter("value", value);
}

uint8_t read_from_i2c(uint8_t address) {
	mock().actualCall(__FUNCTION__)
	    .withParameter("address", address);
	uint8_t ret = mock().returnIntValueOrDefault(0);
	return ret;
}