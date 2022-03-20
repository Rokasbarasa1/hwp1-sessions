#ifndef DEPENDENCY_DRIVER_H_
	#define DEPENDENCY_DRIVER_H_

    #ifndef UNIT_TEST
		#include <avr/io.h>
	#else
		#include "../../../extras/forced_include.h"
		#include "../../../extras/include/avr/io.h"
	#endif

	void hal_create(uint8_t portNo);
    int16_t hal_getVoltage(uint8_t channel);

	// void set_led(uint8_t led_no, uint8_t state); //led_no [0..7], state [0..1]
	// uint8_t read_led(uint8_t led_no);

#endif