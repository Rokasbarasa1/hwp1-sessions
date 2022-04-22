#ifndef SEVEN_DIGIT_DISPLAY_H_
	#define SEVEN_DIGIT_DISPLAY_H_

	#ifndef UNIT_TEST
		#include <avr/io.h>
        #include <util/delay.h>
        #include <avr/interrupt.h>
	#else
		#include "../../extras/forced_include.h"
		#include "../../extras/include/avr/io.h"
	#endif

    #define ZERO    0b00000011
    #define ONE     0b10011111
    #define TWO     0b00100101
    #define THREE   0b00001101
    #define FOUR    0b10011001
    #define FIVE    0b01001001
    #define SIX     0b01000001
    #define SEVEN   0b00011111
    #define EIGHT   0b00000001
    #define NINE    0b00001001


    void init_segments();
    void set_segments(uint8_t numbers_new[4]);
    void set_number(uint16_t number);
    void print_segments();

#endif