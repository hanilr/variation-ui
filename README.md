<!-- ![vn](img/vn.png) -->
<!-- ![vn_info](img/vn_info.png) -->
<!-- ![vn_warn](img/vn_warn.png) -->
<!-- ![vn_example](img/vn_example.png) -->
<!-- ![vn_wiki](img/vn_wiki.png) -->

# ![vn](img/vn.png) VARIATION UI ![vn](img/vn.png)

Variation-ui is single-header terminal user interface library. Written in ansi-c. Simple to use, easy to learn and has small codebase. Also updatable thanks to MIT license (Look [license](#license) if you want to know more).

### ![vn_info](img/vn_info.png) Dependencies:

__Windows & Linux:__
* ` gcc ` > [MinGW](https://sourceforge.net/projects/mingw/)
* ` make ` > [Make For Windows](http://gnuwin32.sourceforge.net/packages/make.htm)

> You can install with package managers for linux.

## ![vn_warn](img/vn_warn.png) Important Note ![vn_warn](img/vn_warn.png)

You need to define ` #define VN_UI_IMPLEMENTATION ` before ` #include "vn_ui.h" `
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
  white.color = vn_hex_color("e9e9e9", white.is_fore);
  black.is_fore = 1;
  black.color = vn_rgb_color(22, 22, 22, black.is_fore);
  
  char* msg = "This is the example. If you had a trouble please leave an issue to https://github.com/hanilr/variation/issues have fun!";
  
  vn_clear();
  vn_label(vn.pos_x, vn.pos_y, vn.width, vn.height, black.color, white.color, text_italic, msg);
  vn_end(vn);

  return 0;
}
```

# ![vn](img/vn.png) Compiling as shared-library or Using as default ![vn](img/vn.png)

![vn_warn](img/vn_warn.png) You can compile as shared-library and develope os specific projects. ![vn_warn](img/vn_warn.png)

![vn_example](img/vn_example.png) How should I compile? ![vn_example](img/vn_example.png)
```
  make run
```
> Windows shared-library (.dll) or Unix shared-library (.so)
>
> If you want to delete this file you can use ` make clean `

![vn_example](img/vn_example.png) What if I want to use as default? ![vn_example](img/vn_example.png)
```
  make install
```
> If you only want to download library with terminal then use curl tool
```sh
curl -fLo /usr/include/vn/vn_ui.h --create-dirs https://raw.githubusercontent.com/hanilr/variation-ui/master/vn_ui.h
```
> If you use curl tool then you need to compile with sudo.
>
> Installing section now run only in unix. (You can find in ` /usr/include/vn/ `)
>
> If you want to uninstall you can use ` make uninstall `

### [![vn_wiki](img/vn_wiki.png)](doc/markdown/wiki.md) : ![vn_warn](img/vn_warn.png) You can take a look to wiki page if you want learn more! ![vn_warn](img/vn_warn.png)

### License
```
MIT License

Copyright (c) 2022 Hakkı Anıl Ragıboğlu

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
