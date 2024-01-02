#include "quantum.h"
#include <stdio.h>

void render_bootmagic_status(uint8_t col, uint8_t line) {
    /* Show Ctrl-Gui Swap options */
    oled_set_cursor(col, line);

    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xAD, 0xAE, 0}},
        {{0x95, 0x96, 0}, {0xAB, 0xAC, 0}},
    };
    if (keymap_config.swap_lalt_lgui) {
        oled_write_P(logo[1][0], false);
        oled_set_cursor(col, line + 1);
        oled_write_P(logo[1][1], false);
    } else {
        oled_write_P(logo[0][0], false);
        oled_set_cursor(col, line + 1);
        oled_write_P(logo[0][1], false);
    }
}
