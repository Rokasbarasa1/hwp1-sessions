#include "../../extras/forced_include.h"
#include <gtest/gtest.h>

extern "C"{
    #include "../../extras/include/avr/io.h"
    #include "../../lib/temperature_driver/temperature_sensor.h"
}

class TEMPERATUREDriverTest : public ::testing::Test {
	protected:
		void SetUp() {

		}
		void TearDown() {

		}
};

void callback(){

}

TEST_F(TEMPERATUREDriverTest, Init_keys) {

    init_temperature_sensor_callback(callback);

	// Checking that every port has been set here would be crazy
	
}