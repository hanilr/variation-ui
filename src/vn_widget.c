/* VARIATION TUI (WIDGET) */

/*  STANDARD LIBRARY */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DIY LIBRARY */
#include "lib/vn_widget.h"
#include "lib/vn_conf.h"
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

/* MADE BY @hanilr */