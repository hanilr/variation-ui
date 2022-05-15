# ![ vn](https://user-images.githubusercontent.com/77579421/164911621-a215c7ac-bd70-40f4-9c7a-c9435f774599.png) VARIATION UI ![ vn](https://user-images.githubusercontent.com/77579421/164911621-a215c7ac-bd70-40f4-9c7a-c9435f774599.png)

Variation-ui is single-header terminal user interface library. Written in ansi-c. Simple to use, easy to learn and has small codebase. Also updatable thanks to MIT license (Just fork it then add or remove codes).

### ![vn_info](https://user-images.githubusercontent.com/77579421/164913730-eaf5649c-3b64-43c7-8d6f-6e25834ec242.png)  1.1v


## ![vn_warn](https://user-images.githubusercontent.com/77579421/164912332-2be5023b-f5e6-4329-9b0b-b3d545f62618.png) Important Note ![vn_warn](https://user-images.githubusercontent.com/77579421/164912332-2be5023b-f5e6-4329-9b0b-b3d545f62618.png)

You need to define ` #define VN_IMPLEMENTATION ` before ` #include "vn.h" `
```c
#define VN_IMPLEMENTATION
#include "vn.h"
```

## ![vn_example](https://user-images.githubusercontent.com/77579421/164912651-d86e1e6a-48ae-4578-b027-b73f865fd4ec.png) Example ![vn_example](https://user-images.githubusercontent.com/77579421/164912645-827d4d60-beae-4401-bee7-8ee097f30c0d.png)

```c
#include <stdio.h>

#define VN_IMPLEMENTATION
#define VN_COLOR
#define VN_WIDGET
#include "vn.h"

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

# ![ vn](https://user-images.githubusercontent.com/77579421/164911621-a215c7ac-bd70-40f4-9c7a-c9435f774599.png) Compiling as shared-library ![ vn](https://user-images.githubusercontent.com/77579421/164911621-a215c7ac-bd70-40f4-9c7a-c9435f774599.png)

![vn_warn](https://user-images.githubusercontent.com/77579421/164912332-2be5023b-f5e6-4329-9b0b-b3d545f62618.png) You can compile as shared-library and develope os specific projects. ![vn_warn](https://user-images.githubusercontent.com/77579421/164912332-2be5023b-f5e6-4329-9b0b-b3d545f62618.png)

![vn_example](https://user-images.githubusercontent.com/77579421/164912651-d86e1e6a-48ae-4578-b027-b73f865fd4ec.png) How should I compile? ![vn_example](https://user-images.githubusercontent.com/77579421/164912651-d86e1e6a-48ae-4578-b027-b73f865fd4ec.png)
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

### [![vn_wiki](https://user-images.githubusercontent.com/77579421/164913562-9a6c5bb6-91d4-4aff-80b5-47dd773eddd2.png)](https://github.com/hanilr/variation-ui/wiki) : ![vn_warn](https://user-images.githubusercontent.com/77579421/164912332-2be5023b-f5e6-4329-9b0b-b3d545f62618.png) You can take a look to wiki page if you want learn more! ![vn_warn](https://user-images.githubusercontent.com/77579421/164912332-2be5023b-f5e6-4329-9b0b-b3d545f62618.png)
