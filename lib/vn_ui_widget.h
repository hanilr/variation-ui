/* VARIATION UI (WIDGET) */
/*     MADE BY @hanilr     */
#ifndef _VN_UI_WIDGET_H
#define _VN_UI_WIDGET_H
    #define VN_UI_BASE_IMPLEMENTATION
    #include "vn_ui_base.h"

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
#endif /* SUMMARY SECTION */

#ifdef VN_UI_WIDGET_IMPLEMENTATION
    #include <stdio.h>

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
#endif /* VN_UI_WIDGET_IMPLEMENTATION */