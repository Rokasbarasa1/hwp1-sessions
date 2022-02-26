#include "../../extras/forced_include.h"
#include <gtest/gtest.h>
// #define DESKTOP_TESTING true

extern "C"{
    #include "../../extras/include/avr/io.h"
    #include "../../lib/led_driver/led_array.h"
}

TEST(add, test_if_test_good){
    init_leds();
    DDRA = 0x00000000;
    int expected = 5;
    int actual = 5;

    ASSERT_EQ(expected, actual);
    ASSERT_EQ(DDRA, 0x00000000);
}