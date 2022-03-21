#include "testing_driver.h"
#include "dependency/dependency_driver.h"

int16_t do_thing(){
    hal_create(5);
    return hal_getVoltage(2);
}