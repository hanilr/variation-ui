/* VARIATION UI (USER INTERFACE) */

/* STANDARD LIBRARY */
#include <stdio.h>
#include <string.h>

/* DIY LIBRARY */
#include "lib/vn_ui.h"
#include "lib/vn_conf.h"

void vn_cursor_visibility(int boolean)
{
    if(boolean == 1) { printf("%s", cursor_visible); } /* SET TERMINAL CURSOR TO VISIBLE */
    else { printf("%s", cursor_invisible); } /* SET TERMINAL CURSOR TO INVISIBLE */
}

void vn_clear(void) { printf("%s", clear_screen); } /* CLEAR TERMINAL SCREEN */

void vn_gotoxy(int pos_x, int pos_y) { printf("\033[%d;%dH", pos_y, pos_x); } /* SET TERMINAL CURRENT CURSOR TO 'pos_x' AND 'pos_y' POSITION */

void vn_savexy(void) { printf("\033[s"); } /* SAVE CURSOR POSITION */

void vn_restorexy(void) { printf("\033[u"); } /* RESTORE SAVED CURSOR POSITION */

void vn_savescr(void) { printf("\033[?47h"); } /* SAVE SCREEN (ONLY WORK WITH SUPPORTED TERMINALS) */

void vn_restorescr(void) { printf("\033[?47l"); } /* RESTORE SCREEN (ONLY WORK WITH SUPPORTED TERMINALS) */

void vn_print(char *str, char *fg_color, char *bg_color, char *str_style)
{ /* IF YOU DON'T WANT TO USE ARGUMENTS THEN ENTER  IN DOUBLE QUOTATION MARKS WITH GAP */
    printf("%s%s%s%s%s", fg_color, bg_color, str_style, str, esc_reset);
} /* EXAMPLE: vn_print("temp", "", "", ""); */

/* MADE BY @hanilr */