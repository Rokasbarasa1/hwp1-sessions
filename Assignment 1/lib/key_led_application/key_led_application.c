#include "key_led_application.h"

// The two keys are the right most keys if the digit display is above
// The two led's over the keys are always on to indicate problems

// How it should work. 
// X - pressed, O - not pressed

// X0 - 0XXX00

// 0X - 0XXX00

// 00 - 000XXX

// XX - XX000X

void init_key_led_application(){
	// Initialize state
	init_leds();
	init_keys();

	// Status indication leds
	set_led(PORTA0, 1);
	set_led(PORTA1, 1);
}


void refresh_key_led_application(){
    uint8_t switches[6]; 

    //Gather all events
    for (uint8_t i = 0; i<6; i++){
        if(get_key_status(i) == (1<<i)){
            switches[i] = 0;
        }else{
            switches[i] = 1;
        }
    }

    //React to events
    {
        //AND
        if(switches[0] == 1 && switches[1] == 1){
            set_led(PORTA7, 1);
        }else{
            set_led(PORTA7, 0);
        }

        //OR
        if(switches[0] == 1 || switches[1] == 1){
            set_led(PORTA6, 1);
        }else{
            set_led(PORTA6, 0);
        }

        //XOR
        if(switches[0] != switches[1]){
            set_led(PORTA5, 1);
        }else{
            set_led(PORTA5, 0);
        }

        //NAND
        if(!(switches[0] == 1 && switches[1] == 1)){
            set_led(PORTA4, 1);
        }else{
            set_led(PORTA4, 0);
        }

        //NOR
        if(switches[0] == 0 && switches[1] == 0){
            set_led(PORTA3, 1);
        }else{
            set_led(PORTA3, 0);
        }

        //XNOR
        if(switches[0] == 0 && switches[1] == 0 || switches[0] == 1 && switches[1] == 1){
            set_led(PORTA2, 1);
        }else{
            set_led(PORTA2, 0);
        }
    }
}