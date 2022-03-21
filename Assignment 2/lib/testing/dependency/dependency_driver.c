#include "dependency_driver.h"

void hal_create(uint8_t portNo){
    DDRA = 0b11111111;
    PORTA = 0b11111111;
}

int16_t hal_getVoltage(uint8_t channel){
    return 8;
}