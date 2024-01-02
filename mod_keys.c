#include "quantum.h"
#include <stdio.h>

void render_mod_keys(uint8_t const modifiers, uint8_t const col, uint8_t const line) {
    // clang-format off
    static const char PROGMEM mod_status[5][3] = {
        {0x88, 0x89, 0},
        {0x84, 0x85, 0},
        {0x86, 0x87, 0},
        {0x8A, 0x8B, 0},
        {0x8C, 0x8D, 0}
    };
    // clang-format on

    oled_set_cursor(col, line);

    oled_write_P(mod_status[0], (modifiers & MOD_MASK_SHIFT));
    oled_write_P(mod_status[!keymap_config.swap_lalt_lgui ? 3 : 4], (modifiers & MOD_MASK_GUI));
    oled_write_P(PSTR(" "), false);
    oled_write_P(mod_status[2], (modifiers & MOD_MASK_ALT));
    oled_write_P(mod_status[1], (modifiers & MOD_MASK_CTRL));
}
