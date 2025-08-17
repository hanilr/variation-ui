// STANDARD LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// VARIATION UI LIBRARY
#define VN_UI_BASE_IMPLEMENTATION
#include "../../../lib/vn_ui_base.h"

int main() {
    /* COLOR DECLARING */
    char* red_fg = vn_color("#e93737", 'f');
    char* green_fg = vn_color("#37e937", 'f');
    char* blue_fg = vn_color("#3737e9", 'f');
    char* white_fg = vn_color("#e9e9e9", 'f');
    char* black_bg = vn_color("#161616", 'b');
    /* --------------- */
    
    /* TEXT ATTRIBUTES */
    VN_UI_TEXT red_text;
    strcpy(red_text.color_fg, red_fg);
    strcpy(red_text.color_bg, black_bg);
    strcpy(red_text.text_style, "");

    VN_UI_TEXT green_text;
    strcpy(green_text.color_fg, green_fg);
    strcpy(green_text.color_bg, black_bg);
    strcpy(green_text.text_style, "");

    VN_UI_TEXT blue_text;
    strcpy(blue_text.color_fg, blue_fg);
    strcpy(blue_text.color_bg, black_bg);
    strcpy(blue_text.text_style, "");
    /* --------------- */

    /* COLOR ATTRIBUTES */
    vn_printf("[ ------------------------------ ]\n\n", white_fg, black_bg, vn_text_bold);
    vn_print("\tText Attributes:\n\n", blue_text);
    vn_printf("1. Bold\n", red_fg, black_bg, vn_text_bold);
    vn_printf("2. Italic\n", green_fg, black_bg, vn_text_italic);
    vn_printf("3. Underline\n", blue_fg, black_bg, vn_text_underline);
    vn_printf("4. Blink\n", red_fg, black_bg, vn_text_blink);
    vn_printf("5. Strikethrough\n", green_fg, black_bg, vn_text_strikethrough);
    vn_printf("[ ------------------------------ ]\n\n", white_fg, black_bg, vn_text_bold);
    /* ---------------- */

    /* FREE 'vn_color' */
    free(red_fg);
    free(green_fg);
    free(blue_fg);
    free(white_fg);
    free(black_bg);
    /* --------------- */
    
    return 0;
}