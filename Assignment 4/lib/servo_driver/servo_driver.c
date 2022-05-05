/**
 * @file servo_driver.c
 * @author Rokas and Arturas (285047@via.dk, 285051@via.dk)
 * @brief
 * @version 0.1
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "./servo_driver.h"

// No pwm is needed because servos are built to get a single pulse and remember it.
// Need specifc timed pulse of high and low for the pwm pin of the servo
void init_servo(){
    //move to 90 (neutral postition)
    DDRL |= _BV(DDL4);
    PORTL |= _BV(PL4);
    _delay_us(1450);
    PORTL &= ~_BV(PL4);
    _delay_ms(1000);
}

// Move the servo counter clockwise
void move_CCW(){
    PORTL |= _BV(PL4);
    _delay_us(2300);
    PORTL &= ~_BV(PL4);
    _delay_ms(1000);
}

// Move the servo clockwise
void move_CW(){
    PORTL |= _BV(PL4);
    _delay_us(600);
    PORTL &= ~_BV(PL4);
    _delay_ms(1000);
}
