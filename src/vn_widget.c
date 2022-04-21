/* VARIATION TUI (WIDGET) */

/*  STANDARD LIBRARY */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DIY LIBRARY */
#include "lib/vn_widget.h"
#include "lib/vn_conf.h"
#include "lib/vn_util.h"
#include "lib/vn_ui.h"

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

void vn_list(int pos_x, int pos_y, int width, int height, char *list_fg_color, char *list_bg_color, char *list_title, char *list_content)
{ /* 'list_fg_color' NEED TO BE 'is_fore = 1', 'list_bg_color' NEED TO BE 'is_fore = 0' */
    int i = 0, a = 0, content_number = vnu_get_repeat(list_content, '|'); /* GET '|' REPEAT TIME */

    vn_bg(pos_x, pos_y, width, height, list_bg_color); /* SET BACKGROUND COLOR */
    vn_gotoxy(pos_x+width/2-strlen(list_title)/2, pos_y); /* GO TO TITLE POSITION */

    printf("%s%s%s[%s]%s", list_fg_color, list_bg_color, text_bold, list_title, esc_reset); /* PRINT THE 'list_title' */
    printf("%s%s", list_fg_color, list_bg_color); /* SET COLOR TO 'list_fg_color' AND 'list_bg_color' */
    while(content_number-1 > i)
    { /* '|' PARSER SECTION */
        vn_gotoxy(pos_x, pos_y+i+1);
        if(list_content[a] == '|')
        { /* IF DETECT '|' */
            printf(" > ");
            i+=1;
            a+=1;
        }
        while(1)
        { /* PRINT CONTENT */
            if(list_content[a] == '|')
            {
                a-=1;
                break;
            }
            printf("%c", list_content[a]);
            a+=1;
        }
        a+=1;
    }
    printf("%s", esc_reset); /* RESET THE COLOR */
}

/* MADE BY @hanilr */