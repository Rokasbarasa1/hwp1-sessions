#include "../../extras/forced_include.h"
#include <gtest/gtest.h>
#include "../../extras/fff.h"

DEFINE_FFF_GLOBALS

extern "C"{
    #include "../../lib/key_driver/key_driver.h"
    #include "../../lib/led_driver/led_driver.h"
    #include "../../lib/key_led_application/key_led_application.h"
}

FAKE_VOID_FUNC(init_leds);
FAKE_VOID_FUNC(init_keys);
FAKE_VOID_FUNC(set_led, uint8_t, uint8_t);
FAKE_VALUE_FUNC(uint8_t, get_key_status, uint8_t);

class KeyLedApplicationTest : public ::testing::Test {
	protected:
		void SetUp() override {
            RESET_FAKE(init_leds);
            RESET_FAKE(init_keys);
            RESET_FAKE(set_led);
            RESET_FAKE(get_key_status);
            FFF_RESET_HISTORY();
		}
		void TearDown() override {
            RESET_FAKE(init_leds);
            RESET_FAKE(init_keys);
            RESET_FAKE(set_led);
            RESET_FAKE(get_key_status);
            FFF_RESET_HISTORY();
		}
};

TEST_F(KeyLedApplicationTest, mock_test_init) {
    init_key_led_application();

    ASSERT_EQ(2, set_led_fake.call_count);
    ASSERT_EQ(1, init_leds_fake.call_count);
    ASSERT_EQ(1, init_keys_fake.call_count);
}

TEST_F(KeyLedApplicationTest, mock_test_read_no_buttons_pressed) {
    // Set up the return values for the mocked function
    uint8_t returnValues[6] = { 1,1,1,1,1,1 }; // This means that they are off 
    SET_RETURN_SEQ(get_key_status, returnValues, 6);

    refresh_key_led_application();

    // CHeck that correct parameters were passed to the function
    ASSERT_EQ(6, set_led_fake.call_count);
    ASSERT_EQ(0, set_led_fake.arg1_history[0]);
    ASSERT_EQ(0, set_led_fake.arg1_history[1]);
    ASSERT_EQ(0, set_led_fake.arg1_history[2]);
    ASSERT_EQ(1, set_led_fake.arg1_history[3]);
    ASSERT_EQ(1, set_led_fake.arg1_history[4]);
    ASSERT_EQ(1, set_led_fake.arg1_history[5]);
}

TEST_F(KeyLedApplicationTest, mock_test_read_left_button_pressed) {
    // Set up the return values for the mocked function
    uint8_t returnValues[6] = { 1,0,1,1,1,1};
    SET_RETURN_SEQ(get_key_status, returnValues, 6);

    refresh_key_led_application();

    // CHeck that correct parameters were passed to the function
    ASSERT_EQ(6, set_led_fake.call_count);
    ASSERT_EQ(0, set_led_fake.arg1_history[0]);
    ASSERT_EQ(1, set_led_fake.arg1_history[1]);
    ASSERT_EQ(1, set_led_fake.arg1_history[2]);
    ASSERT_EQ(1, set_led_fake.arg1_history[3]);
    ASSERT_EQ(0, set_led_fake.arg1_history[4]);
    ASSERT_EQ(0, set_led_fake.arg1_history[5]);
}

TEST_F(KeyLedApplicationTest, mock_test_read_right_button_pressed) {
    // Set up the return values for the mocked function
    uint8_t returnValues[6] = { 0,1,1,1,1,1};
    SET_RETURN_SEQ(get_key_status, returnValues, 6);

    refresh_key_led_application();

    // CHeck that correct parameters were passed to the function
    ASSERT_EQ(6, set_led_fake.call_count);
    ASSERT_EQ(0, set_led_fake.arg1_history[0]);
    ASSERT_EQ(1, set_led_fake.arg1_history[1]);
    ASSERT_EQ(1, set_led_fake.arg1_history[2]);
    ASSERT_EQ(1, set_led_fake.arg1_history[3]);
    ASSERT_EQ(0, set_led_fake.arg1_history[4]);
    ASSERT_EQ(0, set_led_fake.arg1_history[5]);
}

TEST_F(KeyLedApplicationTest, mock_test_read_both_buttons_pressed) {
    // Set up the return values for the mocked function
    uint8_t returnValues[6] = {  0,0,1,1,1,1};
    SET_RETURN_SEQ(get_key_status, returnValues, 6);

    refresh_key_led_application();

    // CHeck that correct parameters were passed to the function
    ASSERT_EQ(6, set_led_fake.call_count);
    ASSERT_EQ(1, set_led_fake.arg1_history[0]);
    ASSERT_EQ(1, set_led_fake.arg1_history[1]);
    ASSERT_EQ(0, set_led_fake.arg1_history[2]);
    ASSERT_EQ(0, set_led_fake.arg1_history[3]);
    ASSERT_EQ(0, set_led_fake.arg1_history[4]);
    ASSERT_EQ(1, set_led_fake.arg1_history[5]);
}