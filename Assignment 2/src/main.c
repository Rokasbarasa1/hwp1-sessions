#ifndef __AVR_ATmega2560__
	#define __AVR_ATmega2560__
#endif

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "../lib/temperature_driver/temperature_sensor.h"

// Meassure temperature once per second. 
// Sensor must use interrupts.
// Convert temperature from sensor
// Calculate as celcius.
// Show it on leds 1-8 as 18-25c 

int main(void){
	// Initialize state
	// Serial.begin(115200);
	init_temperature_sensor();
	sei();
	//Event loop
	
	while (1){
		_delay_ms(200);
		// Turn on LED
		DDRB |= _BV(DDB7);

		_delay_ms(200);
		// Turn off LED
		DDRB &= ~(_BV(DDB7));
  	}
	return 0;
}