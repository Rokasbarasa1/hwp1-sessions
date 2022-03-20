#ifndef LED_DRIVER_H_
	#define LED_DRIVER_H_

	#ifndef UNIT_TEST
		#include <avr/io.h>
	#else
		#include "../../extras/forced_include.h"
		#include "../../extras/include/avr/io.h"
	#endif

	void init_leds();
	void set_led(uint8_t led_no, uint8_t state); //led_no [0..7], state [0..1]
	uint8_t read_led(uint8_t led_no);

#endif