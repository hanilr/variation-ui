/* VARIATION TUI (WIDGET) */

/*  STANDARD LIBRARY */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

/* DIY LIBRARY */
#include "lib/vn_widget.h"
#include "lib/vn_conf.h"
#include "lib/vn_util.h"
#include "lib/vn_ui.h"

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
        printf("%s", esc_reset); /* RESETTING */
        printf("%s%s]%s", progress_frame_color, text_bold, esc_reset); /* PROGRESS BAR ENDING SYMBOL */
        x=0;
        y+=1;
    }
} /* 'width' MEANS LENGTH OF THE PROGRESS BAR AND 'progress_value' MEANS POINT OF THE PROGRESS BAR */

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

void vn_draw(int pos_x, int pos_y, int width, int height, int cursor_pos_x, int cursor_pos_y, char *fg_color, char *bg_color, char cursor_symbol, char draw_symbol)
{
    int i = 0, j = 0;
    char key = 0;

    vn_bg(pos_x, pos_y, width, height, bg_color);
    printf("%s%s", fg_color, bg_color);

    while(1)
    {
        vn_gotoxy(cursor_pos_x+i, cursor_pos_y+j);
        printf("%c", cursor_symbol);

        /* GET WHICH KEY PRESSED */
        vn_gotoxy(pos_x, pos_y+height);
        system("stty raw");
        char key = getchar();
        system("stty cooked");
        vn_gotoxy(pos_x, pos_y+height);
        printf("%s", esc_reset);
        int x = 0;
        while(width > x)
        {
            printf(" ");
            x+=1;
        }
        printf("%s%s", fg_color, bg_color);

        vn_gotoxy(cursor_pos_x+i, cursor_pos_y+j);
        printf("%c", draw_symbol);
        
        /* KEYS AND MEANINGS */
        if(key == 'w') { j-=1; }
        if(key == 's') { j+=1; }
        if(key == 'd') { i+=1; }
        if(key == 'a') { i-=1; }
        if(key == 'q') { break; }
        if(key == 'c') /* COMMAND PANEL */
        {
            char *com = (char*) malloc(2);
            printf("%s", esc_reset);

            vn_line(pos_x, pos_y+height, width, bg_color, "horizontal");
            vn_gotoxy(pos_x, pos_y+height);
            printf("%s%s", fg_color, bg_color);
            printf(":");
            scanf("%s", com);
            printf("%s", esc_reset);

            if(strcmp(com, "q")) /* IF 'com' NOT QUIT */
            {
                char *color_hex = (char*) malloc(6);

                vn_line(pos_x, pos_y+height, width, bg_color, "horizontal");
                vn_gotoxy(pos_x, pos_y+height);
                printf("%s%s", fg_color, bg_color);
                if(!strcmp(com, "fg")) { printf("fg: "); } /* FOREGROUND */
                if(!strcmp(com, "bg")) { printf("bg: "); } /* BACKGROUND */
                scanf("%s", color_hex);
                if(strcmp(color_hex, "q"))
                {
                    printf("%s", esc_reset);
                    vn_line(pos_x, pos_y+height, width, "", "horizontal");
                    printf("%s%s", fg_color, bg_color);

                    /* COLOR CHANGING SECTION */
                    if(!strcmp(com, "fg")) { fg_color = vn_hex_color(color_hex, 0); }
                    if(!strcmp(com, "bg")) { bg_color = vn_hex_color(color_hex, 1); }
                }
                free(color_hex);
            }

            free(com);
            printf("%s%s", fg_color, bg_color);
        }
        
        if(i+cursor_pos_x >= width+pos_x) { i-=1; }
        if(i+cursor_pos_x < pos_x) { i+=1; }
        if(j+cursor_pos_y >= height+pos_y) { j-=1; }
        if(j+cursor_pos_y < pos_y) { j+=1; }
    }
        
    printf("%s", esc_reset);
}

void vn_shell(int pos_x, int pos_y, char *fg_color, char *bg_color, char *text_style)
{
    char *shell_buffer = (char*) malloc(1024);

    vn_gotoxy(pos_x, pos_y);
    printf("%s%s%s", fg_color, bg_color, text_style);
    scanf("%[^\n]s", shell_buffer);

    system(shell_buffer);
    printf("%s", esc_reset);
}

/* MADE BY @hanilr */