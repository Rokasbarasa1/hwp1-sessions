#ifndef KEYS_DRIVER_H_
#define KEYS_DRIVER_H_

	#if defined(DESKTOP_TESTING)
		#include "avr/io.h"
	#else
		#include "../../atmelavr/forced_include.h"
		#include "../../atmelavr/include/avr/io.h"
	#endif


void init_keys();
uint8_t get_key(uint8_t key_no); // key_no [1..6], return true if key pressed
uint8_t read_keys();

#endif