/**
 * @file servo_driver.h
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
    #include <util/delay.h>
#else
    #include "../../extras/forced_include.h"
    #include "../../extras/include/avr/io.h"
#endif

/**
 * Uses ports:
 * 
 * PortL 4
 * 
 */

void init_servo();
void move_CCW();
void move_CW();
