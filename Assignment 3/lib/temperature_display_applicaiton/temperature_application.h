#ifndef TEMPERATURE_APPLICATION_H_
#define TEMPERATURE_APPLICATION_H_

#ifndef UNIT_TEST
#include <avr/io.h>
#include <avr/interrupt.h>
#else
#include "../../extras/forced_include.h"
#include "../../extras/include/avr/io.h"
#include "../../extras/include/avr/interrupt.h"
#endif

// Uses
//  PortG0
//  PortK7
//  PortA0-7
void init_temperature_application();
void obtain_temperature();
#endif