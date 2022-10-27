/* VARIATION TUI (WIDGET) */
#ifndef _VN_WIDGET_H
#define _VN_WIDGET_H

    void vn_line(int pos_x, int pos_y, int length, char *bg_color, char *format); /* DRAW SIMPLE LINE */

    void vn_bg(int pos_x, int pos_y, int width, int height, char *bg_color); /* SET BACKGROUND COLOR */

    void vn_frame(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char vertical_symbol, char horizontal_symbol); /* SET WINDOW FRAME */

    void vn_label(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char* text_style, char *str); /* SET LABEL */

    void vn_progress(int pos_x, int pos_y, int width, int height, char *progress_frame_color, char *progress_color, int progress_value); /* SET PROGRESS BAR */

#endif /* MADE BY @hanilr */