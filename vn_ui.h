/* VARIATION UI (LIBRARY) */
/*     MADE BY @hanilr    */
#ifndef _VN_UI_H
#define _VN_UI_H
    /* ASCII ESCAPE SEQUENCE RESET CODE */
    #define vn_text_reset "\033[0m" /* Use after escape sequences. */

    /* ASCII ESCAPE SEQUENCE TEXT STYLES */
    #define vn_text_bold "\033[1m" /* Bold text. */
    #define vn_text_italic "\033[3m" /* Italic text. */
    #define vn_text_underline "\033[4m" /* Text with underline. */
    #define vn_text_blink "\033[5m" /* Blinker text. */
    #define vn_text_strikethrough "\033[9m" /* Text with strikethrough. */

    /* ASCII ESCAPE SEQUENCE UTILITY CODES */
    #define vn_clear_screen "\033[2J\033[H" /* Screen clear. */
    #define vn_cursor_visible "\033[?25h" /* Visible cursor. */
    #define vn_cursor_invisible "\033[?25l" /* Invisible cursor. */

    /* VARIATION TEXT ATTRIBUTE STRUCT */
    /* ------------------------------- */
    /* You should use 'vn_color' with 'strcpy' function. */
    /* [!] 'vn_color' function need to be free after use [!] */
    typedef struct {
        char color_fg[24];
        char color_bg[24];
        char text_style[24];
    } VN_UI_TEXT;

    /* VARIATION ESCAPE SEQUENCE PRINTER */
    void vn_printizer(char* text, char* color_fg, char* color_bg, char* text_style); /* Variation print linker. */

    /* VARIATION ESCAPE SEQUENCE CODISER */
    void vn_codizer(char* code); /* Variation code linker. */

    void vn_gotoxy(int pos_x, int pos_y); /* Variation cursor position manipulation. */

    /* VARIATION COLORIZER */
    char* vn_colorizer(char* color, char base); /* Variation color linker. */

    /* Variation Print: Escape sequence printizer linker. */
    /* -------------------------------------------------- */
    /* 'text': Context of print.                          */
    /* 'color_fg': Foreground color.                      */
    /* 'color_bg': Background color.                      */
    /* 'text_style': Text attribute.                      */
    #define vn_printf(text, color_fg, color_bg, text_style) (vn_printizer(text, color_fg, color_bg, text_style))

    /* Variation Print: Escape sequence printizer linker. */
    /* -------------------------------------------------- */
    /* 'text': Context of print.                          */
    /* 'vnt': VN_UI_TEXT struct dependency text attribute.*/
    #define vn_print(text, vnt) (vn_printizer(text, vnt.color_fg, vnt.color_bg, vnt.text_style))

    /* Variation Code: Escape sequence codizer linker. */
    /* ----------------------------------------------- */
    /* 'screen:clear': Clear the screen.               */
    /* 'screen:save': Save screen.                     */
    /* 'screen:restore': Restore screen.               */
    /* 'cursor:visible': Cursor visiblity true.        */
    /* 'cursor:invisible': Cursor visiblity false.     */
    /* 'cursor:save': Save cursor position.            */
    /* 'cursor:restore': Restore cursor position.      */
    #define vn_code(code) (vn_codizer(code))

    /* Variation Color: Escape sequence colorizer linker. */
    /* -------------------------------------------------- */
    /* 'color': "#a1b2c3" for HEX or "001 024 200" for RGB */
    /* Foreground: (base = 'f'), Background: (base = 'b') */
    /* [!] Need to free after using. [!] */
    #define vn_color(color, base) (vn_colorizer(color, base))

    #ifdef VN_WIDGET
        /* VARIATION USER INTERFACE WIDGET STRUCTURE */
        typedef struct {
            int pos_x; /* Horizontal position. */
            int pos_y; /* Vertical position. */
            int width; /* Widget's width. */
            int height; /* Widget's height. */
        } VN_UI_WIDGET;

        /* DRAW A LINE AS HORIZONTAL OR VERTICAL */
        void vn_line(char symbol, char* format, VN_UI_TEXT vnt, VN_UI_WIDGET vnw);

        /* SET BACKGROUND SIZE AND A COLOR */
        void vn_bg(char symbol, VN_UI_TEXT vnt, VN_UI_WIDGET vnw);

        /* SET A FRAME AND A COLOR */
        void vn_frame(char vertical_symbol, char horizontal_symbol, VN_UI_TEXT vnt, VN_UI_WIDGET vnw);

        /* MAKE A LABEL WITH CHANGABLE SIZE, COLOR AND TEXT */
        void vn_label(char* text, VN_UI_TEXT vnt, VN_UI_WIDGET vnw);

        /* MAKE A PROGRESS BAR WITH CHANGABLE SIZE AND COLOR */
        void vn_progress(int value, char frame, char complete, char incomplete, VN_UI_TEXT vnt, VN_UI_WIDGET vnw);

        /* POP-UP/NOTIFICATION SCREEN */
        void vn_notif(char* title, char* text, char frame_vertical, char frame_horizontal, VN_UI_TEXT vnt_frame, VN_UI_TEXT vnt_title, VN_UI_TEXT vnt_text, VN_UI_WIDGET vnw);
    #endif /* VN_WIDGET */
#endif /* SUMMARY SECTION */

#ifdef VN_UI_IMPLEMENTATION
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    /* 'vn_print' LINKER */
    void vn_printizer(char* text, char* color_fg, char* color_bg, char* text_style) {
        printf("%s%s%s", color_fg, color_bg, text_style); /* Text attribute. */
        printf("%s", text); /* Context of text. */
        printf("%s", vn_text_reset); /* Reset after attribute. */
    }

    /* 'vn_code' LINKER */
    void vn_codizer(char* code) {
        if(!strcmp(code, "screen:clear")) {
            printf("%s", vn_clear_screen);
        } else if(!strcmp(code, "screen:save")) {
            printf("\033[?47h");
        } else if(!strcmp(code, "screen:restore")) {
            printf("\033[?47l");
        } else if(!strcmp(code, "cursor:visible")) {
            printf("%s", vn_cursor_visible);
        } else if(!strcmp(code, "cursor:invisible")) {
            printf("%s", vn_cursor_invisible);
        } else if(!strcmp(code, "cursor:save")) {
            printf("\033[s");
        } else if(!strcmp(code, "cursor:restore")) {
            printf("\033[u");
        } else {
            fprintf(stderr, "VN_CODE: There is no code found!\n");
        }
    }

    /* GO TO POSITION X AND POSITION Y */
    void vn_gotoxy(int pos_x, int pos_y) {
        printf("\033[%d;%dH", pos_y, pos_x);
    }

    /* 'vn_color' LINKER */
    char* vn_colorizer(char* color, char base) {
        if (strlen(color) == 7 || strlen(color) == 9) {
            int red, green, blue;
            char* rgb = (char*) malloc(32);

            if (rgb == NULL) {
                fprintf(stderr, "VN_COLOR: Memory allocation failed!\n");
                return NULL;
            }

            if (color[0] == '#' && strlen(color) == 7) { /* Hexadecimal color code */
                char red_str[3] = { color[1], color[2], '\0' };
                char green_str[3] = { color[3], color[4], '\0' };
                char blue_str[3] = { color[5], color[6], '\0' };

                red = (int)strtol(red_str, NULL, 16);
                green = (int)strtol(green_str, NULL, 16);
                blue = (int)strtol(blue_str, NULL, 16);
            } else { /* RGB color code */
                int rgb_value = (int)strtol(color, NULL, 10);
                red = rgb_value / 1000000;
                green = (rgb_value / 1000) % 1000;
                blue = rgb_value % 1000;
            }

            if (base == 'f') { /* Foreground selected */
                sprintf(rgb, "\033[38;2;%d;%d;%dm", red, green, blue);
            } else if (base == 'b') { /* Background selected */
                sprintf(rgb, "\033[48;2;%d;%d;%dm", red, green, blue);
            }
            return rgb;
        } else {
            fprintf(stderr, "VN_COLOR: Wrong color value!\n");
        }
    } /* [!] Need to free after using. [!] */

    #ifdef VN_WIDGET
        /* DRAW A LINE AS HORIZONTAL OR VERTICAL */
        void vn_line(char symbol, char* format, VN_UI_TEXT vnt, VN_UI_WIDGET vnw) {
            int i;
            printf("%s%s%s", vnt.color_fg, vnt.color_bg, vnt.text_style);

            if(!strcmp(format, "horizontal")) {
                vn_gotoxy(vnw.pos_x, vnw.pos_y);
                i = vnw.width;
            } else { i = vnw.height; }

            while(i > 0)
            {
                if(!strcmp(format, "vertical")) vn_gotoxy(vnw.pos_x, vnw.pos_y + i);
                printf("%c", symbol);
                i -= 1;
            }
            printf("%s", vn_text_reset);
        }

        /* SET BACKGROUND SIZE AND A COLOR */
        void vn_bg(char symbol, VN_UI_TEXT vnt, VN_UI_WIDGET vnw) {
            int i = vnw.height;
            while (i > 0) {
                vn_line(symbol, "horizontal", vnt, vnw);
                vnw.pos_y += 1;
                i -= 1;
            }
        }

        /* SET A FRAME AND A COLOR */
        void vn_frame(char vertical_symbol, char horizontal_symbol, VN_UI_TEXT vnt, VN_UI_WIDGET vnw) {
            VN_UI_WIDGET vnw_copy = {vnw.pos_x, vnw.pos_y, vnw.width, vnw.height};

            vn_line(horizontal_symbol, "horizontal", vnt, vnw_copy); /* Top line. */
            vnw_copy.pos_y += vnw_copy.height + 1; /* Vertical position change. */
            vn_line(horizontal_symbol, "horizontal", vnt, vnw_copy); /* Bottom line. */
            vnw_copy.pos_y -= vnw_copy.height + 1; /* Vertical position reverse. */

            vn_line(vertical_symbol, "vertical", vnt, vnw_copy); /* Left line. */
            vnw_copy.pos_x += vnw_copy.width - 1; /* Horizontal position change. */
            vn_line(vertical_symbol, "vertical", vnt, vnw_copy); /* Right line. */
        }

        /* MAKE A LABEL WITH CHANGABLE SIZE, COLOR AND TEXT */
        void vn_label(char* text, VN_UI_TEXT vnt, VN_UI_WIDGET vnw) {
            vn_bg(' ', vnt, vnw);
            vn_gotoxy(vnw.pos_x, vnw.pos_y);

            if(strlen(text) > vnw.width)
            { /* IF 'text' LONGER THAN THE 'width' */
                int x = 0, y = 0, z = 0, i = 0;
                printf("%s%s%s", vnt.color_fg, vnt.color_bg, vnt.text_style); /* SET COLOR TO 'fg_color' AND 'bg_color', SET TEXT STYLE TO 'text_style' */
                while(strlen(text) > x)
                { /* LOOP TILL 'text' NOT OVER */
                    if(z == vnw.width)
                    { /* IF PRINTED 'text' CHAR REACHED THE 'width' */
                        i += 1;
                        y += 1;

                        int space_pos = 0;
                        if(text[x+1] != ' ' || text[x] != ' ')
                        { /* IF LAST WORD NOT OVER */
                            z = x;
                            while(1)
                            { /* LOOP TILL LAST WORD MOVED TO NEXT LINE */
                                if(text[z] != ' ') 
                                { /* IF 'text' REACHED TO SPACE */
                                    space_pos += 1;
                                    z -= 1;
                                    vn_gotoxy(vnw.pos_x + vnw.width - space_pos, vnw.pos_y + y - 1); /* GO TO HALF PRINTED WORD */
                                    printf(" "); /* FILL WITH SPACE HALF PRINTED WORD */
                                }
                                else
                                { /* IF 'text' NOT REACHED TO SPACE */
                                    x -= space_pos-1;
                                    break;
                                }
                            }
                        }

                        vn_gotoxy(vnw.pos_x, vnw.pos_y + y); /* GO TO NEW LINE */
                        z=0;
                    }
                    if(i == vnw.height)
                    { /* IF 'text' RECHED TO 'height' */
                        vn_gotoxy(vnw.pos_x + vnw.width - 3, vnw.pos_y + vnw.height - 1); /* GO TO LAST LINE AND GO TO 'width'-3 */
                        printf("..."); /* FILL WITH '...' */
                        break;
                    }

                    printf("%c", text[x]); /* 'text' PRINT SECTION */
                    x+=1;
                    z+=1;
                }
                printf("%s", vn_text_reset); /* RESET THE COLOR AND THE TEXT STYLE */
            }
            else { vn_printf(text, vnt.color_fg, vnt.color_bg, vnt.text_style); } /* IF 'text' NOT LONGER THAN THE 'width' */
        }

        /* MAKE A PROGRESS BAR WITH CHANGABLE SIZE AND COLOR */
        /* ------------------------------------------------- */
        /* 'value' variable has dependency from 'vnw' struct.
        If vnw.width has 10 value then 10 is the maximum value.
        If 'value' is 5 and 'vnw.width' is 10, then progress bar is %50 completed. */
        void vn_progress(int value, char frame, char complete, char incomplete, VN_UI_TEXT vnt, VN_UI_WIDGET vnw) {
            int x = 0, y = 0;
            while(vnw.height > y)
            { /* COLUMN */
                vn_gotoxy(vnw.pos_x, vnw.pos_y + y); /* GO TO START POSITION */
                printf("%s%s%s%c", vnt.color_fg, vnt.color_bg, vnt.text_style, frame); /* PROGRESS BAR STARTING SYMBOL */
                while(value > x)
                { /* COMPLETED PROGRESS SECTION */
                    printf("%c", complete);
                    x+=1;
                }
                while(vnw.width > x)
                { /* INCOMPLETED PROGRESS SECTION */
                    printf("%c", incomplete);
                    x+=1;
                }
                printf("%c%s", frame, vn_text_reset); /* RESETTING */
                x=0;
                y+=1;
            }
        }

        /* POP-UP/NOTIFICATION SCREEN */
        void vn_notif(char* title, char* text, char frame_vertical, char frame_horizontal, VN_UI_TEXT vnt_frame, VN_UI_TEXT vnt_title, VN_UI_TEXT vnt_text, VN_UI_WIDGET vnw) {
            vn_bg(' ', vnt_text, vnw);
            vn_frame(frame_vertical, frame_horizontal, vnt_frame, vnw);

            vn_gotoxy(vnw.pos_x + vnw.width / 2 - strlen(title) / 2, vnw.pos_y + 1); /* TITLE POSITION */
            vn_printf(title, vnt_title.color_fg, vnt_title.color_bg, vnt_title.text_style);

            vnw.pos_x += 2;
            vnw.pos_y += 3;
            vnw.width -= 4;
            vnw.height -= 4;
            vn_label(text, vnt_text, vnw); /* TEXT */
        }
    #endif /* VN_WIDGET */
#endif /* VN_UI_IMPLEMENTATION */
