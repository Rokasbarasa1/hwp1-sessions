#include "temperature_driver.h"

uint16_t raw_sample = 0;

void init_temperature_sensor(){
    // PG0 is to enable the sensor
    PORTG |= _BV(PORTG0);
    // PK7 is the output from the sensor
    DDRK &= ~(_BV(DDK7));


    // REFS1 and 0 sets the reference voltage mode
    ADMUX |= _BV(REFS0);
    ADMUX &= ~_BV(REFS1);

    // Set up the ADC to be on ADC 15, MUX 1-2 and 5,
    // Only 4 bits are adjusted others are 0 by default
    ADMUX |= _BV(MUX0) | _BV(MUX1) | _BV(MUX2);
    ADCSRB |= _BV(MUX5);
    // All MUX combined give 100111 which is ADC15 on pin PK7 
    // MUX5 is the leading bit and MUX 


    //        enable,   reoccurring, use interrupt,   -------- 128 prescaler --------
    ADCSRA |= _BV(ADEN) | _BV(ADATE) | _BV(ADIE) | _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2);

    // Set when the ADC is triggered. It is set to trigger by Timer 0 compare match
    ADCSRB |= _BV(ADTS1) | _BV(ADTS0);
    ADCSRB &= ~(_BV(ADTS2));

    // Start conversion - Only needed on normal mode
    ADCSRA |= _BV(ADSC);

    // Set it to interrupt every 1 seconds on Timer 1B

    // Wrong timer was chosen here was supposed to be 1 hz
    // That is only possible with the 16 bit timer
    OCR0A = 255; // 30 hz compare match 
    TCCR0B |= _BV(WGM02); // Mode CTC
    // Prescaler 1024
    TCCR0B |= _BV(CS02) | _BV(CS00);
    TCCR0B &= ~(_BV(CS01) );

    TCCR0A |= _BV(COM0A0); // Output compare match
}

uint32_t convert_to_voltage(uint16_t value){
    // 5V goes from 48-992 (with normal pre-scale 0-1023)
    // 3.3V goes from 48-768 (with normal pre-scale 0-690)
    uint32_t milivolts = (uint32_t)value;
    milivolts = (milivolts * 5000) / 1023;
    return milivolts;
}

int16_t voltage_to_temperature_TMP36(uint32_t voltage){
    // 10 mV per degree Celsius
    // sensor can detect in range of -40 to 125 temperature Celsius
    int16_t temperature_new = (int16_t)(voltage / 10);
    temperature_new = temperature_new - 50;
    if (temperature_new > 125)
    {
        temperature_new = 125;
    }
    else if (temperature_new < -40)
    {
        temperature_new = -40;
    }
    return temperature_new;
}

int16_t sample_to_temperature(uint16_t sample){
    return voltage_to_temperature_TMP36(convert_to_voltage(sample));
}

ISR(ADC_vect){
    // Get the value in two parts. Lower and upper and combine them.
    uint8_t lower = ADCL;
    uint8_t upper = ADCH << 8;
    raw_sample = lower | upper;

    // Enable the interrupt again
    TIFR0 |= _BV(OCF0A);
}

// Get converted temperature
int16_t get_temperature(){
    return voltage_to_temperature_TMP36(convert_to_voltage(raw_sample));
}
