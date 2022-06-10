#include "temperature_application.h"

void init_temperature_application()
{
    // Initialize needed drivers
    init_display();
    init_temperature_sensor();
}

void refresh_temperature_application()
{
    // Get temperatrue from the temperature sensor and pass it to the 7 segment display
    set_number((uint16_t)get_temperature());
}