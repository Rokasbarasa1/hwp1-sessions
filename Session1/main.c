
#ifndef __AVR_ATmega2560__
	#define __AVR_ATmega2560__
#endif
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void){
    /* Replace with your application code */
	double miliseconds = 200.0;
	while (1){
		// Delay 500 ms
		_delay_ms(miliseconds);
		// Turn on LED
        DDRB = 0b10000000;
		// Delay 500 ms 
		_delay_ms(miliseconds);
		// Turn off LED
        DDRB = 0b00000000;
    }
	return 0;
}
