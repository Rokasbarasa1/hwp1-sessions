#ifndef __AVR_ATmega2560__
	#define __AVR_ATmega2560__
#endif

#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>


//INTERRUPT
#include "../lib/interrupt_key_driver/interrupt_keys.h"

//TIMER
// #include "../lib/timer_driver/timer.h"

//CALLBACK INTERRUPT
// #include "../lib/callback_driver/callback.h"

// volatile int counter = 0;

// void update_leds(){
//     PORTA = 0b11111111;
//     PORTA &= ~(_BV(counter));
// }

// void call_back1(){
//     if(counter > 0){
//         counter--;
//         update_leds();
//     }
// }

// void call_back2(){
//     if(counter < 7){
//         counter++;
//         update_leds();
//     }
// }

//INTERUPT TIMER

int main(void){
	// Initialize state
    
    //TIMER
    // init_timer();

    // INTERRUPT
    init_interrupt_keys();
	sei();

    // CALLBACK INTERRUPT
    // init_callback(call_back1, call_back2);
	// sei();
	
	while(1){}
	return 0;
}