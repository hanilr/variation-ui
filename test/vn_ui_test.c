/* ----------------------------------------------------------- */
/* THIS FILE FOR ALL IN ONE TEST FILE FOR VARIATION UI LIBRARY */
/*               NOTE: USE MAKEFILE FOR COMPILE                */
/*           'make' OR 'make run' TO SHOW MAKE LIST            */
/* ----------------------------------------------------------- */

/* STANDARD LIBRARY */
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */
#include <stdlib.h> /* STANDARD LIBRARY */
#include <pthread.h> /* POSIX THREAD */

/* VARIATION UI LIBRARY */
#define VN_UI_IMPLEMENTATION /* UNLOCK LIBRARY */
#define VN_COLOR /* CUSTOM COLOR SECTION */
#define VN_UTIL /* UTILITIES */
#define VN_WIDGET /* SPECIAL WIDGETS */
#include "../vn_ui.h" /* VARIATION UI LIBRARY */

struct vn_ui_test_status_configuration
{
    char *test_name;
    int test_width;
    int test_height;
};

void *vn_ui_test_status_clock(t)
{
    int i = 0;

    struct vn_init vn_test_status;
    vn_test_status.pos_x = 1;
    vn_test_status.pos_y = 1;
    vn_test_status.width = 58;

    struct vnc_color white_fg;
    white_fg.is_fore = 0;
    white_fg.color = vn_hex_color("e9e9e9", white_fg.is_fore);

    struct vnc_color green_bg;
    green_bg.is_fore = 1;
    green_bg.color = vn_hex_color("37c837", green_bg.is_fore);

    while(30 > i)
    {
        vn_gotoxy(vn_test_status.pos_x+vn_test_status.width/2-4, vn_test_status.pos_y);
        printf("%s%s%s", white_fg.color, green_bg.color, text_bold);
        printf("%s", vnu_get_time());
        printf("%s", esc_reset);
        vnu_sleep("second", 1);
        i+=1;
    }
}

void *vn_ui_test_status(struct vn_ui_test_status_configuration vutsc)
{
    struct vn_init vn_test_status;
    vn_test_status.cursor_visibility = 0;
    vn_test_status.pos_x = 1;
    vn_test_status.pos_y = 1;
    vn_test_status.width = 58;
    vn_test_status.height = 22;

    struct vnc_color black_fg;
    black_fg.is_fore = 0;
    black_fg.color = vn_hex_color("161616", black_fg.is_fore);

    struct vnc_color white_fg;
    white_fg.is_fore = 0;
    white_fg.color = vn_hex_color("e9e9e9", white_fg.is_fore);

    struct vnc_color green_bg;
    green_bg.is_fore = 1;
    green_bg.color = vn_hex_color("37c837", green_bg.is_fore);

    struct vnc_color blue_bg;
    blue_bg.is_fore = 1;
    blue_bg.color = vn_hex_color("3838c7", blue_bg.is_fore);

    vn_cursor_visibility(vn_test_status.cursor_visibility);
    vn_line(vn_test_status.pos_x, vn_test_status.pos_y, vn_test_status.width, green_bg.color, "horizontal");
    vn_frame(vn_test_status.pos_x, vn_test_status.pos_y+1, vn_test_status.width, vn_test_status.height-2, "", blue_bg.color, ' ', ' ');

    /* FIRST LINE */
    vn_gotoxy(vn_test_status.pos_x+1, vn_test_status.pos_y);
    vn_print("vn_ui_test", white_fg.color, green_bg.color, text_bold);

    vn_gotoxy(vn_test_status.width-strlen(getenv("USER")), vn_test_status.pos_y);
    vn_print(getenv("USER"), white_fg.color, green_bg.color, text_bold);

    /* SECOND LINE */
    vn_gotoxy(vn_test_status.pos_x+1, vn_test_status.pos_y+1);
    vn_print("[Testing..]", black_fg.color, blue_bg.color, text_italic);
    
    int width_digit = 1, height_digit = 1, temp_width = vn_test_status.width, temp_height = vn_test_status.height;
    while(1)
    {
        if(temp_width%10 == 0)
        {
            width_digit+=1;
            temp_width/=10;
        }
        if(temp_height%10 == 0)
        {
            height_digit+=1;
            temp_height/=10;
        }
        if(temp_width%10 != 0 && temp_height%10 != 0) { break; }
    }
    
    vn_gotoxy(vn_test_status.width-(19+width_digit+height_digit), vn_test_status.pos_y+1);
    printf("%s%s", black_fg.color, blue_bg.color);
    printf("Width: %d, Height: %d", vn_test_status.width, vn_test_status.height);
    printf("%s", esc_reset);
    vn_timer(vn_test_status.pos_x+vn_test_status.width/2-3, vn_test_status.pos_y+1, black_fg.color, blue_bg.color, "", 59, 1);
}

void *vn_ui_test_frame()
{
    struct vnc_color white_fg;
    white_fg.is_fore = 0;
    white_fg.color = vn_hex_color("e9e9e9", white_fg.is_fore);

    struct vnc_color blue_fg;
    blue_fg.is_fore = 0;
    blue_fg.color = vn_hex_color("3838c7", blue_fg.is_fore);

    struct vnc_color black_bg;
    black_bg.is_fore = 1;
    black_bg.color = vn_hex_color("161616", black_bg.is_fore);

    struct vnc_color blue_bg;
    blue_bg.is_fore = 1;
    blue_bg.color = vn_hex_color("3838c7", blue_bg.is_fore);

    vn_gotoxy(3, 4);
    vn_print("vn_line:\t", white_fg.color, black_bg.color, text_bold);
    vn_print("[.]", blue_fg.color, black_bg.color, text_bold);

    vn_gotoxy(3, 5);
    vn_print("vn_bg:\t", white_fg.color, black_bg.color, text_bold);
    vn_print("[.]", blue_fg.color, black_bg.color, text_bold);

    vn_gotoxy(3, 6);
    vn_print("vn_frame:\t", white_fg.color, black_bg.color, text_bold);
    vn_print("[.]", blue_fg.color, black_bg.color, text_bold);

    vn_gotoxy(3, 7);
    vn_print("vn_label:\t", white_fg.color, black_bg.color, text_bold);
    vn_print("[.]", blue_fg.color, black_bg.color, text_bold);

    vn_gotoxy(3, 8);
    vn_print("vn_progress:\t", white_fg.color, black_bg.color, text_bold);
    vn_print("[.]", blue_fg.color, black_bg.color, text_bold);

    vn_gotoxy(3, 9);
    vn_print("vn_notif:\t", white_fg.color, black_bg.color, text_bold);
    vn_print("[.]", blue_fg.color, black_bg.color, text_bold);

    vn_gotoxy(3, 10);
    vn_print("vn_timer:\t", white_fg.color, black_bg.color, text_bold);
    vn_print("[.]", blue_fg.color, black_bg.color, text_bold);

    vn_line(21, 2, 20, blue_bg.color, "vertical");
    vn_line(0, 12, 21, blue_bg.color, "horizontal");
    vn_label(3, 14, 17, 6, white_fg.color, black_bg.color, text_italic, "At the end of each test, you will be asked a (y/n) question. Result will show after the tests.");
}

void vnu_ui_test_command_bar()
{
    struct vnc_color white_fg;
    white_fg.is_fore = 0;
    white_fg.color = vn_hex_color("e9e9e9", white_fg.is_fore);

    struct vnc_color black_bg;
    black_bg.is_fore = 1;
    black_bg.color = vn_hex_color("161616", black_bg.is_fore);

    vn_line(0, 23, 58, black_bg.color, "horizontal");
    vn_gotoxy(1, 22);
    vn_print(":", white_fg.color, black_bg.color, "");
}

void vnu_ui_test_checker(char key, int pos_y)
{
    struct vnc_color white_fg;
    white_fg.is_fore = 0;
    white_fg.color = vn_hex_color("e9e9e9", white_fg.is_fore);

    struct vnc_color red_fg;
    red_fg.is_fore = 0;
    red_fg.color = vn_hex_color("c73838", red_fg.is_fore);

    struct vnc_color green_fg;
    green_fg.is_fore = 0;
    green_fg.color = vn_hex_color("37c837", green_fg.is_fore);

    struct vnc_color black_bg;
    black_bg.is_fore = 1;
    black_bg.color = vn_hex_color("161616", black_bg.is_fore);

    if(key == 'y')
    {
        vn_gotoxy(18, pos_y);
        vn_print("+", green_fg.color, black_bg.color, "");
    }
    else if(key == 'n')
    {
        vn_gotoxy(18, pos_y);
        vn_print("-", red_fg.color, black_bg.color, "");
    }
    else
    {
        vn_gotoxy(18, pos_y);
        vn_print("?", white_fg.color, black_bg.color, "");
    }
}

void *vn_ui_test()
{
    int test_width = 32, test_height = 16, test_posx = 24, test_posy = 4;

    struct vnc_color black_fg;
    black_fg.is_fore = 0;
    black_fg.color = vn_hex_color("161616", black_fg.is_fore);

    struct vnc_color white_fg;
    white_fg.is_fore = 0;
    white_fg.color = vn_hex_color("e9e9e9", white_fg.is_fore);

    struct vnc_color red_fg;
    red_fg.is_fore = 0;
    red_fg.color = vn_hex_color("c73838", red_fg.is_fore);

    struct vnc_color blue_fg;
    blue_fg.is_fore = 0;
    blue_fg.color = vn_hex_color("3838c7", blue_fg.is_fore);

    struct vnc_color black_bg;
    black_bg.is_fore = 1;
    black_bg.color = vn_hex_color("161616", black_bg.is_fore);

    struct vnc_color white_bg;
    white_bg.is_fore = 1;
    white_bg.color = vn_hex_color("e9e9e9", white_bg.is_fore);

    struct vnc_color red_bg;
    red_bg.is_fore = 1;
    red_bg.color = vn_hex_color("c73838", red_bg.is_fore);

    struct vnc_color green_bg;
    green_bg.is_fore = 1;
    green_bg.color = vn_hex_color("37c837", green_bg.is_fore);

    struct vnc_color blue_bg;
    blue_bg.is_fore = 1;
    blue_bg.color = vn_hex_color("3838c7", blue_bg.is_fore);

    /* LINE */
    vnu_ui_test_command_bar();
    vn_line(test_posx, test_posy, test_width, white_bg.color, "horizontal");
    vn_line(test_posx+test_width/2, test_posy+2, 14, white_bg.color, "vertical");
    vn_gotoxy(2, 22);

    char vn_test_line = vnu_get_char_instantly();
    vnu_ui_test_checker(vn_test_line, 4);
    vn_bg(test_posx-1, test_posy-1, 34, 18, black_bg.color);

    /* BG */
    vnu_ui_test_command_bar();
    vn_bg(test_posx, test_posy, test_width, test_height, white_bg.color);
    vn_gotoxy(2, 22);

    char vn_test_bg = vnu_get_char_instantly();
    vnu_ui_test_checker(vn_test_bg, 5);
    vn_bg(test_posx-1, test_posy-1, 34, 18, black_bg.color);

    /* FRAME */
    vnu_ui_test_command_bar();
    vn_frame(test_posx, test_posy, test_width, test_height, black_fg.color, white_bg.color, '|', '-');
    vn_gotoxy(2, 22);

    char vn_test_frame = vnu_get_char_instantly();
    vnu_ui_test_checker(vn_test_frame, 6);
    vn_bg(test_posx-1, test_posy-1, 34, 18, black_bg.color);

    /* LABEL */
    vnu_ui_test_command_bar();
    vn_label(test_posx, test_posy, test_width, test_height, blue_fg.color, white_bg.color, "", "This is a label example. So if you can see this probably this widget is working perfectly.");
    vn_gotoxy(2, 22);

    char vn_test_label = vnu_get_char_instantly();
    vnu_ui_test_checker(vn_test_label, 7);
    vn_bg(test_posx-1, test_posy-1, 34, 18, black_bg.color);

    /* PROGRESS */
    vnu_ui_test_command_bar();
    int i = 0;
    while(6 > i)
    {
        vn_progress(test_posx, test_posy, 5, 3, red_fg.color, white_fg.color, i);
        vnu_sleep("second", 1);
        i+=1;
    }
    vn_gotoxy(2, 22);

    char vn_test_progress = vnu_get_char_instantly();
    vnu_ui_test_checker(vn_test_progress, 8);
    vn_bg(test_posx-1, test_posy-1, 34, 18, black_bg.color);

    /* NOTIFICATION */
    vnu_ui_test_command_bar();
    vn_notif(test_posx, test_posy, test_width, test_height, '|', '-', white_fg.color, green_bg.color, white_fg.color, black_bg.color, red_fg.color, "'vn_notif' Test!", "", "this is a 'vn_notif' widget so you can use this widget to make pop-up/warning screens!");
    vn_gotoxy(2, 22);

    char vn_test_notif = vnu_get_char_instantly();
    vnu_ui_test_checker(vn_test_notif, 9);
    vn_bg(test_posx-1, test_posy-1, 34, 18, black_bg.color);

    /* TIMER */
    vnu_ui_test_command_bar();
    vn_timer(test_posx, test_posy, white_fg.color, red_bg.color, text_italic, 5, 0);
    vn_gotoxy(2, 22);

    char vn_test_timer = vnu_get_char_instantly();
    vnu_ui_test_checker(vn_test_timer, 10);
    vn_bg(test_posx-1, test_posy-1, 34, 18, black_bg.color);

    vn_gotoxy(2, 2);
    vn_print("[Tested]   ", black_fg.color, blue_bg.color, text_italic);
    vn_label(test_posx, test_posy, test_width, test_height, white_fg.color, black_bg.color, "", "Test finished. You can see the results at the left top side of screen. At this time the timer will continue and when finished test program will close. Or you can type 'q' and terminate the program. (If this doesn't work press <Control> and <C> at the same time!)");
    
    vn_gotoxy(2, 22);
    char key = vnu_get_char_instantly();
    if(key == 'q')
    {
        vn_cursor_visibility(0);
        vn_gotoxy(2, 22);
        exit(0);
    }
}

/* USER TEST GUIDE */
/*  */

int main(int argc, char *argv[])
{
    struct vn_init vn_test;
    vn_test.cursor_visibility = 1;
    vn_test.pos_x = 0;
    vn_test.pos_y = 0;
    vn_test.width = 58;
    vn_test.height = 22;

    struct vn_ui_test_status_configuration vutsc;
    vutsc.test_width = 58;
    vutsc.test_height = 22;

    vn_cursor_visibility(vn_test.cursor_visibility);
    vn_clear();

    /* THREADS */
    pthread_t status, clock, frame, test;
    pthread_create(&status, NULL, (void*) vn_ui_test_status, &vutsc);
    pthread_create(&clock, NULL, (void*) vn_ui_test_status_clock, NULL);
    pthread_create(&frame, NULL, (void*) vn_ui_test_frame, NULL);
    pthread_create(&test, NULL, (void*) vn_ui_test, NULL); 
    pthread_join(status, NULL);
    pthread_join(clock, NULL);
    pthread_join(frame, NULL);
    pthread_join(test, NULL);
    
    vn_end(vn_test);
    return 0;
}

/* MADE BY @hanilr */