//Make the atmelavr library initialize
#include "../../extras/fake_avr_sfr.c"
#include "../../extras/forced_include.h"

#include <gtest/gtest.h>

//Calls every test file
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}