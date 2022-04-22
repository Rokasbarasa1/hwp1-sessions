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
	
	typedef void (*functiontype)(int16_t);

	void init_temperature_sensor_callback(functiontype call_back);
	int16_t sample_to_temperature(uint16_t sample);

#endif