#include "interrupt_keys.h"

volatile int counter = 0;

void init_interrupt_keys(){
    //Initialize the keys
    DDRD |= _BV(DDD2) | _BV(DDD3);
    PORTD |= _BV(PORTD2) | _BV(PORTD3);

    //Initialize the leds 
    DDRA = 0b11111111;
    PORTA = 0b00000000;

    // Set the interrupts to happen on the rising edge.
    // When button is let go
    EICRA |= _BV(ISC21) | _BV(ISC20) | _BV(ISC31) | _BV(ISC30);

    // Set external interrupts on int2 and int3 to be on
    // PD2 PD3 
    EIMSK |= _BV(INT2) | _BV(INT3);
}

void update_leds(){
    PORTA = 0b11111111;
    PORTA &= ~(_BV(counter));
}

// Handle the interrupt service routines
ISR(INT2_vect){
    if(counter > 0){
        counter--;
        update_leds();
    }
}

ISR(INT3_vect){
    if(counter < 7){
        counter++;
        update_leds();
    }
}
