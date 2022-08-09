<!-- ![vn](img/vn.png) -->
<!-- ![vn_info](img/vn_info.png) -->
<!-- ![vn_warn](img/vn_warn.png) -->
<!-- ![vn_example](img/vn_example.png) -->
<!-- ![vn_wiki](img/vn_wiki.png) -->

# ![vn](img/vn.png) VARIATION UI ![vn](img/vn.png)

Variation-ui is single-header terminal user interface library. Written in ansi-c. Simple to use, easy to learn and has small codebase. Also updatable thanks to MIT license (Just fork it then add or remove codes).

### ![vn_info](img/vn_info.png)  1.2v


## ![vn_warn](img/vn_warn.png) Important Note ![vn_warn](img/vn_warn.png)

You need to define ` #define VN_IMPLEMENTATION ` before ` #include "vn.h" `
```c
#define VN_UI_IMPLEMENTATION
#include "vn_ui.h"
```

## ![vn_example](img/vn_example.png) Example ![vn_example](img/vn_example.png)

```c
#include <stdio.h>

#define VN_UI_IMPLEMENTATION
#define VN_COLOR
#define VN_WIDGET
#include "vn_ui.h"

int main()
{
  struct vn_init vn;
  vn.width = 60;
  vn.height = 5;
  vn.pos_x = 2;
  vn.pos_y = 2;

  struct vnc_color white;
  struct vnc_color black;
  
  white.is_fore = 0;
  white.color = vn_color("e9e9e9", white.is_fore);
  black.is_fore = 1;
  black.color = vn_color("161616", black.is_fore);
  
  char* msg = "This is the example. If you had a trouble please leave an issue to https://github.com/hanilr/variation/issues have fun!";
  
  vn_clear();
  vn_label(vn.pos_x, vn.pos_y, vn.width, vn.height, black.color, white.color, text_italic, msg);
  vn_end(vn);

  return 0;
}
```

# ![vn](img/vn.png) Compiling as shared-library ![vn](img/vn.png)

![vn_warn](img/vn_warn.png) You can compile as shared-library and develope os specific projects. ![vn_warn](img/vn_warn.png)

![vn_example](img/vn_example.png) How should I compile? ![vn_example](img/vn_example.png)
```
  make win_run 
```
> Windows shared-library (.dll)
>
> If you want to delete this file you can use ` make win_clean `

```
  make uni_run 
```
> Unix shared-library (.so)
>
> If you want to delete this file you can use ` make uni_clean `

### [![vn_wiki](img/vn_wiki.png)](https://github.com/hanilr/variation-ui/wiki) : ![vn_warn](img/vn_warn.png) You can take a look to wiki page if you want learn more! ![vn_warn](img/vn_warn.png)
