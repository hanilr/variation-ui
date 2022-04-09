# VARIATION
Single-header terminal user interface library. Written in ansi-c. Simple to use and keep updating. If you want to develope this project you can always use pull request section.

## ` This project not finished yet but will be more feature in the future. Some examples or informations in wiki or readme page may not be up to date! `

## Build
You need to define ` #define VN_IMPLEMENTATION ` before ` #include "vn.h" `
```c
#define VN_IMPLEMENTATION
#include "vn.h"
```

## Example
```c
#include <stdio.h>

#define VN_IMPLEMENTATION
#define VN_COLOR
#define VN_WIDGET
#include "vn.h"

int main()
{
  struct vnc_color white;
  struct vnc_color black;
  
  white.is_fore = 0;
  white.color = vn_color("e9e9e9", white.is_fore);
  black.is_fore = 1;
  black.color = vn_color("161616", black.is_fore);
  
  char* msg = "This is the example. If you had a trouble please leave an issue to https://github.com/hanilr/variation/issues have fun!";
  
  vn_clear();
  vn_label(2, 2, 60, 5, black.color, white.color, text_italic, msg);
  vn_gotoxy(0, 7);

  return 0;
}
```
### If you want to learn more please take a look to [wiki](https://github.com/hanilr/variation/wiki) page.

## TO DO LIST

* There is no wiki page yet so prepare the first release the project then make a wiki page.
* Need more widget. Research the tui widgets then make an optimized one.
* Do some demos, examples and documentories.

## NEED TO SOLVE
* User need to use 'vn_gotoxy(pos_x, pos_y);' before finish the code.
* Functions terminal sizes user dependent.
> Solution: Making a terminal size getting function then make a struct to define the terminal sizes.
> like ` vn_get_terminal_size(); ` and ` struct vn_start `
> Then make ` vn_init(struct vn_start); ` and ` vn_end(struct vn_start); `
