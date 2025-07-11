#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include <windows.h>
    #define wait(x) Sleep((x) * 1000)
#else
    #include <unistd.h>
    #define wait(x) sleep(x)
#endif

#define VN_UI_BASE_IMPLEMENTATION
#include "../../../lib/vn_ui_base.h"

int main() {
    char* red_fg = vn_color("#e93737", 'f');
    char* black_bg = vn_color("#161616", 'b');

    VN_UI_TEXT vnt;
    strcpy(vnt.color_fg, red_fg);
    strcpy(vnt.color_bg, black_bg);
    strcpy(vnt.text_style, vn_text_italic);

    // Screen Clear
    vn_print("-----------------------------\n", vnt);
    vn_print("This text should not visible.\n", vnt);
    vn_print("-----------------------------\n", vnt);
    vn_code("screen:clear");

    // Screen Save
    vn_print("------------------------------------------\n", vnt);
    vn_print("This screen will save. This text included.\n", vnt);
    vn_print("------------------------------------------\n", vnt);
    vn_code("screen:save");
    wait(5);
    
    // Screen Restore
    vn_print("[After 5 second screen save will be restored.]\n", vnt);
    wait(5);
    vn_code("screen:restore");
    vn_print("[Screen restored!]\n", vnt);
    wait(5);
    vn_code("screen:clear");

    // Cursor Visibility
    vn_print("------------------------------------------\n", vnt);
    vn_print("Now, cursor visibility will be turned off.\n", vnt);
    vn_print("------------------------------------------\n", vnt);
    vn_code("cursor:invisible");
    vn_print("[Can you see the cursor?]\n", vnt);
    wait(5);
    vn_code("cursor:visible");
    vn_print("[You can see the cursor again now.]\n", vnt);
    vn_code("screen:clear");
    wait(5);

    // Cursor Position
    vn_code("cursor:save");
    vn_print("-------------------------------------------------------------------------------------\n", vnt);
    vn_print("Now, cursor position will be saved and will go to somewhere and will write something.\n", vnt);
    vn_print("-------------------------------------------------------------------------------------\n", vnt);
    vn_code("cursor:restore");
    vn_print("[Edited text here!]\n", vnt);
    wait(5);
    vn_code("screen:clear");

    // Go to x and y
    vn_print("------------------------------------------------------------\n", vnt);
    vn_print("Now, the cursor will go to 2 lines down and write something.\n", vnt);
    vn_print("------------------------------------------------------------\n", vnt);
    vn_gotoxy(25, 0);
    vn_print("[Something]\n", vnt);
    wait(5);
    vn_code("screen:clear");

    // End
    vn_print("-----------------------------------------\n", vnt);
    vn_print("If everything worked, then test finished.\n", vnt);
    vn_print("-----------------------------------------\n", vnt);

    free(red_fg);
    free(black_bg);

    return 0;
}
