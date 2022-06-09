/**
 * @file key_array.h
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
 * PortC 0-5
 * 
 */

void init_keys();
uint8_t get_button(uint8_t key_no); // key_no [1..6], return number if it is pressed
uint8_t read_keys();
