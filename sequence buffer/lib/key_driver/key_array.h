#ifndef KEYS_DRIVER_H_
	#define KEYS_DRIVER_H_

	#ifndef UNIT_TEST
		#include <avr/io.h>
	#else
		#include "../../extras/forced_include.h"
		#include "../../extras/include/avr/io.h"
	#endif

	// Uses PortC 0-5
	void init_keys();
	uint8_t get_key(uint8_t key_no); // key_no [1..6], return true if key pressed
	uint8_t read_keys();

#endif