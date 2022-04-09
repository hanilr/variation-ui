/* VARIATION TUI (LIBRARY) */
#ifndef _VN_H
#define _VN_H
/* -------------------------------- *
 * ASCII ESCAPE SEQUENCE RESET CODE *
 * -------------------------------- */
#define esc_reset "\033[0m" 
/* -------------------------------- *
 *  MUST BE USED AFTER COLOR CODES  */

/* --------------------------------- *
 * ASCII ESCAPE SEQUENCE TEXT STYLES *
 * --------------------------------- */
#define text_bold "\033[1m"
#define text_italic "\033[3m"
#define text_underline "\033[4m"
#define text_blink "\033[5m"
#define text_strikethrough "\033[9m"
/* --------------------------------- */

/* ----------------------------------- *
 * ASCII ESCAPE SEQUENCE UTILITY CODES *
 * ----------------------------------- */
#define clear_screen "\033[2J\033[H"
#define cursor_visible "\033[?25h"
#define cursor_invisible "\033[?25l"
/* ----------------------------------- */

#ifdef VN_COLOR
struct vnc_color 
{ /* VARIATION CUSTOM COLOR */
    int is_fore; /* IS FOR FOREGROUND OR BACKGROUND */
    char* color; /* COLOR BUFFER NEED USE WITH 'vn_color()' FUNCTION */
}; /* ONLY NEED HEX CODE */

char *vn_color(char *hex_color, int is_fore); /* FOR CUSTOM COLORS */
#endif /* COLOR SECTION */

void vn_cursor_visibility(int boolean); /* SET CURSOR VISIBILITY */

void vn_clear(void); /* CLEAR SCREEN */

void vn_gotoxy(int pos_x, int pos_y); /* SET CURSOR TO X AND Y POSITIONS */

void vn_print(char *str, char *fg_color, char *bg_color, char *str_style); /* PRINT WITH COLORS */

#ifdef VN_WIDGET
void vn_bg(int pos_x, int pos_y, int width, int height, char *bg_color); /* SET BACKGROUND COLOR */

void vn_frame(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char vertical_symbol, char horizontal_symbol); /* SET FRAME */

void vn_label(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char* text_style, char *str); /* SET LABEL */
#endif /* VARIATION WIDGET SECTION */

#endif /* SUMMARY SECTION */

#ifdef VN_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

#ifdef VN_COLOR
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
#endif /* COLOR SECTION */

void vn_cursor_visibility(int boolean)
{
    if(boolean == 1) { printf("%s", cursor_visible); }
    else { printf("%s", cursor_invisible); }
}

void vn_clear(void) { printf("%s", clear_screen); }

void vn_gotoxy(int pos_x, int pos_y) { printf("\033[%d;%dH", pos_y, pos_x); }

void vn_print(char *str, char *fg_color, char *bg_color, char *str_style)
{ /* IF YOU DON'T WANT TO USE ARGUMENTS THEN ENTER  IN DOUBLE QUOTATION MARKS WITH GAP */
    printf("%s%s%s%s%s", fg_color, bg_color, str_style, str, esc_reset);
} /* EXAMPLE: vn_print("temp", "", "", ""); */

#ifdef VN_WIDGET
void vn_bg(int pos_x, int pos_y, int width, int height, char *bg_color)
{
    int x = 0, y = 0;
    printf("%s", bg_color);
    while(height > y)
    {
        vn_gotoxy(pos_x, pos_y+y);
        while(width > x)
        {
            printf(" ");
            x+=1;
        }
        x=0;
        y+=1;
    }
    printf("%s", esc_reset);
}

void vn_frame(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char vertical_symbol, char horizontal_symbol)
{
    int x = 0, y = 0;
    printf("%s%s", fg_color, bg_color);
    vn_gotoxy(pos_x, pos_y);
    while(width > x)
    {
        printf("%c", horizontal_symbol);
        x+=1;
    }
    x=0;
    while(height > y+2)
    {
        vn_gotoxy(pos_x, pos_y+y+1);
        printf("%c", vertical_symbol);
        vn_gotoxy(pos_x+width-1, pos_y+y+1);
        printf("%c", vertical_symbol);
        y+=1;
    }
    vn_gotoxy(pos_x, pos_y+height-1);
    while(width > x)
    {
        printf("%c", horizontal_symbol);
        x+=1;
    }
    printf("%s", esc_reset);
}

void vn_label(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char *text_style, char *str)
{
    vn_bg(pos_x, pos_y, width, height, bg_color);
    vn_gotoxy(pos_x, pos_y);
    if(strlen(str) > width)
    {
        int x = 0, y = 0, z = 0, i = 0;
        printf("%s%s%s", fg_color, bg_color, text_style);
        while(strlen(str) > x)
        {
            if(z == width)
            {
                i+=1;
                y+=1;

                int space_pos = 0;
                if(str[x+1] != ' ' || str[x] != ' ')
                {
                    z=x;
                    while(1)
                    {
                        if(str[z] != ' ')
                        {
                            space_pos+=1;
                            z-=1;
                            vn_gotoxy(pos_x+width-space_pos, pos_y+y-1);
                            printf(" ");
                        }
                        else
                        {
                            x-=space_pos-1;
                            break;
                        }
                    }
                }

                vn_gotoxy(pos_x, pos_y+y);
                z=0;
            }
            if(i == height)
            {
                vn_gotoxy(pos_x+width-3, pos_y+height-1);
                printf("...");
                break;
            }

            printf("%c", str[x]);
            x+=1;
            z+=1;
        }
        printf("%s", esc_reset);
    }
    else { vn_print(str, fg_color, bg_color, text_style); }
}
#endif /* VARITATION WIDGET SECTION */

#endif /* MADE BY @hanilr */