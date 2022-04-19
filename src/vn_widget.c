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
{
    int x = 0, y = 0;
    printf("%s", bg_color);
    while(height > y)
    {
        vn_gotoxy(pos_x, pos_y+y);
        while(width > x)
        {
            printf(" ");
            x+=1;
        }
        x=0;
        y+=1;
    }
    printf("%s", esc_reset);
}

void vn_frame(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char vertical_symbol, char horizontal_symbol)
{
    int x = 0, y = 0;
    printf("%s%s", fg_color, bg_color);
    vn_gotoxy(pos_x, pos_y);
    while(width > x)
    {
        printf("%c", horizontal_symbol);
        x+=1;
    }
    x=0;
    while(height > y+2)
    {
        vn_gotoxy(pos_x, pos_y+y+1);
        printf("%c", vertical_symbol);
        vn_gotoxy(pos_x+width-1, pos_y+y+1);
        printf("%c", vertical_symbol);
        y+=1;
    }
    vn_gotoxy(pos_x, pos_y+height-1);
    while(width > x)
    {
        printf("%c", horizontal_symbol);
        x+=1;
    }
    printf("%s", esc_reset);
}

void vn_label(int pos_x, int pos_y, int width, int height, char *fg_color, char *bg_color, char *text_style, char *str)
{
    vn_bg(pos_x, pos_y, width, height, bg_color);
    vn_gotoxy(pos_x, pos_y);
    if(strlen(str) > width)
    {
        int x = 0, y = 0, z = 0, i = 0;
        printf("%s%s%s", fg_color, bg_color, text_style);
        while(strlen(str) > x)
        {
            if(z == width)
            {
                i+=1;
                y+=1;

                int space_pos = 0;
                if(str[x+1] != ' ' || str[x] != ' ')
                {
                    z=x;
                    while(1)
                    {
                        if(str[z] != ' ')
                        {
                            space_pos+=1;
                            z-=1;
                            vn_gotoxy(pos_x+width-space_pos, pos_y+y-1);
                            printf(" ");
                        }
                        else
                        {
                            x-=space_pos-1;
                            break;
                        }
                    }
                }

                vn_gotoxy(pos_x, pos_y+y);
                z=0;
            }
            if(i == height)
            {
                vn_gotoxy(pos_x+width-3, pos_y+height-1);
                printf("...");
                break;
            }

            printf("%c", str[x]);
            x+=1;
            z+=1;
        }
        printf("%s", esc_reset);
    }
    else { vn_print(str, fg_color, bg_color, text_style); }
}

void vn_progress(int pos_x, int pos_y, int width, int height, char *progress_frame_color, char *progress_color, int progress_value)
{ /* 'width' MEANS LENGTH OF THE PROGRESS BAR AND 'progress_value' MEANS POINT OF THE PROGRESS BAR */
    int x = 0, y = 0;

    while(height > y)
    {
        vn_gotoxy(pos_x, pos_y+y);
        printf("%s%s[", progress_frame_color, text_bold);
        while(progress_value > x)
        {
            printf("%s#", progress_color);
            x+=1;
        }
        while(width > x)
        {
            printf("-");
            x+=1;
        }
        printf("%s]%s", progress_frame_color, esc_reset);
        x=0;
        y+=1;
    }
}

void vn_list(int pos_x, int pos_y, int width, int height, char *list_bg_color, char *list_fg_color, char *list_title, char *list_content)
{
    int i = 0, a = 0, content_number = vnu_get_repeat(list_content, '|');

    vn_bg(pos_x, pos_y, width, height, list_bg_color);
    vn_gotoxy(pos_x+width/2-strlen(list_title)/2, pos_y);

    printf("%s%s%s[%s]%s", list_fg_color, list_bg_color, text_bold, list_title, esc_reset);
    printf("%s%s", list_fg_color, list_bg_color);
    while(content_number-1 > i)
    {
        vn_gotoxy(pos_x, pos_y+i+1);
        if(list_content[a] == '|')
        {
            printf(" > ");
            i+=1;
            a+=1;
        }
        while(1)
        {
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
    printf("%s", esc_reset);
}

/* MADE BY @hanilr */