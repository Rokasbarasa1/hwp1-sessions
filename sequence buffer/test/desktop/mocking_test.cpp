#include "../../extras/forced_include.h"
#include <gtest/gtest.h>
#include "../../extras/fff.h"

extern "C"{
    #include "../../extras/include/avr/io.h"
    #include "../../lib/testing/testing_driver.h"
    #include "../../lib/testing/dependency/dependency_driver.h"
}

FAKE_VOID_FUNC(hal_create, uint8_t);
FAKE_VALUE_FUNC(int16_t, hal_getVoltage, uint8_t);
FAKE_VOID_FUNC(create);


class MockingTest : public ::testing::Test {
	protected:
		void SetUp() override {
            RESET_FAKE(hal_create);
            RESET_FAKE(hal_getVoltage);
            RESET_FAKE(create);
            FFF_RESET_HISTORY();
		}
		void TearDown() override {

		}
};

TEST_F(MockingTest, Test_mocking) {
    hal_getVoltage_fake.return_val = 1;
	int16_t value = do_thing();
    int16_t value2 = 1;

    ASSERT_EQ(1, create_fake.call_count);
    ASSERT_EQ(1, hal_getVoltage_fake.call_count);
    ASSERT_EQ(value2, value);
	ASSERT_EQ(1, hal_create_fake.call_count);
}