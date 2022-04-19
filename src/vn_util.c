/* VARIATION TUI (UTILITY) */

/*  STANDARD LIBRARY */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* DIY LIBRARY */
#include "lib/vn_util.h"
#include "lib/vn_ui.h"

int vnu_get_repeat(char *str, char chr)
{ /* 'vnu' = VARIATION UTILITY */
    int count = 0, i = 0;
    while(strlen(str) > i)
    {
        if(str[i] == chr) { count+=1; }
        i+=1;
    }
    return count;
}

int hex_number(int number, int left_side)
{
    if(left_side == 0) { return number; }
    else if(left_side == 1)
    {
        if(number == 1) { return 16; }
        else if(number == 2) { return 32; }
        else if(number == 3) { return 48; }
        else if(number == 4) { return 64; }
        else if(number == 5) { return 80; }
        else if(number == 6) { return 96; }
        else if(number == 7) { return 112; }
        else if(number == 8) { return 128; }
        else if(number == 9) { return 144; }
    }
    return 0;
} /* 'left_side' MEAN IS IF AT LEFT SIDE THEN RETURN ORIGINAL NUMBER IF NOT THEN MULTIPLY WITH 16 */

int hex_letter(char letter, int left_side)
{
    if(left_side == 0)
    {
        if(letter == 'a') { return 10; }
        else if(letter == 'b') { return 11; }
        else if(letter == 'c') { return 12; }
        else if(letter == 'd') { return 13; }
        else if(letter == 'e') { return 14; }
        else if(letter == 'f') { return 15; }
    }
    else if(left_side == 1)
    {
        if(letter == 'a') { return 160; }
        else if(letter == 'b') { return 176; }
        else if(letter == 'c') { return 192; }
        else if(letter == 'd') { return 208; }
        else if(letter == 'e') { return 224; }
        else if(letter == 'f') { return 240; }
    }
    return 0;
} /* 'left_side' MEAN IS IF AT LEFT SIDE THEN RETURN 2 DIGIT NUMBER WHO START WITH 10 IF NOT THEN MULTIPLY WITH 16 */

char *vn_color(char *hex_color, int is_fore)
{
    if(strlen(hex_color) != 6)
    {
        fprintf(stderr, "[ERROR] 'vn_color()' function argument not equal to 6 digit!");
        exit(1);
    } /* IF 'hex_color' ARGUMENT LENGTH NOT EQUAL TO 6 DIGIT THEN PRINT ERROR AND EXIT */
    if(strcmp(hex_color, "#") == 0)
    {
        fprintf(stderr, "[ERROR] 'vn_color()' function argument has '#' symbol!");
        exit(1);
    } /* IF 'hex_color' ARGUMENT HAS '#' SYMBOL THEN PRINT ERROR AND EXIT */

    int red, green, blue, red_x, red_y, green_x, green_y, blue_x, blue_y;
    char *rgb = (char*) malloc(32);

    if(isalpha(hex_color[0]) != 0) { red_x = hex_letter(hex_color[0], 1); }
    else { red_x = hex_number(hex_color[0] - '0', 1); }
    if(isalpha(hex_color[1]) != 0) { red_y = hex_letter(hex_color[1], 0); }
    else { red_y = hex_number(hex_color[1] - '0', 0); }
    if(isalpha(hex_color[2]) != 0) { green_x = hex_letter(hex_color[2], 1); }
    else { green_x = hex_number(hex_color[2] - '0', 1); }
    if(isalpha(hex_color[3]) != 0) { green_y = hex_letter(hex_color[3], 0); }
    else { green_y = hex_number(hex_color[3] - '0', 0); }
    if(isalpha(hex_color[4]) != 0) { blue_x = hex_letter(hex_color[4], 1); }
    else { blue_x = hex_number(hex_color[4] - '0', 1); }
    if(isalpha(hex_color[5]) != 0) { blue_y = hex_letter(hex_color[5], 0); }
    else { blue_y = hex_number(hex_color[5] - '0', 0); }

    red = red_x + red_y;
    green = green_x + green_y;
    blue = blue_x + blue_y;

    if(is_fore == 1) { sprintf(rgb, "\033[38;2;%d;%d;%dm", red, green, blue); }
    if(is_fore == 0) { sprintf(rgb, "\033[48;2;%d;%d;%dm", red, green, blue); }
    return rgb;
}

void vn_end(struct vn_init vn)
{ /* FOR ELEGANT UI */
    vn_gotoxy(0, vn.window_height);
    if(vn.cursor_visibility == 0) { vn_cursor_visibility(1); }
} /* IF 'vn_cursor_visibility()' USED */

/* MADE BY @hanilr */