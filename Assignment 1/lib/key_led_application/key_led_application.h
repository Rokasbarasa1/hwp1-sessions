#pragma once

#ifndef UNIT_TEST
    #include <avr/io.h>
    #include <util/delay.h>
#else
    #include "../../extras/forced_include.h"
    #include "../../extras/include/avr/io.h"
    #include "../../extras/include/util/delay.h"
#endif

#include "../led_driver/led_driver.h"
#include "../key_driver/key_driver.h"

void init_key_led_application();
void refresh_key_led_application();