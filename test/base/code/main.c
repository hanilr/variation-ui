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
#define VN_UI_BASE_IMPLEMENTATION
#include "../../../lib/vn_ui_base.h"

/* CHECK SYSTEM FUNCTION */
typedef struct {
    int vn_check;
    int vn_true;
    int vn_false;
    int vn_none;
    
} VN_CHECK;

/* CHECK SYSTEM RESULT */
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
void sys_prompt(char* text, char* check, VN_UI_TEXT vnt, VN_CHECK* vnc) {
    vn_print(text, vnt);
    scanf(" %c", check);
    sys_check(*check, vnc);
    vn_code("screen:clear");
}

/* CHECK SYSTEM RESULT */
void sys_result(char check, VN_UI_TEXT vnt_true, VN_UI_TEXT vnt_false) {
    if (check == 'y' || check == 'Y') {
        vn_print("[WORKING]\n", vnt_true);
    } else if (check == 'n' || check == 'N') {
        vn_print("[NOT WORKING]\n", vnt_false);
    } else {
        printf("[ - ]\n");
    }
}

int main() {
    // TRUE FALSE SYSTEM INITIAL
    VN_CHECK vnc = {0};
    char check_screen_clear, check_screen_save_restore;
    char check_cursor_invisible, check_cursor_visible;
    char check_cursor_save_restore, check_cursor_xy;

    /* COLOR DECLARING */
    char* red_fg = vn_color("#e93737", 'f');
    char* green_fg = vn_color("#37e937", 'f');
    char* blue_fg = vn_color("#3737e9", 'f');
    char* black_bg = vn_color("#161616", 'b');
    /* --------------- */

    /* TEXT ATTRIBUTES */
    VN_UI_TEXT vnt;
    strcpy(vnt.color_fg, blue_fg);
    strcpy(vnt.color_bg, black_bg);
    strcpy(vnt.text_style, vn_text_italic);

    VN_UI_TEXT vnt_true;
    strcpy(vnt_true.color_fg, green_fg);
    strcpy(vnt_true.color_bg, black_bg);
    strcpy(vnt_true.text_style, vn_text_bold);

    VN_UI_TEXT vnt_false;
    strcpy(vnt_false.color_fg, red_fg);
    strcpy(vnt_false.color_bg, black_bg);
    strcpy(vnt_false.text_style, vn_text_bold);
    /* --------------- */

    /* ------------- */
    /* TESTING CODES */
    /* ------------- */
    // Screen Clear
    vn_print("[ -------------------------- ]\n", vnt);
    vn_print("[ This text will be cleared. ]\n", vnt);
    vn_print("[ -------------------------- ]\n", vnt);
    wait(1);
    vn_code("screen:clear");

    // CHECK SYSTEM
    sys_prompt("\nIs screen clear? (Y/n): ", &check_screen_clear, vnt, &vnc);

    // Screen Save
    vn_print("[ ---------------------- ]\n", vnt);
    vn_print("[ This screen will save. ]\n", vnt);
    vn_print("[ ---------------------- ]\n", vnt);
    vn_code("screen:save");
    wait(1);
    vn_code("screen:clear");
    
    // Screen Restore
    vn_code("screen:restore");
    
    // CHECK SYSTEM
    sys_prompt("\nIs screen restored? (Y/n): ", &check_screen_save_restore, vnt, &vnc);

    // Cursor Visibility
    vn_print("[ ------------------------------------- ]\n", vnt);
    vn_print("[ Cursor visibility will be turned off. ]\n", vnt);
    vn_print("[ ------------------------------------- ]\n", vnt);
    wait(1);
    vn_code("cursor:invisible");
    vn_print("[ ------------------------ ]\n", vnt);
    vn_print("[ Cursor is now invisible. ]\n", vnt);
    vn_print("[ ------------------------ ]\n", vnt);
    wait(1);
    
    // CHECK SYSTEM
    sys_prompt("\nIs cursor invisible? (Y/n): ", &check_cursor_invisible, vnt, &vnc);

    vn_print("[ ------------------------------------ ]\n", vnt);
    vn_print("[ Cursor visibility will be turned on. ]\n", vnt);
    vn_print("[ ------------------------------------ ]\n", vnt);
    wait(1);
    vn_code("cursor:visible");
    vn_print("[ ---------------------- ]\n", vnt);
    vn_print("[ Cursor is now visible. ]\n", vnt);
    vn_print("[ ---------------------- ]\n", vnt);
    wait(1);

    // CHECK SYSTEM
    sys_prompt("\nIs cursor visible? (Y/n): ", &check_cursor_visible, vnt, &vnc);

    // Cursor Position
    vn_print("[ ------------------------------------------------------------------------------------- ]\n", vnt);
    vn_print("[ Cursor position will be saved and restored. ]\n", vnt);
    vn_print("[ ------------------------------------------------------------------------------------- ]\n", vnt);
    vn_code("cursor:save");
    vn_print(" > Cursor position [SAVED].\n", vnt);
    wait(1);
    vn_code("cursor:restore");
    vn_print(" > Cursor position [RESTORED].\n", vnt);

    // CHECK SYSTEM
    sys_prompt("\nIs cursor position changed? (Y/n): ", &check_cursor_save_restore, vnt, &vnc);

    // Go to x and y
    vn_print("[ ---------------------------- ]\n", vnt);
    vn_print("[ Cursor position will change. ]\n", vnt);
    vn_print("[ ---------------------------- ]\n", vnt);
    wait(1);
    vn_gotoxy(2, 1);
    vn_print("Cursor position did changed.\n", vnt);
    wait(1);

    // CHECK SYSTEM
    sys_prompt("\nIs cursor position changed? (Y/n): ", &check_cursor_xy, vnt, &vnc);

    // End
    vn_print("[ ----------------------------------------- ]\n", vnt);
    vn_print("Working:", vnt);
    printf("%s%s%s %d%s,\n", vnt_true.color_fg, vnt_true.color_bg, vnt_true.text_style, vnc.vn_true, vn_text_reset);

    vn_print("Not working:", vnt);
    printf("%s%s%s %d%s,\n", vnt_false.color_fg, vnt_false.color_bg, vnt_false.text_style, vnc.vn_false, vn_text_reset);

    vn_print("None:", vnt);
    printf("%s%s%s %d%s,\n", vnt.color_fg, vnt.color_bg, vnt.text_style, vnc.vn_none, vn_text_reset);

    vn_print("Total:", vnt);
    printf("%s%s%s %d%s\n", vnt.color_fg, vnt.color_bg, vnt.text_style, vnc.vn_check, vn_text_reset);
    vn_print("[ ----------------------------------------- ]\n", vnt);

    wait(1);

    vn_print("Screen Clear: ", vnt);
    sys_result(check_screen_clear, vnt_true, vnt_false);

    vn_print("Screen Save Restore: ", vnt);
    sys_result(check_screen_save_restore, vnt_true, vnt_false);

    vn_print("Cursor Invisible: ", vnt);
    sys_result(check_cursor_invisible, vnt_true, vnt_false);

    vn_print("Cursor Visible: ", vnt);
    sys_result(check_cursor_visible, vnt_true, vnt_false);

    vn_print("Cursor Save Restore", vnt);
    sys_result(check_cursor_save_restore, vnt_true, vnt_false);

    vn_print("Cursor Go To (x, y): ", vnt);
    sys_result(check_cursor_xy, vnt_true, vnt_false);
    vn_print("[ ----------------------------------------- ]\n", vnt);
    /* ------------- */

    /* FREE 'vn_color' */
    free(red_fg);
    free(green_fg);
    free(blue_fg);
    free(black_bg);
    /* --------------- */

    return 0;
}
