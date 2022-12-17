/* VARIATION UI (LIBRARY) */
/*     MADE BY @hanilr     */
#ifndef _VN_UI_H
#define _VN_UI_H
    /* ASCII ESCAPE SEQUENCE RESET CODE */
    #define esc_reset "\033[0m" /* MUST BE USED AFTER COLOR CODES */

    /* ASCII ESCAPE SEQUENCE TEXT STYLES */
    #define text_bold "\033[1m" /* BOLD */
    #define text_italic "\033[3m" /* ITALIC */
    #define text_underline "\033[4m" /* UNDERLINE */
    #define text_blink "\033[5m" /* BLINK */
    #define text_strikethrough "\033[9m" /* STRIKETHROUGH */

    /* ASCII ESCAPE SEQUENCE UTILITY CODES */
    #define clear_screen "\033[2J\033[H" /* CLEAR SCREEN */
    #define cursor_visible "\033[?25h" /* SET CURSOR VISIBLE */
    #define cursor_invisible "\033[?25l" /* SET CURSOR INVISIBLE */

    struct vn_init
    { /* DEFINATION OF DEFAULT WINDOW SIZES */
        int width; /* WIDTH SIZE SHORTCUT */
        int height; /* HEIGHT SIZE SHORTCUT*/
        int pos_x; /* WINDOW START ROW POSITION */
        int pos_y; /* WINDOW START COLUMN POSITION */
        int cursor_visibility; /* 1 = VISIBLE, 0 = INVISIBLE */
    }; /* NOT NECESSARY (IN WIDGETS CAN USE MANUEL WAY) */

    /* END VN SUCCESSFULLY, REQUIRED 'vn_init' STRUCT */
    void vn_end(struct vn_init vn);

    #ifdef VN_COLOR
        struct vnc_color 
        { /* VARIATION CUSTOM COLOR */
            int is_fore; /* IS FOR FOREGROUND OR BACKGROUND */
            char* color; /* COLOR BUFFER NEED USE WITH 'vn_color()' FUNCTION */
        }; /* ONLY NEED HEX CODE */

        int vnc_hex_number(int number, int left_side);

        int vnc_hex_letter(char letter, int left_side);

        /* 'hex_color' => HEX COLOR CODE, 'is_fore' => NEED 'self.is_fore' JUST REPLACE 'self' WITH STRUCT NAME */
        char *vn_hex_color(char *hex_color, int is_fore);

        /* RGB COLOR CODE, 'is_fore' => NEED 'self.is_fore' JUST REPLACE 'self' WITH STRUCT NAME */
        char *vn_rgb_color(int red, int green, int blue, int is_fore);
    #endif /* VN_COLOR */

    #ifdef VN_UTIL
        /* GET CURRENT TIME AND RETURN AS STRING */
        char *vnu_get_time(void);

        /* 'sleep_type' => 'hour', 'minute', 'second' or 'millisecond', 'sleep_time' => INTEGER */
        void vnu_sleep(char *sleep_type, int sleep_time);

        /* GET USER INPUT WITHOUT '<Return>' KEY */
        char vnu_get_char_instantly(void);

        /* GET TERMINAL SIZE, REQUIRED 'vn_init' STRUCT */
        void vnu_get_terminal_size(struct vn_init *vn);
    #endif /* VN_UTIL */

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

    #ifdef VN_WIDGET
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
    #endif /* VN_WIDGET */
#endif /* SUMMARY SECTION */

#ifdef VN_UI_IMPLEMENTATION
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include <time.h>
    #include <unistd.h>
    #include <sys/ioctl.h>

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

    #ifdef VN_UTIL
        /* GET CURRENT TIME AND RETURN AS STRING */
        char *vnu_get_time(void)
        {
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            char *time = (char*) malloc(16);

            sprintf(time, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
            return time;
        }

        /* 'sleep_type' => 'hour', 'minute', 'second' or 'millisecond', 'sleep_time' => INTEGER */
        void vnu_sleep(char *sleep_type, int sleep_time)
        { /* 'sleep_time' MUST BE IN ITs OWN UNIT */
            if(!strcmp(sleep_type, "hour")) { sleep(sleep_time*3600); }
            if(!strcmp(sleep_type, "minute")) { sleep(sleep_time*60); }
            if(!strcmp(sleep_type, "second")) { sleep(sleep_time); }
            if(!strcmp(sleep_type, "millisecond")) { sleep(sleep_time/1000); }
        } /* EXAMPLE: 'vnu_sleep("hour", 1);' IT MEAN SLEEP 1 HOUR */

        /* GET USER INPUT WITHOUT '<Return>' KEY */
        char vnu_get_char_instantly(void)
        {
            system("stty raw"); /* TERMINAL 'raw' MODE */
            char key = getchar();
            system("stty cooked"); /* TERMINAL 'cooked' MODE */
            return key;
        }

        /* GET TERMINAL SIZE, REQUIRED 'vn_init' STRUCT */
        void vnu_get_terminal_size(struct vn_init *vn) 
        {
            struct winsize terminal_size;
            ioctl(0, TIOCGWINSZ, &terminal_size);
            vn->width = terminal_size.ws_row;
            vn->height = terminal_size.ws_col;
        }
    #endif /* VN_UTIL */

    #ifdef VN_COLOR
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

        /* 'hex_color' => HEX COLOR CODE, 'is_fore' => NEED 'self.is_fore' JUST REPLACE 'self' WITH STRUCT NAME */
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

        /* RGB COLOR CODE, 'is_fore' => NEED 'self.is_fore' JUST REPLACE 'self' WITH STRUCT NAME */
        char *vn_rgb_color(int red, int green, int blue, int is_fore)
        {
            char *rgb = (char*) malloc(32);
            if(is_fore == 0) { sprintf(rgb, "\033[38;2;%d;%d;%dm", red, green, blue); }
            if(is_fore == 1) { sprintf(rgb, "\033[48;2;%d;%d;%dm", red, green, blue); }
            return rgb;
        }
    #endif /* VN_COLOR */

    /* END VN SUCCESSFULLY, REQUIRED 'vn_init' STRUCT */
    void vn_end(struct vn_init vn)
    { /* FOR ELEGANT UI */
        vn_gotoxy(0, vn.height+vn.pos_y);
        if(vn.cursor_visibility == 0) { vn_cursor_visibility(1); }
    } /* IF 'vn_cursor_visibility()' USED */

    #ifdef VN_WIDGET
        /* DRAW A LINE AS HORIZONTAL OR VERTICAL */
        void vn_line(int pos_x, int pos_y, int length, char *bg_color, char *format)
        {
            printf("%s", bg_color); /* SET COLOR TO 'bg_color' */
            int x = 0;
            if(!strcmp(format, "horizontal"))
            {
                vn_gotoxy(pos_x, pos_y);
                while(length > x)
                {
                    printf(" ");
                    x+=1;
                }
            }
            if(!strcmp(format, "vertical"))
            {
                while(length > x)
                {
                    vn_gotoxy(pos_x, pos_y+x);
                    printf(" ");
                    x+=1;
                }
            }
            printf("%s", esc_reset); /* RESET THE COLOR */
        }

        /* SET BACKGROUND SIZE AND A COLOR */
        void vn_bg(int pos_x, int pos_y, int width, int height, char *bg_color)
        { /* 'bg_color' NEED TO BE 'is_fore = 0' */
            int x = 0, y = 0;
            printf("%s", bg_color); /* SET COLOR TO 'bg_color' */
            while(height > y) 
            { /* COLUMN */
                vn_gotoxy(pos_x, pos_y+y); /* GO TO CERTAIN LOCATION */
                while(width > x) 
                { /* ROW */
                    printf(" ");
                    x+=1;
                }
                x=0;
                y+=1;
            }
            printf("%s", esc_reset); /* RESET THE COLOR */
        }

        /* SET A FRAME AND A COLOR */
        void vn_frame(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char vertical_symbol, char horizontal_symbol)
        { /* 'fg_color' NEED TO BE 'is_fore = 1', 'bg_color' NEED TO BE 'is_fore = 0' */
            int x = 0, y = 0;
            printf("%s%s", fg_color, bg_color); /* SET COLOR TO 'fg_color' AND 'bg_color' */
            vn_gotoxy(pos_x, pos_y); /* GO TO START POSITION */
            while(width > x)
            { /* FILL THE CERTAIN LINE */
                printf("%c", horizontal_symbol);
                x+=1;
            }
            x=0;
            while(height > y+2)
            { /* FILL THE CERTAIN COLUMN */
                vn_gotoxy(pos_x, pos_y+y+1); /* GO TO LEFT COLUMN */
                printf("%c", vertical_symbol);
                vn_gotoxy(pos_x+width-1, pos_y+y+1); /* GO TO RIGHT COLUMN */
                printf("%c", vertical_symbol);
                y+=1;
            }
            vn_gotoxy(pos_x, pos_y+height-1); /* GO TO LAST LINE */
            while(width > x)
            { /* FILL THE CERTAIN LINE */
                printf("%c", horizontal_symbol);
                x+=1;
            }
            printf("%s", esc_reset); /* RESET THE COLOR */
        } /* 'vertical_symbol' AND 'horizontal_symbol' IS NOT NECESSARY */

        /* MAKE A LABEL WITH CHANGABLE SIZE, COLOR AND TEXT */
        void vn_label(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char *text_style, char *str)
        { /* 'fg_color' NEED TO BE 'is_fore = 1', 'bg_color' NEED TO BE 'is_fore = 0'. 'text_style' CAN FOUND IN 'src/lib/vn_conf.h' */
            vn_bg(pos_x, pos_y, width, height, bg_color); /* SET BACKGROUND COLOR */
            vn_gotoxy(pos_x, pos_y); /* GO TO START POSITION */
            if(strlen(str) > width)
            { /* IF 'str' LONGER THAN THE 'width' */
                int x = 0, y = 0, z = 0, i = 0;
                printf("%s%s%s", fg_color, bg_color, text_style); /* SET COLOR TO 'fg_color' AND 'bg_color', SET TEXT STYLE TO 'text_style' */
                while(strlen(str) > x)
                { /* LOOP TILL 'str' NOT OVER */
                    if(z == width)
                    { /* IF PRINTED 'str' CHAR REACHED THE 'width' */
                        i+=1;
                        y+=1;

                        int space_pos = 0;
                        if(str[x+1] != ' ' || str[x] != ' ')
                        { /* IF LAST WORD NOT OVER */
                            z=x;
                            while(1)
                            { /* LOOP TILL LAST WORD MOVED TO NEXT LINE */
                                if(str[z] != ' ') 
                                { /* IF 'str' REACHED TO SPACE */
                                    space_pos+=1;
                                    z-=1;
                                    vn_gotoxy(pos_x+width-space_pos, pos_y+y-1); /* GO TO HALF PRINTED WORD */
                                    printf(" "); /* FILL WITH SPACE HALF PRINTED WORD */
                                }
                                else
                                { /* IF 'str' NOT REACHED TO SPACE */
                                    x-=space_pos-1;
                                    break;
                                }
                            }
                        }

                        vn_gotoxy(pos_x, pos_y+y); /* GO TO NEW LINE */
                        z=0;
                    }
                    if(i == height)
                    { /* IF 'str' RECHED TO 'height' */
                        vn_gotoxy(pos_x+width-3, pos_y+height-1); /* GO TO LAST LINE AND GO TO 'width'-3 */
                        printf("..."); /* FILL WITH '...' */
                        break;
                    }

                    printf("%c", str[x]); /* 'str' PRINT SECTION */
                    x+=1;
                    z+=1;
                }
                printf("%s", esc_reset); /* RESET THE COLOR AND THE TEXT STYLE */
            }
            else { vn_print(str, fg_color, bg_color, text_style); } /* IF 'str' NOT LONGER THAN THE 'width' */
        }

        /* MAKE A PROGRESS BAR WITH CHANGABLE SIZE AND COLOR */
        void vn_progress(int pos_x, int pos_y, int width, int height, char *progress_frame_color, char *progress_color, int progress_value)
        { /* 'progress_frame_color' NEED TO BE 'is_fore = 1', 'progress_color' NEED TO BE 'is_fore = 1' */
            int x = 0, y = 0;

            while(height > y)
            { /* COLUMN */
                vn_gotoxy(pos_x, pos_y+y); /* GO TO START POSITION */
                printf("%s%s[", progress_frame_color, text_bold); /* PROGRESS BAR STARTING SYMBOL */
                while(progress_value > x)
                { /* COMPLETED PROGRESS SECTION */
                    printf("%s#", progress_color);
                    x+=1;
                }
                while(width > x)
                { /* NOT COMPLETED PROGRESS SECTION */
                    printf(".");
                    x+=1;
                }
                printf("%s", esc_reset); /* RESETTING */
                printf("%s%s]%s", progress_frame_color, text_bold, esc_reset); /* PROGRESS BAR ENDING SYMBOL */
                x=0;
                y+=1;
            }
        } /* 'width' MEANS LENGTH OF THE PROGRESS BAR AND 'progress_value' MEANS POINT OF THE PROGRESS BAR */

        /* POP-UP/NOTIFICATION SCREEN */
        void vn_notif(int pos_x, int pos_y, int width, int height, char notif_frame_vertical_symbol, char notif_frame_horizontal_symbol, char *notif_frame_fg, char *notif_frame_bg, char *notif_fg, char *notif_bg, char *notif_title_fg, char *notif_title, char *notif_text_style, char *notif_text)
        {
            vn_bg(pos_x, pos_y, width, height, notif_bg);
            vn_frame(pos_x, pos_y, width, height, notif_frame_fg, notif_frame_bg, notif_frame_vertical_symbol, notif_frame_horizontal_symbol);

            vn_gotoxy(pos_x+width/2-strlen(notif_title)/2, pos_y+1); /* TITLE POSITION */
            printf("%s%s%s", text_bold, notif_title_fg, notif_bg);
            printf("%s", notif_title);
            printf("%s", esc_reset);

            vn_label(pos_x+2, pos_y+3, width-4, height-4, notif_fg, notif_bg, notif_text_style, notif_text); /* TEXT */
        }

        /* COUNT TO SPECIFIC TIME. A TIMER */
        void vn_timer(int pos_x, int pos_y, char *timer_fg, char *timer_bg, char *timer_style, int time, int is_alarm)
        {
            int time_hour = 0, time_minute = 0, time_second = 0, time_buffer = time;

            if(time > 3600)
            {
                time_hour = time/3600;
                time = time%3600;
            }
            if(time > 60)
            {
                time_minute = time/60;
                time = time%60;
            }
            time_second = time;
            printf("%s%s%s", timer_fg, timer_bg, timer_style);

            while(1)
            {
                vn_gotoxy(pos_x, pos_y);
                if(time_second < 10) { printf("%d:%d:0%d\n", time_hour, time_minute, time_second); }
                else if(time_minute < 10) { printf("%d:0%d:%d\n", time_hour, time_minute, time_second); }
                else if(time_hour < 10) { printf("0%d:%d:%d\n", time_hour, time_minute, time_second); }
                else { printf("%d:%d:%d\n", time_hour, time_minute, time_second); }

                if(time_second == 0)
                {
                    if(time_minute == 0)
                    {
                        if(time_hour == 0) { break; }
                        time_hour-=1;
                        time_minute=59;
                        time_second=60;
                    }
                    else
                    {
                        time_minute-=1;
                        time_second=60;
                    }
                }
                time_second-=1;
                sleep(1);
            }
            printf("%s", esc_reset);
            if(is_alarm == 0) { printf("\a"); }
        }
    #endif /* VN_WIDGET */
#endif /* VN_UI_IMPLEMENTATION */