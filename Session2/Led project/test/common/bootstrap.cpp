#include "../../atmelavr/fake_avr_sfr.c"
#include "../../atmelavr/forced_include.h"
#include <gtest/gtest.h>

// #define DESKTOP_TESTING true

extern "C"{
    #include "../../atmelavr/include/avr/io.h"
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}