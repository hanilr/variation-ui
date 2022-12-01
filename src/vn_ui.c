/* VARIATION UI (USER INTERFACE) */

/* STANDARD LIBRARY */
#include <stdio.h>
#include <string.h>

/* DIY LIBRARY */
#include "lib/vn_ui.h"
#include "lib/vn_conf.h"

/* 'boolean' => 1-> VISIBLE | 0 -> INVISIBLE */
void vn_cursor_visibility(int boolean)
{
    if(boolean == 1) { printf("%s", cursor_visible); } /* SET TERMINAL CURSOR TO VISIBLE */
    else { printf("%s", cursor_invisible); } /* SET TERMINAL CURSOR TO INVISIBLE */
}

/* CLEAR TERMINAL SCREEN */
void vn_clear(void) { printf("%s", clear_screen); }

/* SET TERMINAL CURRENT CURSOR TO 'pos_x' AND 'pos_y' POSITION */
void vn_gotoxy(int pos_x, int pos_y) { printf("\033[%d;%dH", pos_y, pos_x); }

/* SAVE CURSOR POSITION */
void vn_savexy(void) { printf("\033[s"); }

/* RESTORE SAVED CURSOR POSITION */
void vn_restorexy(void) { printf("\033[u"); }

/* SAVE SCREEN (ONLY WORK WITH SUPPORTED TERMINALS) */
void vn_savescr(void) { printf("\033[?47h"); } 

/* RESTORE SCREEN (ONLY WORK WITH SUPPORTED TERMINALS) */
void vn_restorescr(void) { printf("\033[?47l"); }

/* 'str' => STRING, 'fg_color' => FOREGROUND COLOR, 'bg_color' => BACKGROUND COLOR, 'str_style' => STRING STYLE */
void vn_print(char *str, char *fg_color, char *bg_color, char *str_style)
{ /* IF YOU DON'T WANT TO USE ARGUMENTS THEN ENTER  IN DOUBLE QUOTATION MARKS WITH GAP */
    printf("%s%s%s%s%s", fg_color, bg_color, str_style, str, esc_reset);
} /* EXAMPLE: vn_print("temp", "", "", ""); */

/* MADE BY @hanilr */