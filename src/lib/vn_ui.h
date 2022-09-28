/* VARIATION TUI (USER INTERFACE) */
#ifndef _VN_UI_H
#define _VN_UI_H

    void vn_cursor_visibility(int boolean); /* SET CURSOR VISIBILITY */

    void vn_clear(void); /* CLEAR SCREEN */

    void vn_gotoxy(int pos_x, int pos_y); /* SET CURSOR TO X AND Y POSITIONS */

    void vn_savexy(void); /* SAVE CURSOR POSITION */

    void vn_restorexy(void); /* RESTORE SAVED CURSOR POSITION */

    void vn_print(char *str, char *fg_color, char *bg_color, char *str_style); /* PRINT WITH COLORS */

#endif /* MADE BY @hanilr */