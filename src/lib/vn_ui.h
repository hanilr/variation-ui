/* VARIATION UI (USER INTERFACE) */
#ifndef _VN_UI_H
#define _VN_UI_H
    /* SET CURSOR VISIBILITY */
    void vn_cursor_visibility(int boolean);

    /* CLEAR TERMINAL SCREEN */
    void vn_clear(void);

    /* SET CURSOR TO X AND Y POSITIONS */
    void vn_gotoxy(int pos_x, int pos_y);

    /* SAVE CURSOR POSITION */
    void vn_savexy(void);

    /* RESTORE SAVED CURSOR POSITION */
    void vn_restorexy(void);

    /* SAVE SCREEN (ONLY WORK WITH SUPPORTED TERMINALS) */
    void vn_savescr(void);

    /* RESTORE SCREEN (ONLY WORK WITH SUPPORTED TERMINALS) */
    void vn_restorescr(void);

    /* PRINT WITH COLORS */
    void vn_print(char *str, char *fg_color, char *bg_color, char *str_style);
#endif /* MADE BY @hanilr */