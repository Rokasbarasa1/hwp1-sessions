#include "callback.h"

static void (*cb1)() = 0;
static void (*cb2)() = 0;

void init_callback(void (*call_back_down)(), void (*call_back_up)()){
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

    if(call_back_down != 0){
        cb1 = call_back_down;
    }
    
    if(call_back_down != 0){
        cb2 = call_back_up;
    }
}


ISR(INT2_vect){
	if(cb1 != 0){
        cb1();
    }
}

ISR(INT3_vect){
	if(cb2 != 0){
        cb2();
    }
}