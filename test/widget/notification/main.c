#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VN_UI_WIDGET_IMPLEMENTATION
#include "../../../lib/vn_ui_widget.h"

int main() {
    char* red_fg = vn_color("#e93737", 'f');
    char* black_bg = vn_color("#161616", 'b');

    VN_UI_TEXT vnt;
    strcpy(vnt.color_fg, red_fg);
    strcpy(vnt.color_bg, black_bg);
    strcpy(vnt.text_style, "");

    VN_UI_WIDGET vnw;
    vnw.pos_x = 2;
    vnw.pos_y = 2;
    vnw.width = 20;
    vnw.height = 10;

    vn_code("screen:clear");
    vn_notif("Title", "This is the text we got.", '|', '-', vnt, vnt, vnt, vnw);

    return 0;
}
