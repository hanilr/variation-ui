// STANDARD LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// VARIATION UI LIBRARY
#define VN_UI_WIDGET_IMPLEMENTATION
#include "../../../lib/vn_ui_widget.h"

int main() {
    /* COLOR DECLARING */
    char* red_fg = vn_color("#e93737", 'f');
    char* green_fg = vn_color("#37e937", 'f');
    char* blue_fg = vn_color("#3737e9", 'f');
    char* black_bg = vn_color("#161616", 'b');
    /* --------------- */

    /* TEXT ATTRIBUTES */
    VN_UI_TEXT vnt_red;
    strcpy(vnt_red.color_fg, red_fg);
    strcpy(vnt_red.color_bg, black_bg);
    strcpy(vnt_red.text_style, "");

    VN_UI_TEXT vnt_green;
    strcpy(vnt_green.color_fg, green_fg);
    strcpy(vnt_green.color_bg, black_bg);
    strcpy(vnt_green.text_style, "");

    VN_UI_TEXT vnt_blue;
    strcpy(vnt_blue.color_fg, blue_fg);
    strcpy(vnt_blue.color_bg, black_bg);
    strcpy(vnt_blue.text_style, "");
    /* --------------- */

    /* SIZE ATTRIBUTES */
    VN_UI_WIDGET vnw_first;
    vnw_first.pos_x = 1;
    vnw_first.pos_y = 1;
    vnw_first.width  = 30;
    vnw_first.height = 15;

    VN_UI_WIDGET vnw_second;
    vnw_second.width  = 20;
    vnw_second.height = 10;
    vnw_second.pos_x = vnw_first.pos_x + (vnw_first.width  - vnw_second.width)  / 2;
    vnw_second.pos_y = vnw_first.pos_y + (vnw_first.height - vnw_second.height) / 2;

    VN_UI_WIDGET vnw_third;
    vnw_third.width  = 10;
    vnw_third.height = 5;
    vnw_third.pos_x = vnw_second.pos_x + (vnw_second.width  - vnw_third.width)  / 2;
    vnw_third.pos_y = vnw_second.pos_y + (vnw_second.height - vnw_third.height) / 2;
    /* --------------- */

    /* TESTING CODES */
    vn_code("screen:clear");
    vn_frame('I', '-', vnt_red, vnw_first);
    vn_frame('L', 'x', vnt_green, vnw_second);
    vn_frame('|', '+', vnt_blue, vnw_third);
    /* ------------- */

    /* FREE 'vn_color' */
    free(red_fg);
    free(green_fg);
    free(blue_fg);
    free(black_bg);
    /* --------------- */

    return 0;
}