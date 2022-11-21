#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_UI_IMPLEMENTATION /* DO NOT FORGET THIS */
#define VN_UTIL /* FOR UTILITY SECTION */
#include "../../vn_ui.h" /* INCLUDE AFTER DEFINE */

int main()
{
   struct vn_init vn; /* FIRST OF ALL DEFINE WINDOW NAME */
   vn.width = 20; /* WINDOW WIDTH */
   vn.height = 2; /* WINDOW HEIGHT */
   vn.pos_x = 2; /* START ROW POSITION */
   vn.pos_y = 2; /* START COLUMN POSITION */

   vn_clear(); /* CLEAR THE TERMINAL SCREEN */
   vn_gotoxy(vn.pos_x, vn.pos_y); /* GO TO CERTAIN POSITION */
   printf("I'm going to %d and %d! [1]\n", vn.pos_x, vn.pos_y);
   vnu_sleep("second", 5);
   
   vn_savexy();
   vn.pos_x = 5;
   vn.pos_y = 5;
   vn_gotoxy(vn.pos_x, vn.pos_y);
   printf("I saved my location and moved here! [2]\n");
   vnu_sleep("second", 2);
   
   vn_restorexy();
   printf(" | I restored my location and moved a new line! [3]\n");
   vnu_sleep("second", 2);

   vn_savescr();
   vn_clear();
   vn.pos_x = 3;
   vn.pos_y = 3;
   vn_gotoxy(vn.pos_x, vn.pos_y);
   printf("If 5 second passed but you can see this text? Then your terminal doesn't support screen save/restore feature!\n");
   vnu_sleep("second", 5);
   vn_restorescr();

   vn_end(vn); /* ONLY NEED TO USE 'vn_init' */
   return 0;
}