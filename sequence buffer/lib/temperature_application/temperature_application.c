#include "temperature_application.h"
#include "../led_driver/led_array.h"
#include "../temperature_driver/temperature_sensor.h"

int16_t temperature = -40;

//Callback to handle temperature driver
void interrupt_callback(int16_t result){
	temperature = result;

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

void init_temperature_application(){
    //Initialize needed drivers
    init_leds();
    init_temperature_sensor_callback(interrupt_callback);
}