/*
 */
 
#include "susci/kernel.h"
#include "platform/display.h"

display_t display;

void susci_boot(void) {
    display = create_display(PIN_6, PIN_12, PIN_11, PIN_13);

    display.state = ENABLED;
    display.left.state = LOOKING;
    display.right.state = INDIFFERENCE;

    create_process(get_first_empty(), display_process, &display);
}

void susci_panic(void) {
}
