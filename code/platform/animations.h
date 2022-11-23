#ifndef PLATFORM_ANIMATIONS_H_INCLUDED
#define PLATFORM_ANIMATIONS_H_INCLUDED

#include <avr/pgmspace.h>

const uint8_t PROGMEM ANIMATIONS[] = {
    0x01, 0b00000000,
    0x03, 0b00001000, 0b00000000, 0b00001000,
    0x05, 0b00001000, 0b00011100, 0b00111110, 0b00111110, 0b00011100,
    0x06, 0b00001000, 0b00000100, 0b00000010, 0b00000001, 0b00100000, 0b00010000,
    0x03, 0b00000001, 0b00000011, 0b00000001,
    0x05, 0b01011100, 0b00011100, 0b00001000, 0b00011100, 0b01011100,
    0x03, 0b00111111, 0b01011100, 0b00111111,
    0x03, 0b00111110, 0b10111111, 0b00111110,
    0x06, 0b00011100, 0b00001110, 0b00100011, 0b00100011, 0b00001110, 0b00011100
};


#endif
