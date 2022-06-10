#pragma once

#ifndef UNIT_TEST
    #include <avr/io.h>
    #include <avr/interrupt.h>
#else
    #include "../../extras/forced_include.h"
    #include "../../extras/include/avr/io.h"
    #include "../../extras/include/avr/interrupt.h"
#endif

#include "../segments_driver/segments_driver.h"
#include "../temperature_driver/temperature_driver.h"

void init_temperature_application();
void refresh_temperature_application();