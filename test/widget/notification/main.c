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
    vnw_first.pos_x = 2;
    vnw_first.pos_y = 2;
    vnw_first.width  = 30;
    vnw_first.height = 15;

    VN_UI_WIDGET vnw_firsty;
    vnw_firsty.pos_x = vnw_first.pos_x - 1;
    vnw_firsty.pos_y = vnw_first.pos_y - 1;
    vnw_firsty.width  = vnw_first.width  + 2;
    vnw_firsty.height = vnw_first.height + 2;

    VN_UI_WIDGET vnw_second;
    vnw_second.width  = 20;
    vnw_second.height = 10;
    vnw_second.pos_x = vnw_firsty.pos_x + vnw_firsty.width + 2;
    vnw_second.pos_y = vnw_first.pos_y;

    VN_UI_WIDGET vnw_secondy;
    vnw_secondy.pos_x = vnw_second.pos_x - 1;
    vnw_secondy.pos_y = vnw_second.pos_y - 1;
    vnw_secondy.width  = vnw_second.width  + 2;
    vnw_secondy.height = vnw_second.height + 2;

    VN_UI_WIDGET vnw_third;
    vnw_third.width  = 10;
    vnw_third.height = 5;
    vnw_third.pos_x = vnw_secondy.pos_x + vnw_secondy.width + 2;
    vnw_third.pos_y = vnw_second.pos_y;

    VN_UI_WIDGET vnw_thirdy;
    vnw_thirdy.pos_x = vnw_third.pos_x - 1;
    vnw_thirdy.pos_y = vnw_third.pos_y - 1;
    vnw_thirdy.width  = vnw_third.width  + 2;
    vnw_thirdy.height = vnw_third.height + 2;
    /* --------------- */

    /* TESTING CODES */
    vn_code("screen:clear");
    vn_bg('X', vnt_red, vnw_firsty);
    vn_notif("First Notif", "This is the first notification.", '0', '0', vnt_red, vnt_green, vnt_blue, vnw_first);

    vn_bg('X', vnt_green, vnw_secondy);
    vn_notif("Second Notif", "This is the second notification.", 'X', 'X', vnt_green, vnt_blue, vnt_red, vnw_second);

    vn_bg('X', vnt_blue, vnw_thirdy);
    vn_notif("Third Notif", "This is the third notification.", 'I', 'I', vnt_blue, vnt_red, vnt_green, vnw_third);
    /* ------------- */

    /* FREE 'vn_color' */
    free(red_fg);
    free(green_fg);
    free(blue_fg);
    free(black_bg);
    /* --------------- */

    return 0;
}