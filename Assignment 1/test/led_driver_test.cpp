#include "../extras/forced_include.h"
#include <gtest/gtest.h>

extern "C"{
    #include "../extras/include/avr/io.h"
    #include "../lib/led_driver/led_driver.h"
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