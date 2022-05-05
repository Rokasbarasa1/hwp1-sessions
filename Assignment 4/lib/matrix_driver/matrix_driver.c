#include "matrix_driver.h"
// #include <Arduino.h>
/** 
 * Rows
 * OC0B - PG5 - 8
 * OC1B - PB6 - 7
 * OC2B - PH6 - 6
 * OC3B - PE4 - 5
 * 
 * 
 * Columns 
 * ICP4 - PL0 - 4
 * OC4B - PH4 - 3
 * T5   - PL2 - 2
 * OC5A - PL3 - 1
 */

/**
 *  1, 2, 3, A
 *  4, 5 ,6, B
 *  7, 8, 9, C
 *  *, 0, #, D
 */

const char characters[17] = { 
    'x',
    '1', '2', '3', 'A', 
    '4', '5', '6', 'B', 
    '7', '8', '9', 'C', 
    '*', '0', '#', 'D', 
};


void init_matrix_keyboard(void) {

	// configure rows as outputs
	DDRD |= _BV(PD7);
	DDRG |= _BV(PG5);
	DDRB |= _BV(PB6);
	DDRH |= _BV(PH6);

	// set rows to HIGH
	PORTD |= _BV(PD7);
	PORTG |= _BV(PG5);
	PORTB |= _BV(PB6);
	PORTH |= _BV(PH6);

	// configure columns as inputs
	DDRE &= ~(_BV(PE4));
	DDRL &= ~(_BV(PL0));
	DDRH &= ~(_BV(PH4));
	DDRL &= ~(_BV(PL2));

	// enable pullup resistors
	PORTE |= _BV(PE4);
	PORTL |= _BV(PL0);
	PORTH |= _BV(PH4);
    PORTL |= _BV(PL2);
}

uint8_t getKey() {
    uint8_t value = 0;

    for(uint8_t i = 0; i<4; i++){
        if(i == 0){
	        PORTD &= ~(_BV(PD7));
        }else if (i == 1){
            PORTG &= ~(_BV(PG5));
        }else if (i == 2){
            PORTB &= ~(_BV(PB6));
        }else if (i == 3){
            PORTH &= ~(_BV(PH6));
        }

        if(~PINE & _BV(PE4)){
            value = (i*4) + 1;
        }else if(~PINL & _BV(PL0)){
            value = (i*4) + 2;
        }else if(~PINH & _BV(PH4)){
            value = (i*4) + 3;
        }else if(~PINL & _BV(PL2)){
            value = (i*4) + 4;
        }

        if(i == 0){
	        PORTD |= _BV(PD7);
        }else if (i == 1){
	        PORTG |= _BV(PG5);
        }else if (i == 2){
            PORTB |= _BV(PB6);
        }else if (i == 3){
            PORTH |= _BV(PH6);
        }
    }

    return characters[value];
}