#include "./solar_panel_application.hpp"
#include "../segments_driver/segments_driver.hpp"
#include "../matrix_driver/matrix_driver.hpp"
#include "../temperature_driver/temperature_driver.hpp"
#include "../led_driver/led_array.hpp"

int16_t current_temperature = 0;
int16_t low_temperature = 100;
int16_t high_temperature = 0;

// Modes:
// 0 - current temperature,
// 1 - low temperature,
// 2 - high temperature,
// 3 - low temperature enter mode,
// 4 - high temperature enter mode,
uint8_t mode = 0; 

// Modes:
// 0 - pump off
// 1 - pump on
uint8_t pumpMode = 0;



void init_solar_panel_application()
{
    init_display();
    init_matrix_keyboard();
    init_temperature_sensor();
    init_leds();

    set_bar(1);

    set_number_4u(9999);
}

void refresh()
{
    // Get temperatrue from the temperature sensor and pass it to the 7 segment display
    current_temperature = (int16_t)get_temperature();
    char key = getKey();
    set_number_4u((uint16_t)get_temperature());

    // Handle modes of 1 and 2 
    if (mode > 0 && mode < 3){
        if(key != '*' && key != '#'){

        }else{
            if (key == '*'){

                // save
            }else if (key == '#'){
                // cancel
            }
        }
    }else{
        if(key == '1'){
            // t low mode
            mode = 1;
        }else if (key == '2'){
            // t high mode
            mode = 2;
        }else if (key == '3'){
            // Current temperature mode
            mode = 0;
        }
    }

    // Do passive logic here
    // if (pumpMode){

    // }

    // if(key == 'x'){
    //     set_number_4u((uint16_t)get_temperature());
    // }else{
    //     set_number_4u((uint16_t)key);
    // }
}