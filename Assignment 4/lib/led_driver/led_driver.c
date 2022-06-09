/**
 * @file led_array.c
 * @author Rokas and Arturas (285047@via.dk, 285051@via.dk)
 * @brief
 * @version 0.1
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "led_array.h"

void init_leds(){
    // Output high for all leds to turn them off.
    DDRA = 0b11111111;
    PORTA = 0b11111111;
}

//Set status of led in portA of leds.
void set_led(uint8_t led_no, uint8_t state){
    if(state == 0 || state == 1){
        if(led_no >= 0 && led_no < 8){
            if(state == 1){
                PORTA &= ~(_BV(led_no)); //Set to 0 to turn on led
            }else{
                PORTA |= _BV(led_no); //Set to 1 to turn on led
            }
        }
    }
}
 
uint8_t read_led(uint8_t led_no){	
    return (PINA & _BV(led_no));
}

void set_bar(uint8_t glowing_led_no){
    if(glowing_led_no < 9){
        //Shift bits in loop to fill how many leds are lit up
        uint8_t leds_status = 0b11111111;
        for(uint8_t i = 0; i < glowing_led_no; i++){
            leds_status &= ~(1<<i);
        }
        PORTA = leds_status;
    }
}