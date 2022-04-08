#include "temperature_application.h"

#include "../7_digit_display_driver/7_digit_display.h"
#include "../temperature_driver_fixed/temperature_sensor.h"

void init_temperature_application()
{
    // Initialize needed drivers
    init_segments();
    init_temperature_sensor();
}

void obtain_temperature()
{
    set_number((uint16_t)get_temperature());
}