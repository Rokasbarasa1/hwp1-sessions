#include "7_digit_display.h"

// uint8_t digits[4] = [0b11111111,0b11111111,0b11111111,0b11111111];
uint8_t digit_one = 0b11111111;
uint8_t digit_two = 0b11111111;
uint8_t digit_three = 0b11111111;
uint8_t digit_four = 0b11111111;


void init_segments(){
    // RCK = PB0
    // SCK = PB1
    // SI  = PB2
    
    DDRB |= _BV(DDB0);
    DDRB |= _BV(DDB1);
    DDRB |= _BV(DDB2);
     // ADDD DDR
    PORTB &= ~(_BV(PB0));
    PORTB &= ~(_BV(PB1));
    PORTB &= ~(_BV(PB2));

    // = PF3
    // = PF2
    // = PF1
    // = PF0

    DDRF |= _BV(DDF0);
    DDRF |= _BV(DDF1);
    DDRF |= _BV(DDF2);
    DDRF |= _BV(DDF3);

    PORTF |= _BV(PF0);
    PORTF |= _BV(PF1);
    PORTF |= _BV(PF2);
    PORTF |= _BV(PF3);
}


void set_segments(uint8_t numbers_new[4]){
    digit_one = numbers_new[0];
    digit_two = numbers_new[1];
    digit_three = numbers_new[2];
    digit_four = numbers_new[3];
}

void print_segments(){
    const uint8_t digits[] = {digit_one, digit_two, digit_three, digit_four};

    for(uint8_t i = 0; i<4; i++){
        
        for(uint8_t j = 0; j<8; j++){
            //Get least significant bit
            uint8_t bitStatus = (digit_one >> (j+1)) & 1;

            PORTB |= _BV(PB2);
            // if(bitStatus){
            //     PORTB |= _BV(PB2);
            // }else{
            //     PORTB &= ~(_BV(PB2));
            // }

            // Put the bit in the shift register
            PORTB |= _BV(PB1);
            PORTB &= ~(_BV(PB1));
        }

        // Put the data from the loop into 
        PORTB |= _BV(PB0);
        PORTB &= ~(_BV(PB0));

        if(i != 0){
            PORTF &= ~(_BV(PF0+i-1));
        }
        PORTF &= ~(_BV(PF0 + i));
    }

}