/**
 * @file temperature_application.c
 * @author Rokas and Arturas (285047@via.dk, 285051@via.dk)
 * @brief
 * @version 0.1
 * @date 2022-04-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "temperature_application.h"
#include "../segments_driver/segments_driver.h"
#include "../temperature_driver/temperature_driver.h"

void init_temperature_application()
{
    // Initialize needed drivers
    init_display();
    init_temperature_sensor();
}

void obtain_temperature()
{
    // Get temperatrue from the temperature sensor and pass it to the 7 segment display
    set_number((uint16_t)get_temperature());
}