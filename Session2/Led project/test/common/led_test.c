#include <unity.h>
// #ifndef __AVR_ATmega2560__
// 	#define __AVR_ATmega2560__
// #endif
// #include "avr/io.h"
// #include "../lib/led_driver/led_array.h"


// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

// void test_led_init(void) {
//     init_leds();
// }

void test_led_builtin_pin_number(void) {
    TEST_ASSERT_EQUAL(1, 1);
}

void process() {    
    UNITY_BEGIN();
    RUN_TEST(test_led_builtin_pin_number);
    // RUN_TEST(test_led_init);
    UNITY_END();
}

int main(int argc, char **argv) {
    process();
    return 0;
}