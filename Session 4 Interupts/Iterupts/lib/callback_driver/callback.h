#ifndef CALLBACK_H_
	#define CALLBACK_H_

    #include <avr/io.h>
	#include <avr/interrupt.h>

    void init_callback(void (*call_back_down)(), void (*call_back_up)());

#endif