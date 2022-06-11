#include "../../extras/forced_include.h"
#include <gtest/gtest.h>

extern "C"{
    #include "../../extras/include/avr/io.h"
    #include "../../lib/key_driver/key_driver.h"
}

class KEYDriverTest : public ::testing::Test {
	protected:
		void SetUp() {

		}
		void TearDown() {

		}
};

TEST_F(KEYDriverTest, unit_init_keys) {
    //Set some registers to 1 to make checks easier
    DDRC |= _BV(DDC6) | _BV(DDC7);
    PORTC |= _BV(PORTC6) | _BV(PORTC7);

    init_keys(); // sets bits 0-5 as 1

	EXPECT_EQ(DDRC, 0b11111111);
	EXPECT_EQ(PORTC, 0b11111111);
}

TEST_F(KEYDriverTest, unit_get_key_not_pressed) {

    init_keys();
    
    EXPECT_TRUE(!get_key_status(0));
    EXPECT_TRUE(!get_key_status(1));
    EXPECT_TRUE(!get_key_status(2));
    EXPECT_TRUE(!get_key_status(3));
    EXPECT_TRUE(!get_key_status(4));
    EXPECT_TRUE(!get_key_status(5));
}

TEST_F(KEYDriverTest, unit_get_key_pressed) {

    init_keys();
    //Set all 6 key pins to 1 
    PINC |= _BV(PORTC0) | _BV(PORTC1) | _BV(PORTC2) | _BV(PORTC3) | _BV(PORTC4) | _BV(PORTC5);

    EXPECT_TRUE(get_key_status(0));
    EXPECT_TRUE(get_key_status(1));
    EXPECT_TRUE(get_key_status(2));
    EXPECT_TRUE(get_key_status(3));
    EXPECT_TRUE(get_key_status(4));
    EXPECT_TRUE(get_key_status(5));
}