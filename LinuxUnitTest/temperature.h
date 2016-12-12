#pragma once
#include <stdint.h>
extern "C" {
#include "I2C.h"
};

void somethingA(void); 
void somethingB(void); 
void temperature_do(uint8_t address, uint8_t value);

