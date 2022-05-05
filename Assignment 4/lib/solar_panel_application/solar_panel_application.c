#include "./solar_panel_application.h"
#include "../segments_driver/segments_driver.h"
#include "../matrix_driver/matrix_driver.h"
#include "../temperature_driver/temperature_driver.h"
#include "../led_driver/led_array.h"

int16_t current_temperature = 515;
int16_t low_temperature = 100;
int16_t high_temperature = 444;

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

int8_t userInput1 = 20;
int8_t userInput2 = 20;
int8_t userInput3 = 20;
int8_t userInput4 = 20;

uint8_t keyReset = 1;
uint16_t previousKey = 0;
uint16_t sameKeyCount = 0;

int current_index = 0;

void init_solar_panel_application()
{
    init_display();
    init_matrix_keyboard();
    init_temperature_sensor();
    init_leds();

    set_bar(1);
}

void refresh()
{
    char key = getKey();

    if(key != 120){
        if(key == '1' && mode != 1 && mode != 2 && sameKeyCount == 30){
            // t low mode
            mode = 1;
            sameKeyCount = 0;
        }else if (key == '2' && mode != 1 && mode != 2 && sameKeyCount == 30){
            // t high mode
            mode = 2;
            sameKeyCount = 0;
        }else if (key == '3' && mode != 1 && mode != 2 && sameKeyCount == 30){
            // Current temperature mode
            mode = 0;
            sameKeyCount = 0;
        }

    }

    if(mode == 0){
        handle_mode_one(key);
        set_bar(1);
    }else if(mode == 1 || mode == 2){
        handle_mode_two_three(key);
        set_bar(3);
    }else if(mode == 3){
        handle_mode_four(key);
        set_bar(4);
    }else if(mode == 4){
        handle_mode_five(key);
        set_bar(5);
    }


    if (previousKey == key){
        if(sameKeyCount < 30){
            sameKeyCount++;
        }
    }else{
        sameKeyCount = 0;
        previousKey = key;
    }
}


void handle_mode_one(char key){
    set_number_4u((uint16_t)get_temperature());
}

void handle_mode_two_three(char key){
    if(key != '*' && key != '#' && sameKeyCount == 30 && key != 120 ){
        // inputs display as this on segments: 1, 2, 3, 4
        if (userInput4 == 20){
            userInput4 = ((int)key) - 48; // 0 in ascii is 48
        }else if(userInput3 == 20){
            userInput3 = userInput4;
            userInput4 = ((int)key) - 48;
        }else if(userInput2 == 20){
            userInput2 = userInput3;
            userInput3 = userInput4;
            userInput4 = ((int)key) - 48;
        }else if(userInput1 == 20){
            userInput1 = userInput2;
            userInput2 = userInput3;
            userInput3 = userInput4;
            userInput4 = ((int)key) - 48;
        }

        uint16_t number_to_show = 0;

        // Combine the numbers digit by digit
        if(userInput1 != 20)
            number_to_show += userInput1*1000;
        if(userInput2 != 20)
            number_to_show += userInput2*100;
        if(userInput3 != 20)
            number_to_show += userInput3*10;
        if(userInput4 != 20)
            number_to_show += userInput4;

        set_number_4u(number_to_show);
        sameKeyCount = 0;
    }else if(previousKey != key && key != 120 ){
        if (key == '*'){
            // save
            uint16_t number_to_show = 0;

            // Combine the numbers digit by digit
            if(userInput1 != 20)
                number_to_show += userInput1*1000;         
            if(userInput2 != 20)
                number_to_show += userInput2*100;        
            if(userInput3 != 20)
                number_to_show += userInput3*10;
            if(userInput4 != 20)
                number_to_show += userInput4;

            if(mode == 1){
                low_temperature = number_to_show;
                mode = 3;
            }else if (mode == 2){
                high_temperature = number_to_show;
                mode = 4;
            }
            sameKeyCount = 0;

        }else if (key == '#'){
            // cancel
            userInput1 = 20;
            userInput2 = 20;
            userInput3 = 20;
            userInput4 = 20;
            if(mode == 1){
                mode = 3;
            }else if(mode == 2){
                mode = 4;
            }
            sameKeyCount = 0;
        }
    }else{
        if(mode == 1 || mode == 2){
            uint16_t number_to_show = 0;

            // Combine the numbers digit by digit
            if(userInput1 != 20)
                number_to_show += userInput1*1000;
            if(userInput2 != 20)
                number_to_show += userInput2*100;
            if(userInput3 != 20)
                number_to_show += userInput3*10;
            if(userInput4 != 20)
                number_to_show += userInput4;

            set_number_4u(number_to_show);
        }else if (mode){

        }

    }
}

void handle_mode_four(char key){
    set_number_4u(low_temperature);
}

void handle_mode_five(char key){
    set_number_4u(high_temperature);
}