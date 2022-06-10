#include "../../extras/forced_include.h"
#include <gtest/gtest.h>

extern "C"{
    #include "../../extras/include/avr/io.h"
    #include "../../lib/temperature_driver/temperature_driver.h"
}

class TEMPERATUREDriverTest : public ::testing::Test {
	protected:
		void SetUp() {

		}
		void TearDown() {

		}
};

void callback(int16_t value){

}

TEST_F(TEMPERATUREDriverTest, Init_keys) {

    init_temperature_sensor();

	// Checking that every port has been set here would be crazy
	// If you have more features it would be nice to test the registers to ensure they still work
}


TEST_F(TEMPERATUREDriverTest, convert_sample_to_temp_0) {
    ASSERT_EQ(-40, sample_to_temperature(0));
}


TEST_F(TEMPERATUREDriverTest, convert_sample_to_temp_midway) {
    ASSERT_EQ(125, sample_to_temperature(511));
}


TEST_F(TEMPERATUREDriverTest, convert_sample_to_temp_high) {
    ASSERT_EQ(125, sample_to_temperature(1023));
}

TEST_F(TEMPERATUREDriverTest, convert_sample_to_temp_middway_temperature_sensor) {
    ASSERT_EQ(33, sample_to_temperature(170));
}