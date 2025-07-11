#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VN_UI_BASE_IMPLEMENTATION
#include "../../../lib/vn_ui_base.h"

int main() {
    char* red_fg = vn_color("#e93737", 'f');
    char* green_fg = vn_color("#37e937", 'f');
    char* blue_fg = vn_color("#3737e9", 'f');
    char* black_bg = vn_color("#161616", 'b');

    VN_UI_TEXT red_text;
    strcpy(red_text.color_fg, red_fg);
    strcpy(red_text.color_bg, black_bg);
    strcpy(red_text.text_style, vn_text_bold);

    VN_UI_TEXT green_text;
    strcpy(green_text.color_fg, green_fg);
    strcpy(green_text.color_bg, black_bg);
    strcpy(green_text.text_style, vn_text_italic);

    VN_UI_TEXT blue_text;
    strcpy(blue_text.color_fg, blue_fg);
    strcpy(blue_text.color_bg, black_bg);
    strcpy(blue_text.text_style, vn_text_underline);

    vn_print("This text has mold structure.\n", red_text);
    vn_print("This text has mold structure too.\n", green_text);
    vn_print("This text also has mold structure.\n\n", blue_text);

    vn_printf("This text has raw structure.\n", red_fg, black_bg, vn_text_blink);
    vn_printf("This text has raw structure too.\n", green_fg, black_bg, vn_text_strikethrough);
    vn_printf("This text also has raw structure.\n", blue_fg, black_bg, "");

    return 0;
}