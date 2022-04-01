#ifndef __AVR_ATmega2560__
#define __AVR_ATmega2560__
#endif

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "../lib/temperature_display_applicaiton/temperature_application.h"

int main(void)
{
    // Initialize state
    init_temperature_application();
    init_segments();
    sei();

    // Event loop
    while (1)
    {
        _delay_ms(1000);
        show_temperature();
    }
    return 0;
}