#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_UI_IMPLEMENTATION /* DO NOT FORGET THIS */
#define VN_COLOR /* FOR COLOR SECTION */
#include "../../vn_ui.h" /* INCLUDE AFTER DEFINE */

int main()
{
   struct vn_init vn; /* FIRST OF ALL DEFINE WINDOW NAME */
   vn.width = 20; /* WINDOW WIDTH */
   vn.height = 2; /* WINDOW HEIGHT */
   vn.pos_x = 2; /* START ROW POSITION */
   vn.pos_y = 2; /* START COLUMN POSITION */

   struct vnc_color white; /* IF STRUCT NAME WAS A NAME OF THE COLOR THEN YOU CAN UNDERSTAND MUCH EASIER */
   white.is_fore = 0; /* 'is_fore' FOR IS FOREGROUND OR BACKGROUND. IF 'is_fore = 0' THEN YES FOR FOREGROUND, IF 'is_fore = 1' THEN FOR BACKGROUND */
   white.color = vn_hex_color("ffffff", white.is_fore); /* YOU ONLY NEED A HEX CODE TO DEFINE A COLOR */   
   
   struct vnc_color black;
   black.is_fore = 1; /* FOR BACKGROUND */
   black.color = vn_rgb_color(0, 0, 0, black.is_fore);

   vn_clear(); /* CLEAR THE TERMINAL SCREEN */
   vn_gotoxy(vn.pos_x, vn.pos_y); /* GO TO CERTAIN POSITION */
   vn_print("Hey is this text with color?", white.color, black.color, text_bold); /* YOU CAN FIND TEXT STYLES IN 'src/lib/vn_conf.h' or 'vn.h' */

   vn_end(vn); /* ONLY NEED TO USE 'vn_init' */
   return 0;
}