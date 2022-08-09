/* VARIATION TUI (UTILITY) */
#ifndef _VN_UTIL_H
#define _VN_UTIL_H

    struct vn_init
    { /* DEFINATION OF DEFAULT WINDOW SIZES */
        int width; /* WIDTH SIZE SHORTCUT */
        int height; /* HEIGHT SIZE SHORTCUT*/
        int pos_x; /* WINDOW START ROW POSITION */
        int pos_y; /* WINDOW START COLUMN POSITION */
        int cursor_visibility; /* 1 = VISIBLE, 0 = INVISIBLE */
    }; /* NOT NECESSARY (IN WIDGETS CAN USE MANUEL WAY) */

    struct vnc_color 
    { /* VARIATION CUSTOM COLOR */
        int is_fore; /* IS FOR FOREGROUND OR BACKGROUND */
        char* color; /* COLOR BUFFER NEED USE WITH 'vn_color()' FUNCTION */
    }; /* ONLY NEED HEX CODE */

    int vnu_get_repeat(char *str, char chr); /* GET CHAR REPEAT TIMES IN A STRING */

    char vnu_get_char_instantly(void); /* GET CHAR WITHOUT '<Return>' KEY */

    #ifdef __linux__
        void vnu_get_terminal_size(struct vn_init vn); /* GET TERMINAL SIZES TO 'vn_init' */
    #endif /* LINUX ONLY */

    int vnc_hex_number(int number, int left_side); /* NUMBER TO HEX */

    int vnc_hex_letter(char letter, int left_side); /* LETTER TO HEX */

    char *vn_color(char *hex_color, int is_fore); /* FOR CUSTOM COLORS */

    void vn_end(struct vn_init vn); /* GO TO END OF THE WINDOW */

#endif /* MADE BY @hanilr */