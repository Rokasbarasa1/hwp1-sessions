#ifndef TEMPERATURE_SENSOR_H_
#define TEMPERATURE_SENSOR_H_

#ifndef UNIT_TEST
#include <avr/io.h>
#include <avr/interrupt.h>
#else
#include "../../extras/forced_include.h"
#include "../../extras/include/avr/io.h"
#include "../../extras/include/avr/interrupt.h"
#endif

void init_temperature_sensor();
int16_t sample_to_temperature(uint16_t sample);
int16_t get_temperature();
#endif