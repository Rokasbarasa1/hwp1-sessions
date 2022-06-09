#ifndef __AVR_ATmega2560__
	#define __AVR_ATmega2560__
#endif

#define F_CPU 16000000

#include "../lib/key_led_application/key_led_application.h"

int main(void){
	// Initialize state
    init_key_led_application();

	//Event loop
	while(1){
        //To save power
        refresh_key_led_application();
        _delay_ms(20);
	}
	return 0;
}