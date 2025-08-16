/* VARIATION UI (BASE) */
/*     MADE BY @hanilr     */
#ifndef _VN_UI_BASE_H
#define _VN_UI_BASE_H
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
#endif /* SUMMARY SECTION */

#ifdef VN_UI_BASE_IMPLEMENTATION
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
#endif /* VN_UI_BASE_IMPLEMENTATION */