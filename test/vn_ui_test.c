/* ----------------------------------------------------------- */
/* THIS FILE FOR ALL IN ONE TEST FILE FOR VARIATION UI LIBRARY */
/*               NOTE: USE MAKEFILE FOR COMPILE                */
/*           'make' OR 'make run' TO SHOW MAKE LIST            */
/* ----------------------------------------------------------- */

/* STANDARD LIBRARY */
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */
#include <stdlib.h> /* STANDARD LIBRARY */
#include <string.h> /* STRING LIBRARY */
#include <pthread.h> /* POSIX THREAD */

/* VARIATION UI LIBRARY */
#define VN_UI_IMPLEMENTATION /* UNLOCK LIBRARY */
#define VN_COLOR /* CUSTOM COLOR SECTION */
#define VN_UTIL /* UTILITIES */
#define VN_WIDGET /* SPECIAL WIDGETS */
#include "../vn_ui.h" /* VARIATION UI LIBRARY */

/* CONFIGURATION FOR 'vn_ui_test_status' FUNCTION */
struct vn_ui_test_status_configuration
{
    int test_width;
    int test_height;
    int test_time;
};

/* CONFIGURATION FOR WIDGET INFORMATION */
struct vne_ui_test_help_widget_creator_configuration
{
    char *widget_name;
    char *widget_description;
};

/* CONFIGURATION FOR TEST WIDGET CREATOR */
struct vne_ui_test_widget_creator_configuration { char *widget_name; };

/* WORKING CLOCK FOR TOP MIDDLE SIDE */
void *vn_ui_test_status_clock(struct vn_ui_test_status_configuration *vutsc)
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

    while(vutsc->test_time > i)
    {
        vn_gotoxy(vn_test_status.pos_x+vn_test_status.width/2-4, vn_test_status.pos_y);
        printf("%s%s%s", white_fg.color, green_bg.color, text_bold);
        printf("%s", vnu_get_time());
        printf("%s", esc_reset);
        vnu_sleep("second", 1);
        i+=1;
    }
}

/* STATUS BAR */
void *vn_ui_test_status(struct vn_ui_test_status_configuration *vutsc)
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
    vn_timer(vn_test_status.pos_x+vn_test_status.width/2-3, vn_test_status.pos_y+1, black_fg.color, blue_bg.color, "", vutsc->test_time, 1);
}

void *vn_ui_test_frame(void)
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

    /* LINE */
    vn_gotoxy(3, 4);
    vn_print("vn_line:\t", white_fg.color, black_bg.color, text_bold);
    vn_print("[.]", blue_fg.color, black_bg.color, text_bold);

    /* BG */
    vn_gotoxy(3, 5);
    vn_print("vn_bg:\t", white_fg.color, black_bg.color, text_bold);
    vn_print("[.]", blue_fg.color, black_bg.color, text_bold);

    /* FRAME */
    vn_gotoxy(3, 6);
    vn_print("vn_frame:\t", white_fg.color, black_bg.color, text_bold);
    vn_print("[.]", blue_fg.color, black_bg.color, text_bold);

    /* LABEL */
    vn_gotoxy(3, 7);
    vn_print("vn_label:\t", white_fg.color, black_bg.color, text_bold);
    vn_print("[.]", blue_fg.color, black_bg.color, text_bold);

    /* PROGRESS */
    vn_gotoxy(3, 8);
    vn_print("vn_progress:\t", white_fg.color, black_bg.color, text_bold);
    vn_print("[.]", blue_fg.color, black_bg.color, text_bold);

    /* NOTIFICATION */
    vn_gotoxy(3, 9);
    vn_print("vn_notif:\t", white_fg.color, black_bg.color, text_bold);
    vn_print("[.]", blue_fg.color, black_bg.color, text_bold);

    /* TIMER */
    vn_gotoxy(3, 10);
    vn_print("vn_timer:\t", white_fg.color, black_bg.color, text_bold);
    vn_print("[.]", blue_fg.color, black_bg.color, text_bold);

    /* END */
    vn_line(21, 2, 20, blue_bg.color, "vertical");
    vn_line(0, 12, 21, blue_bg.color, "horizontal");
    vn_label(3, 14, 17, 6, white_fg.color, black_bg.color, text_italic, "At the end of each test, you will be asked a (y/n) question. Result will show after the tests.");
}

void vnu_ui_test_command_bar(void)
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

void vnu_change_test_name(char *test_name)
{
    struct vnc_color black_fg;
    black_fg.is_fore = 0;
    black_fg.color = vn_hex_color("161616", black_fg.is_fore);

    struct vnc_color blue_bg;
    blue_bg.is_fore = 1;
    blue_bg.color = vn_hex_color("3838c7", blue_bg.is_fore);

    vn_gotoxy(2, 2);
    vn_print(test_name, black_fg.color, blue_bg.color, text_italic);
}

void *vn_ui_test(void)
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
    vnu_change_test_name("vn_line");
    vn_gotoxy(9, 2);
    vn_line(9, 2, 4, blue_bg.color, "horizontal");

    vnu_ui_test_command_bar();
    vn_line(test_posx, test_posy, test_width, white_bg.color, "horizontal");
    vn_line(test_posx+test_width/2, test_posy+2, 14, white_bg.color, "vertical");
    vn_gotoxy(2, 22);

    char vn_test_line = vnu_get_char_instantly();
    vnu_ui_test_checker(vn_test_line, 4);
    vn_bg(test_posx-1, test_posy-1, 34, 18, black_bg.color);

    /* BG */
    vnu_change_test_name("vn_bg");
    vn_gotoxy(7, 2);
    vn_line(7, 2, 6, blue_bg.color, "horizontal");

    vnu_ui_test_command_bar();
    vn_bg(test_posx, test_posy, test_width, test_height, white_bg.color);
    vn_gotoxy(2, 22);

    char vn_test_bg = vnu_get_char_instantly();
    vnu_ui_test_checker(vn_test_bg, 5);
    vn_bg(test_posx-1, test_posy-1, 34, 18, black_bg.color);

    /* FRAME */
    vnu_change_test_name("vn_frame");
    vn_gotoxy(10, 2);
    vn_line(10, 2, 3, blue_bg.color, "horizontal");

    vnu_ui_test_command_bar();
    vn_frame(test_posx, test_posy, test_width, test_height, black_fg.color, white_bg.color, '|', '-');
    vn_gotoxy(2, 22);

    char vn_test_frame = vnu_get_char_instantly();
    vnu_ui_test_checker(vn_test_frame, 6);
    vn_bg(test_posx-1, test_posy-1, 34, 18, black_bg.color);

    /* LABEL */
    vnu_change_test_name("vn_label");
    vn_gotoxy(10, 2);
    vn_line(10, 2, 3, blue_bg.color, "horizontal");

    vnu_ui_test_command_bar();
    vn_label(test_posx, test_posy, test_width, test_height, blue_fg.color, white_bg.color, "", "This is a label example. So if you can see this probably this widget is working perfectly.");
    vn_gotoxy(2, 22);

    char vn_test_label = vnu_get_char_instantly();
    vnu_ui_test_checker(vn_test_label, 7);
    vn_bg(test_posx-1, test_posy-1, 34, 18, black_bg.color);

    /* PROGRESS */
    vnu_change_test_name("vn_progress");
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
    vnu_change_test_name("vn_notif");
    vn_gotoxy(10, 2);
    vn_line(10, 2, 3, blue_bg.color, "horizontal");

    vnu_ui_test_command_bar();
    vn_notif(test_posx, test_posy, test_width, test_height, '|', '-', white_fg.color, green_bg.color, white_fg.color, black_bg.color, red_fg.color, "'vn_notif' Test!", "", "this is a 'vn_notif' widget so you can use this widget to make pop-up/warning screens!");
    vn_gotoxy(2, 22);

    char vn_test_notif = vnu_get_char_instantly();
    vnu_ui_test_checker(vn_test_notif, 9);
    vn_bg(test_posx-1, test_posy-1, 34, 18, black_bg.color);

    /* TIMER */
    vnu_change_test_name("vn_timer");
    vn_gotoxy(10, 2);
    vn_line(10, 2, 3, blue_bg.color, "horizontal");

    vnu_ui_test_command_bar();
    vn_timer(test_posx, test_posy, white_fg.color, red_bg.color, text_italic, 5, 0);
    vn_gotoxy(2, 22);

    char vn_test_timer = vnu_get_char_instantly();
    vnu_ui_test_checker(vn_test_timer, 10);
    vn_bg(test_posx-1, test_posy-1, 34, 18, black_bg.color);

    /* END */
    vnu_change_test_name("[Tested]   ");
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

void *vne_ui_test_label(void)
{
    struct vnc_color black_fg;
    black_fg.is_fore = 0;
    black_fg.color = vn_hex_color("161616", black_fg.is_fore);

    struct vnc_color white_fg;
    white_fg.is_fore = 0;
    white_fg.color = vn_hex_color("e9e9e9", white_fg.is_fore);

    struct vnc_color black_bg;
    black_bg.is_fore = 1;
    black_bg.color = vn_hex_color("161616", black_bg.is_fore);

    struct vnc_color blue_bg;
    blue_bg.is_fore = 1;
    blue_bg.color = vn_hex_color("3838c7", blue_bg.is_fore);

    vnu_change_test_name("[Error]    ");
    vn_label(3, 4, 53, 17, white_fg.color, black_bg.color, text_italic, "You typed wrong parameter count. If you don't know what to do, then please type './_test -h' or './_test --help'. If you do know what to do, then check your action.");
}

void *vne_ui_test_help(void)
{
    struct vnc_color black_fg;
    black_fg.is_fore = 0;
    black_fg.color = vn_hex_color("161616", black_fg.is_fore);

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

    struct vnc_color blue_bg;
    blue_bg.is_fore = 1;
    blue_bg.color = vn_hex_color("3838c7", blue_bg.is_fore);

    vnu_change_test_name("[Help]     ");

    /* RULE ONE */
    vn_gotoxy(4, 4);
    vn_print("1. ", green_fg.color, black_bg.color, text_bold);
    vn_print("Show help: ", white_fg.color, black_bg.color, "");
    vn_print("'./_test -h' or './_test --help'", red_fg.color, black_bg.color, "");

    /* RULE TWO */
    vn_gotoxy(4, 6);
    vn_print("2. ", green_fg.color, black_bg.color, text_bold);
    vn_print("Show widget list: ", white_fg.color, black_bg.color, "");
    vn_gotoxy(5, 7);
    vn_print("'./_test -h widget' or './_test --help widget'", red_fg.color, black_bg.color, "");

    /* RULE THREE */
    vn_gotoxy(4, 9);
    vn_print("3. ", green_fg.color, black_bg.color, text_bold);
    vn_print("Show each widget help section: ", white_fg.color, black_bg.color, "");
    vn_gotoxy(5, 10);
    vn_print("'./_test -h <Widget>' or './_test --help <Widget>'", red_fg.color, black_bg.color, "");

    /* RULE FOUR */
    vn_gotoxy(4, 12);
    vn_print("4. ", green_fg.color, black_bg.color, text_bold);
    vn_print("If you want to do a full test then type: ", white_fg.color, black_bg.color, "");
    vn_gotoxy(5, 13);
    vn_print("'./_test' or 'make test'", red_fg.color, black_bg.color, "");

    /* RULE FIVE */
    vn_gotoxy(4, 15);
    vn_print("5. ", green_fg.color, black_bg.color, text_bold);
    vn_print("If you want to do each test separately then type: ", white_fg.color, black_bg.color, "");
    vn_gotoxy(5, 16);
    vn_print("'./_test -t <Widget>' or './test --test <Widget>'", red_fg.color, black_bg.color, "");

    /* RULE SIX */
    vn_gotoxy(4, 18);
    vn_print("6. ", green_fg.color, black_bg.color, text_bold);
    vn_print("You found a bug or a broken function? Report to: ", white_fg.color, black_bg.color, "");
    vn_gotoxy(5, 19);
    vn_print("'https://github.com/hanilr/variation-ui/issues'", red_fg.color, black_bg.color, "");
}

void *vne_ui_test_help_widget(void)
{
    struct vnc_color black_fg;
    black_fg.is_fore = 0;
    black_fg.color = vn_hex_color("161616", black_fg.is_fore);

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

    struct vnc_color blue_bg;
    blue_bg.is_fore = 1;
    blue_bg.color = vn_hex_color("3838c7", blue_bg.is_fore);

    vnu_change_test_name("[Widget List]      ");

    /* LINE */
    vn_gotoxy(4, 4);
    vn_print("1. ", green_fg.color, black_bg.color, text_bold);
    vn_print("vn_line: ", red_fg.color, black_bg.color, "");
    vn_print("Draw a line.", white_fg.color, black_bg.color, "");

    /* BG */
    vn_gotoxy(4, 5);
    vn_print("2. ", green_fg.color, black_bg.color, text_bold);
    vn_print("vn_bg: ", red_fg.color, black_bg.color, "");
    vn_print("Set background color.", white_fg.color, black_bg.color, "");

    /* FRAME */
    vn_gotoxy(4, 6);
    vn_print("3. ", green_fg.color, black_bg.color, text_bold);
    vn_print("vn_frame: ", red_fg.color, black_bg.color, "");
    vn_print("Draw a frame.", white_fg.color, black_bg.color, "");

    /* LABEL */
    vn_gotoxy(4, 7);
    vn_print("4. ", green_fg.color, black_bg.color, text_bold);
    vn_print("vn_label: ", red_fg.color, black_bg.color, "");
    vn_print("Make a text in a field.", white_fg.color, black_bg.color, "");

    /* PROGRESS */
    vn_gotoxy(4, 8);
    vn_print("5. ", green_fg.color, black_bg.color, text_bold);
    vn_print("vn_progress: ", red_fg.color, black_bg.color, "");
    vn_print("Progress bar.", white_fg.color, black_bg.color, "");

    /* NOTIFICATION */
    vn_gotoxy(4, 9);
    vn_print("6. ", green_fg.color, black_bg.color, text_bold);
    vn_print("vn_notif: ", red_fg.color, black_bg.color, "");
    vn_print("Pop-up/warning screen.", white_fg.color, black_bg.color, "");

    /* TIMER */
    vn_gotoxy(4, 10);
    vn_print("7. ", green_fg.color, black_bg.color, text_bold);
    vn_print("vn_timer: ", red_fg.color, black_bg.color, "");
    vn_print("Set a timer.", white_fg.color, black_bg.color, "");

    /* NOTE */
    vn_gotoxy(4, 12);
    vn_print("NOTE: ", green_fg.color, black_bg.color, text_bold);
    vn_print("If you want to see information about each", white_fg.color, black_bg.color, "");
    vn_gotoxy(3, 13);
    vn_print("widget, then type: ", white_fg.color, black_bg.color, "");
    vn_gotoxy(4, 15);
    vn_print("'./_test -h <Widget>' or './_test --help <Widget>'", red_fg.color, black_bg.color, "");
}

void *vne_ui_test_help_widget_creator(struct vne_ui_test_help_widget_creator_configuration *vuthwcc)
{
    struct vnc_color white_fg;
    white_fg.is_fore = 0;
    white_fg.color = vn_hex_color("e9e9e9", white_fg.is_fore);

    struct vnc_color green_fg;
    green_fg.is_fore = 0;
    green_fg.color = vn_hex_color("37c837", green_fg.is_fore);

    struct vnc_color black_bg;
    black_bg.is_fore = 1;
    black_bg.color = vn_hex_color("161616", black_bg.is_fore);

    struct vnc_color blue_bg;
    blue_bg.is_fore = 1;
    blue_bg.color = vn_hex_color("3838c7", blue_bg.is_fore);

    vnu_change_test_name(vuthwcc->widget_name);
    vn_gotoxy(2+strlen(vuthwcc->widget_name), 2);
    vn_line(2+strlen(vuthwcc->widget_name), 2, 11-strlen(vuthwcc->widget_name), blue_bg.color, "horizontal");

    vn_gotoxy(25, 4);
    printf("%s%s[%s%s%s]%s", text_underline, green_fg.color, white_fg.color, vuthwcc->widget_name, green_fg.color, esc_reset);
    vn_label(3, 6, 54, 14, white_fg.color, black_bg.color, "", vuthwcc->widget_description);
}

void *vne_ui_test_widget_creator(struct vne_ui_test_widget_creator_configuration *vutwcc)
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

    /* INFORMATION BOX */
    vn_line(21, 2, 20, blue_bg.color, "vertical");
    vn_label(3, 4, 17, 16, white_fg.color, black_bg.color, text_italic, "This is a singular test. So if you want to do a complete test then type './_test' or 'make test'. If you want to see help page then type './_test -h' or './_test --help'");

    /* LINE */
    if(!strcmp(vutwcc->widget_name, "vn_line"))
    {
        vnu_change_test_name("vn_line");
        vn_gotoxy(9, 2);
        vn_line(9, 2, 4, blue_bg.color, "horizontal");

        vnu_ui_test_command_bar();
        vn_line(test_posx, test_posy, test_width, white_bg.color, "horizontal");
        vn_line(test_posx+test_width/2, test_posy+2, 14, white_bg.color, "vertical");
        vn_gotoxy(2, 22);
    }

    /* BG */
    else if(!strcmp(vutwcc->widget_name, "vn_bg"))
    {
        vnu_change_test_name("vn_bg");
        vn_gotoxy(7, 2);
        vn_line(7, 2, 6, blue_bg.color, "horizontal");

        vnu_ui_test_command_bar();
        vn_bg(test_posx, test_posy, test_width, test_height, white_bg.color);
        vn_gotoxy(2, 22);
    }

    /* FRAME */
    else if(!strcmp(vutwcc->widget_name, "vn_frame"))
    {
        vnu_change_test_name("vn_frame");
        vn_gotoxy(10, 2);
        vn_line(10, 2, 3, blue_bg.color, "horizontal");

        vnu_ui_test_command_bar();
        vn_frame(test_posx, test_posy, test_width, test_height, black_fg.color, white_bg.color, '|', '-');
        vn_gotoxy(2, 22);
    }

    /* LABEL */
    else if(!strcmp(vutwcc->widget_name, "vn_label"))
    {
        vnu_change_test_name("vn_label");
        vn_gotoxy(10, 2);
        vn_line(10, 2, 3, blue_bg.color, "horizontal");

        vnu_ui_test_command_bar();
        vn_label(test_posx, test_posy, test_width, test_height, blue_fg.color, white_bg.color, "", "This is a label example. So if you can see this probably this widget is working perfectly.");
        vn_gotoxy(2, 22);
    }

    /* PROGRESS */
    else if(!strcmp(vutwcc->widget_name, "vn_progress"))
    {
        vnu_change_test_name("vn_progress");
        vnu_ui_test_command_bar();
        int i = 0;
        while(6 > i)
        {
            vn_progress(test_posx, test_posy, 5, 3, red_fg.color, white_fg.color, i);
            vnu_sleep("second", 1);
            i+=1;
        }
        vn_gotoxy(2, 22);
    }

    /* NOTIFICATION */
    else if(!strcmp(vutwcc->widget_name, "vn_notif"))
    {
        vnu_change_test_name("vn_notif");
        vn_gotoxy(10, 2);
        vn_line(10, 2, 3, blue_bg.color, "horizontal");

        vnu_ui_test_command_bar();
        vn_notif(test_posx, test_posy, test_width, test_height, '|', '-', white_fg.color, green_bg.color, white_fg.color, black_bg.color, red_fg.color, "'vn_notif' Test!", "", "this is a 'vn_notif' widget so you can use this widget to make pop-up/warning screens!");
        vn_gotoxy(2, 22);
    }

    /* TIMER */
    else if(!strcmp(vutwcc->widget_name, "vn_timer"))
    {
        vnu_change_test_name("vn_timer");
        vn_gotoxy(10, 2);
        vn_line(10, 2, 3, blue_bg.color, "horizontal");

        vnu_ui_test_command_bar();
        vn_timer(test_posx, test_posy, white_fg.color, red_bg.color, text_italic, 5, 0);
        vn_gotoxy(2, 22);
    }
}

/* ------------------ VARIATION UI TEST USER GUIDE ------------------ */
/* 1. './_test' OR 'make test' TO DO A COMPLETE TEST                  */
/* 2. './_test -t <Widget>' or './_test -t <Widget>' TO SINGULAR TEST */
/* 3. './_test -h' OR './_test --help' TO SEE HELP PAGE               */
/* ------------------------------------------------------------------ */
                                                                
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
    vutsc.test_time = 59;

    /* INITIAL */
    vn_cursor_visibility(vn_test.cursor_visibility);
    vn_clear();

    /* THREAD */
    if(argc == 1)
    {
        pthread_t status, clock, frame, test;
        pthread_create(&status, NULL, (void*) vn_ui_test_status, &vutsc);
        pthread_create(&clock, NULL, (void*) vn_ui_test_status_clock, &vutsc);
        pthread_create(&frame, NULL, (void*) vn_ui_test_frame, NULL);
        pthread_create(&test, NULL, (void*) vn_ui_test, NULL); 
        pthread_join(status, NULL);
        pthread_join(clock, NULL);
        pthread_join(frame, NULL);
        pthread_join(test, NULL);
    }

    /* USER HELP */
    else if(argc == 2 && !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
    {
        vutsc.test_time = 1;

        pthread_t status, clock, vne_help;
        pthread_create(&status, NULL, (void*) vn_ui_test_status, &vutsc);
        pthread_create(&clock, NULL, (void*) vn_ui_test_status_clock, &vutsc);
        pthread_create(&vne_help, NULL, (void*) vne_ui_test_help, NULL);
        pthread_join(status, NULL);
        pthread_join(clock, NULL);
        pthread_join(vne_help, NULL);
    }

    /* USER WISH */
    else if(argc == 3)
    {
        vutsc.test_time = 1;
        
        /* HELP SECTION */
        if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
        {
            /* WIDGET LIST */
            if(!strcmp(argv[2], "widget"))
            {
                pthread_t status, clock, vne_widget;
                pthread_create(&status, NULL, (void*) vn_ui_test_status, &vutsc);
                pthread_create(&clock, NULL, (void*) vn_ui_test_status_clock, &vutsc);
                pthread_create(&vne_widget, NULL, (void*) vne_ui_test_help_widget, NULL);
                pthread_join(status, NULL);
                pthread_join(clock, NULL);
                pthread_join(vne_widget, NULL);
            }

            /* MORE INFORMATION */
            else
            {
                struct vne_ui_test_help_widget_creator_configuration vuthwcc;
                
                pthread_t status, clock;
                pthread_create(&status, NULL, (void*) vn_ui_test_status, &vutsc);
                pthread_create(&clock, NULL, (void*) vn_ui_test_status_clock, &vutsc);
                pthread_join(status, NULL);
                pthread_join(clock, NULL);

                /* LINE */
                if(!strcmp(argv[2], "vn_line"))
                {
                    vuthwcc.widget_name = "vn_line";
                    vuthwcc.widget_description = "This widget for a straight line. You must use background color type to use. You can draw a line as horizontal or vertical.";

                    pthread_t vn_help_line;
                    pthread_create(&vn_help_line, NULL, (void*) vne_ui_test_help_widget_creator, &vuthwcc);
                    pthread_join(vn_help_line, NULL);
                }

                /* BG */
                else if(!strcmp(argv[2], "vn_bg"))
                {
                    vuthwcc.widget_name = "vn_bg";
                    vuthwcc.widget_description = "This widget for a colorful square. You must use background color type to use. You can use vn_frame after this widget.";

                    pthread_t vn_help_line;
                    pthread_create(&vn_help_line, NULL, (void*) vne_ui_test_help_widget_creator, &vuthwcc);
                    pthread_join(vn_help_line, NULL);
                }

                /* FRAME */
                else if(!strcmp(argv[2], "vn_frame"))
                {
                    vuthwcc.widget_name = "vn_frame";
                    vuthwcc.widget_description = "This widget for a colorful square with no filled inside. You must use background color type and optionally you can use horizontal and vertical symbols and special foreground and background color type to use.";

                    pthread_t vn_help_line;
                    pthread_create(&vn_help_line, NULL, (void*) vne_ui_test_help_widget_creator, &vuthwcc);
                    pthread_join(vn_help_line, NULL);
                }

                /* LABEL */
                else if(!strcmp(argv[2], "vn_label"))
                {
                    vuthwcc.widget_name = "vn_label";
                    vuthwcc.widget_description = "This widget for text in a field. You must use foreground and background color type to use. You don't have to make a setting to per paragraph. Also you can use text style.";

                    pthread_t vn_help_line;
                    pthread_create(&vn_help_line, NULL, (void*) vne_ui_test_help_widget_creator, &vuthwcc);
                    pthread_join(vn_help_line, NULL);
                }

                /* PROGRESS */
                else if(!strcmp(argv[2], "vn_progress"))
                {
                    vuthwcc.widget_name = "vn_progress";
                    vuthwcc.widget_description = "This widget for loading screen. You must use foreground and background color type to use. Also you must use in a loop. If you want to use with other widgets then you need to use multiprocessing or multithreading.";

                    pthread_t vn_help_line;
                    pthread_create(&vn_help_line, NULL, (void*) vne_ui_test_help_widget_creator, &vuthwcc);
                    pthread_join(vn_help_line, NULL);
                }

                /* NOTIFICATION */
                else if(!strcmp(argv[2], "vn_notif"))
                {
                    vuthwcc.widget_name = "vn_notif";
                    vuthwcc.widget_description = "This widget for pop-up or warning screen. You must use foreground and background color type to use. Also for title you must use foreground and background color type too. If you want symbols like vn_frame you need to make settings like vn_frame.";

                    pthread_t vn_help_line;
                    pthread_create(&vn_help_line, NULL, (void*) vne_ui_test_help_widget_creator, &vuthwcc);
                    pthread_join(vn_help_line, NULL);
                }

                /* TIMER */
                else if(!strcmp(argv[2], "vn_timer"))
                {
                    vuthwcc.widget_name = "vn_timer";
                    vuthwcc.widget_description = "This widget for time counter. You must use foreground and background color type to use. Also you can make a setting to alarm (When timer finished to count then terminal will play a sound.)";

                    pthread_t vn_help_line;
                    pthread_create(&vn_help_line, NULL, (void*) vne_ui_test_help_widget_creator, &vuthwcc);
                    pthread_join(vn_help_line, NULL);
                }
            }
        }

        /* TEST SECTION */
        else if(!strcmp(argv[1], "-t") || !strcmp(argv[1], "--test"))
        {
            struct vne_ui_test_widget_creator_configuration vutwcc;

            pthread_t status, clock;
            pthread_create(&status, NULL, (void*) vn_ui_test_status, &vutsc);
            pthread_create(&clock, NULL, (void*) vn_ui_test_status_clock, &vutsc);
            pthread_join(status, NULL);
            pthread_join(clock, NULL);

            /* LINE */
            if(!strcmp(argv[2], "vn_line"))
            {
                vutwcc.widget_name = "vn_line";

                pthread_t vn_widget_line;
                pthread_create(&vn_widget_line, NULL, (void*) vne_ui_test_widget_creator, &vutwcc);
                pthread_join(vn_widget_line, NULL);
            }

            /* BG */
            else if(!strcmp(argv[2], "vn_bg"))
            {
                vutwcc.widget_name = "vn_bg";

                pthread_t vn_widget_bg;
                pthread_create(&vn_widget_bg, NULL, (void*) vne_ui_test_widget_creator, &vutwcc);
                pthread_join(vn_widget_bg, NULL);
            }

            /* FRAME */
            else if(!strcmp(argv[2], "vn_frame"))
            {
                vutwcc.widget_name = "vn_frame";

                pthread_t vn_widget_frame;
                pthread_create(&vn_widget_frame, NULL, (void*) vne_ui_test_widget_creator, &vutwcc);
                pthread_join(vn_widget_frame, NULL);
            }

            /* LABEL */
            else if(!strcmp(argv[2], "vn_label"))
            {
                vutwcc.widget_name = "vn_label";

                pthread_t vn_widget_label;
                pthread_create(&vn_widget_label, NULL, (void*) vne_ui_test_widget_creator, &vutwcc);
                pthread_join(vn_widget_label, NULL);
            }

            /* PROGRESS */
            else if(!strcmp(argv[2], "vn_progress"))
            {
                vutwcc.widget_name = "vn_progress";

                pthread_t vn_widget_progress;
                pthread_create(&vn_widget_progress, NULL, (void*) vne_ui_test_widget_creator, &vutwcc);
                pthread_join(vn_widget_progress, NULL);
            }

            /* NOTIFICATION */
            else if(!strcmp(argv[2], "vn_notif"))
            {
                vutwcc.widget_name = "vn_notif";

                pthread_t vn_widget_notif;
                pthread_create(&vn_widget_notif, NULL, (void*) vne_ui_test_widget_creator, &vutwcc);
                pthread_join(vn_widget_notif, NULL);
            }

            /* TIMER */
            else if(!strcmp(argv[2], "vn_timer"))
            {
                vutwcc.widget_name = "vn_timer";

                pthread_t vn_widget_timer;
                pthread_create(&vn_widget_timer, NULL, (void*) vne_ui_test_widget_creator, &vutwcc);
                pthread_join(vn_widget_timer, NULL);
            }
        }
    }

    /* WARNING */
    else
    {
        vutsc.test_time = 1;

        pthread_t status, clock, vne_label;
        pthread_create(&status, NULL, (void*) vn_ui_test_status, &vutsc);
        pthread_create(&clock, NULL, (void*) vn_ui_test_status_clock, &vutsc);
        pthread_create(&vne_label, NULL, (void*) vne_ui_test_label, NULL);
        pthread_join(status, NULL);
        pthread_join(clock, NULL);
        pthread_join(vne_label, NULL);
    }
    
    vn_end(vn_test);
    return 0;
}

/* MADE BY @hanilr */