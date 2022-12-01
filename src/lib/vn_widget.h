/* VARIATION UI (WIDGET) */
#ifndef _VN_WIDGET_H
#define _VN_WIDGET_H
    /* DRAW A LINE AS HORIZONTAL OR VERTICAL */
    void vn_line(int pos_x, int pos_y, int length, char *bg_color, char *format);

    /* SET BACKGROUND SIZE AND A COLOR */
    void vn_bg(int pos_x, int pos_y, int width, int height, char *bg_color);

    /* SET A FRAME AND A COLOR */
    void vn_frame(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char vertical_symbol, char horizontal_symbol);

    /* MAKE A LABEL WITH CHANGABLE SIZE, COLOR AND TEXT */
    void vn_label(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char* text_style, char *str);

    /* MAKE A PROGRESS BAR WITH CHANGABLE SIZE AND COLOR */
    void vn_progress(int pos_x, int pos_y, int width, int height, char *progress_frame_color, char *progress_color, int progress_value);

    /* POP-UP/NOTIFICATION SCREEN */
    void vn_notif(int pos_x, int pos_y, int width, int height, char notif_frame_vertical_symbol, char notif_frame_horizontal_symbol, char *notif_frame_fg, char *notif_frame_bg, char *notif_fg, char *notif_bg, char *notif_title_fg, char *notif_title, char *notif_text_style, char *notif_text);

    /* COUNT TO SPECIFIC TIME. A TIMER */
    void vn_timer(int pos_x, int pos_y, char *timer_fg, char *timer_bg, char *timer_style, int time, int is_alarm);
#endif /* MADE BY @hanilr */