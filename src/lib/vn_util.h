/* VARIATION UI (UTILITY) */
#ifndef _VN_UTIL_H
#define _VN_UTIL_H
    /* VN INITIAL STRUCT */
    struct vn_init
    { /* DEFINATION OF DEFAULT WINDOW SIZES */
        int width; /* WIDTH SIZE SHORTCUT */
        int height; /* HEIGHT SIZE SHORTCUT*/
        int pos_x; /* WINDOW START ROW POSITION */
        int pos_y; /* WINDOW START COLUMN POSITION */
        int cursor_visibility; /* 1 = VISIBLE, 0 = INVISIBLE */
    }; /* NOT NECESSARY (IN WIDGETS CAN USE MANUEL WAY) */

    /* VN CUSTOM COLOR STRUCT */
    struct vnc_color 
    { /* VARIATION CUSTOM COLOR */
        int is_fore; /* IS FOR FOREGROUND OR BACKGROUND */
        char* color; /* COLOR BUFFER NEED USE WITH 'vn_color()' FUNCTION */
    }; /* ONLY NEED HEX CODE */

    /* GET CURRENT TIME AND RETURN AS STRING */
    char *vnu_get_time(void);

    /* 'sleep_type' => 'hour', 'minute', 'second' or 'millisecond', 'sleep_time' => INTEGER */
    void vnu_sleep(char *sleep_type, int sleep_time);

    /* GET USER INPUT WITHOUT '<Return>' KEY */
    char vnu_get_char_instantly(void);

    /* GET TERMINAL SIZE, REQUIRED 'vn_init' STRUCT */
    void vnu_get_terminal_size(struct vn_init *vn);

    int vnc_hex_number(int number, int left_side);

    int vnc_hex_letter(char letter, int left_side);

    /* 'hex_color' => HEX COLOR CODE, 'is_fore' => NEED 'self.is_fore' JUST REPLACE 'self' WITH STRUCT NAME */
    char *vn_hex_color(char *hex_color, int is_fore);

    /* RGB COLOR CODE, 'is_fore' => NEED 'self.is_fore' JUST REPLACE 'self' WITH STRUCT NAME */
    char *vn_rgb_color(int red, int green, int blue, int is_fore);

    /* END VN SUCCESSFULLY, REQUIRED 'vn_init' STRUCT */
    void vn_end(struct vn_init vn);
#endif /* MADE BY @hanilr */