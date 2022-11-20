/* VARIATION TUI (WIDGET) */
#ifndef _VN_WIDGET_H
#define _VN_WIDGET_H

    void vn_line(int pos_x, int pos_y, int length, char *bg_color, char *format); /* DRAW SIMPLE LINE */

    void vn_bg(int pos_x, int pos_y, int width, int height, char *bg_color); /* SET BACKGROUND COLOR */

    void vn_frame(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char vertical_symbol, char horizontal_symbol); /* SET WINDOW FRAME */

    void vn_label(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char* text_style, char *str); /* SET LABEL */

    void vn_progress(int pos_x, int pos_y, int width, int height, char *progress_frame_color, char *progress_color, int progress_value); /* SET PROGRESS BAR */

    void vn_notif(int pos_x, int pos_y, int width, int height, char notif_frame_vertical_symbol, char notif_frame_horizontal_symbol, char *notif_frame_fg, char *notif_frame_bg, char *notif_fg, char *notif_bg, char *notif_title_fg, char *notif_title, char *notif_text_style, char *notif_text); /* NOTIFICATION POP-UP/SCREEN (NEED TO DEFINE 'VN_UTIL' BEFORE USING) */

    void vn_timer(int pos_x, int pos_y, char *timer_fg, char *timer_bg, char *timer_style, int time, int is_alarm); /* TIME COUNTER */

#endif /* MADE BY @hanilr */