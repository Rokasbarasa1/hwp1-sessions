#include "temperature_sensor.h"
#include "../led_driver/led_array.h";

int16_t temperature = -40;

uint32_t convert_to_voltage(uint16_t sample){
	// 5V goes from 48-992 (with normal pre-scale 0-1023)
	// 3.3V goes from 48-768 (with normal pre-scale 0-690)
	uint32_t milivolts = (uint32_t)sample;
	milivolts = (milivolts*5000)/1023;
	return milivolts;
}

int16_t voltage_to_temperature_TMP36(uint16_t voltage){
	// 10 mV per degree Celsius
	// sensor can detect in range of -40 to 125 temperature Celsius
	int16_t temperature_new = (int16_t)(voltage/10);
	temperature_new = temperature_new-40;
	if(temperature_new > 125){
		temperature_new = 125;
	}
	return temperature_new;
}

void init_temperature_sensor(){
    init_leds();
    //PG0 is to enable the sensor
    PORTG |= _BV(PORTG0);

    //PK7 is the output from the sensor
    DDRK &= ~(_BV(DDK7));

    // Set up the ADC to be on ADC 15, MUX 1-2 and 5, REFS0/1 sets external capactor mode
    ADMUX |= _BV(REFS0) | _BV(MUX0) | _BV(MUX1) | _BV(MUX2);
    ADMUX &= ~_BV(REFS1);


    ADCSRB |= _BV(MUX5);

    // Set enable, reoccurring, set use interrupt, 128 prescaler
    ADCSRA |= _BV(ADEN) | _BV(ADATE) | _BV(ADIE) | _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2);

    // Enable adc
    ADCSRA |= _BV(ADSC);


    // PORTA = 0b11110000;
    // set_bar(2);
}

ISR(ADC_vect){
    // PORTA = 0b11001111;

	temperature = voltage_to_temperature_TMP36(convert_to_voltage(ADC));

    // uint8_t value = (temperature+40)*100/165;
    // set_bar(value);
    if(temperature < 17){
        set_bar(0);
    }
    else if(temperature >= 18 && temperature <= 25){
        set_bar(temperature-17);
    } else if(temperature > 25){
        set_bar(8);
    }
    
}

