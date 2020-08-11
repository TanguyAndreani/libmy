# libmy

![C/C++ CI](https://github.com/TanguyAndreani/libmy/workflows/C/C++%20CI/badge.svg)

Includes a string manipulation library

## Goals

- As beginner friendly as possible
- With error messages
- Hopefully no segfaults
- Hopefully no memory leaks

## Example

I'm using shortcuts from `include/my_string_shortcuts.h`, if your project
is big and at risk of nameclashes, consider not including this file and
prefix everything with `my_string_` instead of `s_`.

```c
/* You need that before dealing with Unicode characters */
#include <locale.h>
(void)setlocale(LC_ALL, "");

my_string *hello_sekai = s_create(L"Hello, 世界");
my_string *bang = s_create(L"!");

if (s_append_wr(hello_sekai, bang, 0) < 0)
  return (EXIT_FAILURE);
/* equivalent to s_append(hello_sekai, L"!", 1) */

(void)wprintf("%ls\n", s_text(hello_sekai));
/* => Hello, 世界! */

s_destroy(hello_sekai);
s_destroy(bang);
```
