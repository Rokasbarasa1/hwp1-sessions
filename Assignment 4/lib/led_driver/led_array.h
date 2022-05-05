/**
 * @file led_array.h
 * @author Rokas and Arturas (285047@via.dk, 285051@via.dk)
 * @brief
 * @version 0.1
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNIT_TEST
    #include <avr/io.h>
#else
    #include "../../extras/forced_include.h"
    #include "../../extras/include/avr/io.h"
#endif

/**
 * Uses ports:
 * 
 * PortA 0-7
 * 
 */

void set_led(uint8_t led_no, uint8_t state); //led_no [0..7], state [0..1]
uint8_t read_led(uint8_t led_no);
void set_bar(uint8_t glowing_led_no); // glowing_led_no [1..8]
void init_leds();
