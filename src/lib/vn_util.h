/* VARIATION TUI (UTILITY) */
#ifndef _VN_UTIL_H
#define _VN_UTIL_H

struct vn_init
{ /* DEFINATION OF DEFAULT WINDOW SIZES */
    int window_width; /* WIDTH SIZE SHORTCUT */
    int window_height; /* HEIGHT SIZE SHORTCUT*/
}; /* NOT NECESSARY */

struct vnc_color 
{ /* VARIATION CUSTOM COLOR */
    int is_fore; /* IS FOR FOREGROUND OR BACKGROUND */
    char* color; /* COLOR BUFFER NEED USE WITH 'vn_color()' FUNCTION */
}; /* ONLY NEED HEX CODE */

char *vn_color(char *hex_color, int is_fore); /* FOR CUSTOM COLORS */

#endif /* MADE BY @hanilr */