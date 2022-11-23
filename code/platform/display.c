#include "display.h"
#include "animations.h"
#include "../susci/kernel.h"
#include <avr/pgmspace.h>

eye_t create_eye() {
    return (eye_t) {OFF, 0x00};
}

static uint8_t get_eye_char(eye_t *eye, uint8_t *animations) {
    uint8_t *location = animations;
    uint8_t state = eye->state;
    
    while (state > 0x00) {
        location += pgm_read_byte(location) + 1;
        --state;
    }

    if (eye->animation_step >= pgm_read_byte(location)) {
        eye->animation_step = 0x00;
    }

    return pgm_read_byte(location + ++eye->animation_step);
}

exec_state_t display_process(void *display_pointer) {
    display_t *display = display_pointer;

    set_pin_state(
        display->negated_enable, 
        (display->state == ENABLED) ? LOW : HIGH
    );

    procedural_shift_register_driver(
        &display->eyes, 
        get_eye_char(&display->left, ANIMATIONS), 
        false
    );

    procedural_shift_register_driver(
        &display->eyes, 
        get_eye_char(&display->right, ANIMATIONS), 
        true
    );

    wait(TICK_TIME(100));

    return GOOD_STATE;
}

display_t create_display(
    pin_t da, 
    pin_t st_cp,
    pin_t sh_cp,
    pin_t negated_enable
) {
    procedural_shift_register_t eyes = create_procedural_shift_register(
        da,
        st_cp,
        sh_cp
    );

    procedural_shift_register_driver(&eyes, 0x00, false);
    procedural_shift_register_driver(&eyes, 0x00, true);

    set_pin_state(negated_enable, HIGH);
    set_pin_direction(negated_enable, OUTPUT);

    return (display_t) {
        negated_enable,
        eyes,
        create_eye(),
        create_eye(),
        DISABLED
    };
}


