/* VARIATION UI (UTILITY) */

/*  STANDARD LIBRARY */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/ioctl.h>

/* DIY LIBRARY */
#include "lib/vn_util.h"
#include "lib/vn_ui.h"

char *vnu_get_time(void)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char *time = (char*) malloc(16);

    sprintf(time, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
    return time;
}

void vnu_sleep(char *sleep_type, int sleep_time)
{ /* 'sleep_time' MUST BE IN ITs OWN UNIT */
    if(!strcmp(sleep_type, "hour")) { sleep(sleep_time*3600); }
    if(!strcmp(sleep_type, "minute")) { sleep(sleep_time*60); }
    if(!strcmp(sleep_type, "second")) { sleep(sleep_time); }
    if(!strcmp(sleep_type, "millisecond")) { sleep(sleep_time/1000); }
} /* EXAMPLE: 'vnu_sleep("hour", 1);' IT MEAN SLEEP 1 HOUR */

char vnu_get_char_instantly(void)
{
    system("stty raw"); /* TERMINAL 'raw' MODE */
    char key = getchar();
    system("stty cooked"); /* TERMINAL 'cooked' MODE */
    return key;
}

void vnu_get_terminal_size(struct vn_init *vn) 
{
    struct winsize terminal_size;
    ioctl(0, TIOCGWINSZ, &terminal_size);
    vn->width = terminal_size.ws_row;
    vn->height = terminal_size.ws_col;
}

int vnc_hex_number(int number, int left_side)
{ /* IF HEX IS NUMBER */
    if(left_side == 0) { return number; }
    else if(left_side == 1) { return number*16; }
    return 0;
} /* 'left_side' MEAN IS IF AT LEFT SIDE THEN RETURN ORIGINAL NUMBER IF NOT THEN MULTIPLY WITH 16 */

int vnc_hex_letter(char letter, int left_side)
{ /* IF HEX IS LETTER */
    int result;
    if(letter == 'a') { result = 10; }
    else if(letter == 'b') { result = 11; }
    else if(letter == 'c') { result = 12; }
    else if(letter == 'd') { result = 13; }
    else if(letter == 'e') { result = 14; }
    else if(letter == 'f') { result = 15; }
    if(left_side == 1) { result*=16; }
    return result;
} /* 'left_side' MEAN IS IF AT LEFT SIDE THEN RETURN 2 DIGIT NUMBER WHO START WITH 10 IF NOT THEN MULTIPLY WITH 16 */

char *vn_hex_color(char *hex_color, int is_fore)
{
    int red, green, blue, red_x, red_y, green_x, green_y, blue_x, blue_y;
    char *rgb = (char*) malloc(32);

    if(isalpha(hex_color[0]) != 0) { red_x = vnc_hex_letter(hex_color[0], 1); }
    else { red_x = vnc_hex_number(hex_color[0] - '0', 1); }
    if(isalpha(hex_color[1]) != 0) { red_y = vnc_hex_letter(hex_color[1], 0); }
    else { red_y = vnc_hex_number(hex_color[1] - '0', 0); }
    if(isalpha(hex_color[2]) != 0) { green_x = vnc_hex_letter(hex_color[2], 1); }
    else { green_x = vnc_hex_number(hex_color[2] - '0', 1); }
    if(isalpha(hex_color[3]) != 0) { green_y = vnc_hex_letter(hex_color[3], 0); }
    else { green_y = vnc_hex_number(hex_color[3] - '0', 0); }
    if(isalpha(hex_color[4]) != 0) { blue_x = vnc_hex_letter(hex_color[4], 1); }
    else { blue_x = vnc_hex_number(hex_color[4] - '0', 1); }
    if(isalpha(hex_color[5]) != 0) { blue_y = vnc_hex_letter(hex_color[5], 0); }
    else { blue_y = vnc_hex_number(hex_color[5] - '0', 0); }

    red = red_x + red_y;
    green = green_x + green_y;
    blue = blue_x + blue_y;

    /* CONVERT TO COLOR CODE */
    if(is_fore == 0) { sprintf(rgb, "\033[38;2;%d;%d;%dm", red, green, blue); }
    if(is_fore == 1) { sprintf(rgb, "\033[48;2;%d;%d;%dm", red, green, blue); }
    return rgb;
}

char *vn_rgb_color(int red, int green, int blue, int is_fore)
{
    char *rgb = (char*) malloc(32);
    if(is_fore == 0) { sprintf(rgb, "\033[38;2;%d;%d;%dm", red, green, blue); }
    if(is_fore == 1) { sprintf(rgb, "\033[48;2;%d;%d;%dm", red, green, blue); }
    return rgb;
}

void vn_end(struct vn_init vn)
{ /* FOR ELEGANT UI */
    vn_gotoxy(0, vn.height+vn.pos_y);
    if(vn.cursor_visibility == 0) { vn_cursor_visibility(1); }
} /* IF 'vn_cursor_visibility()' USED */

/* MADE BY @hanilr */