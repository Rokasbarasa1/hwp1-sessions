#ifndef __AVR_ATmega2560__
	#define __AVR_ATmega2560__
#endif

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "../lib/temperature_application/temperature_application.h"
#include "../lib/7_digit_display_driver/7_digit_display.h"
// Meassure temperature once per second. 
// Sensor must use interrupts.
// Convert temperature from sensor
// Calculate as celcius.
// Show it on leds 1-8 as 18-25c 

int main(void){
	// Initialize state
	init_temperature_application();
    sei();
	
	init_segments();
	uint8_t digits[] = {ONE, ZERO, ONE, NINE};
	set_segments(digits);

	//Event loop
	while (1){
		// Turn on LED
		// DDRB |= _BV(DDB7);
		// _delay_ms(5);
		
		// // Turn off LED
		// DDRB &= ~(_BV(DDB7));
        // _delay_ms(5);

		print_segments();
		_delay_ms(10);

  	}
	return 0;
}