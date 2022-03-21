#include "led_array.h"

void init_leds(){
    PORTA = 0b00000000; // Output low. High doesn't work.
}

//Set status of led in portA of leds.
void set_led(uint8_t led_no, uint8_t state){
    if(state == 0 || state == 1){
        if(led_no >= 0 && led_no < 8){
            if(state == 1){
                DDRA |= _BV(led_no);
            }else{
                DDRA &= ~(_BV(led_no));
            }
        }
    }
}

uint8_t read_led(uint8_t led_no){	
    return (PINA & _BV(led_no));
}