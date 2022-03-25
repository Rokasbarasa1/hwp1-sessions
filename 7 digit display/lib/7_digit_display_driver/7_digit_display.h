#ifndef SEVEN_DIGIT_DISPLAY_H_
	#define SEVEN_DIGIT_DISPLAY_H_

	#ifndef UNIT_TEST
		#include <avr/io.h>

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

    // const uint8_t numbers_array[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

    void init_segments();
    void set_segments(uint8_t numbers_new[4]);
    void print_segments();


	// void set_led(uint8_t led_no, uint8_t state); //led_no [0..7], state [0..1]
	// uint8_t read_led(uint8_t led_no);
	// void set_bar(uint8_t glowing_led_no); // glowing_led_no [1..8]
	// void init_segments();

#endif