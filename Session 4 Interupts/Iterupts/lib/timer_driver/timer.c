#include "timer.h"

void init_timer(){
    // // Setup OC4A to toggle on compare match
    // TCCR4A |= _BV(COM4A0);
    // // Setup timer 0 pre-scaler to clk/64
    // TCCR4B |= _BV(CS41) | _BV(CS40);
    
    // // Setup port h 3 to output
    // DDRH |= _BV(DDH3);

    // Calculations

    // The formula is f(ocnx) = f(clk_IO)/ (2N(1 + TOP))
    // TOP(16 bit max) = 65535 (0xFFFF)
    // N is clk/64 so N = 64
    // Atmega2560 frequency = 16 Mhz = 16000000 Hz

    // f = 16000000 / (2*64*(1 + 65535)) = 1.90734... = 1.9 Hz

    // Setup OC4A to toggle on compare match
    TCCR4A |= _BV(COM4A0);
    // Setup timer 0 pre-scaler to clk/8
    TCCR4B |= _BV(CS41);
    TCCR4B &= ~(_BV(CS40));
    
    // Setup port h 3 to output
    DDRH |= _BV(DDH3);

}