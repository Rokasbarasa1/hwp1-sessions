/**
 * @file main.c
 * @author Rokas and Arturas (285047@via.dk, 285051@via.dk)
 * @brief
 * @version 0.1
 * @date 2022-04-15
 *
 * @copyright Copyright (c) 2022
 *
 */

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
    sei();

    // Event loop
    while (1)
    {
        _delay_ms(1000);
        obtain_temperature();
    }
    return 0;
}