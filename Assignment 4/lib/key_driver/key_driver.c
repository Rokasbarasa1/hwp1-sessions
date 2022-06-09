/**
 * @file key_array.c
 * @author Rokas and Arturas (285047@via.dk, 285051@via.dk)
 * @brief
 * @version 0.1
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "key_driver.h"

void init_keys(){
    //Change status of 6 button registers
    //Port C
    DDRC |= _BV(DDC0) | _BV(DDC1) | _BV(DDC2) | _BV(DDC3) | _BV(DDC4) | _BV(DDC5);
    PORTC |= _BV(PORTC0) | _BV(PORTC1) | _BV(PORTC2) | _BV(PORTC3) | _BV(PORTC4) | _BV(PORTC5);
}

// Gets the number. If number is not pressed it returns 0 if it is pressed it returns more than zero 
uint8_t get_button(uint8_t key_no){
    if(key_no >= 0 && key_no < 6){
        return (PINC & _BV(key_no));
    }
}