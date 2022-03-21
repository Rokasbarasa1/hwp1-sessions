#ifndef __AVR_ATmega2560__
	#define __AVR_ATmega2560__
#endif

#define F_CPU 16000000
#include <Arduino.h>

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
extern "C" {
	#include "./lib/temperature_driver/temperature_sensor.h"
}

// Meassure temperature once per second. 
// Sensor must use interrupts.
// Convert temperature from sensor
// Calculate as celcius.
// Show it on leds 1-8 as 18-25c 

int main(void){
	// Initialize state
	Serial.begin(115200);
	init_temperature_sensor();
	sei();
	//Event loop
	DDRB &= ~(_BV(DDB7));

	return 0;
}

uint32_t convert_to_voltage(uint16_t sample){
	// 5V goes from 48-992 (with normal pre-scale 0-1023)
	// 3.3V goes from 48-768 (with normal pre-scale 0-690)
	uint32_t milivolts = (uint32_t)sample;
	milivolts = (milivolts*5000)/1023;
	return milivolts;
}

int16_t voltage_to_temperature_TMP36(uint16_t voltage){
	// 10 mV per degree celcius
	// sensor can detect in range of -40 to 125 temperature celcius
	int16_t temperature = (int16_t)(voltage/10);
	temperature = temperature-40;
	if(temperature > 125){
		temperature = 125;
	}
	return temperature;
}

ISR(ADC_vect){
	Serial.println(voltage_to_temperature_TMP36(convert_to_voltage(ADC)));
}

