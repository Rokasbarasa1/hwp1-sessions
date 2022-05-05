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

int8_t uInput1 = 20;
int8_t uInput2 = 20;
int8_t uInput3 = 20;
int8_t uInput4 = 20;

// int8_t uInput1 = 7;
// int8_t uInput2 = 2;
// int8_t uInput3 = 8;
// int8_t uInput4 = 9;

uint8_t keyReset = 1;
uint16_t previousKey = 0;
int current_index = 0;

void init_solar_panel_application()
{
    init_display();
    init_matrix_keyboard();
    // init_temperature_sensor();
    // init_leds();

    // DDRG |= _BV(DDG5);

    // PORTG |= _BV(PG5);
    // PORTG &= ~(_BV(PG5));


    // set_bar(1);
}
// const char characters[17] = { 
//     '1',
//     '5', '3', '7', '1', 
//     '4', '5', '6', 'B', 
//     '7', '8', '9', 'C', 
//     '*', '0', '#', 'D', 
// };

void refresh()
{
    char key = getKey();
    set_number_4u((uint16_t)key);

    // if (key != previousKey){

    //     // Handle modes of 1 and 2 
    //     if (mode > 0 && mode < 3){
    //         if(key != '*' && key != '#'){
    //             // inputs display as this on segments: 1, 2, 3, 4
    //             if (uInput4 == 20){
    //                 uInput4 = ((int)key) - 48; // 0 in ascii is 48
    //             }else if(uInput3 == 20){
    //                 uInput3 = uInput4;
    //                 uInput4 = ((int)key) - 48;
    //             }else if(uInput2 == 20){
    //                 uInput2 = uInput3;
    //                 uInput3 = uInput4;
    //                 uInput4 = ((int)key) - 48;
    //             }else if(uInput1 == 20){
    //                 uInput1 = uInput2;
    //                 uInput2 = uInput3;
    //                 uInput3 = uInput4;
    //                 uInput4 = ((int)key) - 48;
    //             }

    //             uint16_t number_to_show = 0;
    //             if(uInput1 != 20){
    //                 number_to_show += uInput1*1000; // Combine the numbers digit by digit
    //             }
                
    //             if(uInput2 != 20){
    //                 number_to_show += uInput2 * 100;
    //             }
                
    //             if(uInput3 != 20){
    //                 number_to_show += uInput3*10;
    //             }
                
    //             if(uInput4 != 20){
    //                 number_to_show += uInput4;
    //             }

    //             set_number_4u(number_to_show);

    //         }else{
    //             if (key == '*'){

    //                 // save
    //             }else if (key == '#'){
    //                 // cancel
    //             }
                
    //         }
    //     }else{
    //         if(key == '1'){
    //             // t low mode
    //             mode = 1;
    //         }else if (key == '2'){
    //             // t high mode
    //             mode = 2;
    //         }else if (key == '3'){
    //             // Current temperature mode
    //             mode = 0;
    //         }

    //         // Handle display in the mode
    //         if (mode == 0){
    //             set_number_4u((uint16_t)get_temperature());
    //         }else if(mode == 3){
    //             set_number_4u(low_temperature);
    //         }else if(mode == 4){
    //             set_number_4u(high_temperature);
    //         }
    //     }

    // }

    // Do passive logic here
    // if (pumpMode){

    // }

    // if(key == 'x'){
    //     set_number_4u((uint16_t)get_temperature());
    // }else{
    //     set_number_4u((uint16_t)key);
    // }

    previousKey = key;
    // if( current_index < 5){
    //     current_index++;
    // }
}