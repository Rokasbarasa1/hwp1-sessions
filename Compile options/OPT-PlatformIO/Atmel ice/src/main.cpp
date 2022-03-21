#ifndef __AVR_ATmega2560__
	#define __AVR_ATmega2560__
#endif
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void){
	PORTC |= _BV(PORTC0) | _BV(PORTC1);
	DDRC &= ~(_BV(DDC0) | _BV(DDC1));

	uint8_t statusC0 = PINC & _BV(PINC0);
	if(statusC0 == 1){
		DDRA = 0b00000001;
	}

	while (1){
		// Delay 500 ms
		// _delay_ms(miliseconds);

		// // Turn on LED
		// // PORTA = 0b10000001;
		// DDRA = 0b10000001;

		// // Delay 500 ms 
		// _delay_ms(miliseconds);
		// // Turn off LED
		// // PORTA = 0b11111111;
		// DDRA = 0b11111111;


  	}
	return 0;
}