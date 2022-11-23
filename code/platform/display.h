#ifndef PLATFORM_DISPLAY_H_INCLUDED
#define PLATFORM_DISPLAY_H_INCLUDED

#include "../susci/kernel.h"

typedef enum {
    OFF = 0x00,
    CLOSE = 0x01,
    BLINK = 0x02,
    ROLLING = 0x03,
    SURPRISED = 0x04,
    TIRED = 0x05,
    SHOCKED = 0x06,
    LOOKING = 0x07,
    INDIFFERENCE = 0x08
} eye_state_t;

typedef struct {
    eye_state_t state;
    uint8_t animation_step;
} eye_t;

typedef enum {
    DISABLED,
    ENABLED
} display_state_t;

typedef struct {
    pin_t negated_enable;
    procedural_shift_register_t eyes;

    eye_t left;
    eye_t right;
    display_state_t state;
} display_t;

display_t create_display(
    pin_t da, 
    pin_t st_cp,
    pin_t sh_cp,
    pin_t negated_enable
);  

exec_state_t display_process(void *display_pointer);

#endif
