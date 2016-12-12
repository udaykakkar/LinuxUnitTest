#pragma once
#include "I2C.h"
#include "temperature.h"
#include <stdio.h>


void somethingA(void) { }
void somethingB(void) { }

void temperature_do(uint8_t address, uint8_t value) {
	printf("temperatue-do called \n");
	 write_to_i2c(address, value);
	 const uint8_t tempReadback = read_from_i2c(address);
		if (tempReadback == value) {
		printf("somethingA called \n");
		somethingA();
	}
	else {
		printf("somethingB called \n");
		somethingB();
	}
}