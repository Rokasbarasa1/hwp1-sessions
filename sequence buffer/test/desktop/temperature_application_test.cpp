#include "../../extras/forced_include.h"
#include <gtest/gtest.h>
#include "../../extras/fff.h"

extern "C"{
    #include "../../extras/include/avr/io.h"
    #include "../../lib/led_driver/led_array.h"
    #include "../../lib/temperature_driver/temperature_sensor.h"
    #include "../../lib/temperature_application/temperature_application.h"
}

// FAKE_VOID_FUNC(init_temperature_sensor_callback, functiontype);

// FFF behaves inconsistently here. Duplicate import error. 
// In mocking_test.cpp the exact same scenario doesnt produce an error.
// FAKE_VOID_FUNC(init_leds);

class TemperatureApplicationTest : public ::testing::Test {
	protected:
		void SetUp() override {
            // RESET_FAKE(init_leds);
            // RESET_FAKE(init_temperature_sensor_callback);
            FFF_RESET_HISTORY();
		}
		void TearDown() override {

		}
};

TEST_F(TemperatureApplicationTest, Test_mocking) {
    init_temperature_application();

	// ASSERT_EQ(1, init_temperature_sensor_callback_fake.call_count);
    // ASSERT_EQ(1, init_leds_fake.call_count);
}