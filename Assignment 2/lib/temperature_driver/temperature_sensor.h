#ifndef TEMPERATURE_SENSOR_H_
	#define TEMPERATURE_SENSOR_H_

	#ifndef UNIT_TEST
		#include <avr/io.h>
		#include <avr/interrupt.h>
	#else
		#include "../../extras/forced_include.h"
		#include "../../extras/include/avr/io.h"
	#endif

	// Uses 
    //  PortG0
    //  PortK7
	void init_temperature_sensor();

#endif