/* VARIATION TUI (UTILITY) */
#ifndef _VN_UTIL_H
#define _VN_UTIL_H

struct vn_init
{ /* DEFINATION OF DEFAULT WINDOW SIZES */
    int window_width; /* WIDTH SIZE SHORTCUT */
    int window_height; /* HEIGHT SIZE SHORTCUT*/
    int cursor_visibility; /* 1 = VISIBLE, 0 = INVISIBLE */
}; /* NOT NECESSARY */

struct vnc_color 
{ /* VARIATION CUSTOM COLOR */
    int is_fore; /* IS FOR FOREGROUND OR BACKGROUND */
    char* color; /* COLOR BUFFER NEED USE WITH 'vn_color()' FUNCTION */
}; /* ONLY NEED HEX CODE */

int vnu_get_repeat(char *str, char chr); /* GET CHAR REPEAT TIMES IN A STRING */

char *vn_color(char *hex_color, int is_fore); /* FOR CUSTOM COLORS */

void vn_end(struct vn_init vn); /* GO TO END OF THE WINDOW */

#endif /* MADE BY @hanilr */