#include "quantum.h"
#include <stdio.h>

static char wpm_str[10];

void render_wpm(uint8_t col, uint8_t line) {
    sprintf(wpm_str, "%03d", get_current_wpm());
    oled_set_cursor(col, line);
    oled_write_ln(wpm_str, false);
}
