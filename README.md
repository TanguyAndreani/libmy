# libmy

![C/C++ CI](https://github.com/TanguyAndreani/libmy/workflows/C/C++%20CI/badge.svg)

Includes a string manipulation library

## Goals

- As beginner friendly as possible
- With error messages
- Hopefully no segfaults
- Hopefully no memory leaks

## Example

```c
my_string *hello_sekai = my_string_create(L"Hello, 世界");
my_string *bang = my_string_create(L"!");

my_string_append_wr(hello_sekai, bang, 0);

wprintf("%ls\n", hello_sekai->unicode);
/* => Hello, 世界! */

my_string_destroy(hello_sekai);
my_string_destroy(bang);
```
