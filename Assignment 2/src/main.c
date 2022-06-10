#ifndef __AVR_ATmega2560__
	#define __AVR_ATmega2560__
#endif

#define F_CPU 16000000

#include <util/delay.h>
#include <avr/interrupt.h>
#include "../lib/temperature_application/temperature_application.h"

int main(void){
	// Initialize state
	init_temperature_application();
    sei();
	
	//Event loop
	while (1){
        refresh_temperature_application();
		_delay_ms(500);
  	}
	return 0;
}