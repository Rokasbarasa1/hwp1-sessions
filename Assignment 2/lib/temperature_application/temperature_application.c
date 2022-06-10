#include "temperature_application.h"

// Measure temperature once per second. 
// Sensor must use interrupts.
// Convert temperature from sensor
// Calculate as Celsius.
// Show it on leds 1-8 as 18-25c 
void init_temperature_application(){
    //Initialize needed drivers
    init_leds();
    init_temperature_sensor();
}

void refresh_temperature_application(){
    int16_t temperature = get_temperature();

    //Logic for led bar
    if(temperature < 17){
        set_bar(0);
    }
    else if(temperature >= 18 && temperature <= 25){
        set_bar(temperature-17);
    } else if(temperature > 25){
        set_bar(8);
    }
}