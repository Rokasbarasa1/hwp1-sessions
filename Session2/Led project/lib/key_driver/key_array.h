#ifndef KEYS_DRIVER_H_
#define KEYS_DRIVER_H_
#ifndef __AVR_ATmega2560__
	#define __AVR_ATmega2560__
#endif
#include "avr/io.h"

void init_keys();
uint8_t get_key(uint8_t key_no); // key_no [1..6], return true if key pressed
uint8_t read_keys();

#endif