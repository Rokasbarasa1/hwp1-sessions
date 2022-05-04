/**
 * @file solar_panel_application.h
 * @author Rokas and Arturas (285047@via.dk, 285051@via.dk)
 * @brief
 * @version 0.1
 * @date 2022-05-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef UNIT_TEST
    #include <avr/io.h>
    #include <avr/interrupt.h>
#else
    #include "../../extras/forced_include.h"
    #include "../../extras/include/avr/io.h"
    #include "../../extras/include/avr/interrupt.h"
#endif

/**
 * Uses ports:
 * 
 * PortA 0-7
 * 
 */


void init_solar_panel_application();
void refresh();
