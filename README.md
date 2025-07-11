<!-- ![vn](img/vn.png) -->
<!-- ![vn_info](img/vn_info.png) -->
<!-- ![vn_warn](img/vn_warn.png) -->
<!-- ![vn_example](img/vn_example.png) -->
<!-- ![vn_wiki](img/vn_wiki.png) -->

# ![vn](img/vn.png) VARIATION UI ![vn](img/vn.png)

Variation-ui is single-header terminal user interface library. Written in ansi-c. Simple to use, easy to learn and has small codebase. Also updatable thanks to MIT license (Look [license](#license) if you want to know more).

### ![vn_info](img/vn_info.png) Dependencies:

* ` gcc ` _> Gnu Compiler Collection_
* ` make ` _> Gnu Make_

## ![vn_warn](img/vn_warn.png) Important Note ![vn_warn](img/vn_warn.png)

You need to define ` #define VN_UI_IMPLEMENTATION ` before ` #include "vn_ui.h" `
```c
#define VN_UI_IMPLEMENTATION
#include "vn_ui.h"
```

## ![vn_example](img/vn_example.png) Example ![vn_example](img/vn_example.png)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VN_UI_IMPLEMENTATION // Base features
#define VN_WIDGET // Widget features
#include "vn_ui.h"

int main()
{
  /* Color declaring */
  char* color_fg_red = vn_color("#e93737", 'f');
  char* color_bg_blue = vn_color("#3737e9", 'b');

  /* Text attribute */
  VN_UI_TEXT vnt;
  strcpy(vnt.color_fg, color_fg_red);
  strcpy(vnt.color_bg, color_bg_blue);
  strcpy(vnt.text_style, vn_text_bold);

  /* Widget values */
  VN_UI_WIDGET vnw;
  vnw.pos_x = 2;
  vnw.pos_y = 2;
  vnw.width = 20;
  vnw.height = 10;

  /* UI Section */
  vn_bg(' ', vnt, vnw); // Background
  vn_gotoxy((vnw.pos_x + vnw.width) / 2, (vnw.pos_y + vnw.height) / 2); // Go to middle
  vn_print("This is the example.", 'y', vnt.color_fg, vnt.color_bg, vnt.text_style); // Colourful printing
  vn_gotoxy((vnw.pos_x + vnw.width), (vnw.pos_y + vnw.height)); // Go to end

  // Free after use 'vn_color'
  free(color_fg_red);
  free(color_bg_blue);

  return 0;
}
```

# ![vn](img/vn.png) Compiling as shared-library or Using as default ![vn](img/vn.png)

> Show make list `make` or `make run`
```
  make run
```

![vn_warn](img/vn_warn.png) You can compile as shared-library and develope os specific projects. ![vn_warn](img/vn_warn.png)

![vn_example](img/vn_example.png) How should I compile? ![vn_example](img/vn_example.png)
```
  make compile
```
> Unix shared-library (.so)
>
> Windows shared-library (.dll)
>
> If you want to delete this file you can use ` make clean `

![vn_example](img/vn_example.png) What if I want to use as default? ![vn_example](img/vn_example.png)
```
  make install
```

### [![vn_wiki](img/vn_wiki.png)](doc/markdown/wiki.md) : ![vn_warn](img/vn_warn.png) You can take a look to wiki page if you want learn more! ![vn_warn](img/vn_warn.png)

#### Check Other Variation Libraries

* [Variation: Binary](https://github.com/hanilr/variation-bin) - A binary analysis library in Ansi-C.
