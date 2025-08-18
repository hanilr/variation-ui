// STANDARD LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 'wait' FUNCTION FOR CROSS PLATFORM
#ifdef _WIN32
    #include <windows.h>
    #define wait(x) Sleep((x) * 1000)
#else
    #include <unistd.h>
    #define wait(x) sleep(x)
#endif

// VARIATION UI LIBRARY
#define VN_UI_IMPLEMENTATION
#define VN_WIDGET
#include "../vn_ui.h"

// CHECK SYSTEM STRUCTURE
typedef struct {
    int vn_check;
    int vn_true;
    int vn_false;
    int vn_none;
} VN_CHECK;

/* CHECK SYSTEM FUNCTION */
void sys_check(char check, VN_CHECK* vnc) {
    vnc->vn_check += 1;
    if (check == 'y' || check == 'Y') {
        vnc->vn_true += 1;
    } else if (check == 'n' || check == 'N') {
        vnc->vn_false += 1;
    } else {
        vnc->vn_none += 1;
    }
}

/* CHECK SYSTEM PROMPT */
void sys_prompt(char* check, VN_UI_TEXT vnt, VN_UI_WIDGET vnw, VN_CHECK* vnc) {
    vn_bg(' ', vnt, vnw);
    vn_notif("", "Can you see that? (Y/n): ", ' ', ' ', vnt, vnt, vnt, vnw);

    printf("%s%s", vnt.color_fg, vnt.color_bg);
    scanf(" %c", check);
    printf("%s", vn_text_reset);    
    
    sys_check(*check, vnc);
}

/* CHECK SYSTEM RESULT */
void sys_result(char check, VN_UI_TEXT vnt_true, VN_UI_TEXT vnt_false, VN_UI_TEXT vnt) {
    if (check == 'y' || check == 'Y') {
        vn_print("[OK]\n", vnt_true);
    } else if (check == 'n' || check == 'N') {
        vn_print("[NO]\n", vnt_false);
    } else {
        vn_print("[-]\n", vnt);
    }
}

int main() {
    // CHECK SYSTEM INITIAL
    VN_CHECK vnc = {0};
    int value = 0;
    char check_start;
    char check_line, check_bg, check_frame;
    char check_label, check_progress, check_notif;

    /* COLOR DECLARING */
    char* red_fg = vn_color("#e93737", 'f');
    char* green_fg = vn_color("#37e937", 'f');
    char* blue_fg = vn_color("#3737e9", 'f');
    char* white_fg = vn_color("#e9e9e9", 'f');

    char* black_bg = vn_color("#161616", 'b');
    char* red_bg = vn_color("#e93737", 'b');
    char* green_bg = vn_color("#37e937", 'b');
    char* blue_bg = vn_color("#3737e9", 'b');
    /* --------------- */

    /* TEXT ATTRIBUTES */
    VN_UI_TEXT vnt_red;
    strcpy(vnt_red.color_fg, red_fg);
    strcpy(vnt_red.color_bg, black_bg);
    strcpy(vnt_red.text_style, "");

    VN_UI_TEXT vnt_green;
    strcpy(vnt_green.color_fg, green_fg);
    strcpy(vnt_green.color_bg, black_bg);
    strcpy(vnt_green.text_style, "");

    VN_UI_TEXT vnt_blue;
    strcpy(vnt_blue.color_fg, blue_fg);
    strcpy(vnt_blue.color_bg, black_bg);
    strcpy(vnt_blue.text_style, "");

    VN_UI_TEXT vnt_white;
    strcpy(vnt_white.color_fg, white_fg);
    strcpy(vnt_white.color_bg, black_bg);
    strcpy(vnt_white.text_style, "");
    /* --------------- */

    /* WIDGET TEST ATTRIBUTES */
    VN_UI_TEXT vnt_bg;
    strcpy(vnt_bg.color_fg, white_fg);
    strcpy(vnt_bg.color_bg, red_bg);
    strcpy(vnt_bg.text_style, "");

    VN_UI_TEXT vnt_notif;
    strcpy(vnt_notif.color_fg, white_fg);
    strcpy(vnt_notif.color_bg, black_bg);
    strcpy(vnt_notif.text_style, "");
    /* ---------------------- */
                            
    /* SIZE ATTRIBUTES */
    VN_UI_WIDGET vnw_main;
    vnw_main.pos_x = 1;
    vnw_main.pos_y = 1;
    vnw_main.width = 60;
    vnw_main.height = 20;

    VN_UI_WIDGET vnw_vertical ={0};
    vnw_vertical.pos_x = 41;
    vnw_vertical.pos_y = 1;
    vnw_vertical.height = 17;

    VN_UI_WIDGET vnw_horizontal_one = {0};
    vnw_horizontal_one.pos_x = 1;
    vnw_horizontal_one.pos_y = 18;
    vnw_horizontal_one.width = 60;

    VN_UI_WIDGET vnw_horizontal_two = {0};
    vnw_horizontal_two.pos_x = 42;
    vnw_horizontal_two.pos_y = 8;
    vnw_horizontal_two.width = 18;

    VN_UI_WIDGET vnw_progress;
    vnw_progress.pos_x = 1;
    vnw_progress.pos_y = 19;
    vnw_progress.width = 58;
    vnw_progress.height = 1;

    VN_UI_WIDGET vnw_notif;
    vnw_notif.pos_x = 42;
    vnw_notif.pos_y = 2;
    vnw_notif.width = 18;
    vnw_notif.height = 6;
    /* --------------- */
                
    /* TEST SIZE ATTRIBUTES */
    VN_UI_WIDGET vnw_test;
    vnw_test.pos_x = 3;
    vnw_test.pos_y = 3;
    vnw_test.width = 37;
    vnw_test.height = 14;

    VN_UI_WIDGET vnw_progress_test;
    vnw_progress_test.pos_x = 3;
    vnw_progress_test.pos_y = 3;
    vnw_progress_test.width = 34;
    vnw_progress_test.height = 14;

    VN_UI_WIDGET vnw_notif_test;
    vnw_notif_test.pos_x = 10;
    vnw_notif_test.pos_y = 5;
    vnw_notif_test.width = 20;
    vnw_notif_test.height = 10;

    VN_UI_WIDGET vnw_last_notif;
    vnw_last_notif.pos_x = 12;
    vnw_last_notif.pos_y = 4;
    vnw_last_notif.width = 19;
    vnw_last_notif.height = 11;
    /* -------------------- */

    /* ---------------- */
    /* DEMO CODE SECTION*/
    /* ---------------- */
    vn_code("screen:clear");
    vn_bg(' ', vnt_white, vnw_main);

    vn_line('|', "vertical", vnt_blue, vnw_vertical);
    vn_line('=', "horizontal", vnt_blue, vnw_horizontal_one);
    vn_line('=', "horizontal", vnt_blue, vnw_horizontal_two);
    
    vn_frame('|', '=', vnt_blue, vnw_main);
    vn_notif("Start Demo?", "Do you want to start the demo? (Y/n): ", ' ', ' ', vnt_notif, vnt_red, vnt_white, vnw_notif);
    vn_progress(value, '|', '#', '.', vnt_green, vnw_progress);

    // Start Check
    vn_gotoxy(51, 6);
    printf("%s%s", white_fg, black_bg);
    scanf(" %c", &check_start);
    printf("%s", vn_text_reset);

    if (check_start == 'n') {
        return 0;
    } else if (check_start == 'y') {
        // Progress 1
        value += 4;
        vn_progress(value, '|', '#', '.', vnt_green, vnw_progress);

        // 1. Line
        vn_line('X', "horizontal", vnt_red, vnw_test);
        vn_line('Y', "vertical", vnt_blue, vnw_test);
        wait(1);

        // Reset 1
        sys_prompt(&check_line, vnt_white, vnw_notif, &vnc);
        vn_bg(' ', vnt_notif, vnw_test);

        // Result 1
        vn_gotoxy(43, 10);
        vn_print("1. Line: ", vnt_white);
        sys_result(check_line, vnt_green, vnt_red, vnt_white);

        // Progress 2
        value += 9;
        vn_progress(value, '|', '#', '.', vnt_green, vnw_progress);

        // 2. Background
        vn_bg(' ', vnt_bg, vnw_test);
        wait(1);

        // Reset 2
        sys_prompt(&check_bg, vnt_white, vnw_notif, &vnc);
        vn_bg(' ', vnt_notif, vnw_test);

        // Result 2
        vn_gotoxy(43, 11);
        vn_print("2. Bg: ", vnt_white);
        sys_result(check_bg, vnt_green, vnt_red, vnt_white);

        // Progress 3
        value += 9;
        vn_progress(value, '|', '#', '.', vnt_green, vnw_progress);

        // 3. Frame
        vn_frame('|', '-', vnt_green, vnw_test);
        wait(1);
        
        // Reset 3
        sys_prompt(&check_frame, vnt_white, vnw_notif, &vnc);
        vn_bg(' ', vnt_notif, vnw_test);

        // Result 3
        vn_gotoxy(43, 12);
        vn_print("3. Frame: ", vnt_white);
        sys_result(check_frame, vnt_green, vnt_red, vnt_white);

        // Progress 4
        value += 9;
        vn_progress(value, '|', '#', '.', vnt_green, vnw_progress);

        // 4. Label
        vn_label("This is the label's text.", vnt_blue, vnw_test);
        wait(1);
        
        // Reset 4
        sys_prompt(&check_label, vnt_white, vnw_notif, &vnc);
        vn_bg(' ', vnt_notif, vnw_test);

        // Result 4
        vn_gotoxy(43, 13);
        vn_print("4. Label: ", vnt_white);
        sys_result(check_label, vnt_green, vnt_red, vnt_white);

        // Progress 5
        value += 9;
        vn_progress(value, '|', '#', '.', vnt_green, vnw_progress);

        // 5. Progress
        vn_progress(20, 'O', 'o', '.', vnt_red, vnw_progress_test);
        wait(1);
        
        // Reset 5
        sys_prompt(&check_progress, vnt_white, vnw_notif, &vnc);
        vn_bg(' ', vnt_notif, vnw_test);

        // Result 5
        vn_gotoxy(43, 14);
        vn_print("5. Progress: ", vnt_white);
        sys_result(check_progress, vnt_green, vnt_red, vnt_white);

        // Progress 6
        value += 9;
        vn_progress(value, '|', '#', '.', vnt_green, vnw_progress);

        // 6. Notification
        vn_bg(' ', vnt_bg, vnw_test);
        vn_notif("Notification", "This is the notification's text", \
        ' ', ' ', vnt_green, vnt_blue, vnt_white, vnw_notif_test);
        wait(1);
        
        // Reset 6
        sys_prompt(&check_notif, vnt_white, vnw_notif, &vnc);
        vn_bg(' ', vnt_notif, vnw_test);

        // Result 6
        vn_gotoxy(43, 15);
        vn_print("6. Notif: ", vnt_white);
        sys_result(check_notif, vnt_green, vnt_red, vnt_white);

        // Progress 7
        value += 9;
        vn_progress(value, '|', '#', '.', vnt_green, vnw_progress);

        vn_gotoxy(43, 16);
        vn_print("[Demo Finished]", vnt_blue);

        // RESULTS
        vn_bg(' ', vnt_notif, vnw_notif);
        vn_notif("[FINISHED]", "", ' ', ' ', vnt_notif, vnt_notif, vnt_notif, vnw_notif);
        vn_frame('|', '=', vnt_white, vnw_last_notif);

        vn_gotoxy(vnw_test.pos_x + (vnw_test.width - 11) / 2, vnw_test.pos_y + (vnw_test.height - 7) /2);
        vn_print("Worked:", vnt_white);
        printf("%s%s [%d]%s", vnt_green.color_fg, \
            vnt_green.color_bg, vnc.vn_true, vn_text_reset);

        vn_gotoxy(20, 7);
        vn_print("+", vnt_white);

        vn_gotoxy(vnw_test.pos_x + (vnw_test.width - 15) / 2, vnw_test.pos_y + ((vnw_test.height - 3) / 2));
        vn_print("Not Worked:", vnt_white);
        printf("%s%s [%d]%s", vnt_red.color_fg, \
            vnt_red.color_bg, vnc.vn_false, vn_text_reset);

        vn_gotoxy(20, 9);
        vn_print("+", vnt_white);

        vn_gotoxy(vnw_test.pos_x + (vnw_test.width - 9) / 2, vnw_test.pos_y + ((vnw_test.height + 1) / 2));
        vn_print("None:", vnt_white);
        printf("%s%s [%d]%s", vnt_blue.color_fg, \
            vnt_blue.color_bg, vnc.vn_none, vn_text_reset);

        vn_gotoxy(20, 11);
        vn_print("=", vnt_white);
    
        vn_gotoxy(vnw_test.pos_x + (vnw_test.width - 10) / 2, vnw_test.pos_y + ((vnw_test.height + 5) / 2));
        vn_print("Total:", vnt_white);
        printf("%s%s [%d]%s", vnt_green.color_fg, \
            vnt_green.color_bg, vnc.vn_true + vnc.vn_false + vnc.vn_none, vn_text_reset);
    }

    vn_gotoxy(1, 21);
    /* ---------------- */

    /* FREE 'vn_color' */
    free(red_fg);
    free(green_fg);
    free(blue_fg);
    free(white_fg);

    free(black_bg);
    free(red_bg);
    free(green_bg);
    free(blue_bg);
    /* --------------- */

    return 0;
}