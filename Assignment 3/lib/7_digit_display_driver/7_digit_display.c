#include "7_digit_display.h"

uint8_t digit_one = 0b11111111;
uint8_t digit_two = 0b11111111;
uint8_t digit_three = 0b11111111;
uint8_t digit_four = 0b11111111;

uint8_t numbers_array[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

void init_segments()
{
    // RCK = PB0
    // SCK = PB1
    // SI  = PB2
    // Registers that control the shift register functionality
    DDRB |= _BV(DDB0) | _BV(DDB1) | _BV(DDB2);
    PORTB &= ~(_BV(PB0) | _BV(PB1) | _BV(PB2));

    // Disable all transistors that determine which digit is displayed
    DDRF |= _BV(DDF0) | _BV(DDF1) | _BV(DDF2) | _BV(DDF3);
    PORTF |= _BV(PF0) | _BV(PF1) | _BV(PF2) | _BV(PF3);

    // Interupt value
    // OCR4A = 24999; // 5Hz
    // OCR4A = 1249; // 100Hz
    OCR4A = 4999; // 25Hz

    // Mode CTC
    TCCR4B |= _BV(WGM42);
    // Prescaler 64
    TCCR4B |= _BV(CS41) | _BV(CS40);
    // Output compare match
    TCCR4A |= _BV(COM4A0);

    TIMSK4 |= _BV(OCIE4A);
}

// Set segments manually with macros
void set_segments(uint8_t numbers_new[4])
{
    digit_one = numbers_new[0];
    digit_two = numbers_new[1];
    digit_three = numbers_new[2];
    digit_four = numbers_new[3];
}

void set_number(uint16_t number)
{
    if (number < 9999)
    {
        digit_one = numbers_array[number / 1000];
        digit_two = numbers_array[(number % 1000) / 100];
        digit_three = numbers_array[(number % 100) / 10];
        digit_four = numbers_array[(number % 10) / 1];
    }
    else
    {
        digit_one = NINE;
        digit_two = NINE;
        digit_three = NINE;
        digit_four = NINE;
    }
}

void print_segments()
{
    const uint8_t digits[] = {digit_one, digit_two, digit_three, digit_four};

    for (uint8_t i = 0; i < 4; i++)
    {

        for (uint8_t j = 0; j < 8; j++)
        {
            // Get least significant bit
            uint8_t bitStatus = (digits[i] >> (j)) & 1;

            if (bitStatus)
            {
                PORTB |= _BV(PB2);
            }
            else
            {
                PORTB &= ~(_BV(PB2));
            }

            // Put the bit in the shift register
            PORTB |= _BV(PB1);
            PORTB &= ~(_BV(PB1));
        }

        // Put the data from the loop into the sequence register
        PORTB |= _BV(PB0);
        PORTB &= ~(_BV(PB0));

        PORTF &= ~(_BV(i));
        _delay_ms(2);
        PORTF |= _BV(i);
    }
}

// Handle refresh of display
ISR(TIMER4_COMPA_vect)
{
    print_segments();
}