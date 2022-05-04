#include "matrix_driver.hpp"
#include <Arduino.h>
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
 *  
 */

const char characters[17] = { 
    'x',
    '1', '2', '3', 'A', 
    '4', '5', '6', 'B', 
    '7', '8', '9', 'C', 
    '*', '0', '#', 'D', 
};

// ONE KEY PRESS AT A TIME
void init_matrix_keyboard(){
    {
        // Rows OUTPUT
        DDRG |= _BV(DDG5);
        DDRB |= _BV(DDB6);
        DDRH |= _BV(DDH6);
        DDRE |= _BV(DDE4);

        // // Turn off rows
        // PORTG &= ~(_BV(PG5));
        // PORTB &= ~(_BV(PB6));
        // PORTH &= ~(_BV(PH6));
        // PORTE &= ~(_BV(PE4));

        // // // Turn ON rows
        PORTG |= _BV(PG5);
        PORTB |= _BV(PB6);
        PORTH |= _BV(PH6);
        PORTE |= _BV(PE4);
    }

    {

        // // Rows OUTPUT
        // DDRL |= _BV(DDL0);
        // DDRH |= _BV(DDH4);
        // DDRL |= _BV(DDL2);
        // DDRL |= _BV(DDL3);

        // // // Turn ON rows
        // PORTL |= _BV(PL0);
        // PORTH |= _BV(PH4);
        // PORTL |= _BV(PL2);
        // PORTL |= _BV(PL3);


        // Columns INPUT
        DDRL &= ~(_BV(DDL0));
        DDRH &= ~(_BV(DDH4));
        DDRL &= ~(_BV(DDL2));
        DDRL &= ~(_BV(DDL3));

        // Turn on input
        PORTL |= _BV(PL0);
        PORTH |= _BV(PH4);
        PORTL |= _BV(PL2);
        PORTL |= _BV(PL3);
        
    }
}



uint8_t getKey(){

    uint8_t set = 0;
    uint8_t value = 0;

    for(uint8_t i = 0; i<4; i++ ){
        // break;
        // Turn on the input pin and turn off other input pins
        if(i == 0){
            PORTE &= ~(_BV(PE4));
            PORTG |= _BV(PG5);
            // Serial.println("Row 1");
        }else if(i == 1){
            PORTG &= ~(_BV(PG5));
            PORTB |= _BV(PB6);
            // Serial.println("Row 2");
        }else if(i == 2){
            PORTB &= ~(_BV(PB6));
            PORTH |= _BV(PH6);
            // Serial.println("Row 3");
        }else{
            PORTH &= ~(_BV(PH6));
            PORTE |= _BV(PE4);
            // Serial.println("Row 4");
        }

        // _delay_ms(500);
        for(int8_t j = 0; j<4; j++ ){
            //Check input of each of the input pins.
            //If found input break both loops
            //Remember indexes and determine the value in that key by that
            uint8_t keyValue = 0;
            if(j == 0){
                keyValue = PINL & _BV(PL0);
            }else if(j == 1){
                keyValue = PINH & _BV(PH4);
            }else if(j == 2){
                keyValue = PINL & _BV(PL2);
            }else{
                keyValue = PINL & _BV(PL3);
            }


            if(!keyValue){

                set = 1;
                value = (i*4)+(j+1);
                break;
            }
        }
        
        if(set){
            break;
        }
    }

    // if(value == 0){
    //     Serial.println(0);

    // }else{
    //     Serial.println(1);
    // }


    // return characters[value];

    // 
    
    Serial.println(characters[value]);

    return value;

}