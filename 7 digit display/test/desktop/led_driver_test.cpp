#include "../../extras/forced_include.h"
#include <gtest/gtest.h>

extern "C"{
    #include "../../extras/include/avr/io.h"
	#include "../../lib/led_driver/led_array.h"
}

class LEDDriverTest : public ::testing::Test {
	protected:
		void SetUp() {

		}
		void TearDown() {

		}
};

TEST_F(LEDDriverTest, Init_leds) {
    init_leds();
	EXPECT_EQ(DDRA, 0b11111111);
	EXPECT_EQ(PORTA, 0b11111111);
}

TEST_F(LEDDriverTest, Set_led_on) {
    init_leds();
	//When led is set to on it sets the port pin to 0
	set_led(PORTA0, 1);
	set_led(PORTA2, 1);
	set_led(PORTA4, 1);
	set_led(PORTA6, 1);
	EXPECT_EQ(DDRA, 0b11111111);
	EXPECT_EQ(PORTA, 0b10101010);
}

TEST_F(LEDDriverTest, Set_led_off) {
    init_leds();
	//When led is set to on it sets the port pin to 0
	set_led(PORTA1, 0);
	set_led(PORTA2, 0);
	set_led(PORTA4, 0);
	set_led(PORTA7, 0);
	EXPECT_EQ(DDRA, 0b11111111);
	EXPECT_EQ(PORTA, 0b11111111);
}

TEST_F(LEDDriverTest, Set_bar_off) {
    init_leds();
	set_bar(0);
	EXPECT_EQ(PORTA, 0b11111111);
}

TEST_F(LEDDriverTest, Set_bar_on_1) {
    init_leds();
	set_bar(1);
	EXPECT_EQ(PORTA, 0b11111110);
}

TEST_F(LEDDriverTest, Set_bar_on_5) {
    init_leds();
	set_bar(5);
	EXPECT_EQ(PORTA, 0b11100000);
}

TEST_F(LEDDriverTest, Set_bar_on_7) {
    init_leds();
	set_bar(7);
	EXPECT_EQ(PORTA, 0b10000000);
}

TEST_F(LEDDriverTest, Set_bar_on_8) {
    init_leds();
	set_bar(8);
	EXPECT_EQ(PORTA, 0b00000000);
}

TEST_F(LEDDriverTest, Set_bar_on_above_error) {
    init_leds();
	set_bar(9);
	EXPECT_EQ(PORTA, 0b11111111);
}