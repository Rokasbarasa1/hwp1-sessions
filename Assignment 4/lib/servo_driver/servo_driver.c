#include "./servo_driver.h"

void init_servo(){
    DDRL |= _BV(DDL4);
    //move to 90 (neutral postition)
    PORTL |= _BV(PL4);
    _delay_us(1450);
    PORTL &= ~_BV(PL4);
    _delay_ms(1000);
}

void move_CCW(){
    PORTL |= _BV(PL4);
    _delay_us(2300);
    PORTL &= ~_BV(PL4);
    _delay_ms(1000);
}

void move_CW(){
    PORTL |= _BV(PL4);
    _delay_us(600);
    PORTL &= ~_BV(PL4);
    _delay_ms(1000);
}
