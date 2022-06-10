#include "../../extras/forced_include.h"
#include <gtest/gtest.h>
#include "../../extras/fff.h"

extern "C"{
    #include "../../extras/include/avr/io.h"
    #include "../../lib/led_driver/led_driver.h"
    #include "../../lib/temperature_driver/temperature_driver.h"
    #include "../../lib/temperature_application/temperature_application.h"
}

FAKE_VOID_FUNC(init_temperature_sensor);
FAKE_VOID_FUNC(init_leds);
FAKE_VOID_FUNC(get_temperature);
FAKE_VOID_FUNC(set_bar, uint8_t);

// FFF behaves inconsistently here. Duplicate import error. 
// In mocking_test.cpp the exact same scenario doesnt produce an error.

class TemperatureApplicationTest : public ::testing::Test {
	protected:
		void SetUp() override {
            RESET_FAKE(init_leds);
            RESET_FAKE(init_temperature_sensor);
            FFF_RESET_HISTORY();
		}
		void TearDown() override {

		}
};

TEST_F(TemperatureApplicationTest, test_init) {
    init_temperature_application();

    ASSERT_EQ(1, init_leds_fake.call_count);
    ASSERT_EQ(1, init_temperature_sensor_fake.call_count);
}

TEST_F(TemperatureApplicationTest, test_refresh_application_below_17) {
    refresh_temperature_application();

    ASSERT_EQ(1, get_temperature_fake.call_count);
    ASSERT_EQ(1, set_bar_fake.call_count);

    ASSERT_EQ(0, set_bar_fake.arg0_history[0]);
}

TEST_F(TemperatureApplicationTest, test_refresh_application_between) {
    refresh_temperature_application();

    ASSERT_EQ(1, get_temperature_fake.call_count);
    ASSERT_EQ(1, set_bar_fake.call_count);

    ASSERT_EQ(0, set_bar_fake.arg0_history[0]);
}

TEST_F(TemperatureApplicationTest, test_refresh_application_above_25) {
    refresh_temperature_application();

    ASSERT_EQ(1, get_temperature_fake.call_count);
    ASSERT_EQ(1, set_bar_fake.call_count);

    ASSERT_EQ(8, set_bar_fake.arg0_history[0]);
}