<!-- ![vn](../../img/vn.png) -->
<!-- ![vn_info](../../img/vn_info.png) -->
<!-- ![vn_warn](../../img/vn_warn.png) -->
<!-- ![vn_example](../../img/vn_example.png) -->

# ![vn](../../img/vn.png) About the library ![vn](../../img/vn.png)

![vn_info](../../img/vn_info.png) Variation-ui is single-header terminal user interface library. Written in ansi-c. Simple to use, easy to learn and has small codebase. Also updatable thanks to MIT license (Just fork it then add or remove codes).

# ![vn](../../img/vn.png) Topics ![vn](../../img/vn.png)

* **Basics**
* **General functions**
* **Utils**
* **Colors**
* **Widgets**

![vn_info](../../img/vn_info.png) On the basics page, telling you pre informations about single-header files. Also giving you information about security system.

![vn_info](../../img/vn_info.png) On the general functions page, giving you informations about simple functions.

![vn_info](../../img/vn_info.png) On the utilities page, giving you some informations of utilities (You don't need this).

![vn_info](../../img/vn_info.png) On the colors page, telling you about where come colors and how to use.

![vn_info](../../img/vn_info.png) On the widgets page, telling you how many widgets are they and how to use they.

---

## ![vn](../../img/vn.png) Working with a single-header library ![vn](../../img/vn.png)

![vn_warn](../../img/vn_warn.png) You need to define ` #define VN_UI_IMPLEMENTATION ` before ` #include "vn_ui.h" `
```c
#define VN_UI_IMPLEMENTATION
#include "vn_ui.h"
```
![vn_info](../../img/vn_info.png) Because in header file codes are locked and when you define this name you unlock the code. This information is important, because generally if you want to use single-header library you need to use this method.

![vn_example](../../img/vn_example.png) Lets try this method ![vn_example](../../img/vn_example.png)
```c
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_UI_IMPLEMENTATION /* UNLOCK THE CODE */
#include "vn_ui.h" /* INCLUDING THE LIBRARY */

int main()
{
   vn_clear(); /* TERMINAL SCREEN CLEAR */

   return 0;
}
```
![vn_info](../../img/vn_info.png) In this code you included the library then used terminal screen clear function.

## ![vn](../../img/vn.png) Information about sections of this library ![vn](../../img/vn.png)

![vn_warn](../../img/vn_warn.png) You can use 3 more of them for this library
* **'VN_UI_IMPEMENTATION':** _Unlock the variation-ui code_
* **'VN_UTIL':** _Unlock the utility section_
* **'VN_COLOR':** _Unlock the color section_
* **'VN_WIDGET':** _Unlock the widget section_

![vn_info](../../img/vn_info.png) Basically they all have the same meaning, each section in the library is divided into categories and you have to define the name of that section to use it.
* **'VN_UTIL':** _If you want to use library exclusive functions you need to define this name._

* **'VN_COLOR':** _If you want to use custom colors you need to define this name._

* **'VN_WIDGET':** _If you need more basic but effective ui functions you need to define this name. (Require 'VN_COLOR' for colors)_

> You can find informations about this sections in the wiki.

---

# ![vn](../../img/vn.png) How colors work ![vn](../../img/vn.png)

![vn_info](../../img/vn_info.png) Did you ever heard the tragedy of darth Plagueis? If you heard, good for you, but its out of context. But if you heard the ascii escape sequence you would understand what I'm talking about. Yes, this library made completely with ascii escape sequence. So, what is ascii escape sequence? You can find out [here](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797). So your terminal must support to ascii escape sequence to using this library.

![vn_warn](../../img/vn_warn.png) Some terminals may not support or not completely support ascii escape sequence.

# ![vn](../../img/vn.png) Example ![vn](../../img/vn.png)

![vn_info](../../img/vn_info.png) So, how can we use colors? No need to explain anything, you can clearly understand with take a look to code.
> You can use 2 type of function: 'vn_hex_color()' and 'vn_rgb_color()' for use hex or rgb color codes to make strings colourful.

![vn_example](../../img/vn_example.png) Let's do it! ![vn_example](../../img/vn_example.png)
```c
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_UI_IMPLEMENTATION /* DO NOT FORGET THIS */
#define VN_COLOR /* FOR COLOR SECTION */
#include "vn_ui.h" /* INCLUDE AFTER DEFINE */

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
```
![vn_info](../../img/vn_info.png) Did you see? Its that simple. If you need information about how to convert hex to color you can take a look in 'src/vn_util.c' or 'vn.h'.

---

# ![vn](../../img/vn.png) Terminal UI Functions ![vn](../../img/vn.png)

![vn_warn](../../img/vn_warn.png) Only you need 'VN_UI_IMPLEMENTATION' to use this functions.

![vn_info](../../img/vn_info.png) Functions:
* **vn_cursor_visibility(int boolean);** _Set visibility of the terminal cursor. If 'boolean' is 1 then cursor is visible, if 'boolean' is 0 then cursor is invisible._
> 'boolean' has int data type because not mixed up ansi-c to c++.
* **vn_clear();** _Clear terminal screen._
* **void vn_gotoxy(int pos_x, int pos_y);** _Go to certain positions in terminal._
* **void vn_savexy();** _Save current terminal cursor position._
* **void vn_restorexy();** _Restore saved terminal cursor position._
* **void vn_print(char** ***str, char** ***fg_color, char** ***bg_color, char** ***str_style);** _Print with color and text style_
* **void vn_savescr();** _Save current terminal screen. (Only for supported terminals)_
* **void vn_restorescr();** _Restore saved terminal screen. (Only for supported terminals)_
> Need 'VN_COLOR' to use 'fg_color' and 'bg_color', but you can find text styles in `src/lib/vn_conf.h` or 'vn.h' for 'str_style'.

# ![vn](../../img/vn.png) Starting and ending ![vn](../../img/vn.png)

![vn_info](../../img/vn_info.png) For starting I'm highly recommend to use 'vn_init' struct for define window start positions, width and heights. And also I'm highly recommend to use 'vn_end' function to end of the code. Because when 'vn_gotoxy' functions used cursor going to certain position but not come back you can use 'vn_gotoxy' function to go to end of the terminal line but that method may confuse you and can be bad for readable code. If you used 'vn_init' struct to define you only need to use 'vn_end' function.

![vn_example](../../img/vn_example.png) Let's try ![vn_example](../../img/vn_example.png)
```c
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_UI_IMPLEMENTATION /* DO NOT FORGET THIS */
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
   printf("I'm going to %d and %d! [1]", vn.pos_x, vn.pos_y);
   
   vn_savexy();
   vn.pos_x = 5;
   vn.pos_y = 5;
   vn_gotoxy(vn.pos_x, vn.pos_y);
   printf("I saved my location and moved here! [2]");
   
   vn_restorexy();
   printf(" | I restored my location and moved a new line! [3]");

   vn_end(vn); /* ONLY NEED TO USE 'vn_init' */
   return 0;
}
```
![vn_info](../../img/vn_info.png) As you can see this code pretty readable and simple.

---

# ![vn](../../img/vn.png) About Utilies ![vn](../../img/vn.png)

![vn_info](../../img/vn_info.png) In this library utilities uses for functions in library. But if you want to use this section you are able to use these functions.

![vn_example](../../img/vn_example.png) What you need to do? ![vn_example](../../img/vn_example.png)
```c
#define VN_UI_IMPLEMENTATION /* UNLOCK THE CODE */
#define VN_UTIL /* UNLOCK THE UTIL SECTION */
#include "vn_ui.h" /* INCLUDING THE LIBRARY */
```
![vn_info](../../img/vn_info.png) As you can see there is no difference between 'VN_UI_IMPLEMENTATION'. Only you need to do same thing.

![vn_warn](../../img/vn_warn.png) You don't need to use this section, only if you want to use. ![vn_warn](../../img/vn_warn.png)

# ![vn](../../img/vn.png) Functions ![vn](../../img/vn.png)

![vn_info](../../img/vn_info.png) So what you have this section?
* **vnu_half_divider(int number);** _Divide an integer to half._
* **vnu_get_repeat(char** ***str, char chr);** _Get character repeat times in a string._
* **vnu_get_time(void);** _Get time as string._
* **vnu_sleep(char** ***sleep_type, int sleep_time)** _Wait time._
* **vnu_get_char_instantly(void);** _Get character without '<Return>' key. (Only for linux)_
* **vnu_get_terminal_size(struct vn_init vn);** _Get terminal sizes to 'vn_init'. (Only for linux)_

---

![vn_info](../../img/vn_info.png) Do you need convenience widgets? If you do need, this library has 4 of pre-prepared function!

* **vn_line(int pos_x, int pos_y, int width, char** ***bg_color);** _Draw simple line_
* **vn_bg(int pos_x, int pos_y, int width, int height, char** ***bg_color);** _Set background_
* **vn_frame(int pos_x, int pos_y, int width, int height, char** ***fg_color, char** ***bg_color, char vertical_symbol, char horizontal_symbol);** _Set frame_
* **vn_label(int pos_x, int pos_y, int width, int height, char** ***fg_color, char** ***bg_color, char** ***text_style, char** ***str);** _Set label_
* **vn_progress(int pos_x, int pos_y, int width, int height, char** ***progress_frame_color, char** ***progress_color, int progress_value);** _Set progress bar_
* **vn_notif(int pos_x, int pos_y, int width, int height, char notif_frame_vertical_symbol, char notif_frame_horizontal_symbol, char** ***notif_frame_fg, char** ***notif_frame_bg, char** ***notif_fg, char** ***notif_bg, char** ***notif_title_fg, char** ***notif_title, char** ***notif_text_style, char** ***notif_text);** _Notification pop-up/screen_
* **vn_timer(int pos_x, int pos_y, char** ***timer_fg, char** ***timer_bg, char** ***timer_style, int time, int is_alarm);** _Time counter_
* **vn_draw(int pos_x, int pos_y, int width, int height, int cursor_pos_x, int cursor_pos_y, char** ***fg_color, char** ***bg_color, char cursor_symbol, char draw_symbol);** _Draw freedomly_
* **vn_shell(int pos_x, int pos_y, char** ***fg_color, char** ***bg_color, char** ***text_style)** _To access to shell_

![vn_info](../../img/vn_info.png) So how can we use? Apparently you need to use 'VN_COLOR' again (Because of colors). 

![vn_warn](../../img/vn_warn.png) But if you don't want to use color you can simply skip arguments with like `vn_label(1, 1, 20, 10, "", "", "", "It's a label!")`



# ![vn](../../img/vn.png) Draw Simple Line ![vn](../../img/vn.png)


![vn_example](../../img/vn_example.png) Example ![vn_example](../../img/vn_example.png)

```c
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_UI_IMPLEMENTATION /* DO NOT FORGET THIS */
#define VN_COLOR /* FOR COLOR SECTION */
#define VN_WIDGET /* FOR WIDGET SECTION */
#include "../../../vn_ui.h" /* INCLUDE AFTER DEFINE */

int main()
{
   struct vn_init vn; /* FIRST OF ALL DEFINE WINDOW NAME */
   vn.width = 20; /* WINDOW WIDTH */
   vn.height = 10; /* WINDOW HEIGHT */
   vn.pos_x = 2; /* START ROW POSITION */
   vn.pos_y = 2; /* START COLUMN POSITION */

   struct vnc_color white; /* IF STRUCT NAME WAS A NAME OF THE COLOR THEN YOU CAN UNDERSTAND MUCH EASIER */
   white.is_fore = 1; /* 'is_fore' FOR IS FOREGROUND OR BACKGROUND. IF 'is_fore = 0' THEN YES FOR FOREGROUND, IF 'is_fore = 1' THEN FOR BACKGROUND */
   white.color = vn_hex_color("ffffff", white.is_fore); /* YOU ONLY NEED A HEX CODE TO DEFINE A COLOR */   

   vn_clear(); /* CLEAR THE TERMINAL SCREEN */
   vn_gotoxy(vn.pos_x, vn.pos_y); /* GO TO CERTAIN POSITION */
   vn_line(vn.pos_x, vn.pos_y, vn.width, white.color, "horizontal");
   vn.pos_y = 4;
   vn_line(vn.pos_x, vn.pos_y, vn.width, white.color, "vertical");

   vn_end(vn); /* ONLY NEED TO USE 'vn_init' */
   return 0;
}
```

# ![vn](../../img/vn.png) Set background color ![vn](../../img/vn.png)


![vn_example](../../img/vn_example.png) Example ![vn_example](../../img/vn_example.png)
```c
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_UI_IMPLEMENTATION /* DO NOT FORGET THIS */
#define VN_COLOR /* FOR COLOR SECTION */
#define VN_WIDGET /* FOR WIDGET SECTION */
#include "../../../vn_ui.h" /* INCLUDE AFTER DEFINE */

int main()
{
   struct vn_init vn; /* FIRST OF ALL DEFINE WINDOW NAME */
   vn.width = 20; /* WINDOW WIDTH */
   vn.height = 10; /* WINDOW HEIGHT */
   vn.pos_x = 2; /* START ROW POSITION */
   vn.pos_y = 2; /* START COLUMN POSITION */

   struct vnc_color white; /* IF STRUCT NAME WAS A NAME OF THE COLOR THEN YOU CAN UNDERSTAND MUCH EASIER */
   white.is_fore = 1; /* 'is_fore' FOR IS FOREGROUND OR BACKGROUND. IF 'is_fore = 0' THEN YES FOR FOREGROUND, IF 'is_fore = 1' THEN FOR BACKGROUND */
   white.color = vn_hex_color("ffffff", white.is_fore); /* YOU ONLY NEED A HEX CODE TO DEFINE A COLOR */   

   vn_clear(); /* CLEAR THE TERMINAL SCREEN */
   vn_gotoxy(vn.pos_x, vn.pos_y); /* GO TO CERTAIN POSITION */
   vn_bg(vn.pos_x, vn.pos_y, 20, 10, white.color);

   vn_end(vn); /* ONLY NEED TO USE 'vn_init' */
   return 0;
}
```
![vn_info](../../img/vn_info.png) This function only do set background color.

# ![vn](../../img/vn.png) Frame ![vn](../../img/vn.png)

![vn_example](../../img/vn_example.png) Example ![vn_example](../../img/vn_example.png)
```c
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_UI_IMPLEMENTATION /* DO NOT FORGET THIS */
#define VN_COLOR /* FOR COLOR SECTION */
#define VN_WIDGET /* FOR WIDGET SECTION */
#include "../../../vn_ui.h" /* INCLUDE AFTER DEFINE */

int main()
{
   struct vn_init vn; /* FIRST OF ALL DEFINE WINDOW NAME */
   vn.width = 20; /* WINDOW WIDTH */
   vn.height = 10; /* WINDOW HEIGHT */
   vn.pos_x = 2; /* START ROW POSITION */
   vn.pos_y = 2; /* START COLUMN POSITION */

   struct vnc_color white; /* IF STRUCT NAME WAS A NAME OF THE COLOR THEN YOU CAN UNDERSTAND MUCH EASIER */
   white.is_fore = 1; /* 'is_fore' FOR IS FOREGROUND OR BACKGROUND. IF 'is_fore = 0' THEN YES FOR FOREGROUND, IF 'is_fore = 1' THEN FOR BACKGROUND */
   white.color = vn_hex_color("ffffff", white.is_fore); /* YOU ONLY NEED A HEX CODE TO DEFINE A COLOR */

   struct vnc_color gray;
   gray.is_fore = 0; /* FOR FOREGROUND */
   gray.color = vn_hex_color("303030", gray.is_fore);

   vn_clear(); /* CLEAR THE TERMINAL SCREEN */
   vn_gotoxy(vn.pos_x, vn.pos_y); /* GO TO CERTAIN POSITION */
   vn_frame(vn.pos_x, vn.pos_y, 20, 10, gray.color, white.color, '|', '-');

   vn_end(vn); /* ONLY NEED TO USE 'vn_init' */
   return 0;
}
```
![vn_info](../../img/vn_info.png) This function only do make a frame with or without color.

# ![vn](../../img/vn.png) Label ![vn](../../img/vn.png)

![vn_example](../../img/vn_example.png) Example ![vn_example](../../img/vn_example.png)
```c
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_UI_IMPLEMENTATION /* DO NOT FORGET THIS */
#define VN_COLOR /* FOR COLOR SECTION */
#define VN_WIDGET /* FOR WIDGET SECTION */
#include "../../../vn_ui.h" /* INCLUDE AFTER DEFINE */

int main()
{
   struct vn_init vn; /* FIRST OF ALL DEFINE WINDOW NAME */
   vn.width = 20; /* WINDOW WIDTH */
   vn.height = 10; /* WINDOW HEIGHT */
   vn.pos_x = 2; /* START ROW POSITION */
   vn.pos_y = 2; /* START COLUMN POSITION */

   struct vnc_color white; /* IF STRUCT NAME WAS A NAME OF THE COLOR THEN YOU CAN UNDERSTAND MUCH EASIER */
   white.is_fore = 1; /* 'is_fore' FOR IS FOREGROUND OR BACKGROUND. IF 'is_fore = 0' THEN YES FOR FOREGROUND, IF 'is_fore = 1' THEN FOR BACKGROUND */
   white.color = vn_hex_color("ffffff", white.is_fore); /* YOU ONLY NEED A HEX CODE TO DEFINE A COLOR */

   struct vnc_color gray;
   gray.is_fore = 0; /* FOR FOREGROUND */
   gray.color = vn_hex_color("303030", gray.is_fore);

   vn_clear(); /* CLEAR THE TERMINAL SCREEN */
   vn_gotoxy(vn.pos_x, vn.pos_y); /* GO TO CERTAIN POSITION */
   vn_label(vn.pos_x, vn.pos_y, 20, 10, gray.color, white.color, text_italic, "This is a label with or without colors!");

   vn_end(vn); /* ONLY NEED TO USE 'vn_init' */
   return 0;
}
```
![vn_info](../../img/vn_info.png) If a word can't fit to certain line will move new line. If string too long (as height) for label then last 3 character will be '...'

# ![vn](../../img/vn.png) Progress bar ![vn](../../img/vn.png)

![vn_example](../../img/vn_example.png) Example ![vn_example](../../img/vn_example.png)
```c
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_UI_IMPLEMENTATION /* DO NOT FORGET THIS */
#define VN_COLOR /* FOR COLOR SECTION */
#define VN_WIDGET /* FOR WIDGET SECTION */
#include "../../../vn_ui.h" /* INCLUDE AFTER DEFINE */

int main()
{
   struct vn_init vn; /* FIRST OF ALL DEFINE WINDOW NAME */
   vn.width = 20; /* WINDOW WIDTH */
   vn.height = 10; /* WINDOW HEIGHT */
   vn.pos_x = 2; /* START ROW POSITION */
   vn.pos_y = 2; /* START COLUMN POSITION */

   struct vnc_color white; /* IF STRUCT NAME WAS A NAME OF THE COLOR THEN YOU CAN UNDERSTAND MUCH EASIER */
   white.is_fore = 1; /* 'is_fore' FOR IS FOREGROUND OR BACKGROUND. IF 'is_fore = 0' THEN YES FOR FOREGROUND, IF 'is_fore = 1' THEN FOR BACKGROUND */
   white.color = vn_hex_color("ffffff", white.is_fore); /* YOU ONLY NEED A HEX CODE TO DEFINE A COLOR */

   struct vnc_color gray;
   gray.is_fore = 0; /* FOR FOREGROUND */
   gray.color = vn_hex_color("303030", gray.is_fore);

   vn_clear(); /* CLEAR THE TERMINAL SCREEN */
   vn_gotoxy(vn.pos_x, vn.pos_y); /* GO TO CERTAIN POSITION */
   vn_progress(vn.pos_x, vn.pos_y, 20, 10, white.color, gray.color, 10);

   vn_end(vn); /* ONLY NEED TO USE 'vn_init' */
   return 0;
}
```
![vn_info](../../img/vn_info.png) This function also work with loops.
```c
   int i = 0;
   while(i > 10)
   {
      /* DO SOMETHING */
      vn_progress(vn.pos_x, vn.pos_y, 20, 10, white.color, gray.color, i);
      i+=2;
   }
```

# ![vn](../../img/vn.png) Notification Pop-up/Screen ![vn](../../img/vn.png)


![vn_example](../../img/vn_example.png) Example ![vn_example](../../img/vn_example.png)

```c
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_UI_IMPLEMENTATION /* DO NOT FORGET THIS */
#define VN_COLOR /* FOR COLOR SECTION */
#define VN_UTIL /* FOR UTILITIES */
#define VN_WIDGET /* FOR WIDGET SECTION */
#include "../../../vn_ui.h" /* INCLUDE AFTER DEFINE */

int main()
{
    struct vn_init vn; /* FIRST OF ALL DEFINE WINDOW NAME */
    vn.width = 20; /* WINDOW WIDTH */
    vn.height = 10; /* WINDOW HEIGHT */
    vn.pos_x = 2; /* START ROW POSITION */
    vn.pos_y = 2; /* START COLUMN POSITION */

    struct vnc_color white; /* IF STRUCT NAME WAS A NAME OF THE COLOR THEN YOU CAN UNDERSTAND MUCH EASIER */
    white.is_fore = 1; /* 'is_fore' FOR IS FOREGROUND OR BACKGROUND. IF 'is_fore = 0' THEN YES FOR FOREGROUND, IF 'is_fore = 1' THEN FOR BACKGROUND */
    white.color = vn_hex_color("ffffff", white.is_fore); /* YOU ONLY NEED A HEX CODE TO DEFINE A COLOR */   

    struct vnc_color blue;
    blue.is_fore = 1;
    blue.color = vn_hex_color("3838c7", blue.is_fore);

    struct vnc_color green;
    green.is_fore = 0;
    green.color = vn_hex_color("38c738", green.is_fore);

    struct vnc_color red;
    red.is_fore = 0;
    red.color = vn_hex_color("c73838", red.is_fore);

    vn_clear(); /* CLEAR THE TERMINAL SCREEN */
    vn_notif(vn.pos_x, vn.pos_y, vn.width, vn.height, '|', '-', green.color, blue.color, green.color, white.color, red.color, "TEST", text_italic, "If this work then 'vn_notif' widget working!");

    vn_end(vn); /* ONLY NEED TO USE 'vn_init' */
    return 0;
}
```

# ![vn](../../img/vn.png) Timer ![vn](../../img/vn.png)


![vn_example](../../img/vn_example.png) Example ![vn_example](../../img/vn_example.png)

```c
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_UI_IMPLEMENTATION /* DO NOT FORGET THIS */
#define VN_COLOR /* FOR COLOR SECTION */
#define VN_WIDGET /* FOR WIDGET SECTION */
#include "../../../vn_ui.h" /* INCLUDE AFTER DEFINE */

int main()
{
   struct vn_init vn; /* FIRST OF ALL DEFINE WINDOW NAME */
   vn.width = 20; /* WINDOW WIDTH */
   vn.height = 10; /* WINDOW HEIGHT */
   vn.pos_x = 2; /* START ROW POSITION */
   vn.pos_y = 2; /* START COLUMN POSITION */

   struct vnc_color white; /* IF STRUCT NAME WAS A NAME OF THE COLOR THEN YOU CAN UNDERSTAND MUCH EASIER */
   white.is_fore = 1; /* 'is_fore' FOR IS FOREGROUND OR BACKGROUND. IF 'is_fore = 0' THEN YES FOR FOREGROUND, IF 'is_fore = 1' THEN FOR BACKGROUND */
   white.color = vn_hex_color("ffffff", white.is_fore); /* YOU ONLY NEED A HEX CODE TO DEFINE A COLOR */

   struct vnc_color black;
   black.is_fore = 0; /* FOR FOREGROUND */
   black.color = vn_hex_color("161616", black.is_fore);

   vn_clear(); /* CLEAR THE TERMINAL SCREEN */
   vn_timer(vn.pos_x, vn.pos_y, black.color, white.color, text_italic, 5, 0);

   vn_end(vn); /* ONLY NEED TO USE 'vn_init' */
   return 0;
}
```

# ![vn](../../img/vn.png) Draw ![vn](../../img/vn.png)


![vn_example](../../img/vn_example.png) Example ![vn_example](../../img/vn_example.png)

```c
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_UI_IMPLEMENTATION /* DO NOT FORGET THIS */
#define VN_COLOR /* FOR COLOR SECTION */
#define VN_UTIL /* FOR UTILITY SECTION */
#define VN_WIDGET /* FOR WIDGET SECTION */
#include "../../../vn_ui.h" /* INCLUDE AFTER DEFINE */

int main()
{
    struct vn_init vn; /* FIRST OF ALL DEFINE WINDOW NAME */
    vn.width = 20; /* WINDOW WIDTH */
    vn.height = 10; /* WINDOW HEIGHT */
    vn.pos_x = 2; /* START ROW POSITION */
    vn.pos_y = 2; /* START COLUMN POSITION */

    struct vnc_color white; /* IF STRUCT NAME WAS A NAME OF THE COLOR THEN YOU CAN UNDERSTAND MUCH EASIER */
    white.is_fore = 1; /* 'is_fore' FOR IS FOREGROUND OR BACKGROUND. IF 'is_fore = 0' THEN YES FOR FOREGROUND, IF 'is_fore = 1' THEN FOR BACKGROUND */
    white.color = vn_hex_color("ffffff", white.is_fore); /* YOU ONLY NEED A HEX CODE TO DEFINE A COLOR */   

    struct vnc_color black; /* IF STRUCT NAME WAS A NAME OF THE COLOR THEN YOU CAN UNDERSTAND MUCH EASIER */
    black.is_fore = 0; /* 'is_fore' FOR IS FOREGROUND OR BACKGROUND. IF 'is_fore = 0' THEN YES FOR FOREGROUND, IF 'is_fore = 1' THEN FOR BACKGROUND */
    black.color = vn_hex_color("161616", black.is_fore); /* YOU ONLY NEED A HEX CODE TO DEFINE A COLOR */ 

    vn_clear(); /* CLEAR THE TERMINAL SCREEN */
    vn_draw(vn.pos_x, vn.pos_y, vn.width, vn.height, vn.pos_x+vnu_half_divider(vn.width), vn.pos_y+vnu_half_divider(vn.height), black.color, white.color, 'x', '.');

    vn_end(vn); /* ONLY NEED TO USE 'vn_init' */
    return 0;
}
```

![vn_info](../../img/vn_info.png) You can move with `wasd`. Also you can change foreground and background colors! For changing the color just press `c` key. Then write `fg` or `bg` to change. Finally you can type a hex color code then color will change! You want to quit? Just press `q` key!


# ![vn](../../img/vn.png) Shell ![vn](../../img/vn.png)


![vn_example](../../img/vn_example.png) Example ![vn_example](../../img/vn_example.png)

```c
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_UI_IMPLEMENTATION /* DO NOT FORGET THIS */
#define VN_COLOR /* FOR COLOR SECTION */
#define VN_WIDGET /* FOR WIDGET SECTION */
#include "../../../vn_ui.h" /* INCLUDE AFTER DEFINE */

int main()
{
   struct vn_init vn; /* FIRST OF ALL DEFINE WINDOW NAME */
   vn.width = 20; /* WINDOW WIDTH */
   vn.height = 10; /* WINDOW HEIGHT */
   vn.pos_x = 2; /* START ROW POSITION */
   vn.pos_y = 2; /* START COLUMN POSITION */

   struct vnc_color white; /* IF STRUCT NAME WAS A NAME OF THE COLOR THEN YOU CAN UNDERSTAND MUCH EASIER */
   white.is_fore = 1; /* 'is_fore' FOR IS FOREGROUND OR BACKGROUND. IF 'is_fore = 0' THEN YES FOR FOREGROUND, IF 'is_fore = 1' THEN FOR BACKGROUND */
   white.color = vn_hex_color("ffffff", white.is_fore); /* YOU ONLY NEED A HEX CODE TO DEFINE A COLOR */

   struct vnc_color black;
   black.is_fore = 0; /* FOR FOREGROUND */
   black.color = vn_hex_color("161616", black.is_fore);

   vn_clear(); /* CLEAR THE TERMINAL SCREEN */
   vn_shell(vn.pos_x, vn.pos_y, black.color, white.color, "");

   vn_end(vn); /* ONLY NEED TO USE 'vn_init' */
   return 0;
}
```

![vn_info](../../img/vn_info.png) In `vn_shell` function command max length is `1024` byte!