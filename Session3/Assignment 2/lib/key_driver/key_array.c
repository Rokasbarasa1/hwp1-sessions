#include "key_array.h"

void init_keys(){
    //Port C
    PORTC |= _BV(PORTC0) | _BV(PORTC1) | _BV(PORTC2) | _BV(PORTC3) | _BV(PORTC4) | _BV(PORTC5);
    DDRC |= _BV(DDC0) | _BV(DDC1) | _BV(DDC2) | _BV(DDC3) | _BV(DDC4) | _BV(DDC5);

    DDRC = 0b00000000;
    PORTC = 0b11111111;
}

uint8_t get_key(uint8_t key_no){
    if(key_no >= 0 && key_no < 6){
        return (PINC & _BV(key_no));
    }
}