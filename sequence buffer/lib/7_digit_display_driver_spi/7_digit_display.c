#include "7_digit_display.h"

uint8_t digit_one = 0b11111111;
uint8_t digit_two = 0b11111111;
uint8_t digit_three = 0b11111111;
uint8_t digit_four = 0b11111111;

uint8_t current_number = 0;

uint8_t numbers_array[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

void init_segments()
{
    // SS = PB0
    // SCK = PB1
    // MOSI  = PB2
    // MISO  = PB3

    // Set MOSI and SCK as high and SS as low
    DDRB |= _BV(PB0) | _BV(DDB1) | _BV(DDB2);
    PORTB |= _BV(PB0) | _BV(PB1) | _BV(PB2);
    PORTB &= ~(_BV(PB0));

    // Set SPI bits
    SPCR |= _BV(SPE) | _BV(MSTR) | _BV(SPR0);

    // Disable all transistors that determine which digit is displayed
    DDRF |= _BV(DDF0) | _BV(DDF1) | _BV(DDF2) | _BV(DDF3);
    PORTF |= _BV(PF0) | _BV(PF1) | _BV(PF2) | _BV(PF3);

    DDRB = _BV(DDB0) | (1 << 5) | (1 << 3);
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);

    // Interupt speed
    OCR4A = 1249; // 100Hz

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
    // PORTB &= ~(_BV(PB0));

    // SPSR = 0b10101010;

    // while (!(SPSR & (1 << SPIF)))
    //     ;

    // // Put the data from the loop into the sequence register
    // PORTB |= _BV(PB0);
    PORTB &= ~(_BV(PB0));

    SPDR = 0b10101010;

    while (!(SPSR & (1 << SPIF)))
        ;

    PORTB |= _BV(PB0);
}

// Handle refresh of display
ISR(TIMER4_COMPA_vect)
{
    print_segments();
    PORTF &= ~(_BV(0));

    // if (current_number == 0)
    // {
    //     PORTF |= _BV(3);
    // }
    // else
    // {
    //     PORTF |= _BV(current_number - 1);
    // }

    // if (current_number != 3)
    // {
    //     current_number++;
    // }
    // else
    // {
    //     current_number = 0;
    // }
}

// Show one and put number into buffer.