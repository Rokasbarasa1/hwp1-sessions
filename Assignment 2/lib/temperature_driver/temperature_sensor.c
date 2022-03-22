#include "temperature_sensor.h"
#include "../led_driver/led_array.h"

// Hold callback
static void (*cb)(int16_t) = 0;

void init_temperature_sensor_callback(functiontype call_back){
    // Save callback
    if(call_back != 0){
        cb = call_back;
    }
    // PG0 is to enable the sensor
    PORTG |= _BV(PORTG0);

    // PK7 is the output from the sensor
    DDRK &= ~(_BV(DDK7));

    // Set up the ADC to be on ADC 15, MUX 1-2 and 5, REFS0/1 sets external capactor mode
    ADMUX |= _BV(REFS0) | _BV(MUX0) | _BV(MUX1) | _BV(MUX2);
    ADMUX &= ~_BV(REFS1);

    // All MUX combined give 100111 which is PK7
    ADCSRB |= _BV(MUX5);

    // Set enable, reoccurring, set use interrupt, 128 prescaler
    ADCSRA |= _BV(ADEN) | _BV(ADATE) | _BV(ADIE) | _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2);

    // Enable adc
    ADCSRA |= _BV(ADSC);


    //Set it to interrupt every 1 seconds. Timer 1B
    // ADCSRB |= _BV(ADTS2) | _BV(ADTS0);
    ADCSRB |= _BV(ADTS1) | _BV(ADTS0);
    ADCSRB &= ~(_BV(ADTS2));

    // For 1 hz timer this was the calculation result
    OCR0A = 31249;
    // Mode CTC
    TCCR0B |= _BV(WGM02);
    // Prescaler 256
    TCCR0B |= _BV(CS02);
    TCCR0B &= ~(_BV(CS01) | _BV(CS00));
    // Output compare match
    TCCR0A |= _BV(COM0A0);


    // For testing timer.
    // DDRB |= _BV(DDB7);

    //Enable interrupts just in case
    sei();
}

uint32_t convert_to_voltage(uint16_t sample){
	// 5V goes from 48-992 (with normal pre-scale 0-1023)
	// 3.3V goes from 48-768 (with normal pre-scale 0-690)
	uint32_t milivolts = (uint32_t)sample;
	milivolts = (milivolts*5000)/1023;
	return milivolts;
}

int16_t voltage_to_temperature_TMP36(uint32_t voltage){
	// 10 mV per degree Celsius
	// sensor can detect in range of -40 to 125 temperature Celsius
	int16_t temperature_new = (int16_t)(voltage/10);
	temperature_new = temperature_new-50;
	if(temperature_new > 125){
		temperature_new = 125;
	}
	return temperature_new;
}

// Handle interrupt and call the function passed in init.
ISR(ADC_vect){
    if(cb != 0){
        int16_t temperature = voltage_to_temperature_TMP36(convert_to_voltage(ADC));
        cb(temperature);
    }
}

