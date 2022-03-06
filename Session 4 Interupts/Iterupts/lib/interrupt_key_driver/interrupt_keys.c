#include "interrupt_keys.h"

volatile int counter = 0;

void init_interrupt_keys(){
    //Initialize the keys
    DDRD |= _BV(DDD2) | _BV(DDD3);
    PORTD |= _BV(PORTD2) | _BV(PORTD3);

    //Initialize the leds 
    DDRA = 0b11111111;
    PORTA = 0b00000000;

    // Initialize the setting of the interrupt. Current 11, rising one 
    // When you press, only after releasing it triggers
    EICRA |= _BV(ISC21) | _BV(ISC20) | _BV(ISC31) | _BV(ISC30);

    EIMSK |= _BV(INT2) | _BV(INT3);
}

void update_leds(){
    PORTA = 0b11111111;
    PORTA &= ~(_BV(counter));
}

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
