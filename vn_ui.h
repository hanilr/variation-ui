/* VARIATION TUI (LIBRARY) */
/*     MADE BY @hanilr     */
#ifndef _VN_UI_H
#define _VN_UI_H
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

    struct vn_init
    { /* DEFINATION OF DEFAULT WINDOW SIZES */
        int width; /* WIDTH SIZE SHORTCUT */
        int height; /* HEIGHT SIZE SHORTCUT*/
        int pos_x; /* WINDOW START ROW POSITION */
        int pos_y; /* WINDOW START COLUMN POSITION */
        int cursor_visibility; /* 1 = VISIBLE, 0 = INVISIBLE */
    }; /* NOT NECESSARY (IN WIDGETS CAN USE MANUEL WAY) */

    void vn_end(struct vn_init vn); /* GO TO END OF THE WINDOW */

    #ifdef VN_COLOR
        struct vnc_color 
        { /* VARIATION CUSTOM COLOR */
            int is_fore; /* IS FOR FOREGROUND OR BACKGROUND */
            char* color; /* COLOR BUFFER NEED USE WITH 'vn_color()' FUNCTION */
        }; /* ONLY NEED HEX CODE */

        int vnc_hex_number(int number, int left_side); /* NUMBER TO HEX */

        int vnc_hex_letter(char letter, int left_side); /* LETTER TO HEX */

        char *vn_hex_color(char *hex_color, int is_fore); /* HEX COLOR CODE FOR CUSTOM COLORS */

        char *vn_rgb_color(int red, int green, int blue, int is_fore); /* RGB COLOR CODE FOR CUSTOM COLORS */
    #endif /* VN_COLOR */

    #ifdef VN_UTIL
        int vnu_half_divider(int number); /* DIVIDE AN INTEGER TO HALF */

        int vnu_get_repeat(char *str, char chr); /* GET CHAR REPEAT TIMES IN A STRING */

        #ifdef __linux__
            char vnu_get_char_instantly(void); /* GET CHAR WITHOUT '<Return>' KEY */

            void vnu_get_terminal_size(struct vn_init *vn); /* GET TERMINAL SIZES TO 'vn_init' */
        #endif /* LINUX ONLY */
    #endif /* VN_UTIL */

    void vn_cursor_visibility(int boolean); /* SET CURSOR VISIBILITY */

    void vn_clear(void); /* CLEAR SCREEN */

    void vn_gotoxy(int pos_x, int pos_y); /* SET CURSOR TO X AND Y POSITIONS */

    void vn_savexy(void); /* SAVE CURSOR POSITION */

    void vn_restorexy(void); /* RESTORE SAVED CURSOR POSITION */

    void vn_savescr(void); /* SAVE SCREEN (ONLY WORK WITH SUPPORTED TERMINALS) */

    void vn_restorescr(void); /* RESTORE SCREEN (ONLY WORK WITH SUPPORTED TERMINALS) */

    void vn_print(char *str, char *fg_color, char *bg_color, char *str_style); /* PRINT WITH COLORS */

    #ifdef VN_WIDGET
        void vn_line(int pos_x, int pos_y, int length, char *bg_color, char *format); /* DRAW SIMPLE LINE */

        void vn_bg(int pos_x, int pos_y, int width, int height, char *bg_color); /* SET BACKGROUND COLOR */

        void vn_frame(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char vertical_symbol, char horizontal_symbol); /* SET WINDOW FRAME */

        void vn_label(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char* text_style, char *str); /* SET LABEL */

        void vn_progress(int pos_x, int pos_y, int width, int height, char *progress_frame_color, char *progress_color, int progress_value); /* SET PROGRESS BAR */
    #endif /* VN_WIDGET */
#endif /* SUMMARY SECTION */

#ifdef VN_UI_IMPLEMENTATION
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>

    void vn_cursor_visibility(int boolean)
    {
        if(boolean == 1) { printf("%s", cursor_visible); }
        else { printf("%s", cursor_invisible); }
    }

    void vn_clear(void) { printf("%s", clear_screen); }

    void vn_gotoxy(int pos_x, int pos_y) { printf("\033[%d;%dH", pos_y, pos_x); }

    void vn_savexy(void) { printf("\033[s"); }

    void vn_restorexy(void) { printf("\033[u"); }

    void vn_savescr(void) { printf("\033[?47h"); }

    void vn_restorescr(void) { printf("\033[?47l"); }

    void vn_print(char *str, char *fg_color, char *bg_color, char *str_style)
    { /* IF YOU DON'T WANT TO USE ARGUMENTS THEN ENTER  IN DOUBLE QUOTATION MARKS WITH GAP */
        printf("%s%s%s%s%s", fg_color, bg_color, str_style, str, esc_reset);
    } /* EXAMPLE: vn_print("temp", "", "", ""); */

    #ifdef VN_UTIL
        int vnu_half_divider(int number)
        {
            if(number%2 == 0) { return number/2; }
            else { return (number-1)/2; }
        }

        int vnu_get_repeat(char *str, char chr)
        { /* 'vnu' = VARIATION UTILITY */
            int count = 0, i = 0;
            while(strlen(str) > i) 
            { /* LOOP TILL DETECT THE 'chr' */
                if(str[i] == chr) { count+=1; } /* IF DETECTED THE 'chr' THEN INCREASE THE 'count' */
                i+=1;
            }
            return count;
        }

        #ifdef __linux__
            char vnu_get_char_instantly(void)
            {
                system("stty raw"); /* TERMINAL 'raw' MODE */
                char key = getchar();
                system("stty cooked"); /* TERMINAL 'cooked' MODE */
                return key;
            }

            void vnu_get_terminal_size(struct vn_init *vn) 
            {
                #include <sys/ioctl.h>
                struct winsize terminal_size;
                ioctl(0, TIOCGWINSZ, &terminal_size);
                vn->width = terminal_size.ws_row;
                vn->height = terminal_size.ws_col;
            }
        #endif /* LINUX ONLY */
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

        char *vn_rgb_color(int red, int green, int blue, int is_fore)
        {
            char *rgb = (char*) malloc(32);
            if(is_fore == 0) { sprintf(rgb, "\033[38;2;%d;%d;%dm", red, green, blue); }
            if(is_fore == 1) { sprintf(rgb, "\033[48;2;%d;%d;%dm", red, green, blue); }
            return rgb;
        }
    #endif /* VN_COLOR */

    void vn_end(struct vn_init vn)
    { /* FOR ELEGANT UI */
        vn_gotoxy(0, vn.height+vn.pos_y);
        if(vn.cursor_visibility == 0) { vn_cursor_visibility(1); }
    } /* IF 'vn_cursor_visibility()' USED */

    #ifdef VN_WIDGET
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
                    printf("-");
                    x+=1;
                }
                printf("%s]%s", progress_frame_color, esc_reset); /* PROGRESS BAR ENDING SYMBOL */
                x=0;
                y+=1;
            }
        } /* 'width' MEANS LENGTH OF THE PROGRESS BAR AND 'progress_value' MEANS POINT OF THE PROGRESS BAR */
    #endif /* VN_WIDGET */
#endif /* VN_UI_IMPLEMENTATION */